import { base_url } from "./globals.js";

let slideAtual = 0;
let opinioes = [];

document.addEventListener("DOMContentLoaded", () => {
  fetch(`${base_url}/carrosselOpinioesUsuarios`)
    .then(res => res.json())
    .then(data => {
      opinioes = data;
      renderizarCarrossel(opinioes);
      atualizarSlide();
    });
    document.getElementById("btn-anterior").addEventListener("click", () => mudarSlide(-1));
    document.getElementById("btn-proximo").addEventListener("click", () => mudarSlide(1));

});

function renderizarCarrossel(data) {
  const container = document.getElementById("carrosselOpinioes");

  // DUPLICA o primeiro e o último para efeito de looping
  const primeiro = data[0];
  const ultimo = data[data.length - 1];
  const slides = [ultimo, ...data, primeiro];

  container.innerHTML = slides.map(op => `
    <div class="opiniao-card">
      <div class="opiniao-usuario">
        <img src="${op.foto}" alt="${op.nome}">
        <div class="opiniao-info">
          <strong>${op.nome}</strong>
          <small>${op.cargo}<br>${op.cidade}</small>
        </div>
      </div>
      <div class="stars">★★★★★</div>
      <div class="opiniao-texto">"${op.depoimento}"</div>
    </div>
  `).join("");

  // Posiciona no "primeiro slide real"
  setTimeout(() => {
    const larguraSlide = container.offsetWidth;
    container.style.transform = `translateX(-${larguraSlide}px)`;
    slideAtual = 1;
  }, 50);
}

function mudarSlide(direcao) {
  const container = document.getElementById("carrosselOpinioes");
  const totalSlides = opinioes.length + 2; // +2 por causa dos clones
  const larguraSlide = container.offsetWidth;

  slideAtual += direcao;
  container.style.transition = "transform 0.5s ease-in-out";
  container.style.transform = `translateX(-${slideAtual * larguraSlide}px)`;

  // Ajusta após a transição se for um clone
  container.addEventListener("transitionend", () => {
    container.style.transition = "none";

    if (slideAtual === 0) {
      slideAtual = opinioes.length;
      container.style.transform = `translateX(-${slideAtual * larguraSlide}px)`;
    }

    if (slideAtual === totalSlides - 1) {
      slideAtual = 1;
      container.style.transform = `translateX(-${larguraSlide}px)`;
    }
  }, { once: true });
}

function atualizarSlide() {
  const container = document.getElementById("carrosselOpinioes");
  const larguraSlide = container.offsetWidth;
  container.style.transform = `translateX(-${(slideAtual + 1) * larguraSlide}px)`;
}

// CARROSSEL LP
let slideIndexLP = 1;
let totalSlidesLP = 0;

document.addEventListener("DOMContentLoaded", () => {
  fetch("/carrosselLP")
    .then(res => res.json())
    .then(data => {
      renderizarCarrosselLP(data);
      totalSlidesLP = data.length;
      atualizarCarrosselLP(false);
    });
});

function renderizarCarrosselLP(imagens) {
  const carrossel = document.getElementById("carrosselLP");
  const primeiro = imagens[0];
  const ultimo = imagens[imagens.length - 1];
  const clones = [ultimo, ...imagens, primeiro];

  carrossel.innerHTML = clones.map(img => `
    <div class="slide">
      <img src="${img.url}" alt="${img.titulo}">
      <div class="legenda">
        <h3>${img.titulo}</h3>
        <p>${img.descricao}</p>
      </div>
    </div>
  `).join("");
}

function mudarSlideLP(direcao) {
  slideIndexLP += direcao;
  atualizarCarrosselLP(true);
}

function atualizarCarrosselLP(animar = true) {
  const carrossel = document.getElementById("carrosselLP");
  carrossel.style.transition = animar ? "transform 0.6s ease" : "none";
  carrossel.style.transform = `translateX(-${slideIndexLP * 100}%)`;

  if (slideIndexLP === 0 || slideIndexLP === totalSlidesLP + 1) {
    setTimeout(() => {
      carrossel.style.transition = "none";
      slideIndexLP = slideIndexLP === 0 ? totalSlidesLP : 1;
      carrossel.style.transform = `translateX(-${slideIndexLP * 100}%)`;
    }, 600);
  }
}

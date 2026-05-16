// CARROSSEL OPINIÕES
let slideIndexOpinioes = 1;
let totalSlidesOpinioes = 0;

document.addEventListener("DOMContentLoaded", () => {
  fetch("/carrosselOpinioesUsuarios")
    .then(res => res.json())
    .then(data => {
      renderizarCarrosselOpinioes(data);
      totalSlidesOpinioes = data.length;
      atualizarCarrosselOpinioes(false);
    });
});

function renderizarCarrosselOpinioes(imagens) {
  const carrossel = document.getElementById("carrosselOpinioes");
  const primeiro = imagens[0];
  const ultimo = imagens[imagens.length - 1];
  const clones = [ultimo, ...imagens, primeiro];

  carrossel.innerHTML = clones.map(img => `
    <div class="slide">
      <img src="${img.url}" alt="${img.nome}">
      <div class="legenda">
        <h3>${img.nome}</h3>
        <p>${img.nota}</p>
      </div>
    </div>
  `).join("");
}

function mudarSlideOpinioes(direcao) {
  slideIndexOpinioes += direcao;
  atualizarCarrosselOpinioes(true);
}

function atualizarCarrosselOpinioes(animar = true) {
  const carrossel = document.getElementById("carrosselOpinioes");
  carrossel.style.transition = animar ? "transform 0.6s ease" : "none";
  carrossel.style.transform = `translateX(-${slideIndexOpinioes * 100}%)`;

  if (slideIndexOpinioes === 0 || slideIndexOpinioes === totalSlidesOpinioes + 1) {
    setTimeout(() => {
      carrossel.style.transition = "none";
      slideIndexOpinioes = slideIndexOpinioes === 0 ? totalSlidesOpinioes : 1;
      carrossel.style.transform = `translateX(-${slideIndexOpinioes * 100}%)`;
    }, 600);
  }
}

import { base_url } from "./globals.js";

fetch(`${base_url}/equipe`)
  .then(res => res.json())
  .then(equipe => {
    const container = document.getElementById("containerEquipe");
    equipe.forEach(m => {
      container.innerHTML += `
        <div class="membro">
          <img src="${m.imagem}" alt="${m.nome}">
          <h4>${m.nome}</h4>
          <p>${m.descricao}</p>
        </div>`;
    });
  });

function animarMembrosAoScroll() {
  const membros = document.querySelectorAll('.membro');
  membros.forEach(membro => {
    const top = membro.getBoundingClientRect().top;
    const windowHeight = window.innerHeight;

    if (top < windowHeight - 50) {
      membro.classList.add('ativo');
    }
  });
}

window.addEventListener('scroll', animarMembrosAoScroll);
window.addEventListener('load', animarMembrosAoScroll);

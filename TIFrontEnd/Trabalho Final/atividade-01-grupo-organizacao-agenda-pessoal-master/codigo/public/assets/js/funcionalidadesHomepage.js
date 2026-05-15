import { base_url } from "./globals.js";

document.addEventListener("DOMContentLoaded", () => {
  fetch(`${base_url}/funcionalidadesApp`)
    .then(res => res.json())
    .then(data => renderizarFuncionalidades(data));
});

function renderizarFuncionalidades(funcionalidades) {
  const container = document.getElementById("funcionalidades");
  container.innerHTML = funcionalidades.map((item, index) => `
    <div class="funcionalidade-bloco" style="flex-direction: ${index % 2 === 0 ? 'row' : 'row-reverse'}">
      <div class="func-texto">
        <h2>${item.titulo}</h2>
        <p>${item.descricao}</p>
      </div>
      <div class="func-img">
        <img src="${item.url}" alt="${item.titulo}">
      </div>
    </div>
  `).join("");
}

if (localStorage.getItem("loggedUser")) {
  const btnLogin = document.querySelector(".btn-login")
  btnLogin.innerHTML = "Painel Interno"
  btnLogin.href = "../Interno"
}

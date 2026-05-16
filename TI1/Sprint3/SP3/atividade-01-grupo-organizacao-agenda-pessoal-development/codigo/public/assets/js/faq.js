import { base_url } from "./globals.js";

fetch(`${base_url}/faq`)
  .then(res => res.json())
  .then(faqs => {
    const container = document.getElementById('faq-container');
    faqs.forEach((item, index) => {
      const bloco = document.createElement('div');
      bloco.classList.add('faq-item');
      bloco.innerHTML = `
                <div class="faq-pergunta">
                  <i class="bi bi-chevron-down icon" id="icon-${index}"></i>
                  <h4>${item.pergunta}</h4>
                </div>
                <div class="faq-resposta" id="resposta-${index}">
                  <p>${item.resposta}</p>
                </div>
            `;
      container.appendChild(bloco);

      bloco.querySelector('.faq-pergunta').addEventListener('click', () => {
        toggleFaq(index);
      });
    });
  });

function toggleFaq(index) {
  const resposta = document.getElementById(`resposta-${index}`);
  const icon = document.getElementById(`icon-${index}`);
  resposta.classList.toggle('ativo');
  icon.classList.toggle('rotacionado');
}

if (localStorage.getItem("loggedUser")) {
  const btnLogin = document.querySelector(".btn-login")
  btnLogin.innerHTML = "Painel Interno"
  btnLogin.href = "../Interno"
}
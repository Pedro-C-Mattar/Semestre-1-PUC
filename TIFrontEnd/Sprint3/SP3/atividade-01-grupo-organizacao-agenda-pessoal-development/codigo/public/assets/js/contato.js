import { base_url } from "./globals.js";

document.addEventListener("DOMContentLoaded", function () {
  document.getElementById('formContato').addEventListener('submit', function (e) {
    e.preventDefault();

    const nome = document.getElementById('nome').value;
    const email = document.getElementById('email').value;
    const mensagem = document.getElementById('mensagem').value;

    const contato = {
      nome,
      email,
      mensagem,
      data: new Date().toISOString()
    };

    fetch(`${base_url}/contatos`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify(contato)
    })
      .then(res => {
        if (res.ok) {
          document.getElementById('statusEnvio').innerText = "Mensagem enviada com sucesso!";
          document.getElementById('formContato').reset();
        } else {
          document.getElementById('statusEnvio').innerText = "Erro ao enviar mensagem.";
        }
      })
      .catch(() => {
        document.getElementById('statusEnvio').innerText = "Erro de conexão com o servidor.";
      });
  });
  if (localStorage.getItem("loggedUser")) {
    const btnLogin = document.querySelector(".btn-login")
    btnLogin.innerHTML = "Painel Interno"
    btnLogin.href = "../Interno"
  }
});

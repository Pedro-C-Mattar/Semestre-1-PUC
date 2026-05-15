function abrirModal(id, arquivo, destino) {
  fetch(arquivo)
    .then(response => response.text())
    .then(texto => {
      document.getElementById(destino).textContent = texto;
      document.getElementById(id).style.display = "block";
    });
}

function fecharModal(id) {
  document.getElementById(id).style.display = "none";
}

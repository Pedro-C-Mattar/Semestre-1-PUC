fetch("/usuarios")
  .then(res => res.json())
  .then(usuarios => {
    document.getElementById("totalUsuarios").innerText = usuarios.length;
  });

fetch("/tarefas")
  .then(res => res.json())
  .then(tarefas => {
    document.getElementById("totalTarefas").innerText = tarefas.length;
  });

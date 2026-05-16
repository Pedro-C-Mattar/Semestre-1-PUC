import { base_url } from "./globals.js";


fetch(`${base_url}/usuarios`)
  .then(res => res.json())
  .then(usuarios => {
    document.getElementById("totalUsuarios").innerText = usuarios.length;
  });

fetch(`${base_url}/tarefas`)
  .then(res => res.json())
  .then(tarefas => {
    document.getElementById("totalTarefas").innerText = tarefas.length;
  });

import { base_url } from "../../assets/js/globals.js";

// Recupera usuário logado
const usuarioLogado = JSON.parse(localStorage.getItem("loggedUser"));

// Verifica se está logado e é admin
if (!usuarioLogado || !usuarioLogado.admin) {
  document.body.innerHTML = `
    <h2 style="color: red; text-align:center; margin-top: 50px;">
      Acesso negado. Você não é administrador ou não está logado.
    </h2>`;
  throw new Error("Acesso negado.");
}

// Lista de entidades que o admin pode gerenciar
const entidades = [
  "usuarios",
  "funcionalidadesApp",
  "carrosselOpinioesUsuarios",
  "tarefas",
  "status",
  "categorias",
  "sobreNos",
  "equipe",
  "faq",
  "contatos"
];

// Exibe nome do admin
document.getElementById("admin-nome").innerText = `Admin: ${usuarioLogado.nome}`;

// Preenche seletor
const seletor = document.getElementById("painelSelector");
seletor.innerHTML = entidades.map(entidade => `<option value="${entidade}">${entidade}</option>`).join('');
seletor.addEventListener("change", () => renderPainel(seletor.value));

// Botão de voltar
const voltarBtn = document.getElementById("btnVoltar");
if (voltarBtn) {
  voltarBtn.addEventListener("click", () => {
    window.location.href = "../Interno/";
  });
}

// Carrega o painel inicial
carregarPainel();

function carregarPainel() {
  renderPainel(seletor.value);
}

function renderPainel(chave) {
  fetch(`${base_url}/${chave}`)
    .then(res => res.json())
    .then(lista => {
      const content = document.getElementById("admin-content");
      content.innerHTML = `<h3>${chave}</h3>`;

      lista.forEach(item => {
        const div = document.createElement("div");
        div.style.border = "1px solid #ccc";
        div.style.padding = "10px";
        div.style.marginBottom = "10px";
        div.innerHTML = `
          <pre style="white-space: pre-wrap; word-break: break-word;">${JSON.stringify(item, null, 2)}</pre>
          <button onclick="editarItem('${chave}', '${item.id}')">Editar</button>
          <button onclick="excluirItem('${chave}', '${item.id}')">Excluir</button>
        `;
        content.appendChild(div);
      });

      const btnAdicionar = document.createElement("button");
      btnAdicionar.innerText = "Adicionar Novo";
      btnAdicionar.onclick = () => mostrarFormularioAdicionar(chave);
      btnAdicionar.style.marginTop = "20px";
      btnAdicionar.style.marginRight = "10px";
      content.appendChild(btnAdicionar);
    });
}

window.renderPainel = renderPainel;

window.editarItem = function (secao, id) {
  fetch(`${base_url}/${secao}/${id}`)
    .then(res => res.json())
    .then(item => {
      const painel = document.getElementById("admin-content");

      let campos = Object.keys(item).map(key => {
        if (secao === "usuarios" && key === "admin") {
          return `
            <label>${key}:<br>
              <select name="${key}">
                <option value="true" ${item[key] ? "selected" : ""}>true</option>
                <option value="false" ${!item[key] ? "selected" : ""}>false</option>
              </select>
            </label><br><br>
          `;
        }
        return `<label>${key}:<br><input type="text" name="${key}" value="${item[key]}"></label><br><br>`;
      }).join('');

      painel.innerHTML = `
        <h3>Editar ${secao}</h3>
        <form id="form-editar-geral">
          ${campos}
          <button type="submit">Salvar</button>
        </form>
      `;

      document.getElementById("form-editar-geral").onsubmit = function (e) {
        e.preventDefault();
        const form = e.target;
        const dados = {};
        for (let input of form.elements) {
          if (input.name) {
            dados[input.name] = input.name === "admin" ? input.value === "true" : input.value;
          }
        }

        fetch(`${base_url}/${secao}/${id}`, {
          method: "PUT",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify(dados)
        }).then(() => {
          alert("Atualizado com sucesso!");
          renderPainel(secao);
        });
      };
    });
};

window.excluirItem = function (secao, id) {
  if (!confirm("Tem certeza que deseja excluir?")) return;

  fetch(`${base_url}/${secao}/${id}`, {
    method: "DELETE"
  }).then(() => {
    alert("Item excluído!");
    renderPainel(secao);
  });
};

window.mostrarFormularioAdicionar = function(secao) {
  fetch(`${base_url}/${secao}`)
    .then(res => res.json())
    .then(lista => {
      const modelo = lista[0] || { id: "", nome: "" };
      delete modelo.id;

      const formFields = Object.keys(modelo).map(key => {
        if (secao === "usuarios" && key === "admin") {
          return `
            <label>${key}:<br>
              <select name="${key}" required>
                <option value="true">true</option>
                <option value="false">false</option>
              </select>
            </label><br><br>
          `;
        }
        return `
          <label>${key}:<br><input type="text" name="${key}" required></label><br><br>
        `;
      }).join("");

      const content = document.getElementById("admin-content");
      content.innerHTML = `
        <h3>Novo item em: ${secao}</h3>
        <form id="form-novo-geral">
          ${formFields}
          <button type="submit" class="btn btn-success">Salvar</button>
          <button type="button" class="btn btn-secondary ms-2" onclick="renderPainel('${secao}')">Cancelar</button>
        </form>
      `;

      document.getElementById("form-novo-geral").onsubmit = function (e) {
        e.preventDefault();
        const form = e.target;
        const novo = {};
        for (let input of form.elements) {
          if (input.name) {
            novo[input.name] = input.name === "admin" ? input.value === "true" : input.value;
          }
        }

        fetch(`${base_url}/${secao}`, {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify(novo)
        }).then(() => {
          alert("Item adicionado com sucesso!");
          renderPainel(secao);
        });
      };
    });
};

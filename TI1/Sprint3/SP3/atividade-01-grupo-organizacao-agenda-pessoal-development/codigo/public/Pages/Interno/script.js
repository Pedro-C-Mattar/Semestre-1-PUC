import Tarefas from "../../assets/js/controllers/Tarefas.js"
import Status from "../../assets/js/controllers/Status.js"
import { base_url } from "../../assets/js/globals.js"
import { startFadeAnimation } from "../../assets/js/fadeInAnimation.js"
import { showKanban } from "./kanban.js";
import { showCalendar } from "./calendario.js";
import User from "../../assets/js/controllers/User.js";
import Categorias from "../../assets/js/controllers/Categorias.js";

// Key para salvar status no localStorage
const STATUS_STORAGE_KEY = 'soshi_custom_status';

var displayAtual = "kanban"

// Status iniciais
const defaultStatus = [
    { id: 1, nome: "A fazer" },
    { id: 2, nome: "Em andamento" },
    { id: 3, nome: "Feito" },
    { id: 4, nome: "Finalizado" }
];

function getStatusFromStorage() {
    const stored = localStorage.getItem(STATUS_STORAGE_KEY);
    return stored ? JSON.parse(stored) : defaultStatus;
}

function saveStatusToStorage(statusList) {
    localStorage.setItem(STATUS_STORAGE_KEY, JSON.stringify(statusList));
}

const updateData = async (displayType) => {
    document.getElementById("kanban-view").classList.remove("active");
    document.getElementById("calendar-view").classList.remove("active");
    displayAtual = displayType

    if (displayType == "kanban") {
        await showKanban()
    } else if (displayType == "calendar") {
        showCalendar()
    }
}

document.querySelectorAll(".nav-tab").forEach(el => {
    el.addEventListener("click", ev => {
        ev.preventDefault();
        displayAtual = el.dataset.display
        updateData(displayAtual)
    })
})

const loadCategorias = async () => {

    const response = await Categorias.listAll();

    const categoriaSelect = document.querySelector("#categoriasAddInput");
    const categoriaEditSelect = document.querySelector("#categoriasEditInput");
    if (!categoriaSelect) return;
    if (!categoriaEditSelect) return;

    categoriaSelect.innerHTML = '';
    categoriaEditSelect.innerHTML = '';

    response.data.forEach(categoria => {
        categoriaSelect.innerHTML += `<option value="${categoria.id}">${categoria.nome}</option>`;
        categoriaEditSelect.innerHTML += `<option value="${categoria.id}">${categoria.nome}</option>`;
    });
}

async function loadStatus() {

    const response = await Status.listAll();

    const statusSelect = document.querySelector("#statusAddInput");
    const statusEditSelect = document.querySelector("#statusEditInput");
    if (!statusSelect) return;
    if (!statusEditSelect) return;

    statusSelect.innerHTML = '';
    statusEditSelect.innerHTML = '';

    response.data.forEach(status => {
        statusSelect.innerHTML += `<option value="${status.id}">${status.nome}</option>`;
        statusEditSelect.innerHTML += `<option value="${status.id}">${status.nome}</option>`;
    });
}

async function addNewStatus(nome) {
    try {
        const response = await Status.add({ nome });
        if (response.status === "success") {
            await loadStatus();
            return true;
        }
        throw new Error();
    } catch {
        const statusList = getStatusFromStorage();
        const nextId = statusList.length ? Math.max(...statusList.map(s => s.id)) + 1 : 1;

        statusList.push({ id: nextId, nome });
        saveStatusToStorage(statusList);
        await loadStatus();
        return true;
    }
}

document.addEventListener('DOMContentLoaded', async () => {
    await loadStatus()
    await loadCategorias()

    document.querySelectorAll("[data-action='add-status']").forEach(addStatusBtn => {
        addStatusBtn.addEventListener('click', (event) => {
            const button = event.target.closest('.add-btn');
            const container = button.parentElement;

            button.style.display = 'none';

            const inputContainer = document.createElement('div');
            inputContainer.className = 'temp-status-input';
            inputContainer.innerHTML = `
                <input type="text" placeholder="Digite o nome do status" class="status-name-input">
                <button type="button" class="confirm-status-btn">✓</button>
                <button type="button" class="cancel-status-btn">✕</button>
            `;

            button.insertAdjacentElement('afterend', inputContainer);

            const input = inputContainer.querySelector('input');
            input.focus();

            const handleConfirm = async () => {
                const nome = input.value.trim();
                if (nome && await addNewStatus(nome)) {
                    inputContainer.remove();
                    button.style.display = 'flex';
                }
            };

            inputContainer.querySelector('.confirm-status-btn').onclick = handleConfirm;
            inputContainer.querySelector('.cancel-status-btn').onclick = () => {
                inputContainer.remove();
                button.style.display = 'flex';
            };

            input.onkeypress = (e) => {
                if (e.key === 'Enter') {
                    e.preventDefault();
                    handleConfirm();
                }
            };
        });
    })
});

document.querySelector("#categoriasAddInput").addEventListener("change", (ev) => {
    console.log(ev.target.value);

})
document.querySelector("#dateTimeAddInput").addEventListener("change", (ev) => {
    console.log(ev.target.value);

})

//Zera o conteúdo do textarea da descrição ao carregar a página
const addTaskForm = document.querySelector("#add-tarefa-form")
addTaskForm.descricaoAddInput.value = "";

(async () => {
    await updateData(displayAtual)
})()

//Pega os dados do formulário de adição e envia a requisição pro backend
document.querySelector("#add-tarefa-form").addEventListener('submit', async (ev) => {
    ev.preventDefault()
    const form = ev.target
    let retorno

    try {
        retorno = await Tarefas.add({
            titulo: form.tituloAddInput.value,
            descricao: form.descricaoAddInput.value,
            categorias: Array.from(form.categoriasAddInput.selectedOptions).map(opt => opt.value),
            status: Array.from(form.statusAddInput.selectedOptions).map(opt => opt.value),
            dataHora: form.dateTimeAddInput.value
        });
    } catch (err) {
        console.log(err);
        retorno.msg = "Erro interno ao cadastrar. Por favor tente novamente mais tarde!"
        retorno.status = "error"
    }

    updateData(displayAtual)
    closeAddModal()
    form.reset()

    Toastify({
        text: retorno.msg,
        duration: 4000,
        newWindow: true,
        close: true,
        gravity: "top", // `top` or `bottom`
        position: "right", // `left`, `center` or `right`
        stopOnFocus: true, // Prevents dismissing of toast on hover
        style: {
            background: retorno.status == "error" ? "red" : "green",
            color: "white"
        }
    }).showToast();

})

document.querySelector(".delete-form-submit").addEventListener("click", () => {
    const confirm = window.confirm("Tem certeza que deseja excluir tarefa?")
    console.log(confirm);

    if (!confirm) return
    Tarefas.delete(document.querySelector("#edit-tarefa-form").dataset.idItem)
})

//Pega os dados do formulário de edição e envia a requisição pro backend
document.querySelector("#edit-tarefa-form").addEventListener('submit', async (ev) => {
    ev.preventDefault()
    const form = ev.target
    let retorno

    try {
        retorno = await Tarefas.edit(form.dataset.idItem, {
            titulo: form.tituloEditInput.value,
            descricao: form.descricaoEditInput.value,
            categorias: Array.from(form.categoriasEditInput.selectedOptions).map(opt => opt.value),
            status: form.statusEditInput.selectedOptions[0].value,
            dataHora: form.dateTimeEditInput.value
        });
    } catch (err) {
        console.log(err);
        retorno.msg = "Erro interno ao cadastrar. Por favor tente novamente mais tarde!"
        retorno.status = "error"
    }

    updateData(displayAtual)
    closeEditModal()
    form.reset()

    Toastify({
        text: retorno.msg,
        duration: 4000,
        newWindow: true,
        close: true,
        gravity: "top", // `top` or `bottom`
        position: "right", // `left`, `center` or `right`
        stopOnFocus: true, // Prevents dismissing of toast on hover
        style: {
            background: retorno.status == "error" ? "red" : "green",
            color: "white"
        }
    }).showToast();

})

//Abre menu lateral
document.querySelector("#open-navigation-btn").addEventListener("click", () => {
    document.querySelector("aside").classList.toggle("closed")
})

//Expande opções do menu
document.querySelectorAll(".pages-title").forEach((el) => {
    el.addEventListener("click", (ev) => {
        ev.target.parentNode.querySelector(".aside-nav-ul").classList.toggle("closed")
    })
})

//Abre modal de adição
document.querySelectorAll(".add-task-btn").forEach(ele => {
    ele.addEventListener("click", (ev) => {
        document.querySelector(".add-task-modal-container").classList.remove("closed")
        // Recarrega os status quando o modal é aberto
        loadStatus();
    })
})

//Fecha modal de adição
const closeAddModal = () => {
    document.querySelector(".add-task-modal-container").classList.add("closed")
}

document.querySelector(".add-task-modal-container .add-task-modal .close-btn").addEventListener("click", () => closeAddModal())
document.querySelector(".add-task-modal-container .add-task-modal-bg").addEventListener("click", () => closeAddModal())

//Fecha modal de edição
const closeEditModal = () => {
    document.querySelector(".edit-task-modal-container").classList.add("closed")
}

document.querySelector(".edit-task-modal-container .edit-task-modal .close-btn").addEventListener("click", () => closeEditModal())
document.querySelector(".edit-task-modal-container .edit-task-modal-bg").addEventListener("click", () => closeEditModal())


document.querySelectorAll(".kanban-content .tarefa-container .buttons-container .edit-btn")



async function atualizarLinkCategoria() {
    const link = document.getElementById("linkCategoria");
    link.href = `../Categoria/`;
}

document.querySelectorAll(".search-input").forEach(el => {
    el.addEventListener("input", async (ev) => {
        let data = await Tarefas.search(ev.target.value)

        console.log(data);
        if (data.status == "error") return
        data = data.data

        console.log(ev.target.parentNode);
        const searchContent = ev.target.parentNode.querySelector(".search-content")
        searchContent.classList.remove("hidden")
        searchContent.innerHTML = ""
        data.forEach(ele => {
            searchContent.innerHTML += `
                <div class="item" data-item-id="${ele.id}">${ele.titulo}</div>
            `
        })
        let eve1
        document.querySelectorAll(".search-content .item").forEach(ele => {
            ele.addEventListener("click", async (eve) => {

                const itemId = eve.target.dataset.itemId;
                console.log(eve.target);

                const data = await Tarefas.getById(itemId);

                const form = document.querySelector("#edit-tarefa-form");
                form.reset();
                form.dataset.idItem = `${itemId}`;
                form.tituloEditInput.value = data.titulo;
                form.descricaoEditInput.value = data.descricao;
                form.statusEditInput.querySelectorAll("option").forEach(elem => {
                    if (elem.value == data.status[0]) {
                        elem.selected = true;
                    }
                });
                form.categoriasEditInput.querySelectorAll("option").forEach(elem => {
                    data.categorias.forEach(categoriaId => {
                        if (elem.value == categoriaId) {
                            elem.selected = true;
                        }
                    });
                });
                form.dateTimeEditInput.value = data.dataHora;
                document.querySelector(".edit-task-modal-container").classList.remove("closed");
            })
        })

    })
    el.addEventListener("blur", ev => {
        setTimeout(() => {
            const searchContent = ev.target.parentNode.querySelector(".search-content")
            searchContent.innerHTML = ""
            searchContent.classList.add("hidden")
        }, 400)
    })
})

document.addEventListener("DOMContentLoaded", atualizarLinkCategoria);
import Tarefas from "../../assets/js/controllers/Tarefas.js"
import Status from "../../assets/js/controllers/Status.js"
import { base_url } from "../../assets/js/globals.js"
import { startFadeAnimation } from "../../assets/js/fadeInAnimation.js"
import { showKanban } from "./kanban.js";

// Key para salvar status no localStorage
const STATUS_STORAGE_KEY = 'soshi_custom_status';

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

async function loadStatus() {
    let statusData = [];
    
    try {
        const response = await Status.listAll();
        statusData = response.data?.length ? response.data : getStatusFromStorage();
    } catch {
        statusData = getStatusFromStorage();
    }

    const statusSelect = document.querySelector("#statusAddInput");
    if (!statusSelect) return;
    
    statusSelect.innerHTML = '';
    
    if (!statusData?.length) {
        statusData = defaultStatus;
        saveStatusToStorage(statusData);
    }
    
    statusData.forEach(status => {
        statusSelect.innerHTML += `<option value="${status.id}">${status.nome}</option>`;
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

document.addEventListener('DOMContentLoaded', () => {
    setTimeout(loadStatus, 100);
    
    const addStatusBtn = document.querySelector("[data-action='add-status']");
    if (!addStatusBtn) return;
    
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

showKanban()

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

    showKanban()
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
            status: form.statusEditInput.selectedOptions[0],
            dataHora: form.dateTimeEditInput.value
        });
    } catch (err) {
        console.log(err);
        retorno.msg = "Erro interno ao cadastrar. Por favor tente novamente mais tarde!"
        retorno.status = "error"
    }

    showKanban()
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
document.querySelector("#add-task-btn").addEventListener("click", (ev) => {
    document.querySelector(".add-task-modal-container").classList.remove("closed")
    
    // Recarrega os status quando o modal é aberto
    loadStatus();
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


//Lista as tarefas em formato simples de lista (provisório)
// const updateData = async () => {
//     const tarefas = (await Tarefas.listAll()).data
//     console.log(tarefas);

//     document.querySelector(".kanban-content").innerHTML = ""

//     tarefas.forEach((el) => {
//         document.querySelector(".kanban-content").innerHTML += `
//             <div class="tarefa-container">
//                 <div class="info-container">
//                     ${el.titulo}
//                 </div>
//                 <div class="buttons-container">
//                     <div class="edit-btn" data-id-item="${el.id}">Editar</div>
//                     <div class="delete-btn" data-id-item="${el.id}">Excluir</div>
//                 </div>
//             </div>
//         `
//     })

//     document.querySelectorAll(".kanban-content .tarefa-container .buttons-container .edit-btn").forEach(el => {
//         el.addEventListener("click", async ev => {
//             const itemId = ev.target.dataset.idItem
//             const data = await Tarefas.getById(itemId);

//             document.querySelector("#edit-tarefa-form").dataset.idItem = `${itemId}`

//             const form = document.querySelector("#edit-tarefa-form")
//             form.tituloEditInput.value = data.titulo
//             form.descricaoEditInput.value = data.descricao
//             form.statusEditInput.value = data.status[0]
//             form.categoriasEditInput.querySelectorAll("option").forEach(ele => {
//                 data.categorias.forEach(categoriaId => {
//                     if(ele.value == categoriaId) {
//                         ele.selected = true
//                     }
//                 })
//             })
//             form.dateTimeEditInput.value = data.dataHora

//             document.querySelector(".edit-task-modal-container").classList.remove("closed")
//         })
//     })

//     document.querySelectorAll(".kanban-content .tarefa-container .buttons-container .delete-btn").forEach(el => {
//         el.addEventListener("click", async (ev) => {
//             const btn = ev.target
//             const id = btn.dataset.idItem
//             let retorno

//             try {
//                 retorno = await Tarefas.delete(id);
//             } catch (err) {
//                 retorno.status = "error"
//                 retorno.msg = "Erro interno ao excluir, por favor tente mais tarde!"
//             }

//             Toastify({
//                 text: retorno.msg,
//                 duration: 4000,
//                 newWindow: true,
//                 close: true,
//                 gravity: "top", // `top` or `bottom`
//                 position: "right", // `left`, `center` or `right`
//                 stopOnFocus: true, // Prevents dismissing of toast on hover
//                 style: {
//                     background: retorno.status == "error" ? "red" : "green",
//                     color: "white"
//                 }
//             }).showToast();

//             updateData();

//         })
//     })
// }

// await updateData()


document.querySelectorAll(".kanban-content .tarefa-container .buttons-container .edit-btn")
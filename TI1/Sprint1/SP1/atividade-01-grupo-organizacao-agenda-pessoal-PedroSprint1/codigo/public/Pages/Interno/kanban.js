import Status from "../../assets/js/controllers/Status.js";
import Tarefas from "../../assets/js/controllers/Tarefas.js";

export const showKanban = async () => {

    const mainElement = document.querySelector("main");

    mainElement.innerHTML = `
        <div class="kanban">
            <div class="kanban-options">
                <div></div>
                <div id="add-task-btn">Adicionar tarefa</div>
            </div>
            <div class="kanban-content">
                
            </div>
        </div>
    `

    let status

    status = await Status.listAll();

    if (status.status == "success") {
        const kanbanContent = document.querySelector("main .kanban-content")
        kanbanContent.innerHTML = ``
        status.data.forEach(async el => {
            kanbanContent.innerHTML += `
                <div class="status-container">
                    <div class="status-header">
                        ${el.nome}
                    </div>
                    <div class="status-body" data-id-status="${el.id}">
                    
                    </div>
                </div>
            `

            const statusBody = document.querySelector(`main .status-body[data-id-status="${el.id}"]`)

            const tasks = await Tarefas.getByStatus()

            tasks.data.forEach(ele => {
                statusBody.innerHTML += `
                    <div class="task-container" data-id-task="${ele.id}">
                        ${ele.titulo}
                    </div>
                `
            })
            

            document.querySelectorAll(".kanban .kanban-content .status-container .status-body .task-container").forEach(elem => {
                elem.addEventListener("click", async ev => {
                    const taskId = ev.target.dataset.idTask
                    console.log(taskId);
                    
                    const data = await Tarefas.getById(taskId);

                    const form = document.querySelector("#edit-tarefa-form")

                    form.reset()
                    form.dataset.idItem = `${taskId}`

                    form.tituloEditInput.value = data.titulo
                    form.descricaoEditInput.value = data.descricao
                    form.statusEditInput.value = data.status[0]
                    form.categoriasEditInput.querySelectorAll("option").forEach(ele => {
                        data.categorias.forEach(categoriaId => {
                            if (ele.value == categoriaId) {
                                ele.selected = true
                            }
                        })
                    })
                    form.dateTimeEditInput.value = data.dataHora

                    document.querySelector(".edit-task-modal-container").classList.remove("closed")
                })
            })

            console.log(status);

        })


    } else {

    }

}
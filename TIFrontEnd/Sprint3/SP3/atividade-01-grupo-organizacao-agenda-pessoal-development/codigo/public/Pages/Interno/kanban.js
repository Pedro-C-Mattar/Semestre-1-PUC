import Status from "../../assets/js/controllers/Status.js";
import Tarefas from "../../assets/js/controllers/Tarefas.js";

export const showKanban = async () => {
    document.getElementById("calendar-view").classList.remove("active");
    document.getElementById("kanban-view").classList.add("active");

    const status = await Status.listAll();


    if (status.status == "success") {
        const kanbanContent = document.querySelector(".kanban-content");
        kanbanContent.innerHTML = '';

        for (const el of status.data) {
            const containerHTML = `
        <div class="status-container">
            <div class="status-header">${el.nome}</div>
            <div class="status-body" data-id-status="${el.id}"></div>
        </div>
    `;
            kanbanContent.insertAdjacentHTML('beforeend', containerHTML);

            const statusBody = document.querySelector(`.status-body[data-id-status="${el.id}"]`);
            const tasks = await Tarefas.getByStatus(el.id);

            tasks.data.forEach(task => {
                const taskHTML = `<div class="task-container" data-id-task="${task.id}">${task.titulo}</div>`;
                statusBody.insertAdjacentHTML('beforeend', taskHTML);
            });
        }

        document.querySelectorAll(".task-container").forEach(elem => {
            elem.addEventListener("click", async ev => {
                const taskId = ev.target.dataset.idTask;
                const data = await Tarefas.getById(taskId);

                const form = document.querySelector("#edit-tarefa-form");
                form.reset();
                form.dataset.idItem = `${taskId}`;
                form.tituloEditInput.value = data.titulo;
                form.descricaoEditInput.value = data.descricao;
                form.statusEditInput.value = data.status[0];
                form.categoriasEditInput.querySelectorAll("option").forEach(ele => {
                    data.categorias.forEach(categoriaId => {
                        if (ele.value == categoriaId) {
                            ele.selected = true;
                        }
                    });
                });
                form.dateTimeEditInput.value = data.dataHora;
                document.querySelector(".edit-task-modal-container").classList.remove("closed");
            });
        });


    } else {

    }

}
import Tarefas from "../../assets/js/controllers/Tarefas.js";
import Status from "../../assets/js/controllers/Status.js";
import { base_url } from "../../assets/js/globals.js";
import { startFadeAnimation } from "../../assets/js/fadeInAnimation.js"

let calendar;
let currentTask = null;
let statusList = [];

let currentDate = new Date();
let events = [
    {
        date: '2025-01-15',
        title: 'Reunião de Trabalho',
        category: 'work'
    },
    {
        date: '2025-01-18',
        title: 'Consulta Médica',
        category: 'personal'
    },
    {
        date: '2025-01-20',
        title: 'Estudar JavaScript',
        category: 'study'
    },
    {
        date: '2025-01-22',
        title: 'Projeto Soshi',
        category: 'project'
    }
];

const monthNames = [
    'Janeiro', 'Fevereiro', 'Março', 'Abril', 'Maio', 'Junho',
    'Julho', 'Agosto', 'Setembro', 'Outubro', 'Novembro', 'Dezembro'
];

const defaultStatus = [
    { id: 1, nome: "A fazer" },
    { id: 2, nome: "Em andamento" },
    { id: 3, nome: "Feito" },
    { id: 4, nome: "Finalizado" }
];

const statusColors = {
    1: '#ffc107', // Amarelo 
    2: '#17a2b8', // Azul  
    3: '#28a745', // Verde 
    4: '#6c757d'  // Cinza 
};

let currentMonth = new Date().getMonth();
let currentYear = new Date().getFullYear();
let tasks = []; // Armazenar as tarefas

document.addEventListener('DOMContentLoaded', async function() {
    console.log('Página carregada - Calendário integrado!');
    
    if (typeof FullCalendar !== 'undefined') {
        await initializeCalendar();
    }
    
    await loadStatus();
    setupEventListeners();
});

export function showCalendar() {
    document.getElementById("kanban-view").classList.remove("active")
    document.getElementById("calendar-view").classList.add("active")
    generateCalendar(currentMonth, currentYear)
    loadTasks()
}

function generateCalendar(month, year) {
    const calendarElement = document.getElementById("calendar");
}

function showList() {
    const kanbanView = document.getElementById('kanban-view');
    const calendarView = document.getElementById('calendar-view');
    const listView = document.getElementById('list-view');
    const kanbanTab = document.getElementById('kanban-tab');
    const calendarTab = document.getElementById('calendar-tab');
    const listTab = document.getElementById('list-tab');
    
    if (kanbanView && calendarView && kanbanTab && calendarTab && listTab) {
        kanbanView.classList.remove('active');
        calendarView.classList.remove('active');
        if (listView) listView.classList.add('active');
        kanbanTab.classList.remove('active');
        calendarTab.classList.remove('active');
        listTab.classList.add('active');
    }
}

// Funções do calendário integrado
function renderCalendar() {
    const calendar = document.getElementById('calendar');
    const monthYear = document.getElementById('monthYear');
    
    if (!calendar || !monthYear) return;
    
    // Limpar calendário (manter cabeçalhos)
    while (calendar.children.length > 7) {
        calendar.removeChild(calendar.lastChild);
    }
    
    // Atualizar título
    monthYear.textContent = `${monthNames[currentDate.getMonth()]} ${currentDate.getFullYear()}`;
    
    // Primeiro dia do mês
    const firstDay = new Date(currentDate.getFullYear(), currentDate.getMonth(), 1);
    const lastDay = new Date(currentDate.getFullYear(), currentDate.getMonth() + 1, 0);
    
    // Dias do mês anterior para completar a primeira semana
    const startDate = new Date(firstDay);
    startDate.setDate(startDate.getDate() - firstDay.getDay());
    
    // Renderizar 42 dias (6 semanas)
    for (let i = 0; i < 42; i++) {
        const cellDate = new Date(startDate);
        cellDate.setDate(startDate.getDate() + i);
        
        const dayCell = document.createElement('div');
        dayCell.className = 'day-cell';
        
        // Verificar se é do mês atual
        if (cellDate.getMonth() !== currentDate.getMonth()) {
            dayCell.classList.add('other-month');
        }
        
        // Verificar se é hoje
        const today = new Date();
        if (cellDate.toDateString() === today.toDateString()) {
            dayCell.classList.add('today');
        }
        
        // Número do dia
        const dayNumber = document.createElement('div');
        dayNumber.className = 'day-number';
        dayNumber.textContent = cellDate.getDate();
        dayCell.appendChild(dayNumber);
        
        // Eventos do dia
        const dateStr = cellDate.toISOString().split('T')[0];
        const dayEvents = events.filter(event => event.date === dateStr);
        
        dayEvents.forEach(event => {
            const eventDiv = document.createElement('div');
            eventDiv.className = `event ${event.category}`;
            eventDiv.textContent = event.title;
            dayCell.appendChild(eventDiv);
        });
        
        calendar.appendChild(dayCell);
    }
}

function previousMonth() {
    currentDate.setMonth(currentDate.getMonth() - 1);
    renderCalendar();
}

function nextMonth() {
    currentDate.setMonth(currentDate.getMonth() + 1);
    renderCalendar();
}

// Inicializar o calendário FullCalendar
export async function initializeCalendar() {
    const calendarEl = document.getElementById('calendar');
    
    if (!calendarEl) return;
    
    calendar = new FullCalendar.Calendar(calendarEl, {
        locale: 'pt-br',
        initialView: 'dayGridMonth',
        headerToolbar: {
            left: 'prev,next today',
            center: 'title',
            right: 'dayGridMonth,timeGridWeek,timeGridDay'
        },
        buttonText: {
            today: 'Hoje',
            month: 'Mês',
            week: 'Semana',
            day: 'Dia'
        },
        height: 'auto',
        editable: true,
        selectable: true,
        selectMirror: true,
        dayMaxEvents: true,
        weekends: true,
        
        // Eventos do calendário
        select: function(info) {
            openTaskModal(null, info.startStr);
        },
        
        eventClick: function(info) {
            showTaskDetails(info.event.extendedProps.taskData);
        },
        
        eventDrop: function(info) {
            updateTaskDate(info.event.extendedProps.taskData, info.event.startStr);
        },
        
        eventResize: function(info) {
            updateTaskDate(info.event.extendedProps.taskData, info.event.startStr);
        }
    });
    
    calendar.render();
    await loadTasks();
}

// Carregar tarefas da API
async function loadTasks() {
    try {
        const response = await Tarefas.listAll();
        const tasks = response.data || [];
        
        // Atualizar eventos do calendário integrado
        events = tasks.map(task => ({
            date: task.dataHora ? task.dataHora.split('T')[0] : new Date().toISOString().split('T')[0],
            title: task.titulo,
            category: getStatusName(getStatusId(task.status)).toLowerCase().replace(' ', '')
        }));
        
        // Se FullCalendar estiver disponível
        if (calendar) {
            // Limpar eventos existentes
            calendar.removeAllEvents();
            
            // Adicionar tarefas como eventos
            tasks.forEach(task => {
                const event = {
                    id: task.id,
                    title: task.titulo,
                    start: task.dataHora,
                    backgroundColor: getStatusColor(task.status),
                    borderColor: getStatusColor(task.status),
                    className: `status-${getStatusId(task.status)}`,
                    extendedProps: {
                        taskData: task
                    }
                };
                
                calendar.addEvent(event);
            });
        } else {
            // Renderizar calendário simples
            renderCalendar();
        }
        
    } catch (error) {
        console.error('Erro ao carregar tarefas:', error);
        showToast('Erro ao carregar tarefas', 'error');
    }
}

// Carregar status da API
async function loadStatus() {
    try {
        const response = await Status.listAll();
        statusList = response.data?.length ? response.data : defaultStatus;
    } catch (error) {
        console.error('Erro ao carregar status:', error);
        statusList = defaultStatus;
    }
    
    updateStatusSelect();
}

// Atualizar select de status
function updateStatusSelect() {
    const statusSelect = document.getElementById('status');
    statusSelect.innerHTML = '<option value="">Selecione um status</option>';
    
    statusList.forEach(status => {
        const option = document.createElement('option');
        option.value = status.id;
        option.textContent = status.nome;
        statusSelect.appendChild(option);
    });
}

// Obter cor do status
function getStatusColor(status) {
    const statusId = getStatusId(status);
    return statusColors[statusId] || '#6c757d';
}

// Obter ID do status (compatibilidade com diferentes formatos)
function getStatusId(status) {
    if (Array.isArray(status)) {
        return status[0] || 1;
    }
    return status || 1;
}

// Obter nome do status
function getStatusName(statusId) {
    const status = statusList.find(s => s.id == statusId);
    return status ? status.nome : 'Desconhecido';
}

// Configurar event listeners
function setupEventListeners() {
    // Menu lateral
    const openNavBtn = document.getElementById('open-navigation-btn');
    if (openNavBtn) {
        openNavBtn.addEventListener('click', () => {
            const aside = document.querySelector('aside');
            if (aside) aside.classList.toggle('closed');
        });
    }
    
    // Expandir opções do menu
    document.querySelectorAll('.pages-title').forEach(el => {
        el.addEventListener('click', (ev) => {
            const navUl = ev.target.parentNode.querySelector('.aside-nav-ul');
            if (navUl) navUl.classList.toggle('closed');
        });
    });
    
    // Botões de visualização FullCalendar
    const monthViewBtn = document.getElementById('month-view');
    const weekViewBtn = document.getElementById('week-view');
    const dayViewBtn = document.getElementById('day-view');
    
    if (monthViewBtn) {
        monthViewBtn.addEventListener('click', () => {
            if (calendar) calendar.changeView('dayGridMonth');
            updateActiveViewButton('month-view');
        });
    }
    
    if (weekViewBtn) {
        weekViewBtn.addEventListener('click', () => {
            if (calendar) calendar.changeView('timeGridWeek');
            updateActiveViewButton('week-view');
        });
    }
    
    if (dayViewBtn) {
        dayViewBtn.addEventListener('click', () => {
            if (calendar) calendar.changeView('timeGridDay');
            updateActiveViewButton('day-view');
        });
    }
    
    // Botão adicionar tarefa
    const addTaskBtn = document.getElementById('add-task-btn');
    if (addTaskBtn) {
        addTaskBtn.addEventListener('click', () => {
            openTaskModal();
        });
    }
    
    // Modal de adicionar tarefa
    const addTaskModalClose = document.querySelector('.add-task-modal-container .close-btn');
    const addTaskModalBg = document.querySelector('.add-task-modal-bg');
    
    if (addTaskModalClose) addTaskModalClose.addEventListener('click', closeTaskModal);
    if (addTaskModalBg) addTaskModalBg.addEventListener('click', closeTaskModal);
    
    // Modal de editar tarefa
    const editTaskModalClose = document.querySelector('.edit-task-modal-container .close-btn');
    const editTaskModalBg = document.querySelector('.edit-task-modal-bg');
    
    if (editTaskModalClose) editTaskModalClose.addEventListener('click', closeEditTaskModal);
    if (editTaskModalBg) editTaskModalBg.addEventListener('click', closeEditTaskModal);
    
    // Formulários
    const addTaskForm = document.getElementById('add-tarefa-form');
    const editTaskForm = document.getElementById('edit-tarefa-form');
    
    if (addTaskForm) {
        addTaskForm.addEventListener('submit', handleTaskSubmit);
    }
    
    if (editTaskForm) {
        editTaskForm.addEventListener('submit', handleEditTaskSubmit);
    }
    
    // Modal de detalhes (se existir)
    const detailModalClose = document.querySelector('.task-detail-modal-container .close-btn');
    const detailModalBackdrop = document.querySelector('.task-detail-modal-container .modal-backdrop');
    
    if (detailModalClose) detailModalClose.addEventListener('click', closeTaskDetailModal);
    if (detailModalBackdrop) detailModalBackdrop.addEventListener('click', closeTaskDetailModal);
    
    // Botões do modal de detalhes (se existirem)
    const editTaskBtn = document.getElementById('edit-task-btn');
    const deleteTaskBtn = document.getElementById('delete-task-btn');
    
    if (editTaskBtn) {
        editTaskBtn.addEventListener('click', () => {
            closeTaskDetailModal();
            openTaskModal(currentTask);
        });
    }
    
    if (deleteTaskBtn) {
        deleteTaskBtn.addEventListener('click', handleDeleteTask);
    }
    
    // Navegação do calendário integrado
    const prevBtn = document.querySelector('[onclick="previousMonth()"]');
    const nextBtn = document.querySelector('[onclick="nextMonth()"]');
    
    if (prevBtn) prevBtn.addEventListener('click', previousMonth);
    if (nextBtn) nextBtn.addEventListener('click', nextMonth);
}

// Atualizar botão de visualização ativo
function updateActiveViewButton(activeId) {
    document.querySelectorAll('.view-btn').forEach(btn => {
        btn.classList.remove('active');
    });
    document.getElementById(activeId).classList.add('active');
}

// Abrir modal de tarefa
function openTaskModal(task = null, selectedDate = null) {
    currentTask = task;
    const modal = document.querySelector('.add-task-modal-container');
    
    if (!modal) {
        console.error('Modal de adicionar tarefa não encontrado');
        return;
    }
    
    // Resetar formulário
    const form = document.getElementById('add-tarefa-form');
    if (form) form.reset();
    
    // Preencher campos se for edição
    if (task) {
        document.getElementById('tituloAddInput').value = task.titulo || '';
        document.getElementById('descricaoAddInput').value = task.descricao || '';
        document.getElementById('dateTimeAddInput').value = formatDateTimeForInput(task.dataHora);
        
        // Selecionar status
        const statusSelect = document.getElementById('statusAddInput');
        if (statusSelect) {
            statusSelect.value = getStatusId(task.status);
        }
        
        // Selecionar categorias
        if (task.categorias && Array.isArray(task.categorias)) {
            const categoriasSelect = document.getElementById('categoriasAddInput');
            if (categoriasSelect) {
                Array.from(categoriasSelect.options).forEach(option => {
                    option.selected = task.categorias.includes(option.value);
                });
            }
        }
    } else {
        // Se uma data foi selecionada, usar ela
        if (selectedDate) {
            const dateInput = document.getElementById('dateTimeAddInput');
            if (dateInput) dateInput.value = selectedDate;
        }
    }
    
    modal.classList.remove('closed');
}

// Fechar modal de tarefa
function closeTaskModal() {
    const modal = document.querySelector('.add-task-modal-container');
    if (modal) modal.classList.add('closed');
    currentTask = null;
}

// Fechar modal de editar tarefa
function closeEditTaskModal() {
    const modal = document.querySelector('.edit-task-modal-container');
    if (modal) modal.classList.add('closed');
    currentTask = null;
}

// Mostrar detalhes da tarefa
function showTaskDetails(task) {
    currentTask = task;
    
    document.getElementById('detail-titulo').textContent = task.titulo || '';
    document.getElementById('detail-descricao').textContent = task.descricao || '';
    document.getElementById('detail-dataHora').textContent = formatDateTime(task.dataHora);
    document.getElementById('detail-status').textContent = getStatusName(getStatusId(task.status));
    
    // Mostrar categorias
    let categoriasText = 'Nenhuma';
    if (task.categorias && Array.isArray(task.categorias) && task.categorias.length > 0) {
        const categoriasSelect = document.getElementById('categorias');
        const categoriasNomes = task.categorias.map(catId => {
            const option = Array.from(categoriasSelect.options).find(opt => opt.value === catId);
            return option ? option.textContent : catId;
        });
        categoriasText = categoriasNomes.join(', ');
    }
    document.getElementById('detail-categorias').textContent = categoriasText;
    
    document.querySelector('.task-detail-modal-container').classList.remove('closed');
}

// Fechar modal de detalhes
function closeTaskDetailModal() {
    document.querySelector('.task-detail-modal-container').classList.add('closed');
    currentTask = null;
}

// Manipular envio do formulário
async function handleTaskSubmit(event) {
    event.preventDefault();
    
    const formData = new FormData(event.target);
    const taskData = {
        titulo: document.getElementById('tituloAddInput').value,
        descricao: document.getElementById('descricaoAddInput').value,
        dataHora: document.getElementById('dateTimeAddInput').value,
        status: [document.getElementById('statusAddInput').value],
        categorias: Array.from(document.getElementById('categoriasAddInput').selectedOptions).map(opt => opt.value)
    };
    
    try {
        let response;
        
        if (currentTask) {
            // Atualizar tarefa existente
            response = await Tarefas.edit(currentTask.id, taskData);
        } else {
            // Criar nova tarefa
            response = await Tarefas.add(taskData);
        }
        
        if (response.status === 'success' || response.data) {
            showToast(currentTask ? 'Tarefa atualizada com sucesso!' : 'Tarefa criada com sucesso!', 'success');
            closeTaskModal();
            await loadTasks();
        } else {
            showToast(response.msg || 'Erro ao salvar tarefa', 'error');
        }
        
    } catch (error) {
        console.error('Erro ao salvar tarefa:', error);
        showToast('Erro interno ao salvar tarefa', 'error');
    }
}

// Manipular envio do formulário de editar tarefa
async function handleEditTaskSubmit(event) {
    event.preventDefault();
    
    const taskData = {
        titulo: document.getElementById('tituloEditInput').value,
        descricao: document.getElementById('descricaoEditInput').value,
        dataHora: document.getElementById('dateTimeEditInput').value,
        categorias: Array.from(document.getElementById('categoriasEditInput').selectedOptions).map(opt => opt.value)
    };
    
    try {
        if (currentTask) {
            const response = await Tarefas.edit(currentTask.id, taskData);
            
            if (response.status === 'success' || response.data) {
                showToast('Tarefa atualizada com sucesso!', 'success');
                closeEditTaskModal();
                await loadTasks();
            } else {
                showToast(response.msg || 'Erro ao atualizar tarefa', 'error');
            }
        }
        
    } catch (error) {
        console.error('Erro ao atualizar tarefa:', error);
        showToast('Erro interno ao atualizar tarefa', 'error');
    }
}

// Manipular exclusão de tarefa
async function handleDeleteTask() {
    if (!currentTask) return;
    
    if (confirm('Tem certeza que deseja excluir esta tarefa?')) {
        try {
            await Tarefas.delete(currentTask.id);
            showToast('Tarefa excluída com sucesso!', 'success');
            closeTaskDetailModal();
            await loadTasks();
        } catch (error) {
            console.error('Erro ao excluir tarefa:', error);
            showToast('Erro ao excluir tarefa', 'error');
        }
    }
}

// Atualizar data da tarefa (drag & drop)
async function updateTaskDate(task, newDate) {
    try {
        const updatedTask = {
            ...task,
            dataHora: newDate
        };
        
        await Tarefas.edit(task.id, updatedTask);
        showToast('Data da tarefa atualizada!', 'success');
        
    } catch (error) {
        console.error('Erro ao atualizar data:', error);
        showToast('Erro ao atualizar data da tarefa', 'error');
        // Recarregar tarefas para reverter a mudança visual
        await loadTasks();
    }
}

// Utilitários de formatação
function formatDateTime(dateTimeString) {
    if (!dateTimeString) return '';
    
    const date = new Date(dateTimeString);
    return date.toLocaleString('pt-BR', {
        day: '2-digit',
        month: '2-digit',
        year: 'numeric',
        hour: '2-digit',
        minute: '2-digit'
    });
}

function formatDateTimeForInput(dateTimeString) {
    if (!dateTimeString) return '';
    
    const date = new Date(dateTimeString);
    const year = date.getFullYear();
    const month = String(date.getMonth() + 1).padStart(2, '0');
    const day = String(date.getDate()).padStart(2, '0');
    const hours = String(date.getHours()).padStart(2, '0');
    const minutes = String(date.getMinutes()).padStart(2, '0');
    
    return `${year}-${month}-${day}T${hours}:${minutes}`;
}

// Mostrar toast de notificação
function showToast(message, type = 'info') {
    if (typeof Toastify !== 'undefined') {
        Toastify({
            text: message,
            duration: 4000,
            newWindow: true,
            close: true,
            gravity: "top",
            position: "right",
            stopOnFocus: true,
            style: {
                background: type === 'error' ? '#dc3545' : type === 'success' ? '#28a745' : '#17a2b8',
                color: "white"
            }
        }).showToast();
    } else {
        alert(message);
    }
}

// Expor funções globalmente para compatibilidade
window.showCalendar = showCalendar;
window.showList = showList;
window.previousMonth = previousMonth;
window.nextMonth = nextMonth; 
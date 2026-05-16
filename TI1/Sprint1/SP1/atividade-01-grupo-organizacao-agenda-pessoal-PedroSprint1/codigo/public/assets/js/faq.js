fetch('/faq')
    .then(res => res.json())
    .then(faqs => {
        const container = document.getElementById('faq-container');
        faqs.forEach((item, index) => {
            const bloco = document.createElement('div');
            bloco.classList.add('faq-item');
            bloco.innerHTML = `
            <div class="faq-pergunta" onclick="toggleFaq(${index})">
              <i class="bi bi-chevron-down icon" id="icon-${index}"></i>
              <h4>${item.pergunta}</h4>
            </div>
            <div class="faq-resposta" id="resposta-${index}">
              <p>${item.resposta}</p>
            </div>
          `;
            container.appendChild(bloco);
        });
    });

function toggleFaq(index) {
    const resposta = document.getElementById(`resposta-${index}`);
    const icon = document.getElementById(`icon-${index}`);
    resposta.classList.toggle('ativo');
    icon.classList.toggle('rotacionado');
}

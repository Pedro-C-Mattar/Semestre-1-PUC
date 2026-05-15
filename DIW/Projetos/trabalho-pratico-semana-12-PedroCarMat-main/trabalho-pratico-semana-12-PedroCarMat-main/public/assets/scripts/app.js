let dados = [];

async function carregarDadosDoJSON() {
    try {
        const response = await fetch('http://localhost:3000/dados');
        if (!response.ok) {
            throw new Error(`Erro HTTP: ${response.status}`);
        }
        const db = await response.json();
        console.log('Dados recebidos:', db); 
        dados = db.dados || db; 
        return dados;
    } catch (error) {
        console.error('Erro ao carregar dados:', error);
        return [];
    }
}

async function carregarDados() {

    await carregarDadosDoJSON();
    
    const destaquesMundo = document.getElementById('Mundo');
    for (let i = 0; i < dados.length; i++) {
        const lugar = dados[i];
        
        const destaque = document.createElement("a");
        destaque.className = `destaqueM`;
        destaque.href = `detalhes.html?id=${lugar.id}`;
        destaque.style.backgroundImage = `url('${lugar.imagem_lugar}')`;
      
        const article = document.createElement("article");
        const span = document.createElement("span");
        span.className = "nomeLugar";
        span.textContent = lugar.nome;
      
        article.appendChild(span);
        destaque.appendChild(article);
        destaquesMundo.appendChild(destaque);
    }
    
}

async function carregarDetalhes() {

    await carregarDadosDoJSON();
    
    const params = new URLSearchParams(location.search);
    const id = params.get('id');
    
    const lugar = dados.find(elem => elem.id == id);
    
    if (lugar) {
        const secDetalhes = document.getElementById('Detalhes');
        
        secDetalhes.innerHTML = `
        <span class="tituloDetalhes">${lugar.nome}</span>
        <div class="divDetalhes">
            <img src="${lugar.imagem_lugar}" width="400px" alt="${lugar.nome}">
        </div>
        <span class="tituloDetalhes">Detalhes</span>
        <div class="divDetalhes">
            <ul>
                <li>Localização: ${lugar.localizacao}</li>
                <li>Continente: ${lugar.continente}</li>
                <li>Idioma: ${lugar.idioma}</li>
                <li>Moeda: ${lugar.moeda}</li>
                <li>Categoria: ${lugar.categoria}</li>
                <li>Atrações: ${lugar.principais_atracoes}</li>
            </ul>
        </div>
        <span class="tituloDetalhes">Imagens</span>
        <div class="divDetalhes">
            <img src="${lugar.imagem_complementar1}" width="200px" height="200px" alt="Atração 1">
            <img src="${lugar.imagem_complementar2}" width="200px" height="200px" alt="Atração 2">
            <img src="${lugar.imagem_complementar3}" width="200px" height="200px" alt="Atração 3">
            <img src="${lugar.imagem_complementar4}" width="200px" height="200px" alt="Atração 4">
        </div>
        <span class="tituloDetalhes">Gerenciamento</span>
        <div class="divDetalhes">
            <a class="btEdit" href="update.html?id=${lugar.id}">Editar</a>
            <button class="btDelete" onclick="deleteItem()">Deletar</button>
        </div>
        `;
    }
}
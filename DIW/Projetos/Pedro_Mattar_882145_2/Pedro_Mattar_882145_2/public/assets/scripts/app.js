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

    const secCarrosel = document.getElementById('Carrosel');
    
    const lugarC1 = dados[4];
    const lugarC2 = dados[1];

    secCarrosel.innerHTML = `
    <div id="carouselExample" class="carousel slide carousel-fade">
        <div class="carousel-inner">
            <a href="detalhes.html?id=${lugarC1.id}">
                <div class="carousel-item active">
                <img src="${lugarC1.imagem_lugar}" class="imgSlider d-block w-100" height="800px">
                    <div class="carousel-caption">
                        <span class="tituloSlider">${lugarC1.nome}</span>
                        <p class="textoSlider">Conheça o lindo mar do caribe e relaxe em praias deslumbrantes.</p>
                    </div>        
                </div>
            </a>
            <a href="detalhes.html?id=${lugarC2.id}">
                <div class="carousel-item active">
                <img src="${lugarC2.imagem_lugar}" class="imgSlider d-block w-100" height="800px">
                    <div class="carousel-caption">
                        <span class="tituloSlider">${lugarC2.nome}</span>
                        <p class="textoSlider">Visite os famosos parques da disney e decubra a verdadeira magia.</p>
                    </div>        
                </div>
            </a>
        </div>
        <button class="carousel-control-prev" type="button" data-bs-target="#carouselExample" data-bs-slide="prev">
          <span class="carousel-control-prev-icon" aria-hidden="true"></span>
          <span class="visually-hidden">Previous</span>
        </button>
        <button class="carousel-control-next" type="button" data-bs-target="#carouselExample" data-bs-slide="next">
          <span class="carousel-control-next-icon" aria-hidden="true"></span>
          <span class="visually-hidden">Next</span>
        </button>
      </div>
    `
    
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
        <span class="tituloDetalhes">Marcação</span>
        <div class="divDetalhes">
            <button class="btFavorite" onclick="adicionarFavorito()">Favoritar</button>
        </div>
        `;
    }
}



document.getElementById("formPesquisa").addEventListener("submit", async (e) => {
    e.preventDefault();
    
    const nomeLugar = document.getElementById("inputLugar").value.trim();
    if (!nomeLugar) {
        alert("Digite um lugar válido!");
        return;
    }
    try {
        const response = await fetch('http://localhost:3000/dados');
        if (!response.ok) {
            throw new Error(`Erro no servidor: ${response.status}`);
        }
        const data = await response.json();
        console.log("Dados recebidos:", data);
        const lugares = data.dados || data;
        if (!Array.isArray(lugares)) {
            throw new Error("Formato de dados inválido");
        }
        const lugarEncontrado = lugares.find(lugar => 
            lugar.nome.toLowerCase().includes(nomeLugar.toLowerCase())
        );
        if (lugarEncontrado) {
            window.location.href = `detalhes.html?id=${lugarEncontrado.id}`;
        } else {
            alert(`"${nomeLugar}" não encontrado!`);
        }
    } catch (error) {
        console.error("Erro completo:", error);
        alert(`Falha na pesquisa: ${error.message}`);
    }
});



mapboxgl.accessToken = 'pk.eyJ1IjoicGVkcjBjYXJtYXQiLCJhIjoiY21iZHRjMGZkMWlxcTJrcHY1cWVubnRtaiJ9.E633obVcvVIBEtHemue_vw';

try {
    const map = new mapboxgl.Map({
        container: 'map',
        style: 'mapbox://styles/mapbox/streets-v11',
        center: [0, 20],
        zoom: 1.5
    });

    map.addControl(new mapboxgl.NavigationControl());

    map.on('load', async () => {
        console.log('Mapa carregado com sucesso!');
        
        try {
            
            const response = await fetch('http://localhost:3000/dados');
            if (!response.ok) {
                throw new Error(`Falha na requisição: ${response.status} ${response.statusText}`);
            }
            
            const data = await response.json();
            console.log('Dados recebidos da API:', data);

         
            let lugares;
            
            if (Array.isArray(data)) {
                
                lugares = data;
            } else if (data.dados && Array.isArray(data.dados)) {
                
                lugares = data.dados;
            } else if (data.data && Array.isArray(data.data)) {
                
                lugares = data.data;
            } else if (data.results && Array.isArray(data.results)) {
                
                lugares = data.results;
            } else {
                throw new Error('Estrutura de dados não reconhecida. Esperado um array ou objeto com propriedade array');
            }

            console.log(`Encontrados ${lugares.length} lugares para exibir`);

            
            for (const lugar of lugares) {
                try {
                    
                    const localizacao = lugar.nome;
                    if (!localizacao) {
                        console.warn('Localização não encontrada para:', lugar);
                        continue;
                    }

                    const geocodeResponse = await fetch(
                        `https://api.mapbox.com/geocoding/v5/mapbox.places/${encodeURIComponent(localizacao)}.json?access_token=${mapboxgl.accessToken}`
                    );
                    
                    if (!geocodeResponse.ok) {
                        console.warn(`Falha na geocodificação para: ${localizacao}`);
                        continue;
                    }
                    
                    const geocodeData = await geocodeResponse.json();
                    
                    if (geocodeData.features && geocodeData.features.length > 0) {
                        const [longitude, latitude] = geocodeData.features[0].center;
                        
                        const el = document.createElement('div');
                        el.className = 'custom-marker';
                        
                        const imagem = lugar.imagem_lugar || 'https://via.placeholder.com/50?text=' + encodeURIComponent(lugar.nome?.substring(0,2) || '');
                        el.style.backgroundImage = `url(${imagem})`;
                        
                        
                        new mapboxgl.Marker(el)
                            .setLngLat([longitude, latitude])
                            .setPopup(new mapboxgl.Popup({ offset: 25 })
                                .setHTML(`
                                    <div class="popup-content">
                                        <h3>${lugar.nome || 'Local sem nome'}</h3>
                                        ${imagem ? `<img src="${imagem}" alt="${lugar.nome}" class="popup-image">` : ''}
                                        <div class="popup-details">
                                            ${lugar.localizacao ? `<p><strong>Localização:</strong> ${lugar.localizacao}</p>` : ''}
                                            ${lugar.continente ? `<p><strong>Continente:</strong> ${lugar.continente}</p>` : ''}
                                            ${lugar.principais_atracoes ? `<p><strong>Atrações:</strong> ${lugar.principais_atracoes}</p>` : ''}
                                        </div>
                                        <button class="details-btn" data-id="${lugar.id}">Ver detalhes</button>
                                    </div>
                                `))
                            .addTo(map);
                    } else {
                        console.warn(`Nenhum resultado de geocodificação para: ${localizacao}`);
                    }
                } catch (error) {
                    console.error(`Erro ao processar local ${lugar.id || lugar.nome}:`, error);
                }
            }
        } catch (error) {
            console.error('Erro ao carregar dados:', error);
            showError(`Erro ao carregar dados: ${error.message}`);
        }
    });

} catch (error) {
    console.error('Erro ao inicializar o mapa:', error);
    showError(`Erro ao inicializar o mapa: ${error.message}`);
}

function showError(message) {
    const mapContainer = document.getElementById('map');
    mapContainer.innerHTML = `
        <div class="error-container">
            <h3>Ocorreu um erro</h3>
            <p>${message}</p>
            <p>Por favor, verifique:</p>
            <ul>
                <li>Se o servidor da API está rodando</li>
                <li>Se a URL da API está correta</li>
                <li>O console do navegador para detalhes (F12)</li>
            </ul>
            <button onclick="window.location.reload()">Tentar novamente</button>
        </div>
    `;
}

document.addEventListener('click', function(e) {
    if (e.target && e.target.classList.contains('details-btn')) {
        const id = e.target.getAttribute('data-id');
        window.location.href = `detalhes.html?id=${id}`;
    }
});





async function adicionarFavorito() {
    try {
        const url = window.location.href;
        let id;
        
        const match = url.match(/\/(\d+)(?:\/|$)/);
        if (match && match[1]) {
            id = match[1];
        } 
        else {
            const urlObj = new URL(url);
            id = urlObj.searchParams.get('id');
        }
        
        if (!id) throw new Error('Nenhum ID encontrado na URL');
        
        if (!/^\d+$/.test(id)) throw new Error(`ID inválido: "${id}" - deve conter apenas números`);
        
        const stringId = id.toString();
        if (stringId.length === 0) throw new Error('ID não pode ser vazio');

        const checkResponse = await fetch(`http://localhost:3000/favoritos?itemId=${stringId}`);
        if (!checkResponse.ok) {
            throw new Error(`Servidor retornou status ${checkResponse.status}`);
        }
        
        const existingFavs = await checkResponse.json();
        if (existingFavs.length > 0) {
            alert('Este item já está nos seus favoritos!');
            return {
                success: false,
                message: 'Este item já está nos seus favoritos',
                id: stringId
            };
        }

        const newFavorite = {
            itemId: stringId  
        };

        const addResponse = await fetch('http://localhost:3000/favoritos', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify(newFavorite)
        });

        if (!addResponse.ok) {
            throw new Error(`Erro ao adicionar: status ${addResponse.status}`);
        }

        alert('Item adicionado aos favoritos com sucesso!');
        return {
            success: true,
            message: 'Adicionado aos favoritos com sucesso!',
            id: stringId,
            data: await addResponse.json()
        };

    } catch (error) {
        console.error('Erro detalhado:', error);
        alert('Ocorreu um erro ao tentar favoritar: ' + error.message);
        return {
            success: false,
            message: `Falha: ${error.message}`,
            error: error
        };
    }
}






async function carregarFavoritos() {
  try {
    const [resDados, resFavoritos] = await Promise.all([
      fetch('http://localhost:3000/dados'),
      fetch('http://localhost:3000/favoritos')
    ]);

    const [dados, favoritos] = await Promise.all([
      resDados.json(),
      resFavoritos.json()
    ]);

    const itensFavoritos = dados.filter(item => 
      favoritos.some(fav => fav.itemId === item.id)
    );

    const section = document.querySelector('#Favorito');
    section.innerHTML = ''; 

    if (itensFavoritos.length === 0) {
      section.innerHTML = '<p class="sem-favoritos">Nenhum favorito encontrado</p>';
      return;
    }

    itensFavoritos.forEach(lugar => {
      const favorito = favoritos.find(fav => fav.itemId === lugar.id);
      
      if (!favorito) return; 

      const destaque = document.createElement("a");
      destaque.className = `destaqueM`;
      destaque.href = `detalhes.html?id=${lugar.id}`;
      destaque.style.backgroundImage = `url('${lugar.imagem_lugar}')`;
      
      const article = document.createElement("article");
      const span = document.createElement("span");
      span.className = "nomeLugar";
      span.textContent = lugar.nome;

      const btnRemover = document.createElement("button");
      btnRemover.className = "btn-remover-favorito";
      btnRemover.innerHTML = "×";
      btnRemover.title = "Remover dos favoritos";

      btnRemover.addEventListener('click', async (e) => {
        e.preventDefault();
        e.stopPropagation();
        
          btnRemover.disabled = true;
          btnRemover.innerHTML = '<span class="spinner">...</span>';
          
          try {
            await removerFavorito(favorito.id);
            destaque.remove();
            alert('Item removido dos favoritos com sucesso!');
          } catch (error) {
            console.error(error);
            alert('Erro ao remover favorito');
            btnRemover.disabled = false;
            btnRemover.innerHTML = "×";
          }
        
      });

      article.appendChild(span);
      destaque.appendChild(article);
      destaque.appendChild(btnRemover);
      section.appendChild(destaque);
    });

  } catch (error) {
    console.error("Erro ao carregar favoritos:", error);
    document.querySelector('#Favorito').innerHTML = 
      '<p class="erro-favoritos">Erro ao carregar favoritos</p>';
  }
}

async function removerFavorito(id) {
  const response = await fetch(`http://localhost:3000/favoritos/${id}`, {
    method: 'DELETE'
  });

  if (!response.ok) {
    throw new Error(`HTTP error! status: ${response.status}`);
  }
  
  return await response.json();
}






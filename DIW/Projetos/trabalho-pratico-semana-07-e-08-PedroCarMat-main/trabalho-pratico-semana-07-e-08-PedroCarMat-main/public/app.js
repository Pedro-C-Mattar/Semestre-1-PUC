const dados = [
    {
        "id": 1,
        "nome": "Paris",
        "imagem_lugar":"img/Paris.jpg",
        "localizacao": "Paris, França",
        "continente": "Europa",
        "idioma": "Francês",
        "moeda": "Euro",
        "categoria":"Cultura",
        "principais_atracoes": "Torre Eiffel, Museu do Louvre, Catedral de Notre-Dame, Arco do Triunfo",
        "imagem_complementar1": "img/torreEiffel.jpg",
        "imagem_complementar2": "img/louvre.jpg",
        "imagem_complementar3": "img/notreDame.jpg",
        "imagem_complementar4": "img/arcoTriunfo.jpg"
    },
    {
        "id": 2,
        "nome": "Orlando",
        "imagem_lugar":"img/Orlando.jpg",
        "localizacao": "Orlando, Florida, EUA",
        "continente": "América do Norte",
        "idioma": "Inglês",
        "moeda": "Dólar Americano",
        "categoria":"Parques",
        "principais_atracoes": "Magic Kingdom, Universal Studios, SeaWorld, Animal Kingdom",
        "imagem_complementar1": "img/magicKingdom.jpg",
        "imagem_complementar2": "img/universal.jpg",
        "imagem_complementar3": "img/seaWorld.jpg",
        "imagem_complementar4": "img/animalKingdom.jpg"
    },
    {
        "id": 3,
        "nome": "Tokyo",
        "imagem_lugar":"img/Tokyo.jpg",
        "localizacao": "Tokyo, Japão",
        "continente": "Ásia",
        "idioma": "Japonês",
        "moeda": "Iene",
        "categoria":"City Tour",
        "principais_atracoes": "Shibuya, Akihabara, Tokyo Skytree, Senso-Ji",
        "imagem_complementar1": "img/shibuya.jpg",
        "imagem_complementar2": "img/akihabara.jpg",
        "imagem_complementar3": "img/tokyoSkytree.webp",
        "imagem_complementar4": "img/sensoJi.jpg"
    },
    {
        "id": 4,
        "nome": "Barcelona",
        "imagem_lugar":"img/Barcelona.jpg",
        "localizacao": "Barcelona, Espanha",
        "continente": "Europa",
        "idioma": "Espanhol",
        "moeda": "Euro",
        "categoria":"Cultura",
        "principais_atracoes": "Camp Nou, Sagrada Familia, Parque Guell, Barceloneta",
        "imagem_complementar1": "img/campNou.webp",
        "imagem_complementar2": "img/sagradaFamilia.jpg",
        "imagem_complementar3": "img/parqueGuell.jpg",
        "imagem_complementar4": "img/barceloneta.jpg"
    },
    {
        "id": 5,
        "nome": "Cancún",
        "imagem_lugar":"img/Cancun.jpg",
        "localizacao": "Cancun, México",
        "continente": "Europa",
        "idioma": "Espanhol",
        "moeda": "Peso Mexicano",
        "categoria":"Praias",
        "principais_atracoes": "Playa Delfines, Playa Tortugas, Garrafón, Chichén Itzá",
        "imagem_complementar1": "img/playaDelfines.webp",
        "imagem_complementar2": "img/playaTortugas.webp",
        "imagem_complementar3": "img/garrafon.jpg",
        "imagem_complementar4": "img/piramideMaia.jpg"
    },
    {
        "id": 6,
        "nome": "Rio de Janeiro",
        "imagem_lugar": "img/RJ.jpg",
        "localizacao": "Rio de Janeiro, Brasil",
        "continente": "América do Sul",
        "idioma": "Português",
        "moeda": "Real",
        "categoria": "Praias",
        "principais_atracoes": "Cristo Redentor, Pão de Açúcar, Praia de Copacabana, Praia de Ipanema",
        "imagem_complementar1": "img/cristo.jpg",
        "imagem_complementar2": "img/paoDeAcucar.jpg",
        "imagem_complementar3": "img/copacabana.jpg",
        "imagem_complementar4": "img/ipanema.jpg"
      },
      {
        "id": 7,
        "nome": "Bahia",
        "imagem_lugar": "img/BA.webp",
        "localizacao": "Bahia, Brasil",
        "continente": "América do Sul",
        "idioma": "Português",
        "moeda": "Real",
        "categoria": "Praias",
        "principais_atracoes": "Pelourinho, Praia do Porto da Barra, Morro de São Paulo, Boipeba",
        "imagem_complementar1": "img/pelourinho.jpg",
        "imagem_complementar2": "img/praiaDoPortoDaBarra.jpg",
        "imagem_complementar3": "img/morroDeSaoPaulo.webp",
        "imagem_complementar4": "img/boipeba.webp"
      },
      {
        "id": 8,
        "nome": "Maranhão",
        "imagem_lugar": "img/MR.jpg",
        "localizacao": "Maranhão, Brasil",
        "continente": "América do Sul",
        "idioma": "Português",
        "moeda": "Real",
        "categoria": "Natureza",
        "principais_atracoes": "Lençóis Maranhenses, Rio Preguiças, Alcântara, Parque da Chapada das Mesas",
        "imagem_complementar1": "img/lencois.webp",
        "imagem_complementar2": "img/rioPreguicas.jpg",
        "imagem_complementar3": "img/parqueChapadaDasMesas.webp",
        "imagem_complementar4": "img/alcantara.jpg"
      },
      {
        "id": 9,
        "nome": "Santa Catarina",
        "imagem_lugar": "img/SC.webp",
        "localizacao": "Santa Catarina, Brasil",
        "continente": "América do Sul",
        "idioma": "Português",
        "moeda": "Real",
        "categoria": "Praias / Parques",
        "principais_atracoes": "Florianópolis, Parque Unipraias, Beto Carrero World, Bombinhas",
        "imagem_complementar1": "img/floripa.jpg",
        "imagem_complementar2": "img/parqueUnipraias.jpg",
        "imagem_complementar3": "img/betoCarrero.webp",
        "imagem_complementar4": "img/bombinhas.jpg"
      },
      {
        "id": 10,
        "nome": "Minas Gerais",
        "imagem_lugar": "img/MG.jpg",
        "localizacao": "Minas Gerais, Brasil",
        "continente": "América do Sul",
        "idioma": "Português",
        "moeda": "Real",
        "categoria": "Cultura",
        "principais_atracoes": "Ouro Preto, Inhotim, Serra da Canastra, Serra da Mantiqueira",
        "imagem_complementar1": "img/ouroPreto.jpg",
        "imagem_complementar2": "img/inhotim.webp",
        "imagem_complementar3": "img/serraDaCanastra.jpg",
        "imagem_complementar4": "img/serraDaMantiqueira.jpg"
      }
]
function carregarDados(){
    const destaquesMundo = document.getElementById('Mundo');
    for (let i = 0; i < 5; i++) {
        
        const lugar = dados[i];

        const destaque = document.createElement("a");
        destaque.className = `destaqueM${i + 1}`;
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
    const destaquesNacional = document.getElementById('Nacional');
    for (let i = 0; i < 5; i++) {
        
        const lugar = dados[i+5];

        const destaque = document.createElement("a");
        destaque.className = `destaqueN${i + 1}`;
        destaque.href = `detalhes.html?id=${lugar.id}`;

        destaque.style.backgroundImage = `url('${lugar.imagem_lugar}')`;
      
        const article = document.createElement("article");
        const span = document.createElement("span");
        span.className = "nomeLugar";
        span.textContent = lugar.nome;
      
        article.appendChild(span);
        destaque.appendChild(article);
        destaquesNacional.appendChild(destaque);
    }
}
function carregarDetalhes(){
    const params = new URLSearchParams(location.search);
    const id = params.get('id');
    const lugar = dados.find(function (elem) {return elem.id == id});
    if(lugar){
        const secDetalhes = document.getElementById('Detalhes');

        secDetalhes.innerHTML =`
        <span class="tituloDetalhes">${lugar.nome}</span>
        <div class="divDetalhes">
            <img src="${lugar.imagem_lugar}" width="500px">
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
            <img src="${lugar.imagem_complementar1}" width="250px" height"="250px">
            <img src="${lugar.imagem_complementar2}" width="250px" height"="250px">
            <img src="${lugar.imagem_complementar3}" width="250px" height"="250px">
            <img src="${lugar.imagem_complementar4}" width="250px" height"="250px">
        </div>
        `
    }
}
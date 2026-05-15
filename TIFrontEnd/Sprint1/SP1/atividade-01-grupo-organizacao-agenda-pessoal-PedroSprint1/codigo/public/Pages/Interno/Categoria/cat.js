document.addEventListener('DOMContentLoaded', function() {
    async function carregarCategorias() {
        try {
            const response = await fetch('http://localhost:3000/categorias');
            const categorias = await response.json();
            
            console.log('Dados recebidos:', categorias); // Verifique se todos os itens chegam
            
            const sectionCategorias = document.querySelector('section#catgorias');
            
            if (!sectionCategorias) {
                console.error('Elemento section#categorias não encontrado!');
                return;
            }
            
            sectionCategorias.innerHTML = '';
            
            categorias.forEach((categoria, index) => {
                console.log(`Processando categoria ${index}:`, categoria);
                
                const divCat = document.createElement('div');
                divCat.className = 'dvCat';

                divCat.style.backgroundColor = categoria.cor;

                
                divCat.innerHTML = `
                    <span class="txtCat">${categoria.id}</span>
                    <span class="txtCat">Nome: ${categoria.nome}</span>
                    <span class="txtCat">Descrição: ${categoria.descricao}</span>
                    <div class="dvBtns">
                        <a class="btn" href="editCategoria.html?id=${categoria.id}">Editar</a>
                        <button class="btn btn-deletar" data-id="${categoria.id}">Deletar</button>
                    </div>
                `;
                
                const textElements = divCat.querySelectorAll('.txtCat');
                textElements.forEach(el => {
                    el.style.color = getContrastColor(categoria.cor);
                });

                sectionCategorias.appendChild(divCat);
            });
    
            document.querySelectorAll('.btn-deletar').forEach(btn => {
                btn.addEventListener('click', function() {
                    deletarCategoria(this.getAttribute('data-id'));
                });
            });
        } catch (error) {
            console.error('Erro ao carregar categorias:', error);
        }
    }

    function getContrastColor(hexColor) {

        const r = parseInt(hexColor.substr(1, 2), 16);
        const g = parseInt(hexColor.substr(3, 2), 16);
        const b = parseInt(hexColor.substr(5, 2), 16);
        
        const brightness = (r * 299 + g * 587 + b * 114) / 1000;
        
        return brightness > 128 ? '#000000' : '#FFFFFF';
    }

    async function deletarCategoria(id) {
            try {
                const response = await fetch(`http://localhost:3000/categorias/${id}`, {
                    method: 'DELETE'
                });
                
                if (response.ok) {
                    alert('Categoria deletada com sucesso!');
                    await carregarCategorias();
                    location.reload();
                }
            } catch (error) {
                console.error('Erro ao deletar categoria:', error);
            }

    }
    carregarCategorias();
});



document.querySelector('.formAdd').addEventListener('submit', async function(e) {
    e.preventDefault();
    
    const nome = document.querySelector('.formAdd input[type="text"]:nth-of-type(1)').value;
    const descricao = document.querySelector('.formAdd input[type="text"]:nth-of-type(2)').value;
    const cor = document.querySelector('.formAdd input[type="color"]').value;
    
    const novaCategoria = {
        nome: nome,
        descricao: descricao,
        cor: cor
    };
    
    try {
        const response = await fetch('http://localhost:3000/categorias', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(novaCategoria)
        });
        
        if (response.ok) {
            alert('Categoria adicionada com sucesso!');
            window.location.href = 'categoria.html';
        } else {
            console.error('Erro ao adicionar categoria:', response.status);
            alert('Erro ao adicionar categoria. Por favor, tente novamente.');
        }
    } catch (error) {
        console.error('Erro na requisição:', error);
        alert('Erro ao conectar com o servidor. Verifique sua conexão.');
    }
});
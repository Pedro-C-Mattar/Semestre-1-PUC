
import { base_url } from "../../assets/js/globals.js";

document.addEventListener('DOMContentLoaded', function () {

    const urlParams = new URLSearchParams(window.location.search);
    const categoriaId = urlParams.get('id');

    if (categoriaId) {

        fetch(`${base_url}/categorias/${categoriaId}`)
            .then(response => response.json())
            .then(categoria => {
                document.querySelector('.formEdit input[type="text"]:nth-of-type(1)').value = categoria.nome;
                document.querySelector('.formEdit input[type="text"]:nth-of-type(2)').value = categoria.descricao;
                document.querySelector('.formEdit input[type="color"]').value = categoria.cor;
            })
            .catch(error => console.error('Erro ao carregar categoria:', error));
    }

    const form = document.querySelector('.formEdit');
    form.addEventListener('submit', function (e) {
        e.preventDefault();

        const nome = document.querySelector('.formEdit input[type="text"]:nth-of-type(1)').value;
        const descricao = document.querySelector('.formEdit input[type="text"]:nth-of-type(2)').value;
        const cor = document.querySelector('.formEdit input[type="color"]').value;

        const categoriaAtualizada = {
            nome: nome,
            descricao: descricao,
            cor: cor
        };

        fetch(`${base_url}/categorias/${categoriaId}`, {
            method: 'PUT',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(categoriaAtualizada)
        })
            .then(response => response.json())
            .then(() => {
                alert('Categoria atualizada com sucesso!');
                window.location.href = `../Categoria/`;
            })
            .catch(error => console.error('Erro ao atualizar categoria:', error));
    });
});


document.querySelector('.formAdd').addEventListener('submit', async function (e) {
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
        const response = await fetch(`${base_url}/categorias`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(novaCategoria)
        });

        if (response.ok) {
            alert('Categoria adicionada com sucesso!');
            window.location.href = `../Categoria/`;

        } else {
            console.error('Erro ao adicionar categoria:', response.status);
            alert('Erro ao adicionar categoria. Por favor, tente novamente.');
        }
    } catch (error) {
        console.error('Erro na requisição:', error);
        alert('Erro ao conectar com o servidor. Verifique sua conexão.');
    }
});
import { base_url } from "../../assets/js/globals.js";

document.addEventListener('DOMContentLoaded', function () {

    const userData = JSON.parse(localStorage.getItem("loggedUser"));
    
    if (!userData || !userData.id) {
        alert('Usuário não está logado ou ID não encontrado!');
        window.location.href = `../Interno/`;
        return;
    }

    const itemId = userData.id;

    fetch(`${base_url}/usuarios/${itemId}`)
        .then(response => {
            if (!response.ok) {
                throw new Error('Perfil não encontrado');
            }
            return response.json();
        })
        .then(item => {
            document.getElementById('itemId').value = item.id;
            document.getElementById('nome').value = item.nome || '';
            document.getElementById('login').value = item.login || '';
            document.getElementById('senha').value = item.senha || '';
            document.getElementById('email').value = item.email || '';
            
        })
        .catch(error => {
            console.error('Erro ao carregar perfil:', error);
            alert('Erro ao carregar dados do perfil: ' + error.message);
        });

    document.getElementById('editForm').addEventListener('submit', function (e) {
        e.preventDefault();
        const itemId = document.getElementById('itemId').value;
        
        if (!itemId) {
            alert('ID do perfil não encontrado!');
            return;
        }

        fetch(`${base_url}/usuarios/${itemId}`)
            .then(response => response.json())
            .then(currentData => {
                const updatedItem = {
                    id: itemId, 
                    nome: document.getElementById('nome').value,
                    login: document.getElementById('login').value,
                    senha: document.getElementById('senha').value,
                    email: document.getElementById('email').value,
                    admin: currentData.admin 
                };

                return fetch(`${base_url}/usuarios/${itemId}`, {
                    method: 'PUT',
                    headers: {
                        'Content-Type': 'application/json',
                    },
                    body: JSON.stringify(updatedItem)
                });
            })
            .then(response => {
                if (!response.ok) {
                    throw new Error('Falha ao atualizar');
                }
                return response.json();
            })
            .then(data => {
                if (itemId === userData.id) {
                    const updatedUserData = {
                        ...userData,
                        nome: document.getElementById('nome').value,
                        email: document.getElementById('email').value
                    };
                    localStorage.setItem("loggedUser", JSON.stringify(updatedUserData));
                }
                
                alert('Perfil atualizado com sucesso!');
                window.location.href = `../Interno/`;
            })
            .catch(error => {
                console.error('Erro:', error);
                alert('Erro ao atualizar o perfil: ' + error.message);
            });
    });
});

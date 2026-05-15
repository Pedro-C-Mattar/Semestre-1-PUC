import { base_url } from "../../assets/js/globals.js";
import User from "../../assets/js/controllers/User.js";


document.addEventListener('DOMContentLoaded', function () {
    const userData = JSON.parse(localStorage.getItem("loggedUser"));

    if (!userData || !userData.id) {
        document.getElementById('dadosPerfil').innerHTML =
            '<p>Usuário não está logado ou ID não encontrado</p>';
        return;
    }

    const userId = userData.id;

    fetch(`${base_url}/usuarios/${userId}`)
        .then(response => {
            if (!response.ok) {
                throw new Error('Perfil não encontrado!');
            }
            return response.json();
        })
        .then(usuario => {
            const dadosPerfil = document.getElementById('dadosPerfil');
            dadosPerfil.innerHTML = `
                <p class="txtPerfil"><strong>Nome:</strong> ${usuario.nome}</p>
                <p class="txtPerfil"><strong>Login:</strong> ${usuario.login}</p>
                <p class="txtPerfil"><strong>Senha:</strong> ${usuario.senha}</p>
                <p class="txtPerfil"><strong>Email:</strong> ${usuario.email}</p>
                <a class="btMudarPerfil" href="../painelUsuario/editPerfil.html">Mudar</a>
                <button class="btDelPerf">Deletar</button>
                <button class="logout-btn">Sair</button>
            `;

            if (usuario.admin) {
                dadosPerfil.innerHTML += `
                    <a class="btn-admin" href="../../Pages/Admin/" style="display:block; margin-top: 10px;">Painel Admin</a>
                `;
            }

            document.querySelector('.btDelPerf').addEventListener('click', function () {
                deletarPerfil();
            });
            document.querySelector(".logout-btn").addEventListener("click", ev => {
                console.log("aaaaa");

                User.logout(() => {
                    window.location.href = "../Home"
                })
            })
        })
        .catch(error => {
            console.error('Erro:', error);
            document.getElementById('dadosPerfil').innerHTML =
                '<p>Erro ao carregar os dados do perfil.</p>';
        });
});



async function deletarPerfil() {
    const userData = JSON.parse(localStorage.getItem("loggedUser"));

    if (!userData || !userData.id) {
        alert('Usuário não está logado ou ID não encontrado!');
        return;
    }

    const userId = userData.id;

    if (!confirm('Tem certeza que deseja deletar este perfil permanentemente?')) {
        return;
    }

    try {
        const response = await fetch(`${base_url}/usuarios/${userId}`, {
            method: 'DELETE',
            headers: {
                'Content-Type': 'application/json'
            }
        });

        if (response.ok) {
            localStorage.removeItem("loggedUser");
            alert('Perfil deletado com sucesso!');
            window.location.href = `../Home/`;
        } else {
            throw new Error('Falha ao deletar perfil');
        }
    } catch (error) {
        console.error('Erro:', error);
        alert('Erro ao deletar perfil: ' + error.message);
    }
}



import { base_url } from "../globals.js";

const headers = new Headers()
headers.append("Content-Type", "application/json");
headers.append("Access-Control-Allow-Origin", "*");

const User = {

    getById: async (id) => {
        let retorno

        try {
            retorno = await fetch(`${base_url}/usuarios/${id}`, {
                method: "GET",
                headers: headers
            })
        } catch (err) {
            console.error(err);

            return {
                data: err,
            }
        }

        return {
            data: await retorno.json(),
        }
    },

    register: async (data) => {
        const { nome, email, senha } = data;
        data.admin = false
        data.favourites = []

        const retorno = {
            msg: "",
            status: "error"
        }

        if (!nome) {
            retorno.msg = "Por favor, preencha o nome!"
            return retorno
        }

        if (!email) {
            retorno.msg = "Por favor, preencha o email!"
            return retorno
        }

        if (!senha) {
            retorno.msg = "Por favor, preencha a senha!"
            return retorno
        }

        try {
            let user = await fetch(`${base_url}/usuarios?email=${email}`, {
                method: "GET",
                headers: headers
            })

            user = await user.json()


            if (user.length == 1) {
                retorno.msg = "Email em uso! Utilize outro!"
                return retorno
            }

            retorno.data = await fetch(`${base_url}/usuarios`, {
                method: "POST",
                headers: headers,
                body: JSON.stringify(data)
            })

            retorno.data = await retorno.data.json()
        } catch (err) {
            console.error(err)
            retorno.msg = "Erro interno, por favor tente novamente mais tarde!"
            return retorno
        }

        retorno.msg = "Sucesso ao registrar!"
        retorno.status = "success"
        return retorno
    },

    login: async (data) => {
        const { email, password } = data;

        const retorno = {
            status: "error"
        }

        if (!email) {
            retorno.msg = "Por favor, preencha o email!"
            return retorno
        }

        if (!password) {
            retorno.msg = "Por favor, preencha a senha!"
            return retorno
        }

        let user

        try {
            user = await fetch(`${base_url}/usuarios?email=${email}`, {
                method: "GET",
                headers: headers
            })
            user = await user.json()
        } catch (err) {
            console.log(err);

            retorno.msg = "Erro interno, tente novamente mais tarde!"
            return retorno
        }

        console.log(user);
        
        if (user.length != 1) {
            retorno.msg = "Usuário e/ou senha incorretos"
            return retorno
        }

        if (user[0].senha != password) {
            retorno.msg = "Usuário e/ou senha incorretos"
            return retorno
        }

        retorno.msg = "Sucesso ao logar! Você será redirecionado em alguns intantes"
        retorno.status = "success"
        retorno.user = user[0]
        return retorno

    },

    logout: async (callback) => {
        localStorage.removeItem("loggedUser")

        callback()
    }

}

export default User
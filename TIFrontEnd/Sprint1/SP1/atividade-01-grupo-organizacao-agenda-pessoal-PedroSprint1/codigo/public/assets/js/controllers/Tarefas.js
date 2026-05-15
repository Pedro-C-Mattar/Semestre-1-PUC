
import { base_url } from "../globals.js";

const headers = new Headers()
headers.append("Content-Type", "application/json");
headers.append("Access-Control-Allow-Origin", "*");



const Tarefas = {

    listAll: async () => {

        let retorno

        try {
            retorno = await fetch(`${base_url}/tarefas`, {
                method: "GET",
                headers: headers
            })
        } catch (err) {
            console.error(err);

            return {
                data: err,
                msg: "teste"
            }
        }

        return {
            data: await retorno.json(),
            msg: "teste"
        }
    },

    getByStatus: async(statusId) => {

        let retorno
        
        try {
            retorno = await fetch(`${base_url}/tarefas?status=${statusId}`, {
                method: "GET",
                headers: headers
            })
        } catch (err) {
            console.error(err);

            return {
                data: err,
                msg: "teste"
            }
        }

        return {
            data: await retorno.json(),
            msg: "teste"
        }
    },

    getById: async (id) => {

        const retorno = await fetch(`${base_url}/tarefas/${id}`, {
            method: "GET",
            headers: headers
        })

        return await retorno.json()
    },

    add: async (data) => {
        const { titulo, descricao, categorias, status, dataHora } = data;
        console.log("entra no add");

        const returnData = {
            msg: "",
            status: "error"
        }

        if (!titulo) {
            returnData.msg = "Por favor preencha o título!"
            return returnData
        }


        if (!descricao) {
            returnData.msg = "Por favor preencha a descrição!"
            return returnData
        }

        if (status.length == 0) {
            returnData.msg = "Por favor selecione ao menos uma categoria!"
            return returnData
        }

        if (categorias.status == 0) {
            returnData.msg = "Por favor selecione o status!"
            return returnData
        }

        if (!dataHora) {
            returnData.msg = "Por favor selecione uma data para entrega!"
            return returnData
        }

        try {
            returnData.data = await fetch(`${base_url}/tarefas`, {
                method: "POST",
                headers: headers,
                body: JSON.stringify(data)
            })
        } catch (err) {
            console.error(err)
            returnData.msg = "Erro interno, por favor tente novamente mais tarde!"
            return returnData
        }

        returnData.msg = "Sucesso ao cadastrar tarefa!"
        returnData.status = "success"
        return returnData
    },

    delete: async (id) => {

        const returnData = {}

        try {
            returnData.data = await fetch(`${base_url}/tarefas/${id}`, {
                method: "DELETE",
                headers: headers
            })

            returnData.msg = "Sucesso ao excluir tarefa!"
            returnData.status = "success"
        } catch(err) {
            returnData.data = {}
            returnData.msg = "Erro interno ao excluir, tente novamente mais tarde!"
            returnData.status = "error"
        }

        return returnData
    },

    edit: async (id, data) => {

        const { titulo, descricao, categorias, status, dataHora } = data;
        console.log("entra no edit");

        const returnData = {
            msg: "",
            status: "error"
        }

        if (!titulo) {
            returnData.msg = "Por favor preencha o título!"
            return returnData
        }


        if (!descricao) {
            returnData.msg = "Por favor preencha a descrição!"
            return returnData
        }

        if (status.length == 0) {
            returnData.msg = "Por favor selecione ao menos uma categoria!"
            return returnData
        }

        if (categorias.status == 0) {
            returnData.msg = "Por favor selecione o status!"
            return returnData
        }

        if (!dataHora) {
            returnData.msg = "Por favor selecione uma data para entrega!"
            return returnData
        }

        try {
            returnData.data = await fetch(`${base_url}/tarefas/${id}`, {
                method: "PUT",
                headers: headers,
                body: JSON.stringify(data)
            })
        } catch (err) {
            console.error(err)
            returnData.msg = "Erro interno, por favor tente novamente mais tarde!"
            return returnData
        }

        returnData.msg = "Sucesso ao editar tarefa!"
        returnData.status = "success"
        return returnData
    }
}

export default Tarefas
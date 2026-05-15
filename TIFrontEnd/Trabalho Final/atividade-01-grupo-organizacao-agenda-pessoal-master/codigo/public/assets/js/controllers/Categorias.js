import { base_url } from "../globals.js";

const headers = new Headers()
headers.append("Content-Type", "application/json");
headers.append("Access-Control-Allow-Origin", "*");


const Categorias = {

    listAll: async () => {
        let retorno

        try {
            retorno = await fetch(`${base_url}/categorias`, {
                method: "GET",
                headers: headers
            })
        } catch (err) {
            console.error(err);

            return {
                data: err,
                msg: "Erro interno",
                status: "error"
            }
        }

        return {
            data: await retorno.json(),
            msg: "Sucesso",
            status: "success"
        }
    },

    getById: async (id) => {
        const retorno = await fetch(`${base_url}/categorias/${id}`, {
            method: "GET",
            headers: headers
        })

        return await retorno.json()
    },

    add: async (data) => {
        const { cor, nome, descricao } = data;
        console.log("entra no add");

        const returnData = {
            msg: "",
            status: "error"
        }

        if (!nome) {
            returnData.msg = "Por preencha o nome!"
            return returnData
        }

        if (!cor) {
            returnData.msg = "Por favor preencha a cor!"
            return returnData
        }


        if (!descricao) {
            returnData.msg = "Por favor preencha a descrição!"
            return returnData
        }


        try {
            returnData.data = await fetch(`${base_url}/categorias`, {
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

    edit: (id, data) => {

    },

    delete: (id) => {

    }
}

export default Categorias
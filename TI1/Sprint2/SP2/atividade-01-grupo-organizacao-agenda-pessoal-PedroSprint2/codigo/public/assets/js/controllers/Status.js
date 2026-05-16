import { base_url } from "../globals.js"

const headers = new Headers({ "Content-Type": "application/json" })

const Status = {
    listAll: async () => {
        try {
            const retorno = await fetch(`${base_url}/status`, { method: "GET", headers });
            return {
                data: await retorno.json(),
                msg: "Status carregados com sucesso",
                status: "success"
            };
        } catch(err) {
            console.error("Ops! Erro ao carregar status:", err);
            return { data: [], msg: "Erro ao carregar status", status: "error" };
        }
    },

    getById: async (id) => {
        try {
            const retorno = await fetch(`${base_url}/status/${id}`, { method: "GET", headers });
            return await retorno.json();
        } catch(err) {
            console.error("Erro ao buscar status:", err);
            return null;
        }
    },

    add: async ({ nome }) => {
        const returnData = { msg: "", status: "error" };

        if (!nome?.trim()) {
            returnData.msg = "Por favor preencha o nome do status!";
            return returnData;
        }

        try {
            const response = await fetch(`${base_url}/status`, {
                method: "POST",
                headers,
                body: JSON.stringify({ nome: nome.trim() })
            });

            returnData.status = response.ok ? "success" : "error";
            returnData.msg = response.ok 
                ? "Status adicionado com sucesso!"
                : "Erro ao adicionar status!";
                
            if (response.ok) {
                returnData.data = await response.json();
            }
        } catch (err) {
            console.error("Falha ao adicionar status:", err);
            returnData.msg = "Erro interno, por favor tente novamente mais tarde!";
        }

        return returnData;
    },

    delete: async (id) => {
        try {
            const retorno = await fetch(`${base_url}/status/${id}`, { method: "DELETE", headers });
            return await retorno.json();
        } catch(err) {
            console.error("Erro ao excluir status:", err);
            return { error: "Erro ao deletar status" };
        }
    },

    edit: async (id, data) => {
        try {
            const retorno = await fetch(`${base_url}/status/${id}`, {
                method: "PUT",
                headers,
                body: JSON.stringify(data)
            });
            return await retorno.json();
        } catch(err) {
            console.error("Erro ao atualizar status:", err);
            return { error: "Erro ao editar status" };
        }
    }
};

export default Status;
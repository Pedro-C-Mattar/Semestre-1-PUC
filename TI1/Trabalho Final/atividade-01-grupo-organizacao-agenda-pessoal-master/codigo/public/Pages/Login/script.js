import User from "../../assets/js/controllers/User.js"

const loginForm = document.querySelector("#login-form")
const registerForm = document.querySelector("#register-form")


loginForm.addEventListener("submit", async (ev) => {
    ev.preventDefault()
    
    const retorno = await User.login({
        email: ev.target.emailLogin.value,
        password: ev.target.passwordLogin.value
    })

    Toastify({
        text: retorno.msg,
        duration: 4000,
        newWindow: true,
        close: true,
        gravity: "top", // `top` or `bottom`
        position: "right", // `left`, `center` or `right`
        stopOnFocus: true, // Prevents dismissing of toast on hover
        style: {
            background: retorno.status == "error" ? "red" : "green",
            color: "white"
        }
    }).showToast();

    if (retorno.status == "error") {
        return
    }

    localStorage.removeItem("loggedUser")
    localStorage.setItem("loggedUser", JSON.stringify(retorno.user))

    setTimeout(() => { window.location.href = "../Interno" }, 4000)
})

registerForm.addEventListener("submit", async (ev) => {
    ev.preventDefault()
    
    let retorno

    retorno = await User.register({
        nome: ev.target.nameRegister.value,
        email: ev.target.emailRegister.value,
        senha: ev.target.passwordRegister.value
    })

    console.log(retorno);

    Toastify({
        text: retorno.msg,
        duration: 4000,
        newWindow: true,
        close: true,
        gravity: "top", // `top` or `bottom`
        position: "right", // `left`, `center` or `right`
        stopOnFocus: true, // Prevents dismissing of toast on hover
        style: {
            background: retorno.status == "error" ? "red" : "green",
            color: "white"
        }
    }).showToast();

    if (retorno.status == "error") {
        return
    }
})
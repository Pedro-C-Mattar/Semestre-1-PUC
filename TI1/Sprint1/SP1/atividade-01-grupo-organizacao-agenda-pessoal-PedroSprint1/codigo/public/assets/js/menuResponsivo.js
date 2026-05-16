function abrirMenu() {
  const menu = document.getElementById("menuMobile");
  const iconAbrir = document.getElementById("iconeAbrir");
  const iconFechar = document.getElementById("iconeFechar");

  menu.classList.add("ativo");
  iconAbrir.style.display = "none";
  iconFechar.style.display = "inline-block";
}

function fecharMenu() {
  const menu = document.getElementById("menuMobile");
  const iconAbrir = document.getElementById("iconeAbrir");
  const iconFechar = document.getElementById("iconeFechar");

  menu.classList.remove("ativo");
  iconAbrir.style.display = "inline-block";
  iconFechar.style.display = "none";
}

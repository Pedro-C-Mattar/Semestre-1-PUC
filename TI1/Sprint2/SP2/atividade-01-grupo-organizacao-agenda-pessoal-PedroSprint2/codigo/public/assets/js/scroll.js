document.addEventListener("DOMContentLoaded", () => {
  const header = document.querySelector("header");
  let lastScroll = window.scrollY;

  header.classList.add("fixed"); // começa fixo

  window.addEventListener("scroll", () => {
    if (!header) return;

    const currentScroll = window.scrollY;
    const halfPage = window.innerHeight / 2;
    const scrollingDown = currentScroll > lastScroll;
    const scrollingUp = currentScroll < lastScroll;

    // No topo ou antes da metade → mantém fixo e visível
    if (currentScroll < halfPage) {
      header.classList.remove("hide");
      header.classList.add("fixed");
    }

    // Scroll para baixo após metade → esconder suavemente
    else if (scrollingDown) {
      header.classList.add("hide");

      // Espera a transição completar antes de remover .fixed
      setTimeout(() => {
        header.classList.remove("fixed");
      }, 400); // tempo igual ao transition do CSS
    }

    // Scroll para cima após metade → mostrar e fixar
    else if (scrollingUp) {
      header.classList.remove("hide");
      header.classList.add("fixed");
    }

    lastScroll = currentScroll;
  });
});

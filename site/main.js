        const burger = document.getElementById('burger');
        const mobileMenu = document.getElementById('mobileMenu');
        
        burger.addEventListener('click', function() {
            this.classList.toggle('active');
            mobileMenu.classList.toggle('active');
        });
        
        // Закрываем меню при клике на пункт
        const menuItems = mobileMenu.querySelectorAll('a');
        menuItems.forEach(item => {
            item.addEventListener('click', function() {
                burger.classList.remove('active');
                mobileMenu.classList.remove('active');
            });
        });
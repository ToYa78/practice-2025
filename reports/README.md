# Руководство по созданию игрового движка на SFML

## 1. Введение
Простой 2D игровой движок на базе библиотеки SFML, реализующий:
- Управление спрайтом с клавиатуры
- Основной игровой цикл
- Систему ввода, обновления и отрисовки

## 2. Технологический стек
| Компонент       | Версия     |
|-----------------|------------|
| C++            | 17 стандарт|
| SFML           | 3.0.0       |

## 3. Реализация компонентов

### 3.1. Класс Square
**Square.h**
```cpp
#pragma once
#include <SFML/Graphics.hpp>

class Square {
private:
    sf::Vector2f position;
    sf::Sprite sprite;
    sf::Texture texture;
    float speed = 400.f;
    bool moveFlags[4]; // Left, Right, Up, Down
    
public:
    Square();
    const sf::Sprite& getSprite() const;
    
    void setMovement(int direction, bool state);
    void update(float deltaTime);
};
```

### 3.2. Класс Engine
**Engine.h**
```cpp
#pragma once
#include "Square.h"
#include <SFML/Graphics.hpp>

class Engine {
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    Square player;
    
    void processInput();
    void update(float dt);
    void render();
    
public:
    Engine();
    void run();
};
```

## 4. Основной игровой цикл
**Engine.cpp**
```cpp
void Engine::run() {
    sf::Clock clock;
    
    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        
        processInput();
        update(dt.asSeconds());
        render();
    }
}
```
## 5. Структура проекта
```
EngineGame/
└── EngineGame/
    ├── Engine.cpp
    ├── Engine.h
    ├── Square.cpp
    ├── Square.h
    └── Main.cpp
```

## 6. Дальнейшее развитие
1. Добавление системы сущностей (ECS)
2. Реализация физики (Box2D)
3. Система частиц
4. Менеджер ресурсов
5. Поддержка звука

---

> **Примечание**: Полные исходные коды доступны в приложенных файлах реализации.
``` 

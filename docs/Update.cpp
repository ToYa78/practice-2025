#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
    m_Square.update(dtAsSeconds);
    m_Rectangle.update(dtAsSeconds);
}
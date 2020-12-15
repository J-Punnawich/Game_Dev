#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
    body(body)
{
}

bool Collider::Checkcollision(Collider& other)
{
    sf::Vector2f otherPos = other.Getpos();
    sf::Vector2f otherHalfsize = other.Gethalfsize();
    sf::Vector2f thisPos = Getpos();
    sf::Vector2f thisHalfsize = Gethalfsize();

    float deltaX = otherPos.x - thisPos.x;
    float deltaY = otherPos.y - thisPos.y;

    float intersectX = abs(deltaX) - (otherHalfsize.x + thisHalfsize.x);
    float intersectY = abs(deltaY) - (otherHalfsize.y + thisHalfsize.y);

    if (intersectX < 0.0f    &&    intersectY < 0.0f)
    {

        return true;
    }
    return false;
}

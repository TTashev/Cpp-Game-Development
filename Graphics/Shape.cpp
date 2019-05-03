#include "Shape.h"

void Shape::moveBy(const Vec2D& deltaOffset)
{
    for(Vec2D& point : points)
    {
        point = point + deltaOffset;
    }
}

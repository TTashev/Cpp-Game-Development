#include "Circle.h"
#include "../../Section-6-Full-Source/Utils/Utils.h"

Circle::Circle() : Circle(Vec2D::Zero, 0)
{

}

Circle::Circle(const Vec2D& center, float radius) : radius(radius)
{
    points.push_back(center);
}


bool Circle::intersects(const Circle& otherCircle) const
{
    return GetCenterPoint().Distance(otherCircle.GetCenterPoint()) < (radius + otherCircle.radius);
}


bool Circle::containsPoint(const Vec2D& point) const
{
    return IsLessThanOrEqual(GetCenterPoint().Distance(point), radius);
}

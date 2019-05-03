#include "AARectangle.h"
#include "../../Section-6-Full-Source/Utils/Utils.h"
#include <cmath>

AARectangle::AARectangle() : AARectangle(Vec2D::Zero, Vec2D::Zero)
{

}

AARectangle::AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height)
{
    points.push_back(topLeft);
    points.push_back(Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1));
}

AARectangle::AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight)
{
    points.push_back(topLeft);
    points.push_back(bottomRight);
}

AARectangle::~AARectangle()
{

}

float AARectangle::getWidth() const
{
    return getBottomRightPoint().GetX() - getTopLeftPoint().GetX() + 1;
}

float AARectangle::getHeight() const
{
    return getBottomRightPoint().GetY() - getTopLeftPoint().GetY() + 1;
}

void AARectangle::moveTo(const Vec2D& position)
{
    float width = getWidth();
    float height = getHeight();

    setTopLeftPoint(position);
    setBottomRightPoint(Vec2D(position.GetX() + width - 1, position.GetY() + height - 1));
}

Vec2D AARectangle::GetCenterPoint() const
{
    return Vec2D(getTopLeftPoint().GetX() + getWidth() / 2.0f, getTopLeftPoint().GetY() + getHeight() / 2.0f);
}

bool AARectangle::intersects(const AARectangle& otherRect) const
{
    return !(otherRect.getBottomRightPoint().GetX() < getTopLeftPoint().GetX() ||
             otherRect.getTopLeftPoint().GetX() > getBottomRightPoint().GetX() ||
             otherRect.getBottomRightPoint().GetY() < getTopLeftPoint().GetY() ||
             otherRect.getTopLeftPoint().GetY() > getBottomRightPoint().GetY());
}

bool AARectangle::containsPoint(const Vec2D& point) const
{
    bool withinX = point.GetX() >= getTopLeftPoint().GetX() && point.GetX() <= getBottomRightPoint().GetX();
    bool withinY = point.GetY() >= getTopLeftPoint().GetY() && point.GetY() <= getBottomRightPoint().GetY();

    return withinX && withinY;
}

AARectangle Inset(const AARectangle& rect, Vec2D& insets)
{
    return AARectangle(rect.getTopLeftPoint() + insets, rect.getWidth() - 2 * insets.GetX(), rect.getHeight() - 2 * insets.GetY());
}

std::vector<Vec2D> AARectangle::GetPoints() const
{
    std::vector<Vec2D> rectPoints;

    rectPoints.push_back(points[0]);
    rectPoints.push_back(Vec2D(points[1].GetX(), points[0].GetY()));
    rectPoints.push_back(points[1]);
    rectPoints.push_back(Vec2D(points[0].GetX(), points[1].GetY()));

    return rectPoints;
}

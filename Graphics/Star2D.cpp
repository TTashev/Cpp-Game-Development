#include "Star2D.h"

Star2D::Star2D()
{

}

Star2D::Star2D(const Vec2D& startPoint, const Vec2D& endPoint)
{
    firstLine = {startPoint, endPoint};
    secondLine = {startPoint, endPoint};
}

Star2D::~Star2D()
{

}

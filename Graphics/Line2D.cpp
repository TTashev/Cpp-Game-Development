#include "Line2D.h"
#include <cmath>
#include "../../Section-6-Full-Source/Utils/Utils.h"

Line2D::Line2D() : Line2D(Vec2D::Zero, Vec2D::Zero)
{

}

Line2D::Line2D(float x0, float y0, float x1, float y1) : Line2D(Vec2D(x0, y0), Vec2D(x1, y1))
{

}

Line2D::Line2D(const Vec2D& startPt, const Vec2D& endPt) : startPoint(startPt), endPoint(endPt)
{

}

Line2D::~Line2D()
{

}


bool Line2D::operator==(const Line2D& line) const
{
    return line.getStartPoint() == this->startPoint && line.getEndPoint() == this->endPoint;
}

float Line2D::minDistanceFrom(const Vec2D& p, bool limitToSegment) const
{
    return p.Distance(closestPoint(p, limitToSegment));
}

Vec2D Line2D::closestPoint(const Vec2D& p, bool limitToSegment) const
{
   Vec2D startPointToP = p - startPoint;

   Vec2D startPointToEndPoint = endPoint - startPoint;

   float l2 = startPointToEndPoint.Mag2();

   float dot = startPointToP.Dot(startPointToEndPoint);

   float t = dot / l2;

   if(limitToSegment)
   {
       t = std::fmax(0, std::fmin(1.0f, t));
   }

   return startPoint + startPointToEndPoint * t;
}

Vec2D Line2D::midPoint() const
{
    return Vec2D((startPoint.GetX() + endPoint.GetX()) / 2.0f,  (startPoint.GetY() + endPoint.GetY()) / 2.0f);
}

float Line2D::Slope() const
{
    float dx = endPoint.GetX() - startPoint.GetX();
    if(fabsf(dx) < EPSILON)
    {
        return 0;
    }

    float dy = endPoint.GetY() - startPoint.GetY();
    return dy / dx;
}

float Line2D::Length() const
{
    return endPoint.Distance(startPoint);
}

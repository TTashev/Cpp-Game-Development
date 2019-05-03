#ifndef LINE2D_H
#define LINE2D_H

#include "../../Section-6-Full-Source/Utils/Vec2D.h"

class Line2D
{
public:
    Line2D();
    Line2D(float x0, float y0, float x1, float y1);
    Line2D(const Vec2D& startPoint, const Vec2D& endPoint);
    ~Line2D();

    inline const Vec2D& getStartPoint() const {return startPoint;}
    inline const Vec2D& getEndPoint() const {return endPoint;}

    inline void setStartPoint(const Vec2D& startPt) {startPoint = startPt;}
    inline void setEndPoint(const Vec2D& endPt) {endPoint = endPt;}

    bool operator==(const Line2D& line) const;
    float minDistanceFrom(const Vec2D& p, bool limitToSegment = false) const;
    Vec2D closestPoint(const Vec2D& p, bool limitToSegment = false) const;

    Vec2D midPoint() const;
    float Slope() const;
    float Length() const;

private:
    Vec2D startPoint;
    Vec2D endPoint;
};

#endif // LINE2D_H

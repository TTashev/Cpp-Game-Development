#ifndef STAR2D_H
#define STAR2D_H

#include "Line2D.h"
#include "../../Section-6-Full-Source/Utils/Vec2D.h"


class Star2D
{
public:
    Star2D();
    Star2D(const Vec2D& startPoint, const Vec2D& endPoint);
    ~Star2D();

    Line2D firstLine;
    Line2D secondLine;
};

#endif // STAR2D_H

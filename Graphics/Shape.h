#ifndef SHAPE_H
#define SHAPE_H

#include "../../Section-6-Full-Source/Utils/Vec2D.h"
#include <vector>

class Shape
{
public:
    virtual ~Shape() {};
    virtual Vec2D GetCenterPoint() const = 0;
    inline virtual std::vector<Vec2D> GetPoints() const {return points;}
    void moveBy(const Vec2D& deltaOffset);

protected:
    std::vector<Vec2D> points;
};

#endif // SHAPE_H

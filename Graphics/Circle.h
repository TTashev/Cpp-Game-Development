#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
    Circle();
    Circle(const Vec2D& center, float radius);

    inline virtual Vec2D GetCenterPoint() const override {return points[0];}
    inline float getRadius() const {return radius;}
    inline void setRadius(float rad) {radius = rad;}
    inline void moveTo(const Vec2D& position) {points[0] = position;}

    bool intersects(const Circle& otherCircle) const;
    bool containsPoint(const Vec2D& point) const;

private:
    float radius;
};

#endif // CIRCLE_H

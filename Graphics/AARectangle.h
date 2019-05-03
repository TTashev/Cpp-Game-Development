#ifndef AARECTANGLE_H
#define AARECTANGLE_H

#include "Shape.h"

class AARectangle : public Shape
{
public:
    AARectangle();
    AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height);
    AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight);
    ~AARectangle();

    inline void setTopLeftPoint(const Vec2D& topLeft) {points[0] = topLeft;}
    inline void setBottomRightPoint(const Vec2D& bottomRight) {points[1] = bottomRight;}

    Vec2D getTopLeftPoint() const {return points[0];}
    Vec2D getBottomRightPoint() const {return points[1];}

    float getWidth() const;
    float getHeight() const;

    void moveTo(const Vec2D& position);

    virtual Vec2D GetCenterPoint() const override;

    bool intersects(const AARectangle& otherRect) const;
    bool containsPoint(const Vec2D& point) const;

    static AARectangle Inset(const AARectangle& rect, Vec2D& insets);

    virtual std::vector<Vec2D> GetPoints() const override;
};

#endif // AARECTANGLE_H

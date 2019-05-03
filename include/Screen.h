#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <stdint.h>
#include "ScreenBuffer.h"
#include "../Graphics/Color.h"

class Vec2D;
class Line2D;
class Triangle;
class AARectangle;
class Circle;
class Star2D;
struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:
    Screen();
    ~Screen();

    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
    void swapScreen();

    inline void setClearColor(const Color& clearCol) {clearColor = clearCol;}
    inline uint32_t Width() const {return width;}
    inline uint32_t Height() const {return heigth;}

    // draw shapes methods
    void Draw(int x, int y, const Color& color);
    void Draw(const Vec2D& point, const Color& color);
    void Draw(const Line2D& line, const Color& color);
    void Draw(const Star2D& star, const Color& color);
    void Draw(const Triangle& triangle, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const AARectangle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const Circle& circle, const Color& color, bool fill = false, const Color& fillColor = Color::White());

private:
    void ClearScreen();
    void FillPoly(const std::vector<Vec2D> points, const Color& color);

private:
    Screen(const Screen& screen);
    Screen& operator=(const Screen& screen);

    uint32_t width;
    uint32_t heigth;

    Color clearColor;
    ScreenBuffer backBuffer;

    SDL_Window * window;
    SDL_Surface * windowSurface;
};

#endif // SCREEN_H

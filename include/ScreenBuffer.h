#ifndef SCREENBUFFER_H
#define SCREENBUFFER_H

#include <stdint.h>

#include "../Graphics/Color.h"
struct SDL_Surface;

class ScreenBuffer
{
public:
    ScreenBuffer();
    ScreenBuffer(const ScreenBuffer& screenBuffer);
    ~ScreenBuffer();

    ScreenBuffer& operator=(const ScreenBuffer& ScreenBuffer);

    void Init(uint32_t format, uint32_t width, uint32_t height);

    inline SDL_Surface * GetSurface() {return surface;}

    void Clear(const Color& c = Color::Black());

    void setPixel(const Color& color, int x, int y);
private:
    SDL_Surface * surface;
    uint32_t GetIndex(int r, int c);
};

#endif // SCREENBUFFER_H

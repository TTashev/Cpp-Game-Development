#include "ScreenBuffer.h"
#include <SDL.h>
#include <cassert>

ScreenBuffer::ScreenBuffer() : surface(NULL) {}

ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer)
{
    surface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.surface->w, screenBuffer.surface->h, 0, screenBuffer.surface->format->format);

    SDL_BlitSurface(screenBuffer.surface, nullptr, this->surface, nullptr);
}

ScreenBuffer::~ScreenBuffer()
{
    if(surface)
    {
        SDL_FreeSurface(surface);
    }
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& ScreenBuffer)
{
    if(this == &ScreenBuffer)
    {
        return *this;
    }

    if(surface != NULL)
    {
        SDL_FreeSurface(surface);
        surface = NULL;
    }

    if(ScreenBuffer.surface != NULL)
    {
        this->surface = SDL_CreateRGBSurfaceWithFormat(0, ScreenBuffer.surface->w, ScreenBuffer.surface->h, 0, ScreenBuffer.surface->format->format);

        SDL_BlitSurface(ScreenBuffer.surface, NULL, surface, NULL);
    }

    return *this;
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height)
{
    surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
    Clear();
}

void ScreenBuffer::Clear(const Color& c)
{
    assert(surface);
    if(surface)
    {
        SDL_FillRect(surface, NULL, c.GetPixelColor());
    }
}

void ScreenBuffer::setPixel(const Color& color, int x, int y)
{
    assert(surface);
    if(surface && (y < surface->h && y >= 0 && x >= 0 && x < surface->w))
    {
        SDL_LockSurface(surface);

        uint32_t * pixels = (uint32_t*)surface->pixels;

        size_t index = GetIndex(y, x);

        pixels[index] = color.GetPixelColor();

        SDL_UnlockSurface(surface);
    }

}
size_t ScreenBuffer::GetIndex(int r, int c)
{
    assert(surface);
    return r * surface->w + c;
}

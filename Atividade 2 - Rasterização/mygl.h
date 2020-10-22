#ifndef MYGL_H
#define MYGL_H

#include <string.h>
#include <stdlib.h>
#include "core.h"
#include "frame_buffer.h"

struct _Color;  
typedef struct _Color Color;

struct _Pixel;  
typedef struct _Pixel Pixel;

void MyGlDraw(void);

void PutPixel(Pixel *p, Color *c);

void DrawLine(Pixel *p1, Pixel *p2, Color *c, Color *c1);

void DrawTriangle(Pixel *p1, Pixel *p2, Pixel *p3, Color *c, Color *c1);

float distanceBetweenPixels(Pixel *pixel1, Pixel *pixel2);

int squareRoot(int x);

Color* interpolColor(float p, Color *c, Color *c1);

#endif  // MYGL_H

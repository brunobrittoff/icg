#include "mygl.h"//// >>> Defina aqui as funções que você implementar <<< //

struct _Color {
    int r,g,b,a;
};

struct _Pixel{
    int x,y;
};

void PutPixel(Pixel *p, Color *c) {
         
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 0]  = c->r;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 1]  = c->g;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 2]  = c->b;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 3]  = c->a;
}

void DrawLine(Pixel *pixel1, Pixel *pixel2, Color *c, Color *c1) {
    
    int dx = (pixel2->x) - (pixel1->x);
    int dy = (pixel2->y) - (pixel1->y);
    int D = (2 * dx) - dy;
    int inc_E = 2 * dx;
    int inc_NE = 2 * (dx-dy);
    int posx = pixel1->x;
    int posy = pixel1->y;
    int fposx = pixel2->x;
    int fposy = pixel2->y;
    int xdecres;
    int ydecres;
    float distP;
    float distT = distanceBetweenPixels(pixel1,pixel2);
    
    Color *newcolor = (Color*)malloc(sizeof(Color));

    newcolor = c;
    
    if(posx > fposx) {
        xdecres = 1;
    }
    else {
        xdecres = 0;
    }
    if(posy > fposy) {
        ydecres = 1;
    }
    else {
        ydecres = 0;
    }
    
    if(dx == 0) {
        int posi = pixel1->y;
        if(posi > fposy) {
            int aux = posi;
            posi = fposy;
            fposy = aux;
            ydecres = 0;
        }
        while(posi <= fposy) {
            Pixel *pixelatual = (Pixel*)malloc(sizeof(Pixel));
            pixelatual->x = pixel1->x;
            pixelatual->y = posi;
            distP = distanceBetweenPixels(pixelatual,pixel2);
            newcolor = interpolColor(distP/distT,c,c1);
            PutPixel(pixelatual, newcolor);
            ydecres ? posi-- : posi++;
        }
        return;
    }

    if(dy == 0) {
        int posi = pixel1->x;
        if(posi > fposx) {
            int aux = posi;
            posi = fposx;
            fposx = aux;
            xdecres = 0;
        }
        while(posi <= fposx) {
            Pixel *pixelatual = (Pixel*)malloc(sizeof(Pixel));
            pixelatual->x = posi;
            pixelatual->y = pixel1->y;
            distP = distanceBetweenPixels(pixelatual,pixel2);
            newcolor = interpolColor(distP/distT,c,c1);
            PutPixel(pixelatual, newcolor);
            xdecres ? posi-- : posi++;
        }
        return;
    }    

    if(dy>dx) {
        if(dx < 0) {
            dx *= -1;
        }
        D = (2*dx) - dy;
        inc_E = 2 * dx;
        inc_NE = 2 * (dx - dy);
        while (posy != fposy) {
            if(D <= 0) {
                D += inc_E;
                if(ydecres == 1) {
                    posy--;
                }
                else {
                    posy++;
                }
            }
            else {
                D += inc_NE;
                if(ydecres == 1) {
                    posy--;
                }
                else{
                    posy++;
                }
                if(xdecres == 1) {
                    posx--;
                }
                else {
                    posx++;
                }
            }
            Pixel *pixelatual = (Pixel*)malloc(sizeof(Pixel));
            pixelatual->x = posx;
            pixelatual->y = posy;
            distP = distanceBetweenPixels(pixelatual,pixel2);
            newcolor = interpolColor(distP/distT,c,c1);
            PutPixel(pixelatual, newcolor);
        } 

        return;
    }

    else if(dx>=dy) {
        if(dy < 0) {
            dy *= -1;
        }
        D = (2*dy) - dx;
        inc_E = 2 * dy;
        inc_NE = 2 * (dy - dx);
        while (posx != fposx) {
            if(D <= 0) {
                D += inc_E;
                if(xdecres == 1) {
                    posx--;
                }
                else {
                    posx++;
                }
            }
            else {
                D += inc_NE;
                if(ydecres == 1) {
                    posy--;
                }
                else{
                    posy++;
                }
                if(xdecres == 1) {
                    posx--;
                }
                else {
                    posx++;
                }
            }
            Pixel *pixelatual = (Pixel*)malloc(sizeof(Pixel));
            pixelatual->x = posx;
            pixelatual->y = posy;
            distP = distanceBetweenPixels(pixelatual,pixel2);
            newcolor = interpolColor(distP/distT,c,c1);
            PutPixel(pixelatual, newcolor);
        } 

        return;
    }
         
}

void DrawTriangle(Pixel *p1, Pixel *p2, Pixel *p3, Color *c, Color *c1) {
    DrawLine(p1, p2, c, c1);
    DrawLine(p2, p3, c, c1);
    DrawLine(p3, p1, c, c1);
}

float distanceBetweenPixels(Pixel *pixel1, Pixel *pixel2){
    return squareRoot((pixel2->x-pixel1->x)*(pixel2->x-pixel1->x)+(pixel2->y-pixel1->y)*(pixel2->y-pixel1->y));
}

int squareRoot(int x) 
{ 
    if (x == 0 || x == 1) 
    return x; 

    int i = 1, result = 1; 
    while (result <= x) 
    { 
      i++; 
      result = i * i; 
    } 
    return i - 1; 
}

Color* interpolColor(float p, Color *c, Color *c1) {
    Color *newcolor = (Color*)malloc(sizeof(Color));
    newcolor->r = c->r*p + (1-p)*c1->r;
    newcolor->g = c->g*p + (1-p)*c1->g;
    newcolor->b = c->b*p + (1-p)*c1->b;
    newcolor->a = c->a*p + (1-p)*c1->a;
    return newcolor;
}

void MyGlDraw(void) {
    
    Pixel *pontoInicial = (Pixel*)malloc(sizeof(Pixel));
    Pixel *pontoFinal = (Pixel*)malloc(sizeof(Pixel));
    Pixel *pontoMedio = (Pixel*)malloc(sizeof(Pixel));
    Color *c = (Color*)malloc(sizeof(Color));
    Color *c1 = (Color*)malloc(sizeof(Color));
        
    pontoInicial->x = 150;
    pontoInicial->y = 150;   
    pontoMedio->x = 150;
    pontoMedio->y = 400;
    pontoFinal->x = 400;
    pontoFinal->y = 150;
    c->r = 0;
    c->g = 0;
    c->b = 255;
    c->a = 255;
    c1->r = 255;
    c1->g = 0;
    c1->b = 0;
    c1->a = 255;
    

    DrawTriangle(pontoInicial, pontoMedio, pontoFinal, c, c1);

    free(pontoInicial);
    free(pontoMedio);
    free(pontoFinal);
    free(c);
    free(c1);
}



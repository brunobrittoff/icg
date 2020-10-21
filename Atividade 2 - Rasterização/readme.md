# Rasterização - Atividade 2

## Sobre a atividade
A atividade tem como objetivo o aprendizado sobre algoritmos de rasterização através da implementação de funções para rasterizar pixels, linhas e triângulos. Como pedido pelo professor, apenas os arquivos mygl.h e mygl.c foram alterados.

## Função PutPixel
Para que seja rasterizado um ponto, é necessária a criação da função PutPixel. Essa função recebe por parâmetros uma estrutura "Pixel", que contém dois inteiros x e y, que seriam as coordenadas do pixel, e uma estrutura "Color", que contém sua cor. Seu código ficou da seguinte forma:

~~~ 
void PutPixel(Pixel *p, Color *c) {
         
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 0]  = c->r;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 1]  = c->g;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 2]  = c->b;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 3]  = c->a;
}
~~~

## Função DrawLine
A função DrawLine foi feita com base no algoritmo passado pelo professor na aula 06 - Rasterização de Linhas, utilizando o Algoritmo do Ponto Médio. Para essa função, ela recebe por parâmetros duas estruturas Pixel e duas estruturas Color. Como a função ficou muito grande, deixarei apenas o que tem no arquivo mygl.h, mas a função completa está na mygl.c

~~~
void DrawLine(Pixel *pixel1, Pixel *pixel2, Color *c, Color *c1);
~~~

## Função DrawTriangle
A função DrawTriangle recebe por parâmetros três estruturas Pixel, responsáveis por rasterizar as retas, e duas estruturas Color, responsáveis por suas cores.
~~~
void DrawTriangle(Pixel *p1, Pixel *p2, Pixel *p3, Color *c, Color *c1) {
    DrawLine(p1, p2, c, c1);
    DrawLine(p2, p3, c, c1);
    DrawLine(p3, p1, c, c1);
}
~~~

Após isso, obtive o seguinte resultado:

![image](https://user-images.githubusercontent.com/72406702/96665696-db60ae80-132b-11eb-8e74-d6ee8fe97252.png)

## Dificuldades Encontradas
No meu caso, a maior dificuldade foi na questão da implementação do Algoritmo do Ponto Médio e na Interpolação de Cores, que não consegui realizar. Ao tentar compilar meu código, os triângulos permaneciam nas mesmas cores e infelizmente não consegui resolver a tempo.
  
## Referências
Site utilizado: <http://disciplinas.ist.utl.pt/leic-cg/textos/livro/Rasterizacao.pdf>

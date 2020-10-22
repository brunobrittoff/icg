# Rasterização - Atividade 2

## Sobre a atividade
A atividade tem como objetivo o aprendizado sobre algoritmos de rasterização através da implementação de funções para rasterizar pixels, linhas e triângulos. Como pedido pelo professor, apenas os arquivos mygl.h e mygl.c foram alterados.

## Estruturas Criadas
Para o desenvolvimento da atividade, criei duas estruturas, a estrutura Color e a estrutura Pixel. Na estrutura Color, foram criados quatro inteiros (r,g,b,a) referentes as cores, já na estrutura Pixel, foram criados dois inteiros, x e y, referentes às coordenadas de cada pixel. Seus códigos ficaram assim:
~~~
struct _Color {
    int r,g,b,a;
};
~~~

~~~
struct _Pixel{
    int x,y;
};
~~~
## Estruturas Auxiliares
<p style='text-align: justify;'> Para desenvolver a atividade, eu criei duas funções, a squareRoot e a distanceBetweenPixels, para evitar o uso da biblioteca math. A função squareRoot faz o cálculo da raiz quadrada sem utilizar o sqrt, já a função distanceBetweenPixels realiza o cálculo da hipotenusa. Seus códigos ficaram da seguinte forma: </p>


~~~
int squareRoot(int x) { 
    
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
~~~

~~~
float distanceBetweenPixels(Pixel *pixel1, Pixel *pixel2) {
    return squareRoot((pixel2->x-pixel1->x)*(pixel2->x-pixel1->x)+(pixel2->y-pixel1->y)*(pixel2->y-pixel1->y));
}
~~~


## Função PutPixel
Para que seja rasterizado um ponto, é necessária a criação da função PutPixel. Essa função recebe por parâmetro uma estrutura "Pixel", que contém dois inteiros x e y, que seriam as coordenadas do pixel, e uma estrutura "Color", que contém sua cor. Seu código ficou da seguinte forma:

~~~ 
void PutPixel(Pixel *p, Color *c) {
         
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 0]  = c->r;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 1]  = c->g;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 2]  = c->b;
    fb_ptr[4*(p->x) + 4*(p->y)*IMAGE_WIDTH + 3]  = c->a;
}
~~~

Após utilizá-la, obtive o seguinte resultado:


![image](https://user-images.githubusercontent.com/72406702/96666489-9fc6e400-132d-11eb-8ec0-a1df90aaaefe.png)

## Função DrawLine
A função DrawLine foi feita com base no algoritmo passado pelo professor na aula 06 - Rasterização de Linhas, utilizando o Algoritmo do Ponto Médio. Para essa função, ela recebe por parâmetro duas estruturas Pixel e duas estruturas Color. Como a função ficou muito grande, deixarei apenas o que tem no arquivo `mygl.h`, mas a função completa está na `mygl.c`.

~~~
void DrawLine(Pixel *pixel1, Pixel *pixel2, Color *c, Color *c1);
~~~
Ao utilizar a função, obtive o seguinte resultado:


![Captura de tela de 2020-10-20 23-43-59](https://user-images.githubusercontent.com/72406702/96666951-76f31e80-132e-11eb-9320-8d219a531d57.png)

## Função DrawTriangle
A função DrawTriangle recebe por parâmetro três estruturas Pixel, que formam os vértices do triângulo, e duas estruturas Color, responsáveis por suas cores.
~~~
void DrawTriangle(Pixel *p1, Pixel *p2, Pixel *p3, Color *c, Color *c1) {
    DrawLine(p1, p2, c, c1);
    DrawLine(p2, p3, c, c1);
    DrawLine(p3, p1, c, c1);
}
~~~
Após isso, obtive o seguinte resultado:

![image](https://user-images.githubusercontent.com/72406702/96665696-db60ae80-132b-11eb-8e74-d6ee8fe97252.png)

## Função interpolColor
A função interpolColor recebe por parâmetro um float p, que representa em que parte da reta o algoritmo está e atribuir a cor correta ao pixel correspondente, e duas estruturas Color, que serão responsáveis pela cor atual e final.

~~~
Color* interpolColor(float p, Color *c, Color *c1) {
    Color *newcolor = (Color*)malloc(sizeof(Color));
    newcolor->r = c->r*p + (1-p)*c1->r;
    newcolor->g = c->g*p + (1-p)*c1->g;
    newcolor->b = c->b*p + (1-p)*c1->b;
    newcolor->a = c->a*p + (1-p)*c1->a;
    return newcolor;
}
~~~

## Dificuldades Encontradas
No meu caso, a maior dificuldade foi na questão da implementação do Algoritmo do Ponto Médio e na Interpolação de Cores. Durante o Algoritmo do Ponto Médio, o maior problema foi sua generalização para os demais octantes. Em um exemplo, o seguinte erro acontecia ao tentar printar para o oitavo octante.

![TentandoPrintarSudoeste](https://user-images.githubusercontent.com/72406702/96927363-52618880-148d-11eb-9dd9-9256e7f8538d.png)

Ao realizar as correções, ele continuou na horizontal, mas foi apenas um erro de desatenção. Ao corrigir, obtive o seguinte resultado, junto com o algoritmo de interpolação de iores:

![Captura de tela de 2020-10-22 17-43-11](https://user-images.githubusercontent.com/72406702/96927913-2c88b380-148e-11eb-9339-886d1b6e0e60.png)

Durante a função de intepolação de cores, ao tentar compilar o código, os triângulos permaneciam nas mesmas cores, e ao pesquisar sobre o cálculo de distância entre dois pontos, entendi como poderia ser feito. No entanto, como eu não sabia se poderia usar o `#include <math.h>`, pesquisei uma função que fizesse a mesma coisa que a função sqrt. Porém, ao implementar, o terminal crashou e ficou assim:

![DeuPregoNaPrecisao](https://user-images.githubusercontent.com/72406702/96928578-26df9d80-148f-11eb-9675-abfd76f9c3ce.png)

Em seguida, consegui arrumar pois era um problema com a variável precisão no código, devido ao alto custo computacional causado pelos pontos flutuantes. Ao trocar, o programa funcionou, porém com as cores erradas: 

![image](https://user-images.githubusercontent.com/72406702/96928755-702fed00-148f-11eb-94a6-511c45db4c10.png)

Para corrigir isso, foi simples, eu esqueci de realizar uma multiplicação dentro da função de interpolação de cores e, ao realizar a correção, obtive o resultado final:

![ResultadoFinal](https://user-images.githubusercontent.com/72406702/96929604-c05b7f00-1490-11eb-94e2-eb9d82269fc8.png)

Portanto, pode-se perceber que a atividade foi concluída com sucesso, com a formação de triângulos correta e as cores interpoladas.

## Possíveis melhoras
* Fazer um triângulo com interpolação contínua para melhorar a estética da imagem gerada.
* Fazer o algoritmo para outras estruturas geométricas.
* Interpolar mais de três cores.

## Referências
Sites utilizados:

<http://disciplinas.ist.utl.pt/leic-cg/textos/livro/Rasterizacao.pdf>

<https://www.geeksforgeeks.org/square-root-of-an-integer/>

<https://brasilescola.uol.com.br/matematica/distancia-entre-dois-pontos.htm>

## 

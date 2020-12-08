# Transformations - Atividade 3

## Sobre a atividade
A atividade tem como objetivo de aplicar o conhecimento obtido em aula sobre a estrutura do pipeline gráfico e treinar a implementação de transformações geométricas. Para isso, foi necessário instalar as seguintes dependências para utilizar o código template disponibilizado pelo professor. 

* GLEW
* glm

Após a instalação das dependências necessárias, primeiro foi necessário checar se estava funcionando. Para isso, foi utilizado o arquivo **Makefile** para compilar, e a execução foi dada pelo comando `./transform_gl`. 

Resultando na seguinte imagem:

![ATIVIDADEICGINICIO](https://user-images.githubusercontent.com/72406702/101526790-e323f300-396b-11eb-899d-ec7629eaa16b.png)

## Exercício 1
Para a resolução do primeiro exercício, foi necessário efetuar uma mudança na **matriz model**, com fatores de escala (x,y,z) = (1/3,3/2,1) para que seja gerada a imagem solicitada na atividade, a figura 5. O código ficou dessa forma:

![CODIGOEXERCICIO1](https://user-images.githubusercontent.com/72406702/101527294-912f9d00-396c-11eb-9dc5-5d41b3bdb903.png)

Gerando a seguinte imagem:

![ATIVIDADEICGEXERCICIO1](https://user-images.githubusercontent.com/72406702/101527385-b4f2e300-396c-11eb-98b0-14b3cb775dbe.png)

## Exercício 2
Para a resolução do segundo exercício, foi necessário efetuar uma mudança na **matriz model**, com translações em (x,y,z) = (1,0,0), para que seja gerada a imagem solicitada na atividade, a figura 6. O código ficou dessa forma:

![CODIGOEXERCICIO2](https://user-images.githubusercontent.com/72406702/101528181-b83a9e80-396d-11eb-8bcd-616748a3a0a0.png)

Gerando a seguinte imagem:

![ATIVIDADEICGEXERCICIO2](https://user-images.githubusercontent.com/72406702/101528242-d30d1300-396d-11eb-85dc-6d5b9531573b.png)

## Exercício 3
Para a resolução do terceiro exercício, foi necessário efetuar uma mudança na **matriz projection**, com parâmetro d = 1/8, para que seja gerada a imagem solicitada na atividade, a figura 7. O código ficou dessa forma:

![CODIGOEXERCICIO3](https://user-images.githubusercontent.com/72406702/101528818-8970f800-396e-11eb-881b-ddcc27472b11.png)

Gerando a seguinte imagem:

![ATIVIDADEICGEXERCICIO3](https://user-images.githubusercontent.com/72406702/101529137-eec4e900-396e-11eb-9132-38bd0441b2d2.png)

## Exercício 4
Para a resolução do quarto exercício, baseado nas teorias passadas pelo professor durante as aulas, foi necessário adicionar mais código. Para que seja gerada a imagem solicitada na atividade, a figura 8, foram adicionadas informações como: a posição da câmera = (-1/10,1/10,1/10), o vetor up da câmera = (0,1,0) e o ponto  para  o  qual a câmera está apontando = (0,0,−1). O código ficou dessa forma:

![CODIGOEXERCICIO4](https://user-images.githubusercontent.com/72406702/101538019-423d3400-397b-11eb-99f1-5ac3a3498baf.png)

Gerando a seguinte imagem:

![ATIVIDADEICGEXERCICIO4](https://user-images.githubusercontent.com/72406702/101538065-55e89a80-397b-11eb-9a27-7276c800be0f.png)

## Exercício 5
Para a resolução do quinto exercício, existiam duas condições: Modificar as 3 matrizes para formar uma nova cena e ser diferente das cenas apresentadas anteriormente. Para realizar o exercício, fui fazendo na seguinte sequência: modificar a matriz model, para realizar uma rotação de 270°, modificar a matriz view, para modificar a escala, e modificar a matriz projection, para realizar uma translação com Tx = 0.2, Ty = 5.0 e d = 1/5. Uma opção também seria alterar a câmera.

### Modificando a matriz model

![EXERCICIO5ROTAÇAO270](https://user-images.githubusercontent.com/72406702/101538837-68af9f00-397c-11eb-9daf-1b1059c82530.png)

Gerando a seguinte imagem:

![ROTACAOMODEL270](https://user-images.githubusercontent.com/72406702/101538877-76652480-397c-11eb-9265-40ee8e9913ea.png)

### Modificando a matriz view

![EXERCICIO5ESCALAVIEW](https://user-images.githubusercontent.com/72406702/101538947-8a108b00-397c-11eb-8096-180915fea7ab.png)

Gerando a seguinte imagem:

![EXERCICIO5MODEL+VIEWESCALA](https://user-images.githubusercontent.com/72406702/101539007-9a286a80-397c-11eb-8f63-93b495f91db5.png)

### Modificando a matriz projection

![EXERCICIO5PROJARRAY](https://user-images.githubusercontent.com/72406702/101539158-d3f97100-397c-11eb-9c33-fa0e13265730.png)

Gerando a seguinte imagem:

![EXERCICIOMODELROTACAO+VIEWESCALA+PROJTRANSLACAO](https://user-images.githubusercontent.com/72406702/101539328-2175de00-397d-11eb-9347-e7c9a8abded2.png)

### Modificando os valores da câmera

Caso queira alterar os valores da câmera, uma idéia seria os seguintes valores:

![EXERCICIO5COMALTERAÇÃOCAMERA](https://user-images.githubusercontent.com/72406702/101540687-1f148380-397f-11eb-8d46-06700aa7ac05.png)

Teríamos a seguinte imagem gerada:

![EXERCICIO5COMCAMERA](https://user-images.githubusercontent.com/72406702/101540700-2b004580-397f-11eb-8431-779cd672f7d7.png)

## Dificuldades Encontradas
No meu caso, tive dificuldade nos exercícios 1, 2 e 3, por não ter atentado ao fato de a glm implementar as matrizes internamente no formato column major. Por esse motivo, as imagens estavam saindo bem diferentes. No quinto exercício, a maior dificuldade foi entender o enunciado, se seriam três alterações individuais, gerando três imagens diferentes, ou se seriam três alterações para gerar apenas uma imagem. No quarto, foi pesquisar como funcionava a `glm::vec3`, como seria feito o vetor com os valores da posição da camera, do up da camera e para a posição que ela aponta e para montar a matriz do `glm::mat4`, para poder realizar a multiplicação das matrizes no final.

## Possíveis melhoras
* Organização do código.
* Tentar fazer a câmera ficar rotacionando.
* Tentar com outras imagem, além dos triângulos.


## Referências
Sites utilizados:

<http://www.lapix.ufsc.br/ensino/computacao-grafica/transformacoes-geometricas-2d-e-coordenadas-homogeneas/>

<http://www.ic.uff.br/~anselmo/cursos/CGI/slidesGrad/CG_aula10(transformacoesnoespaco).pdf>

<https://learnopengl.com>

## 

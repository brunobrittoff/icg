# Compilando e Executando um Programa OpenGL Moderno

## Sobre a atividade
A atividade a seguir tem como objetivo verificar se o ambiente de desenvolvimento em OpenGL 3.3 está corretamente configurado no computador dos alunos e familizarizar os alunos com a estrutura de um programa OpenGL moderno. Para isso, deve-se instalar o OpenGL na máquina, compilar e executar o seguinte programa:

![image](https://user-images.githubusercontent.com/72406702/95122270-9e3ece80-0726-11eb-9619-2af969afdb42.png)

## Configuração
Inicialmente, tentei instalar e configurar o OpenGL no Windows10, tentando executar o programa através do VSCode. No entanto, aconteceram vários erros e não consegui executá-lo. Com isso, migrei para o sistema operacional Linux Mint, onde consegui configurar e rodar sem muita dificuldade.
Com isso em vista, instalei o OpenGL no Linux Mint utilizando os seguintes códigos (em sequência):

~~~ 
sudo apt-get update
sudo apt-get install freeglut3
sudo apt-get install freeglut3-dev
sudo apt-get install binutils-gold
sudo apt-get install g++ cmake
sudo apt-get install libglew-dev
sudo apt-get install g++
sudo apt-get install mesa-common-dev
sudo apt-get install mesa-common-dev
sudo apt-get install libglew1.5-dev libglm-dev
~~~

## Execução
Para rodar o programa, precisei executar os comandos:

~~~
gcc main.c -o exerc -lglut -lGLU -lGL (main.c é o arquivo principal e o exerc é o programa executável)
~~~
~~~
./exerc
~~~

Após isso, obtive o seguinte resultado:

![TerminalOpenGL1](https://user-images.githubusercontent.com/72406702/95121387-5bc8c200-0725-11eb-91bd-40d4b2df268d.png)

![TerminalOpenGL2](https://user-images.githubusercontent.com/72406702/95121540-8dda2400-0725-11eb-81c8-785b9601a9d9.png)

Com isso, percebe-se que o programa compilou e executou com sucesso. 

## Conclusão
Portanto, no meu caso, a maior dificuldade foi configurar o OpenGL usando o Windows junto com o VSCode, onde a maioria dos erros eram por não encontrar o caminho certo para as bibliotecas do OpenGL, e, além disso, não consegui encontrar possíveis soluções para esse problema. Ao mudar para o LinuxMint, encontrei vários tutoriais que foram de suma importância para que eu obtivesse êxito na instalação e, posteriormente, na compilação e execução do programa, apesar de nunca ter utilizado o LinuxMint.
  
## Referências
Site utilizado: <https://pt.wikihow.com/Instalar-Mesa-(OpenGL)-no-Linux-Mint>

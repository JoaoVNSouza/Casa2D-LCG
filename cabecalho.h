#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

// Constantes.
#define win 100 // Constante que armazena o valor de coordenadas para orientação x.

// Variáveis globais.
GLfloat width, height; // Armazena o tamanho da janela, para eventos de redimensionar a janela.

/* Protótipos de Funções/Procedimentos. */
// Rotinas callbacks.
static void resize(int, int);
static void display();
static void key(unsigned char, int, int);

// Rotinas diversos.
void inicializa();

// Primitivas.
void Quadrado();
void Triangulo();

#endif // CABECALHO_H_INCLUDED

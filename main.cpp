/*
 * Universidade Federal da Grande Dourados - UFGD.
 * Faculdade de Ciências Exatas e Tecnologia - FACET.
 * Bacharelado em Engenharia de Computação.
 *
 * Disciplina: Laboratório de Computação Gráfica - LCG.
 * Professor: Adailton José Alves da Cruz.
 * Período: semestre 2022.1 || ocorrência no 2º semestre do ano de 2022.
 *
 * Programa: main.cpp
 * Desenvolvido por: João Vitor Nascimento De Souza.
 *
 * Objetivo: Desenhar uma casa utilizando:
 * - Primitivas (quadrado e triângulo).
 * - Transformações geométricas e de coordenadas.
 * Referência: Autoria própria.
 */

// Bibliotecas utilizadas.
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include "cabecalho.h"

/*
 * Função principal: responsável pela execução do programa do início ao fim.
 * Entrada: argumentos passados pelos prompt de comando.
 * Saída:
 * - EXIT_SUCESS: finalizado corretamente.
 * - Outros valors: ocorrência de erros na execução.
 */
int main(int argc, char *argv[])
{
    inicializa();                                // Inicializa variáveis.
    glutInit(&argc, argv);                       // Inicicializa com os argumentos passados no prompt de comando.
    glutInitWindowSize(width, height);           // Define o tamanho da janela em pixels.
    glutInitWindowPosition(300, 200);            // Define a posição do canto superior esquerda da janela.
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Descreve as configurações da janela (cores suportadas e suas características).
    glutCreateWindow("Casa 2D");                 // Cria a janela e inseri um título.

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Seleciona a cor de fundo para limpeza da tela (R, G, B, A).

    /*
     * Rotinas callback:
     *  Se ocorrer um evento de sistema devido a interação com a janela criada
     *  aciona uma dessas rotinas, executando suas funções internas.
     */
    glutReshapeFunc(resize);  // Executa o procedimento resize.
    glutDisplayFunc(display); // Executa o procedimento display.
    glutKeyboardFunc(key);    // Executa o procedimento key.

    glutMainLoop(); // Mantém o programa executando em loop, aguardando a ocorrência de novos eventos com a janela.

    return EXIT_SUCCESS;
}

// Funções/Procedimentos das rotinas callback.

/*
 * Função responsável por adaptar a janela de visualização (Viewport) e os elementos contidos na janela (Projeção),
 * caso ocorra um evento de redimensionamento de janela.
 * Entrada:
 *  - w: nova largura.
 *  - h: nova altura.
 */
static void resize(int w, int h)
{
    width = w;
    height = h;

    glViewport(0, 0, width, height); // Porta de visualização, onde será feitos os desenhos dos elementos.
    glMatrixMode(GL_PROJECTION);     // Inicializa os valores de visualização.
    glLoadIdentity();                // Faz com que a matriz corrente seja inicializada com a matriz identidade.

    // Se ocorrer de altura ser 0, altera é pelo menos 1.
    if (height == 0)
        height = 1;

    // Difine o limites para as coordenadas da janela (RANGE em 2D).
    if (width <= height)
        gluOrtho2D(-win, win, -win * height / width, win * height / width);
    else
        gluOrtho2D(-win * width / height, win * width / height, -win, win);
}

/*
 * Procedimento responsável por executar instruções caso ocorra o pressionamento de teclas na janela exibida.
 * Entrada: uma tecla digitada.
 * - "ESC" ou "q": fecha o programa.
 * - "o": volta o programa como original.
 * Saída: Executa uma instrução.
 */
static void key(unsigned char letra, int x, int y)
{
    switch (letra)
    {
    case 27:
    case 'q':
    case 'Q':
        exit(0);
        break;
    default:
        break;
    }

    glutPostRedisplay(); // Atualiza o display a cada evento do teclado.
}

/*
 * Procedimento responsável por atualizar o display da janela.
 *  -> Mostra todos os desenhos.
 */
static void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cores atual da janela.

    glMatrixMode(GL_MODELVIEW); // Matriz corrente, contendo todas as transformações geométricas em um determinado momento.
    glLoadIdentity();           // Faz com que a matriz corrente seja inicializada com a matriz identidade.

    /* Utiliza transformações de COORDENADAS. */

    // eixos 1
    glTranslatef(-50, -25, 0);
    glScalef(0.1, 0.3, 1); // Eixos agora serão reduzidos, fazendo com que as coordenadas da janela aumentem.
    glColor3f(1, 0, 0);    // Vermelho.
    Quadrado();

    // eixos 2
    glTranslatef(400, 0, 0);
    Quadrado();

    // eixos 3
    glTranslatef(200, 50, 0);
    glScalef(1, 0.5, 1);
    Quadrado();

    // eixos 4
    glTranslatef(400, 0, 0);
    Quadrado();

    // eixos 5
    glTranslatef(-200, -200, 0);
    glScalef(3, 1, 1);
    Quadrado();

    // eixos 6
    glTranslatef(-200, 300, 0);
    glScalef(1, 2, 1);
    Triangulo();

    // eixos 7
    glRotatef(90, 0, 0, 1);
    Triangulo();

    // eixos 8
    glTranslatef(100, -100, 0);
    glRotatef(90, 0, 0, 1);
    glColor3f(0, 0, 1); // Azul.
    Triangulo();

    // eixos 9
    glTranslatef(-100, 0, 0);
    Triangulo();

    // eixos 10
    glTranslatef(100, 100, 0);
    glRotatef(180, 0, 0, 1);
    Triangulo();

    // eixos 11
    glTranslatef(100, 0, 0);
    Triangulo();

    glFlush(); // Faz os comandos não executados serem executados.
}

// Funções/Procedimentos.

/*
 * Inicialização das variáveis globais.
 */
void inicializa()
{
    width = 1000;
    height = 500;
}

/*
 * Desenha um quadrado de lado 200.
 */
void Quadrado()
{
    glBegin(GL_QUADS);
    glVertex2f(-100, -100);
    glVertex2f(-100, 100);
    glVertex2f(100, 100);
    glVertex2f(100, -100);
    glEnd();
}

/*
 * Desenha Triangulo no quadradante positivo.
 */
void Triangulo()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(100, 0);
    glVertex2f(0, 100);
    glEnd();
}

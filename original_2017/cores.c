#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include "cores.h"

/**
 * Muda a cor do texto que ser� impresso ap�s este comando. Afeta
 * todas as fun��es de console (printf, puts, putc, etc.)
 * @param ForgC N�mero da cor
 * @return
 **/
void SetColor(int ForgC)
{
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //muda o cor do texto sem alterar a cor do fundo
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

/**
 * Muda a cor do fundo texto que ser� impresso ap�s este comando.
 * Afeta todas as fun��es de console (printf, puts, putc, etc.)
 * @param BackC N�mero da cor
 * @return
 **/
void SetBack(int BackC)
{
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //muda a cor do fundo sem alterar a cor do texto
          wColor = (csbi.wAttributes & 0x0F) + ((BackC & 0x0F) << 4);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

/**
 * Desloca o cursor at� uma determinada coordenada no console. Texto
 * impresso depois desse comando come�ar� nesta posi��o.
 * @param x Coluna
 * @param y Linha
 * @return
 **/
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


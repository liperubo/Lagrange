// ------------------------- Cabeçalho --------------------------- //
/*Projeto Lagrange - Métodos Númericos

Integrantes:
Felipe Eler de Oliveira Machado 200738
Felipe Victorino Sarubo 200574

Turma: CP004TIM2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ------------------------- Estruturas --------------------------- //

typedef struct Lagrange
{
	float x;
  float y;
} Lagrange;

// ------------------------- Protótipos de Funções ---------------- //

void alocaLagrange(Lagrange **p, int tam);

// ------------------------- Main --------------------------------- //

int main()
{
  Lagrange *pLagr = NULL;
  int n, i = 0, j = 0;
  float A = 1, B = 1, C = 0, x;

  //Receber o numero de pontos (n)
  printf("\nDigite a quantidade de pontos na tabela: ");
  scanf("%i",&n);
  fflush(stdin);

  alocaLagrange(&pLagr, n);

  //Loop (For i=n):
  for (i = 0; i < n; i++)
  {
    //Receber os pontos no formato [x y]
    printf("Digite o %io ponto no formato [x y]: ", i+1);
    scanf("%f %f",&((pLagr+i)->x), &((pLagr+i)->y));
    fflush(stdin);
  }

  printf("\nx\ty");
  for (i = 0; i < n; i++)
  {
    printf("\n%.3f %.3f", (pLagr+i)->x, (pLagr+i)->y);
  }
  
  //Receber o valor a ser interpolado (x)
  printf("\n\nDigite o valor a ser interpolado: ");
  scanf("%f",&x);
  fflush(stdin);

  //Loop (For i<n):
  for (i = 0; i < n; i++)
  {
    A = 1;
    B = 1;
    //Loop (For j<n):
    for (j = 0; j < n; j++)
    {
      //Se(i != j):
      if (i != j)
      {
        //Calcular A (A * (x - Lagr[j].x))
        A = A * (x - (pLagr+j)->x);
        //Calcular B (B * (Lagr[i].x - Lagr[j].x))
        B = B * ((pLagr+i)->x - (pLagr+j)->x);
      }
    }
    //Calcular C (C + ((A/B)*Lagr[i].y))
    C = C + ((A/B)*(pLagr+i)->y);
  }
  //"O valor interpolado: C"
  printf("O valor interpolado: %.3f", C);
  return 0;
}

// ------------------------- Funções ------------------------------ //

void alocaLagrange(Lagrange **p, int m)
{
	if ((*p = (Lagrange *)realloc(*p, m * sizeof(Lagrange))) == NULL)
	{
		printf("\nErro na alocacao. O programa sera encerrado!");
		exit(1);
	}
}

// ------------------------- To Do List --------------------------- //
/*
Processamento:
  Receber os pontos:
    Receber o numero de pontos (n)
    Loop (For i=n):
      Receber os pontos no formato [x y]
  Receber o valor a ser interpolado (x)
  Loop (For i<n):
    Loop (For j<n):
      Se(i != j):
        Calcular A (A * (x - Lagr[j].x))
        Calcular B (B * (Lagr[i].x - Lagr[j].x))
    Calcular C (C + ((A/B)*Lagr[i].y))
  "O valor interpolado é: C"
*/
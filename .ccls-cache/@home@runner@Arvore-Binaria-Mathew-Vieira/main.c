#include "btree.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int n;

  printf("Informe o tamanho do vetor: ");
  scanf(" %d", &n);

  long vetor[n];

  printf("\nPreencha o vetor... \n");

  for (int i = 0; i < n; i++) {
    printf("└── Posição %d: ", i);
    scanf(" %ld", &vetor[i]);
  }

  struct No *raiz = preencherArvoreComArray(vetor, 0, n);
  
  int altura = calcularAltura(raiz), nivMax = altura - 1, opcao, tempInfo;
  bool sair = false;

  printf("\nÁrvore preenchida! \n");

  printLinhaInicio();
  printArvore(raiz, 0);

  printLinhaInicio();
  printEhArvoreCheia(raiz);
  printAltura(raiz);
  printNivMax(raiz);

  printPause();
  printLinhaFim();

  while (!sair) {
    printf("\n\n");
    printf("1. Procurar Nó \n");
    printf("2. Exibir em Pré-ordem \n");
    printf("3. Exibir em Em-ordem \n");
    printf("4. Exibir em Pós-ordem \n");
    printf("5. Sair");
    printf("\n\n");

    printf("Aguardando opção: ");
    scanf(" %d", &opcao);

    switch (opcao) {
    case (1):
      printf("\nInforme o Valor que deja procurar: ");
      scanf(" %d", &tempInfo);

      printLinhaInicio();
      printProcurarNoPorInfo(raiz, tempInfo);
      printPause();
      printLinhaFim();
      break;

    case (2):
      printLinhaInicio();
      printPreOrdemComMsg(raiz);
      printPause();
      printLinhaFim();
      break;

    case (3):
      printLinhaInicio();
      printEmOrdemComMsg(raiz);
      printPause();
      printLinhaFim();
      break;

    case (4):
      printLinhaInicio();
      printPosOrdemComMsg(raiz);
      printPause();
      printLinhaFim();
      break;

    case (5):
      sair = true;
      break;

    default:
      printLinhaFim();
    }
  }

  return 0;

  /*
  struct No *raiz = addNo(1);

  raiz->esq = addNo(2);
  raiz->dir = addNo(3);

  raiz->dir->esq = addNo(4);
  raiz->dir->dir = addNo(5);
  raiz->dir->esq->esq = addNo(6);
  raiz->dir->esq->dir = addNo(7);
  raiz->dir->esq->dir->esq = addNo(8);
  raiz->dir->dir->esq = addNo(9);
  raiz->dir->dir->esq->dir = addNo(10);
  raiz->dir->dir->dir = addNo(11);

  raiz->esq->esq = addNo(12);
  raiz->esq->dir = addNo(13);
  raiz->esq->esq->esq = addNo(14);
  raiz->esq->esq->dir = addNo(15);
  raiz->esq->esq->dir->esq = addNo(16);
  raiz->esq->esq->dir->dir = addNo(17);
  raiz->esq->dir->esq = addNo(18);
  raiz->esq->dir->dir = addNo(19);

  printArvore(raiz, 0);

  printf("\n");

  printNivMax(raiz);
  printAltura(raiz);
  printQtdNos(raiz);
  printQtdArcos(raiz);
  printEhArvoreCheia(raiz);
  printEhArvoreCheiaComBaseNivMax(raiz, calcularNivMax(raiz));
  printEhArvoreBalanceada(raiz);

  printf("\n");

  printPreOrdemComMsg(raiz);
  printEmOrdemComMsg(raiz);
  printPosOrdemComMsg(raiz);
  printPorNivelOrdemComMsg(raiz, calcularAltura(raiz));

  printf("\n");

  printNiveis(raiz, calcularNivMax(raiz));

  printf("\n");

  printQtdNosPorNiveis(raiz, calcularNivMax(raiz));

  printf("\n");

  printGrauNo(raiz);
  printGrauNo(raiz->esq);
  printGrauNo(raiz->dir->dir->esq);
  printGrauNo(raiz->esq->esq->dir);
  printGrauNo(raiz->esq->esq->dir->esq);
  printGrauNo(raiz->esq->dir->dir);

  printf("\n");

  printProcurarNoPorInfo(raiz, 15);

  printf("\n");

  printProcurarNoPorInfo(raiz, 10);

  printf("\n");

  printProcurarNoPorInfo(raiz, 7);

  printf("\n");

  printProcurarNoPorInfo(raiz, 12);

  printf("\n");

  printProcurarNoPorInfo(raiz, 9);

  printf("\n");

  printProcurarNoPorInfo(raiz, 19);

  printf("\n");
  */
};

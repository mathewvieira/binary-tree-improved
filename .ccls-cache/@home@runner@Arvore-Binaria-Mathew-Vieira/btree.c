#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct No {
  long info;
  struct No *esq;
  struct No *dir;
};

struct No *addNo(long info) {
  struct No *no = (struct No *)malloc(sizeof(struct No));
  no->info = info;
  no->esq = NULL;
  no->dir = NULL;
  return no;
}

void addEsq(struct No *no, long data) {
  no->esq = addNo(data); // Adiciona o nó à esquerda do nó atual
}

void addDir(struct No *no, long data) {
  no->dir = addNo(data); // Adiciona o nó à direita do nó atual
}

struct No *procurarNoPorInfo(struct No *no, long info) {
  if (no == NULL)
    return NULL;

  if (no->info == info)
    return no;

  struct No *noEsq = procurarNoPorInfo(no->esq, info);
  if (noEsq != NULL) {
    return noEsq;
  }

  struct No *noDir = procurarNoPorInfo(no->dir, info);
  if (noDir != NULL) {
    return noDir;
  }

  return NULL;
}

struct No *preencherArvoreComArray(long vetor[], int index, int n) {
  if (index >= n) {
    return NULL;
  }

  struct No *no = addNo(vetor[index]);
  no->esq = preencherArvoreComArray(vetor, 2 * index + 1, n);
  no->dir = preencherArvoreComArray(vetor, 2 * index + 2, n);

  return no;
}

int calcularAltura(struct No *no) {
  if (no == NULL)
    return 0;
  int alturaEsq = calcularAltura(no->esq);
  int alturaDir = calcularAltura(no->dir);
  return (alturaEsq > alturaDir) ? alturaEsq + 1 : alturaDir + 1;
}

int calcularNivMax(struct No *no) {
  return calcularAltura(no) - 1; //*//*//*//*//
}

int calcularAlturaDoNoComInfo(struct No *no, int info, int alturaAtual) {
  if (no == NULL)
    return 0;

  if (no->info == info)
    return alturaAtual + 1;

  int alturaEsq = calcularAlturaDoNoComInfo(no->esq, info, alturaAtual + 1);
  int alturaDir = calcularAlturaDoNoComInfo(no->dir, info, alturaAtual + 1);

  return (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
}

int calcularGrauNo(struct No *no) {
  if (no == NULL)
    return -1;
  return (no->esq != NULL) + (no->dir != NULL);
}

int calcularQtdNos(struct No *no) {
  if (no == NULL)
    return 0;

  int alturaEsquerda = calcularQtdNos(no->esq);
  int alturaDireita = calcularQtdNos(no->dir);

  return 1 + alturaEsquerda + alturaDireita;
}

int calcularQtdNosPorNivel(struct No *no, int nivel) {
  if (no == NULL)
    return 0;

  if (nivel == 0)
    return 1;

  int alturaEsquerda = calcularQtdNosPorNivel(no->esq, nivel - 1);
  int alturaDireita = calcularQtdNosPorNivel(no->dir, nivel - 1);
  return alturaEsquerda + alturaDireita;
}

bool ehArvoreCheia(struct No *no) {
  if (no == NULL)
    return true;

  if (no->esq == NULL && no->dir == NULL)
    return true;

  if (no->esq != NULL && no->dir != NULL)
    return ehArvoreCheia(no->esq) && ehArvoreCheia(no->dir);

  return false;
}

bool ehArvoreCheiaComBaseNivMax(struct No *no, int nivMax) {
  return pow(2, nivMax) == calcularQtdNosPorNivel(no, nivMax);
}

bool ehArvoreBalanceada(struct No *no) {
  if (no == NULL)
    return 1;

  int alturaEsq = calcularAltura(no->esq);
  int alturaDir = calcularAltura(no->dir);

  if (abs(alturaEsq - alturaDir) <= 1 && ehArvoreBalanceada(no->esq) &&
      ehArvoreBalanceada(no->dir))
    return 1;

  return 0;
}

void desenharArvore(struct No *no, int espacos) {
  if (no == NULL)
    return;
  espacos += 7;
  desenharArvore(no->dir, espacos); // printf("\n");
  for (int i = 10; i < espacos; i++)
    printf(" ");
  printf("%ld \n", no->info);
  desenharArvore(no->esq, espacos);
}

void printAltura(struct No *no) {
  printf("Altura: %d\n", calcularAltura(no)); //*//*//*//*//
}

void printNivMax(struct No *no) {
  printf("Nível Máximo: %d\n", calcularNivMax(no));
}

void printQtdNos(struct No *no) {
  printf("Qtd. Nós: %d\n", calcularQtdNos(no));
}

void printQtdArcos(struct No *no) {
  printf("Qtd. Arcos: %d\n", calcularQtdNos(no) - 1);
}

void printNivel(struct No *no, int nivel) {
  if (no == NULL) {
    return;
  }
  if (nivel == 0) {
    printf("%ld ", no->info);
  } else {
    printNivel(no->esq, nivel - 1);
    printNivel(no->dir, nivel - 1);
  }
}

void printPreOrdem(struct No *no) {
  if (no == NULL)
    return;
  printf("%ld ", no->info);
  printPreOrdem(no->esq);
  printPreOrdem(no->dir);
}

void printEmOrdem(struct No *no) {
  if (no == NULL)
    return;
  printEmOrdem(no->esq);
  printf("%ld ", no->info);
  printEmOrdem(no->dir);
}

void printPosOrdem(struct No *no) {
  if (no == NULL)
    return;
  printPosOrdem(no->esq);
  printPosOrdem(no->dir);
  printf("%ld ", no->info);
}

void printPorNivelOrdem(struct No *no, int altura) {
  for (int i = 0; i < altura; i++)
    printNivel(no, i);
}

void printPreOrdemComMsg(struct No *no) {
  printf("Pré-ordem: ");
  printPreOrdem(no);
  printf("\n");
}

void printEmOrdemComMsg(struct No *no) {
  printf("Em-ordem: ");
  printEmOrdem(no);
  printf("\n");
}

void printPosOrdemComMsg(struct No *no) {
  printf("Pós-ordem: ");
  printPosOrdem(no);
  printf("\n");
}

void printPorNivelOrdemComMsg(struct No *no, int altura) {
  printf("Por-nível: ");
  printPorNivelOrdem(no, altura);
  printf("\n");
}

void printArvore(struct No *no, int espacos) {
  printf(" Direita: ↑\n");
  printf("Esquerda: ↓\n");

  printf("\n");

  desenharArvore(no, espacos);
}

void printGrauNo(struct No *no) {
  if (no == NULL)
    return;

  int grauNo = calcularGrauNo(no);

  if (grauNo == -1) {
    printf("Nó inválido \n");
    return;
  }

  printf("Nó(%ld): Grau %d ", no->info, grauNo);

  if (grauNo == 0)
    printf("(folha) ");

  printf("\n");

  return;
}

void printQtdNosPorNivel(struct No *no, int nivel) {
  printf("Qtd. Nós Nível %d: %d \n", nivel, calcularQtdNosPorNivel(no, nivel));
}

void printEhArvoreCheia(struct No *no) {
  printf("Árvore cheia: %s \n", ehArvoreCheia(no) ? "SIM" : "NÃO");
}

void printEhArvoreCheiaComBaseNivMax(struct No *no, int nivMax) {
  printf("Árvore cheia: %s (calculado a partir do nível máximo)\n",
         ehArvoreCheiaComBaseNivMax(no, nivMax) ? "SIM" : "NÃO");
}

void printEhArvoreBalanceada(struct No *no) {
  printf("Árvore balanceada: %s \n", ehArvoreBalanceada(no) ? "SIM" : "NÃO");
}

void printNiveis(struct No *no, int nivMax) {
  for (int i = 0; i <= nivMax; i++) {
    printf("Nível %d: ", i);
    printNivel(no, i);
    printf("\n");
  }
}

void printQtdNosPorNiveis(struct No *no, int nivMax) {
  for (int i = 0; i <= nivMax; i++)
    printQtdNosPorNivel(no, i);
}

void printProcurarNoPorInfo(struct No *no, long info) {
  struct No *noEncontrado = procurarNoPorInfo(no, info);

  if (noEncontrado != NULL) {
    int grauNo = calcularGrauNo(noEncontrado);
    int altura = calcularAlturaDoNoComInfo(no, info, 0);

    printf("Nó(%ld) encontrado!", noEncontrado->info);

    printf("\n└── Nível: %d ", altura - 1);
    printf("\n└── Altura: %d ", altura);

    printf("\n└── Grau: %d ", grauNo);

    if (grauNo == 0)
      printf("(folha) ");

    if (noEncontrado->esq != NULL)
      printf("\n└── Filho esquerda: %ld", noEncontrado->esq->info);

    if (noEncontrado->dir != NULL)
      printf("\n└── Filho direita: %ld", noEncontrado->dir->info);
  } else {
    printf("Nó(%ld) não encontrado!", info);
  }

  printf("\n");
}

void printPause() {
  const char *anyKey = "Pressione qualquer tecla para continuar...";

  printf("\n\n%s", anyKey);

  while (getchar() != '\n') {
  }
  getchar();
}

void printLinhaInicio() {
  const char *hr = "────────────────────";

  printf("\n%s \n\n", hr);
}

void printLinhaFim() {
  const char *hr = "────────────────────";

  printf("\n%s", hr);
}

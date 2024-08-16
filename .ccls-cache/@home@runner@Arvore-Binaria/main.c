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

int calcularAltura(struct No *no) {
  if (no == NULL)
    return 0;
  int alturaEsq = calcularAltura(no->esq);
  int alturaDir = calcularAltura(no->dir);
  return (alturaEsq > alturaDir) ? alturaEsq + 1 : alturaDir + 1;
}

int quantidadeDeNos(struct No *no) {
  if (no == NULL)
    return 0;

  int alturaEsquerda = quantidadeDeNos(no->esq);
  int alturaDireita = quantidadeDeNos(no->dir);

  return 1 + alturaEsquerda + alturaDireita;
}

int quantidadeDeNosPorNivel(struct No *no, int nivel) {
  if (no == NULL)
    return 0;
  if (nivel == 0) {
    return 1;
  } else {
    int alturaEsquerda = quantidadeDeNosPorNivel(no->esq, nivel - 1);
    int alturaDireita = quantidadeDeNosPorNivel(no->dir, nivel - 1);
    return alturaEsquerda + alturaDireita;
  }
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

void printArvore(struct No *no, int espacos) {
  if (no == NULL)
    return;
  espacos += 7;
  printArvore(no->dir, espacos);
  // printf("\n");
  for (int i = 10; i < espacos; i++)
    printf(" ");
  printf("%ld\n", no->info);
  printArvore(no->esq, espacos);
}

int main(void) {
  struct No *raiz = addNo(1);

  raiz->esq = addNo(2);
  raiz->dir = addNo(3);

  raiz->dir->esq = addNo(4);
  raiz->dir->dir = addNo(5);
  raiz->dir->esq->esq = addNo(6);
  raiz->dir->esq->dir = addNo(7);
  raiz->dir->dir->esq = addNo(8);
  raiz->dir->dir->dir = addNo(9);

  raiz->esq->esq = addNo(10);
  raiz->esq->dir = addNo(11);
  raiz->esq->esq->esq = addNo(12);
  raiz->esq->esq->dir = addNo(13);
  raiz->esq->esq->dir->esq = addNo(14);
  raiz->esq->esq->dir->dir = addNo(15);
  raiz->esq->dir->esq = addNo(16);
  raiz->esq->dir->dir = addNo(17);

  printf("Direita:  ↑\n");
  printf("Esquerda: ↓\n");
  printf("\n\n");

  // Exibir altura da árvore
  // Exibir em pre-order, order, post-order
  // Exibir quantidade de arcos (qtd total de nós menos 1 | nós - 1)

  // Exibir grau dos nós

  // Árvore é cheia ou não
  // Árvore é balanceada ou não
  // Buscar um nó e exibir informações dele

  printArvore(raiz, 0);

  int nivMax = -1;
  int altura = nivMax + 1;

  altura = calcularAltura(raiz);
  nivMax = altura - 1;

  int qtdNos = quantidadeDeNos(raiz);

  printf("\n\n");
  printf("Nível Máximo: %d", nivMax);

  printf("\n");
  printf("Altura: %d", altura);

  printf("\n");
  printf("Quantida de nós: %d", qtdNos);

  printf("\n");
  printf("Quantida de arcos: %d", qtdNos - 1);

  printf("\n\n");
  printf("Pré-ordem: ");
  printPreOrdem(raiz);

  printf("\n");
  printf("Em-ordem: ");
  printEmOrdem(raiz);

  printf("\n");
  printf("Pós-ordem: ");
  printPosOrdem(raiz);

  printf("\n\n");
  printf("Nível 0: ");
  printNivel(raiz, 0);

  printf("\n");
  printf("Nível 1: ");
  printNivel(raiz, 1);

  printf("\n");
  printf("Nível 2: ");
  printNivel(raiz, 2);

  printf("\n");
  printf("Nível 3: ");
  printNivel(raiz, 3);

  printf("\n");
  printf("Nível 4: ");
  printNivel(raiz, 4);

  printf("\n\n");
  printf("Quantidade de nós Nível 0: %d", quantidadeDeNosPorNivel(raiz, 0));

  printf("\n");
  printf("Quantidade de nós Nível 1: %d", quantidadeDeNosPorNivel(raiz, 1));

  printf("\n");
  printf("Quantidade de nós Nível 2: %d", quantidadeDeNosPorNivel(raiz, 2));

  printf("\n");
  printf("Quantidade de nós Nível 3: %d", quantidadeDeNosPorNivel(raiz, 3));

  printf("\n");
  printf("Quantidade de nós Nível 4: %d", quantidadeDeNosPorNivel(raiz, 4));

  return 0;
};
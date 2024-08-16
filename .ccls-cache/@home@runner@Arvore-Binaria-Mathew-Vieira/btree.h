#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef btree
#define btree

struct No *addNo(long info);

void addEsq(struct No *no, long data);

void addDir(struct No *no, long data);

struct No *procurarNoPorInfo(struct No *no, long info);

struct No *preencherArvoreComArray(long vetor[], int index, int n);

int calcularAltura(struct No *no);

int calcularNivMax(struct No *no);

int calcularAlturaDoNoComInfo(struct No *no, int info, int alturaAtual);

int calcularGrauNo(struct No *no);

int calcularQtdNos(struct No *no);

int calcularQtdNosPorNivel(struct No *no, int nivel);

bool ehArvoreCheia(struct No *no);

bool ehArvoreCheiaComBaseNivMax(struct No *no, int nivMax);

bool ehArvoreBalanceada(struct No *no);

void desenharArvore(struct No *no, int espacos);

void printAltura(struct No *no);

void printNivMax(struct No *no);

void printQtdNos(struct No *no);

void printQtdArcos(struct No *no);

void printNivel(struct No *no, int nivel);

void printPreOrdem(struct No *no);

void printEmOrdem(struct No *no);

void printPosOrdem(struct No *no);

void printPorNivelOrdem(struct No *no, int altura);

void printPreOrdemComMsg(struct No *no);

void printEmOrdemComMsg(struct No *no);

void printPosOrdemComMsg(struct No *no);

void printPorNivelOrdemComMsg(struct No *no, int altura);

void printArvore(struct No *no, int espacos);

void printGrauNo(struct No *no);

void printQtdNosPorNivel(struct No *no, int nivel);

void printEhArvoreCheia(struct No *no);

void printEhArvoreCheiaComBaseNivMax(struct No *no, int nivMax);

void printEhArvoreBalanceada(struct No *no);

void printNiveis(struct No *no, int nivMax);

void printQtdNosPorNiveis(struct No *no, int nivMax);

void printProcurarNoPorInfo(struct No *no, long info);

void printPause();

void printLinhaInicio();

void printLinhaFim();

#endif

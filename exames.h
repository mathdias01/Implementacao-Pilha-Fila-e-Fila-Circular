#ifndef EXAMES_H
#define EXAMES_H
#include "paciente.h"
#define MAX_EXAMES 8

typedef struct{
    int frente;
    int tras;
    int qtd;
    Paciente exames[MAX_EXAMES];

}Exame;

Exame iniciarFilaExames();
int estaCheiaExames(Exame e);

int estaVaziaExa(Exame e);

Exame enfileirarExames(Exame e, Paciente p);

Exame desenfileirarExames(Exame e);

void mostrarExames(Exame e);

void gerarRelatorioExames(Exame e);

#endif
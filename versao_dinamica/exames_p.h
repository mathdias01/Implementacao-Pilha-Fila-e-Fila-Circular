#ifndef EXAMES_P_H
#define EXAMES_P_H
#include "paciente_p.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int tras;
    int frente;
    Paciente *pacientes;
    int qtd;
    int tamanho;
}Exames;

Exames* iniciarExames(int tamanho);
Exames* enfileirarExames(Exames *e, Paciente p);
Exames* desenfileirarExames(Exames *e);
int estaCheiaExames(Exames *e);
int estaVaziaExames(Exames *e);
void mostrarExames(Exames *e);
void gerarRelatorioExames(Exames *e);

#endif 
#ifndef CONSULTAS_P_H
#define CONSULTAS_P_H
#include "paciente_p.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int frente;
    int tras;
    int quantidade;
    Paciente *pacientes;

}Consultas;

Consultas* iniciarFilaConsultas(int quantidade);
int estaCheiaConsultas(Consultas *c);
int estaVaziaConsultas(Consultas *c);
Consultas* enfileirarConsultas(Consultas *c, Paciente p);
Consultas* desenfileirarConsultas(Consultas *c);
void mostrarConsultas(Consultas *c);
void gerarRelatorioConsultas(Consultas *c);

#endif
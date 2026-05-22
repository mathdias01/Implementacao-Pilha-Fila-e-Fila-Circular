#ifndef EMERGeNCIA_P_H
#define EMERGeNCIA_P_H
#include "paciente_p.h"
#include<stdio.h>
#include <stdlib.h>

typedef struct{
    Paciente *pacientes;
    int topo;
    int capacidade;
    
}Emergencia;

Emergencia* iniciarEmergencia(int capacidade);
int estaVaziaEmergencia(Emergencia *e);
int estaCheiaEmergencia(Emergencia *e);
Emergencia* empilharEmergencia(Emergencia *e, Paciente paciente);
Emergencia* desempilharEmergencia(Emergencia *e);
void mostrarPilhaEmergencia(Emergencia *e);
void gerarRelatorioEmergencia(Emergencia *e);



#endif
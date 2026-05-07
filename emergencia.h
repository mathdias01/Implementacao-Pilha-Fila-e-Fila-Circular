#ifndef EMERGENCIA_H
#define EMERGENCIA_H
#include "paciente.h"

#define MAX_EMERGENCIA 5

typedef struct{
    Paciente pacientes[MAX_EMERGENCIA];
    int topo;

}Emergencia;

Emergencia IniciarPilha();

int EstaCheia(Emergencia p);

int EstaVazia(Emergencia p);

Emergencia empilhar(Emergencia e, Paciente p);

Emergencia desempilhar(Emergencia e);

#endif
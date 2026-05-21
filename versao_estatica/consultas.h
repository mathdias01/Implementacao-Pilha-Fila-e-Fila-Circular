#ifndef CONSULTAS_H
#define CONSULTAS_H
#include "paciente.h"
#define MAX_CONSULTAS 1000

typedef struct{
    
    int frente;
    int tras;
    Paciente consultas[MAX_CONSULTAS];
}consulta;

int estaCheiaConsultas(consulta c);

int estaVaziaConsultas(consulta c);

consulta iniciarFila();

consulta enfileirarConsultas(consulta c, Paciente p);

consulta desenfileirarConsultas(consulta c);

void mostrarConsultas(consulta c);

void gerarRelatorioConsultas(consulta c);

#endif
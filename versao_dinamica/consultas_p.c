#include <stdio.h>
#include <stdlib.h>
#include "consultas_p.h"
#include "paciente_p.h"


Consultas* iniciarFilaConsultas(int quantidade){
    Consultas *c = (Consultas*) malloc(sizeof(Consultas));
    c->frente = 0;
    c->tras = -1;
    c->quantidade = quantidade;

    c->pacientes = (Paciente*) malloc(c->quantidade * sizeof(Paciente));

    return c;
}


int estaCheiaConsultas(Consultas *c){
    return c->quantidade == (c->tras + 1);
}

int estaVaziaConsultas(Consultas *c){
    return c-> tras < c->frente;
}

Consultas* enfileirarConsultas(Consultas *c, Paciente p){
    if (estaCheiaConsultas(c)){
        printf("Setor de consultas lotado, espere alguem ser atendido!\n");
    }
    else{
        c->tras++;
        c->pacientes[c->tras] = p;
        printf("Paciente %s direcionado para o setor de Consultas!\n", c->pacientes[c->tras].nome); 

        return c;
    }

}

Consultas* desenfileirarConsultas(Consultas *c){
    if(estaVaziaConsultas(c)){
        printf("Setor consultas vazio!\n");
    }
    else{
        printf("Paciente: %s\n Idade: %d\n Gravidade: %d\n Tipo atendimento: %d\n atendido!\n", c->pacientes[c->frente].nome, c->pacientes[c->frente].idade, c->pacientes[c->frente].gravidade, c->pacientes[c->frente].tipo_atendimento);
}


}
void mostrarConsultas(Consultas *c){
    if(estaVaziaConsultas(c)){
        printf("Setor consultas vazio!\n");
    }
    else{
        for (int i = c->frente; i <= c->tras; i++){
            printf("Posicao: %d - Nome: %s | Gravidade: %d\n ",i + 1, c->pacientes[i].nome, c->pacientes[i].gravidade);
        }
    }
}


void gerarRelatorioConsultas(Consultas *c){
    printf("\n========== RELATÓRIO: SETOR DE CONSULTAS ==========\n");
    int total = c->tras + 1;
    int vagas = c->quantidade - total;
       if(estaVaziaConsultas(c)){
        printf("Setor consultas vazio!\n");
        printf("Vagas no setor Consultas:%d\n", vagas);
    }
    else{
        printf("Pacientes a serem atendidos:%d\n", total);
        printf("Vagas no setor Consultas:%d\n", vagas);
    }
}   



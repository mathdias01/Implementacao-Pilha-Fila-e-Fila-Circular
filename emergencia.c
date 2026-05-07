#include <stdio.h>
#include "paciente.h"
#include "emergencia.h"

Emergencia IniciarPilha(){
    Emergencia p;
    p.topo = -1;
    return p;
}

int EstaCheia(Emergencia p){
    return p.topo == MAX_EMERGENCIA - 1;
}

int EstaVazia(Emergencia p){
    return p.topo == -1;
}

Emergencia empilhar(Emergencia e, Paciente p){
    if (EstaCheia(e)){
        printf("Emergencia lotada, espere alguem ser atendido\n");
    }

    else{
        e.topo++;
        e.pacientes[e.topo] = p;
        printf("Paciente %d, enviado para a Emergencia!\n", p.nome);
    }
    return e;

}

Emergencia desempilhar(Emergencia e){
    if (EstaVazia(e)){
        printf("Emergencia vazia, nao a pacientes a serem atendidos!\n");
    }

    else{
        printf("Paciente %s atendido", e.pacientes[e.topo].nome);
        e.topo--;
    }
    return e;
}
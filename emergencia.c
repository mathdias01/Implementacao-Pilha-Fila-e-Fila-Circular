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
        printf("Paciente: %s, Enviado para a Emergencia!\n", p.nome);
    }
    return e;

}

Emergencia desempilhar(Emergencia e){
    if (EstaVazia(e)){
        printf("Emergencia vazia, nao a pacientes a serem atendidos!\n");
    }

    else{
        printf("\n-- Dados do paciente atendido--\n");
        printf("Paciente: %s\n Idade: %d\n Gravidade: %d\n Tipo atendimento: %d.\n", e.pacientes[e.topo].nome, e.pacientes[e.topo].idade, e.pacientes[e.topo].gravidade, e.pacientes[e.topo].tipo_atendimento);
        e.topo--;
    }
    return e;
}

void mostrarPilha(Emergencia e){
    if (EstaVazia(e)) {
        printf("\nSetor de Emergencia vazio. Ninguem aguardando.\n");
        return;
    }

    printf("\n--- PACIENTES NA EMERGENCIA (Do mais recente ao mais antigo) ---\n");

    for(int i = e.topo ; i>= 0; i--){
        printf("Posicao: %d - Nome: %s | Gravidade: %d\n ",i, e.pacientes[i].nome, e.pacientes[i].gravidade);
    }
}

void gerarRelatorio(Emergencia e){
    int total = e.topo + 1;
    int vagas = MAX_EMERGENCIA - total;


    printf("\n========== RELATÓRIO: SETOR DE EMERGÊNCIA ==========\n");
    printf("Pacientes aguardando atendimento: %d\n", total);
    printf("Vagas disponiveis no setor: %d\n", vagas);

    if (total == MAX_EMERGENCIA) {
        printf("ALERTA: Setor operando em CAPACIDADE MÁXIMA!\n");
    } else if (total == 0) {
        printf("Status: Setor livre.\n");
    }
    printf("====================================================\n");

}
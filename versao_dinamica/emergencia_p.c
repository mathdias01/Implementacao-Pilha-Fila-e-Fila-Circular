#include "emergencia_p.h"


Emergencia* iniciarEmergencia(int capacidade){
        Emergencia* e = (Emergencia*) malloc(sizeof(Emergencia));
        e->capacidade = capacidade;
        e->topo = -1;

        e->pacientes = (Paciente*) malloc(e->capacidade * sizeof(Paciente));
        return e;

}

int estaVaziaEmergencia(Emergencia *e){
        return e->topo == -1;
}

int estaCheiaEmergencia(Emergencia *e){
        return e->topo == e->capacidade - 1;
}

Emergencia* empilharEmergencia(Emergencia *e, Paciente paciente){
        if (estaCheiaEmergencia(e)){
                printf("A fila da emergencia esta lotada, aguarde alguem ser atendido\n");
                return e;
        }
        else{
                e->topo++;
                e->pacientes[e->topo] = paciente;
                printf("Paciente: %s | enviado para a emergencia\n",e->pacientes[e->topo].nome);
                return e;
        }
}


Emergencia* desempilharEmergencia(Emergencia *e){
        if(estaVaziaEmergencia(e)){
                printf("Setor emergencia vazio!");
                return e;
        }
        else{
                printf("Paciente: %s | Gravidade: %d | tipo de atendimento: %d - Foi atendido na emergencia!\n", e->pacientes[e->topo].nome, e->pacientes[e->topo].gravidade, e->pacientes[e->topo].tipo_atendimento);
                e->topo--;
                return e;
        }
}

void mostrarPilhaEmergencia(Emergencia *e){
        if(estaVaziaEmergencia(e)){
                printf("Nao a pacientes no setor emergencia!\n");

        }
        else{
        printf("--- PACIENTES SETOR EMERGENCIA ---\n");
        for (int i = e->topo; i >= 0; i--){
                printf("Posicao: %d - Nome: %s | Gravidade: %d\n ",i + 1, e->pacientes[i].nome, e->pacientes[i].gravidade);
        }
       }
}

void gerarRelatorioEmergencia(Emergencia *e){
        printf("\n========== RELATÓRIO: SETOR DE EMERGÊNCIA ==========\n");
        int total = e->topo + 1;
        int vagas = e->capacidade - total;
         if(estaVaziaEmergencia(e)){
                printf("Nao a pacientes no setor emergencia!\n");
                printf("Vagas no setor emergencia:%d\n", vagas);

        }
        else{
                printf("Pacientes a serem atendidos: %d\n", total);
                printf("Vagas no setor emergencia:%d\n", vagas);
        }
}

void liberarEmergencia(Emergencia *e) {
    if (e != NULL) {
        // 1. Libera o vetor de pacientes alocado dinamicamente dentro da pilha
        if (e->pacientes != NULL) {
            free(e->pacientes);
        }
        // 2. Libera a estrutura da Pilha de Emergência em si
        free(e);
    }
}
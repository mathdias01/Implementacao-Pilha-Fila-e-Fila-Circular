#include <stdio.h>
#include "exames.h"

Exame iniciarFilaExames(){
    Exame e;
    e.frente = 0;
    e.tras = -1;
    e.qtd = 0;
    return e;
}

int estaCheiaExames(Exame e){
    return e.qtd == MAX_EXAMES;
}

int estaVaziaExames(Exame e){
    return e.qtd == 0;
}

Exame enfileirarExames(Exame e, Paciente p){
    if (estaCheiaExames(e)){
        printf("Fila de exames cheia, aguarde um paciente ser atendido\n");
    } else {
        e.tras = (e.tras + 1) % MAX_EXAMES;
        e.exames[e.tras] = p;
        e.qtd++;
        printf("Paciente: %s, Enviado para a fila de exames!\n", p.nome);
    }
    return e;
}


Exame desenfileirarExames(Exame e){
    if (estaVaziaExames(e)){
        printf("Fila de exames vazia!\n");
    } else {
        e.frente = (e.frente + 1) % MAX_EXAMES;
          printf("Paciente: %s\n Idade: %d\n Gravidade: %d\n Tipo atendimento: %d\n atendido!\n", e.exames[e.frente].nome, e.exames[e.frente].idade, e.exames[e.frente].gravidade, e.exames[e.frente].tipo_atendimento);
          e.qtd--;
    }
    return e;
}

void mostrarExames(Exame e){
    if (estaVaziaExames(e)){
        printf("Setor de exames vazio!\n");
    
    }
    else{
        printf("\n--- PACIENTES NO SETOR DE EXAMES (Do mais recente ao mais antigo) ---\n");
        int i = e.frente;
        int total = e.qtd;
        for(int cont = 0; cont < total; cont++){
            printf("Posicao: %d - Nome: %s | Gravidade: %d\n",i+ 1, e.exames[i].nome, e.exames[i].gravidade);
            i = (i + 1) % MAX_EXAMES;
        }
        
    }
}

void gerarRelatorioExames(Exame e){
    printf("\n========== RELATÓRIO: SETOR DE EXAMES (CIRCULAR) ==========\n");
    if (estaVaziaExames(e)){
        printf("Status: setor Exames vazio!\n");
    }
    else{
        printf("Pacientes na fila: %d\n", e.qtd);
    }
    int vagas = MAX_EXAMES - e.qtd;
    if (vagas == 0){
        printf("Fila do setor exames cheia! espere alguem ser atendido para entrar.\n");
    }
    else{
        printf("Vagas disponiveis no setor Exames: %d\n", vagas);
    }
}


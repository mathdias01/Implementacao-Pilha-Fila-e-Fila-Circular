#include <stdio.h>
#include "consultas.h"


consulta iniciarFila(){
    consulta c;
    c.frente = 0;
    c.tras = -1;
    return c;
}

int estaCheiaConsultas(consulta c){
    return c.tras == MAX_CONSULTAS -1;
}

int estaVaziaConsultas(consulta c){
    return c.tras < c.frente;
}

consulta enfileirarConsultas(consulta c, Paciente p){
    if (estaCheiaConsultas(c)){
        printf("Fila de consultas cheia, aguarde um paciente ser atendido\n");
    }

    else{
        c.tras++;
        c.consultas[c.tras] = p;
        printf("Paciente: %s, Enviado para a fila de consultas!\n", p.nome);
    }
    return c;
}

consulta desenfileirarConsultas(consulta c){
    if (estaVaziaConsultas(c)){
        printf("Fila de consultas vazia!\n");
    }
    else{
        printf("Paciente: %s\n Idade: %d\n Gravidade: %d\n Tipo atendimento: %d\n atendido!\n", c.consultas[c.frente].nome, c.consultas[c.frente].idade, c.consultas[c.frente].gravidade, c.consultas[c.frente].tipo_atendimento);
        c.frente++;
    }
    return c;
}


void mostrarConsultas(consulta c){
    if (estaVaziaConsultas(c)){
        printf("Setor consultas vazio!\n");
    }
    else{
        printf("\n--- PACIENTES NO SETOR DE CONSULTAS (Do mais recente ao mais antigo) ---\n");
        for (int i = c.frente; i <= c.tras; i++){
            printf("Posicao: %d - Nome: %s | Gravidade: %d\n ",i + 1, c.consultas[i].nome, c.consultas[i].gravidade);
        }
    }
}

void gerarRelatorioConsultas(consulta c){
    if (estaVaziaConsultas(c)){
        printf("Setor de consultas vazio, nenhum paciente atendido!\n");
    }
    else{
        int total = c.tras - c.frente + 1;
        int vagas = MAX_CONSULTAS - total;
        printf("\n========== RELATÓRIO: SETOR DE CONSULTAS ==========\n");
        printf("Total de pacientes aguardando: %d\n", total);
        printf("Vagas restantes: %d\n", vagas);
    }
}

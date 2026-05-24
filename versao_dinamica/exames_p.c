#include "exames_p.h"


Exames* iniciarExames(int tamanho){
        Exames *e = (Exames*) malloc(sizeof(Exames));
        e->frente = 0;
        e->tras = -1;
        e->qtd = 0;
        e->tamanho = tamanho;

        e->pacientes = (Paciente*) malloc(e->tamanho* sizeof(Paciente));
        return e;
}


int estaCheiaExames(Exames *e){
    return e->qtd == e->tamanho;
}

int estaVaziaExames(Exames *e){
    return e->qtd == 0;
}

Exames* enfileirarExames(Exames *e, Paciente p){
    if(estaCheiaExames(e)){
        printf("Setor exames cheio, espere alguem ser atendido!\n");
        return e;
    }
    else{
       
        e->tras = (e->tras + 1) % e->tamanho;
        e->pacientes[e->tras] = p;
        e->qtd++;
        printf("Paciente %s direcionado para o setor de Exames!\n", e->pacientes[e->tras].nome); 
        return e;
    }
}

Exames* desenfileirarExames(Exames *e){
    if(estaVaziaExames(e)){
        printf("Setor exames vazio, ninguem para ser atendido!\n");
        return e;
    }
    else{
        printf("Paciente: %s\n Idade: %d\n Gravidade: %d\n Tipo atendimento: %d\n atendido!\n", e->pacientes[e->frente].nome, e->pacientes[e->frente].idade, e->pacientes[e->frente].gravidade, e->pacientes[e->frente].tipo_atendimento);
        e->frente = (e->frente + 1) % e->tamanho;
        e->qtd--;  
        return e;
    }
}


void mostrarExames(Exames *e){
    printf("\n--- PACIENTES NO SETOR DE EXAMES (Do mais recente ao mais antigo) ---\n");
    int i = e->frente;
    if(estaVaziaExames(e)){
        printf("Setor exames vazio, ninguem para ser atendido!\n");
    }
    else{
        for(int cont = 0; cont < e->qtd; cont++){
            printf("Posicao: %d - Nome: %s | Gravidade: %d\n",i + 1, e->pacientes[i].nome, e->pacientes[i].gravidade);
            i = (i + 1) % e->tamanho;
            
        }
    }
}
void gerarRelatorioExames(Exames *e){
    int total = e->qtd;
    int vagas = e->tamanho - total;
    if(estaVaziaExames(e)){
        printf("Setor exames vazio, ninguem para ser atendido!\n");
        printf("Vagas disponiveis no setor: %d\n", vagas);
    }
    else if(vagas == 0){
        printf("Fila de exames cheia, espere alguem ser atendido!\n");
    }
    else{
        printf("Vagas disponiveis no setor: %d\n", vagas);
        printf("Pacientes a serem atendidos: %d\n", total);
    }
}

void liberarExames(Exames *e) {
    if (e != NULL) {
        // 1. Libera o vetor de pacientes alocado dinamicamente dentro da fila circular
        if (e->pacientes != NULL) {
            free(e->pacientes);
        }
        // 2. Libera a estrutura da Fila de Exames em si
        free(e);
    }
}
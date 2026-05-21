#include <stdio.h>
#include <stdlib.h>
#include "paciente_p.h"
#include "emergencia_p.h"
#include "consultas_p.h"

Paciente  cadastrarPaciente(){
    Paciente p;
  

    printf("Insira o nome do paciente:");
    scanf(" %99[^\n]", p.nome);
    
    printf("Insira a idade do paciente: ");
    scanf("%d", &p.idade);

    printf("Insira a gravidade (1-5): ");
    scanf("%d", &p.gravidade);

    printf("Insira o tipo de atendimento (1-Emergencia, 2-Consulta, 3-Exame): ");
    scanf("%d", &p.tipo_atendimento);
    return p;

}


int main(){
    Emergencia *setorEmergencia = iniciarEmergencia(1000);
    Consultas *setorConsultas = iniciarFilaConsultas(1000);
    int opcao;

    do{
                printf("\n--- HOSPITAL --- \n");
        printf("CADASTRO E ATENDIMENTOS\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Atender na Emergencia\n");
        printf("3. Atender na Consulta\n");
        printf("4. Atender no Exame/Laboratorio\n");

        printf("\n\n--- listagem de pacientes em  cada setor---\n");
        printf("5. Mostrar pacientes da emergencia\n");
        printf("6. Mostrar pacientes das consultas agendadas\n");
        printf("7. Mostrar pacientes dos Exames/laboratorio \n");

        printf("\n\n --- Relatorios ---\n");
        printf("8. Exibir relatorio da emergencia.\n");
        printf("9. Exibir relatorio das consultas agendadas.\n");
        printf("10. Exibir relatorio dos Exames/laboratorio.\n");
    
        printf("11. Rodar teste de estresse e tempo.\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:{
                Paciente p = cadastrarPaciente();
                if (p.gravidade >= 4){
                    printf("Gravidade acima de 4 encontrada, direcionando-o diretamente para o setor emergencia!\n");
                    p.tipo_atendimento = 1;
                    setorEmergencia = empilharEmergencia(setorEmergencia, p);
                
                } 
                else{
                    if(p.tipo_atendimento ==1){
                        setorEmergencia = empilharEmergencia(setorEmergencia, p);
                    }
                    else if(p.tipo_atendimento == 2){
                        setorConsultas = enfileirarConsultas(setorConsultas, p);
                    }
                    else if(p.tipo_atendimento ==3){
                        //colocar exames
                    }
                    
                }
                break;
            }
            case 2:{
                setorEmergencia = desempilharEmergencia(setorEmergencia);
                break;
            }
            case 3:{
                setorConsultas = desenfileirarConsultas(setorConsultas);
                break;
            }

            case 5:{
                printf("\n---PACIENTES DA EMERGENCIA---\n");
                mostrarPilhaEmergencia(setorEmergencia);
                break;
            }
            case 6: {
                printf("\n---PACIENTES DAS CONSULTAS---\n");
                mostrarConsultas(setorConsultas);
                break;
            }

            case 8:{
                gerarRelatorioEmergencia(setorEmergencia);
                break;
            }
            case 9:{
                gerarRelatorioConsultas(setorConsultas);
            }

            case 0:{
                printf("Saindo do sistema...\n");
                break;
            }

        }
    }while(opcao != 0);

}
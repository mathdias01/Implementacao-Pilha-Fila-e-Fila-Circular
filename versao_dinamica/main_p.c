#include <stdio.h>
#include <stdlib.h>
#include "paciente_p.h"
#include "emergencia_p.h"
#include "consultas_p.h"
#include "exames_p.h"
#include <time.h>


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
    Emergencia *setorEmergencia = iniciarEmergencia(10000);
    Consultas *setorConsultas = iniciarFilaConsultas(10000);
    Exames *setorExames = iniciarExames(10000);


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
                        setorExames = enfileirarExames(setorExames, p);
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
            case 4:{
                setorExames = desenfileirarExames(setorExames);
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
            case 7:{
                mostrarExames(setorExames);
                break;
            }

            case 8:{
                gerarRelatorioEmergencia(setorEmergencia);
                break;
            }
            case 9:{
                gerarRelatorioConsultas(setorConsultas);
                break;
            }
            case 10:{
                gerarRelatorioExames(setorExames);
                break;
            }
            case 11:{
                
                Paciente p_teste_emergencia = {"P_teste", 18,5,1};
                Paciente p_teste_consultas = {"P_teste", 18,2,2};
                Paciente p_teste_exames = {"P_teste", 18,2,3};

                clock_t inicio, fim;
                double t_emergencia_inserir, t_emergencia_atender;
                double t_consultas_inserir, t_consultas_atender;
                double t_exames_inserir, t_exames_atender;

                inicio = clock();
                
                for(int i = 0; i < 10000; i++){
                    setorEmergencia = empilharEmergencia(setorEmergencia, p_teste_emergencia);
                }
                fim = clock();

                t_emergencia_inserir = ((double) (fim - inicio)) / CLOCKS_PER_SEC; 

                inicio = clock();
                for(int i = 0; i < 10000; i++){
                    setorEmergencia = desempilharEmergencia(setorEmergencia);
                }
                fim = clock();

                t_emergencia_atender = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                inicio = clock();

                for(int i = 0; i < 10000; i++){
                    setorConsultas = enfileirarConsultas(setorConsultas, p_teste_consultas);
                }

                fim = clock();

                t_consultas_inserir = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                inicio = clock();

                for(int i = 0; i < 10000; i++){
                    setorConsultas = desenfileirarConsultas(setorConsultas);
                }

                fim = clock();

                t_consultas_atender = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                inicio = clock();

                for(int i = 0; i < 10000; i++){
                    setorExames = enfileirarExames(setorExames, p_teste_exames);
                }

                fim = clock();

                t_exames_inserir = ((double)(fim - inicio)) / CLOCKS_PER_SEC;


                inicio = clock();

                for(int i = 0; i < 10000; i++){
                    setorExames = desenfileirarExames(setorExames);
                }
                fim = clock();

                t_exames_atender = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\n--- INICIANDO TESTE DE ESTRESSE E TEMPO ---\n");
                printf(" --- SETOR DE EMERGÊNCIA (PILHA DINIÂMICA) ---\n");
                printf(" -> Tempo para Empilhar 10.000:   %f segundos.\n", t_emergencia_inserir);
                printf(" -> Tempo para Desempilhar 10.000: %f segundos.\n\n", t_emergencia_atender);

                printf(" --- SETOR DE CONSULTAS (FILA LINEAR) ---\n");
                printf(" -> Tempo para Enfileirar 10.000:  %f segundos.\n", t_consultas_inserir);
                printf(" -> Tempo para Desenfileirar 10.000: %f segundos.\n\n", t_consultas_atender);

                printf(" --- SETOR DE EXAMES (FILA CIRCULAR) ---\n");
                printf(" -> Tempo para Enfileirar 10.000:  %f segundos.\n", t_exames_inserir);
                printf(" -> Tempo para Desenfileirar 10.000: %f segundos.\n\n", t_exames_atender);
                break;
            }
            case 0:{
                printf("Liberando memoria do sistema...\n");
                
                liberarEmergencia(setorEmergencia);
                liberarConsultas(setorConsultas);
                liberarExames(setorExames);
                printf("Saindo do sistema...\n");
                break;
            }

        }
    }while(opcao != 0);

}
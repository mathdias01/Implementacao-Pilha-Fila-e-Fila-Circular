#include <stdio.h>
#include "emergencia.h"
#include "consultas.h"
#include "exames.h"

Paciente CadastrarPaciente(){
    Paciente p;
    printf("Insira o nome do paciente: ");
    scanf(" %[^\n]", p.nome);

    printf("Insira a idade: ");
    scanf("%d", &p.idade);

    printf("Insira a gravidade(1-5): ");
    scanf("%d", &p.gravidade);

    printf("Insira o tipo de atendimento (1-Emergência, 2-Consulta, 3-Exame):");
    scanf("%d", &p.tipo_atendimento);

    return p;
}



int main(){
    Emergencia setorEmergencia = IniciarPilha();
    consulta setorConsultas = iniciarFila();
    Exame setorExames = iniciarFilaExames();

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

        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        
        case 1:{
            Paciente p = CadastrarPaciente();

            if (p.gravidade >= 4){
                printf("Gravidade alta! Direcionando para a Emergencia!\n");
                p.tipo_atendimento = 1;
                setorEmergencia = empilhar(setorEmergencia, p);
            }
            else{
                printf("Paciente enviado para triagem normal, (aguardando consultas/exames)\n");
                if (p.tipo_atendimento ==2){
                    printf("Paciente precisa de consulta, direcionando para a fila de consultas!\n");
                    setorConsultas = enfileirarConsultas(setorConsultas, p);
                }
                else if(p.tipo_atendimento == 3){
                    printf("Paciente precisa de exame, direcionando para a fila de exames!\n");
                    setorExames = enfileirarExames(setorExames, p);
                }
                else{
                    printf("Tipo de atendimento invalido, paciente nao direcionado para nenhum setor!\n");
                }
            }
            break;
        }

        case 2: {
            setorEmergencia = desempilhar(setorEmergencia);
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

        case 5: {
            mostrarPilha(setorEmergencia);
            break;
        }

        case 6:{
            mostrarConsultas(setorConsultas);
            break;
        }
        case 7:{
            mostrarExames(setorExames);
            break;
        }

        case 8:{
            gerarRelatorio(setorEmergencia);
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
        case 0:{
            printf("Saindo do sistema...\n");
            break;
        }
        default: 
            printf("Opcao invalida, tente novamente!\n");

        }
    }while (opcao != 0);
    return 0;
}

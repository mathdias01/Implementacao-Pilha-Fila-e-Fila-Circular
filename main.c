#include <stdio.h>
#include "emergencia.h"


Paciente CadastrarPaciente(){
    Paciente p;
    printf("Insira o nome do paciente: ");
    scanf(" %[^\n]", p.nome);

    printf("Insira a idade: ");
    scanf("%d", &p.idade);

    printf("Insira a gravidade: ");
    scanf("%d", &p.gravidade);

    printf("Insira o tipo de atendimento (1-Emergência, 2-Consulta, 3-Exame):");
    scanf("%d", &p.tipo_atendimento);

    return p;
}



int main(){
    Emergencia setorEmergencia = IniciarPilha();

    int opcao;

    do{
        printf("\n--- HOSPITAL --- \n");
        printf("CADASTRO E ATENDIMENTOS\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Atender na Emergencia\n");

        printf("\n\n--- listagem de pacientes em  cada setor---\n");
        printf("3. Mostrar pacientes da emergencia\n");
        printf("4. Mostrar pacientes das consultas agendadas\n");
        printf("5. Mostrar pacientes dos Exames/laboratorio \n");

        printf("\n\n --- Relatorios ---\n");
        printf("6. Exibir relatorio da emergencia.\n");
        printf("7. Exibir relatorio das consultas agendadas.\n");
        printf("8. Exibir relatorio dos Exames/laboratorio.\n");

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
                printf("Paciente enviado para triagem normal, (aguardando fila/exames)\n");
            }
            break;
        }

        case 2: {
            setorEmergencia = desempilhar(setorEmergencia);
            break;
        }

        case 3: {
            mostrarPilha(setorEmergencia);
            break;
        }

        case 6:{
            gerarRelatorio(setorEmergencia);
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

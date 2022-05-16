#include "biblioteca.h"

void menuPrincipal(void){
    int escolha;
    static int mes, diaMes, horario, direcao, poltrona;
    static float contador = 0;

    printf("\nDIGITE 1 PARA VENDER UMA PASSAGEM\n");
    printf("DIGITE 2 PARA VER O TOTAL ARRECADADO EM UMA VIAGEM\n");
    printf("DIGITE 3 PARA PARA VER O TOTAL ARRECADO EM UM MÊS\n");
    printf("DIGITE 4 PARA SABER O NOME DE UM PASSAGEIRO EM UMA POLTRONA EM UMA VIAGEM\n");
    printf("DIGITE 5 PARA VER O HORÁRIO MAIS RENTAVEL\n");
    printf("DIGITE 6 PARA VER A MÉDIA DE IDADE DOS PASSAGEIROS\n\n");
    printf("ESCOLHA A OPÇÃO: ");
    scanf("%d", &escolha);

    if(escolha == 1){
        dadosVendas();
    }else if(escolha == 2){
        printf("Digite o mês da viagem de 0 a 11: ");
        scanf("%d", &mes);
        printf("Digite o dia do mês de 0 a 27: ");
        scanf("%d", &diaMes);
        printf("Escolha o horario\n12:00PM[0]\n14:00PM[1]\n16:00PM[2]\n18:00PM[3]\n20:00PM[4]\nEscolha: ");
        scanf("%d", &horario);
        printf("Escolha a direção\nSão Paulo -> Rio de Janeiro[0]\nRio de Janeiro -> São Paulo[1]\nEscolha: ");
        scanf("%d", &direcao);

        printf("Total da viagem: %d\n\n", totalArrecadadoViagem(mes, diaMes, horario, direcao));
    }else if(escolha == 3){
        printf("Digite o mês: ");
        scanf("%d", &mes);

        printf("O total no mês foi %d\n\n", totalArrecadadoMes(mes));
    }else if(escolha == 4){
        printf("Digite o mês da viagem de 0 a 11: ");
        scanf("%d", &mes);
        printf("Digite o dia do mês de 0 a 27: ");
        scanf("%d", &diaMes);
        printf("Escolha o horario\n12:00PM[0]\n14:00PM[1]\n16:00PM[2]\n18:00PM[3]\n20:00PM[4]\nEscolha: ");
        scanf("%d", &horario);
        printf("Escolha a direção\nSão Paulo -> Rio de Janeiro[0]\nRio de Janeiro -> São Paulo[1]\nEscolha: ");
        scanf("%d", &direcao);
        printf("Digite o nũmero da poltrona: ");
        scanf("%d", &poltrona);

        printf("O nome do passgeiro(a) é %s\n\n", meses[mes].days[diaMes].horas[horario].idaEVolta[direcao].pltrn[poltrona].nome);
    }else if(escolha == 5){
        printf("O horariomais rentavel foi %d:00\n\n", horarioMaisRentavel());
    }else if(escolha == 6){
        printf("A média de idade é %f\n\n", mediaDeIdades());
    }
}

void dadosVendas(void){
    int i, j, k, l, m;
    static int horas, direcao, poltrona, totalVendas = 0, mes, dia, mesArrecadado;

    printf("Escolha o mês de 0 a 11: ");
    scanf("%d", &mes);

    for(i = mes; i <= mes; i++){
        printf("Escolha o dia do mês de 0 a 27: ");
        scanf("%d", &dia);

        for(j = dia; j <= dia; j++){
            printf("\nEscolha o horário\n\n");
            printf("12:00PM[0]\n14:00PM[1]\n16:00PM[2]\n18:00PM[3]\n20:00PM[4]\n");
            printf("Escolha a opção: ");
            scanf("%d", &horas);

            for(k = horas; k <= horas; k++){
                printf("Escolha a direção\n\n");
                printf("São Paulo -> Rio de Janeiro[0]\n");
                printf("Rio de janeiro -> São Paulo[1]\nEscolha a opção: ");
                scanf("%d", &direcao);

                for(l = direcao; l <= direcao; l++){
                    printf("Escolha a poltrona de 0 a 39: ");
                    scanf("%d", &poltrona);

                    for(m = poltrona; m <= poltrona; m++){
                        printf("Digite o nome do(a) passageiro(a): ");
                        scanf("%s", meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].nome);
                        printf("Digite o CPF do(a) cliente(a): ");
                        scanf("%s", meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].cpf);
                        printf("Digite a idade do(a) passageiro(a): ");
                        scanf("%d", &meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].idade);

                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].contador++;

                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].totalDeterminadaViagem = meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].totalDeterminadaViagem + 80;

                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].totalDeterminadoMes = meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].totalDeterminadoMes + 80;

                    }
                }
            }
        }
    }
}

int totalArrecadadoViagem(int mes, int diaMes, int horario, int direcao){
    int soma = 0, i;

    for(i = 0; i < 40; i++){
        soma = soma + meses[mes].days[diaMes].horas[horario].idaEVolta[direcao].pltrn[i].totalDeterminadaViagem;
    }

    return soma;
}

int totalArrecadadoMes(int mes){
    int diaMes, horario, direcao, poltrona, soma = 0;

    for(diaMes = 0; diaMes < 28; diaMes++){
        for(horario = 0; horario < 5; horario++){
            for(direcao = 0; direcao < 2; direcao++){
                for(poltrona = 0; poltrona < 40; poltrona++){
                    soma = soma + meses[mes].days[diaMes].horas[horario].idaEVolta[direcao].pltrn[poltrona].totalDeterminadoMes;
                }
            }
        }
    }

    return soma;
}

int horarioMaisRentavel(void){
    int hora1 = 0, hora2 = 0, hora3 = 0, hora4 = 0, hora5 = 0;
    int i, j, k, l;

    for(i = 0; i < 12; i++){
        for(j = 0; j < 28; j++){
            for(k = 0; k < 2; k++){
                for(l = 0; l < 40; l++){
                    hora1 = hora1 + meses[i].days[j].horas[0].idaEVolta[k].pltrn[l].totalDeterminadaViagem;
                    hora2 = hora2 + meses[i].days[j].horas[1].idaEVolta[k].pltrn[l].totalDeterminadaViagem;
                    hora3 = hora3 + meses[i].days[j].horas[2].idaEVolta[k].pltrn[l].totalDeterminadaViagem;
                    hora4 = hora4 + meses[i].days[j].horas[3].idaEVolta[k].pltrn[l].totalDeterminadaViagem;
                    hora5 = hora5 + meses[i].days[j].horas[4].idaEVolta[k].pltrn[l].totalDeterminadaViagem;
                }
            }
        }
    }

    if(hora1 > hora2 && hora1 > hora3 && hora1 > hora4 && hora1 > hora5){
        return 12;
    }else if(hora2 > hora1 && hora2 > hora3 && hora2 > hora4 && hora2 > hora5){
        return 14;
    }else if(hora3 > hora1 && hora3 > hora2 && hora3 > hora4 && hora3 > hora5){
        return 16;
    }else if(hora4 > hora1 && hora4 > hora2 && hora4 > hora3 && hora4 > hora5){
        return 18;
    }else{
        return 20;
    }
}

float mediaDeIdades(){
    int i, j, k, l, m, soma = 0, contador = 0;

    for(i = 0; i < 12; i ++){
        for(j = 0; j < 28; j++){
            for(k = 0; k < 5; k++){
                for(l = 0; l < 2; l++){
                    for(m = 0; m < 40; m++){
                        soma = soma + meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].idade;
                        if(meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].idade != 0){
                            contador++;
                        }
                    }
                }
            }
        }
    }

    return soma / contador;
}

void iniciaVariaveis(void){
    int i, j, k, l, m;

    for(i = 0; i < 12; i ++){
        for(j = 0; j < 28; j++){
            for(k = 0; k < 5; k++){
                for(l = 0; l < 2; l++){
                    for(m = 0; m < 40; m++){
                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].totalDeterminadaViagem = 0;
                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].totalDeterminadoMes = 0;
                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].mediaIdade = 0;
                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].vendas = 0;
                        meses[i].days[j].horas[k].idaEVolta[l].pltrn[m].contador = 0;
                    }
                }
            }
        }
    }
}
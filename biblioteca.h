#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define CPF 14
#define NOME 20

//Inicio das estruturas anihadas
struct Poltronas{
    char nome[NOME], cpf[CPF];
    int idade, totalDeterminadaViagem, totalDeterminadoMes, mediaIdade, vendas, contador;
};

struct IdaVolta{
    struct Poltronas pltrn[40];//m
};

struct Horario{
    struct IdaVolta idaEVolta[2];//l
};

struct Dias{
    struct Horario horas[5];//k
};

struct Mes{
    struct Dias days[28];//j
};

struct Mes meses[12];//i
//Fim das estruturas aninhadas

//Declaração das funções
void dadosVendas(void);
int totalArrecadadoViagem(int mes, int diaMes, int horario, int direcao);
int totalArrecadadoMes(int mes);
int horarioMaisRentavel(void);
float mediaDeIdades(void);
void iniciaVariaveis(void);
void menuPrincipal(void);
//Fim das declarações de funções

#endif
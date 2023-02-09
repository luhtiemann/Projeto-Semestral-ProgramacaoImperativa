#include <stdio.h>
#include <string.h>

#define numLinhas 27 
//define o tamanho da tabela

typedef struct{ //struct covidInfo com os dados do arquivo txt, regiao, estado, casos1, casos2, mortes1, mortes2
  enum {sudeste, sul, nordeste, centro_oeste, norte} regiao;
  char estado[2];
  double casos1;
  double casos2;
  double mortes1;
  double mortes2;
} covidInfo;

//chamar funcoes
int validaInput(int);
void tabelaInfo(FILE *fpInput, covidInfo info[numLinhas]);
void arrumarEnum(char[20], int, covidInfo info[numLinhas]);
void somarMortes1(covidInfo info[numLinhas], FILE *fpTxt);
void somarCasos1(covidInfo info[numLinhas], FILE *fpTxt);
void mediaMortes1(covidInfo info[numLinhas], FILE *fpTxt);
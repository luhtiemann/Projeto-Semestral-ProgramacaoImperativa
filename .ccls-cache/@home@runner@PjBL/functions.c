#include "declarations.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

//funcao para validar input, se a quantidade de argumentos for correta codigo continua, se nao comeca dnv
int validaInput(int valor) {
  if (valor == 3) { 
    printf("Quantidade de argumentos do comando correto.\n");
    return 1;
  } else {
    printf("Quantidade de argumentos do comando errado, digite novamente.\n");
    return 0;
  }
}

//funcao para colocar as informacoes na tabela
void tabelaInfo(FILE *fpInput, covidInfo info[numLinhas]) { //
  char regioes[20];
  for (int i=0;fscanf(fpInput, "%s %s %lf %lf %lf %lf\n", &info[i].estado, &regioes, &info[i].casos1,&info[i].casos2, &info[i].mortes1, &info[i].mortes2) != -1; i++){
    arrumarEnum(regioes, i, info);
    }
  //for(int i=0;i<numLinhas;i++){
    //printf("%s %s %lf %lf %lf %lf\n", info[i].regiao, info[i].estado,info[i].casos1, info[i].casos2, info[i].mortes1,info[i].mortes2);
  //}  
}

//funcao para definir os numeros da enum de regioes
void arrumarEnum(char regioes[20], int categoria, covidInfo info[numLinhas]){
  if(strcmp(regioes,"sudeste") == 0){
    info[categoria].regiao = 1;}
  else if(strcmp(regioes,"sul") == 0){
    info[categoria].regiao = 2;}
  else if(strcmp(regioes,"nordeste") == 0){
    info[categoria].regiao = 3;}
  else if(strcmp(regioes,"centro_oeste") == 0){
    info[categoria].regiao = 4;}
  else if(strcmp(regioes,"norte") == 0){
    info[categoria].regiao = 5;}
}

//funcao para somar mortes por covid no brasil
void somaMortes1(covidInfo infos[numLinhas], FILE *fpTxt){
  int soma=0;
  for(int i=0;i<numLinhas;i++){
    soma += (infos[i].mortes1);
  }
  printf("Resultado: %d\n",soma);  
  fprintf(fpTxt, "Numero total de mortes por Covid-19 no Brasil: %d\n", soma); //printa no file
  
}

//funcao para somar casos de covid no brasil
void somaCasos1(covidInfo infos[numLinhas], FILE *fpTxt){
  int soma=0;
  for(int i=0;i<numLinhas;i++){
    soma += (infos[i].casos1);
  }
  printf("Resultado: %d\n",soma);
  fprintf(fpTxt, "Numero total de casos de Covid-19 no Brasil: %d\n", soma); //printa no file
}

//funcao que calcula a media de mortes de covid por estado
void mediaMortes1(covidInfo infos[numLinhas], FILE *fpTxt){
  double soma=0;
  double media=0;
  for(int i=0;i<numLinhas;i++){
    soma += (infos[i].mortes1);
    media=soma/numLinhas;
  }
  printf("Resultado: %lf\n",media);
  fprintf(fpTxt, "Média de mortes por Covid-19 no Brasil por estado: %lf\n", media); //printa no file
}


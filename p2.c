#include <stdio.h>
#include <string.h>
#include "declarations.h"

covidInfo infos[27];

int main(int argc, char *argv[]){
  printf("PROGRAMA PARA LER BIN\n");
  int x = validaInput(argc); //funcao de validacao do tamanho do input
  if(x==0){
    return 0;}
  FILE *fpOutput, *fpTxt;//pega input

  //output binario
  fpOutput = fopen(argv[1],"rb"); //abre arquivo e valida
  if(fpOutput == NULL)
    printf("ERRO! Arquivo bin não aberto!\n\n");
  else
    printf("Arquivo bin aberto com sucesso!\n\n");

  fpTxt = fopen(argv[2], "wb+"); //cria arquivo e valida
  if (fpOutput == NULL) {
    printf("ERRO! Arquivo de output não criado!\n");
  } 
  else{
    printf("Arquivo de output criado com sucesso!\n");
  }
  
  for(int i=0;i<numLinhas;i++){
    fread(&infos, sizeof(covidInfo),numLinhas,fpOutput); //le o arquivo em bin
    printf("%s %d %lf %lf %lf %lf\n", infos[i].estado, infos[i].regiao, infos[i].casos1, infos[i].casos2, infos[i].mortes1, infos[i].mortes2); //printa no console
  }

  int opcao=0;
  while (opcao!=4){ //while para opcoes de escolha de comandos pelo usuario
    puts("\nEscolha uma operação: ");
    puts("1: Soma do número de mortos de Covid-19 no Brasil de acordo com o Ministério da Saúde.");
    puts("2: Soma do número de casos confimados de Covid-19 no Brasil de acordo com o Ministério da Saúde.");
    puts("3: Média de mortes de acordo com o Ministério da Saúde por estado.");
    puts("4: Sair.\n");
    scanf("%d",&opcao);

    switch(opcao){
      case 1:
        somaMortes1(infos, fpTxt); //funcao de somar mortes
        break;
      case 2:
        somaCasos1(infos, fpTxt); //funcao de somar casos
        break;
      case 3:
        mediaMortes1(infos, fpTxt); //funcao de media de mortes por estado
        break;
    }
  }
  fclose(fpTxt);//fecha file
  return 0;
}

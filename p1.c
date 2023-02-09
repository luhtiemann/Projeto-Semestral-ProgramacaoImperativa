#include <stdio.h>
#include <string.h>
#include "declarations.h"

int main(int argc, char *argv[]) {
  printf("PROGRAMA PARA TRANSFORMAR ARQUIVO TXT EM BIN\n");
  covidInfo info[numLinhas]; //struct com numero de linhas
  int x = validaInput(argc); //funcao de validacao do tamanho do input
  if(x==0){
    return 0;}
  FILE *fpInput, *fpOutput; //pega o nome dos files

  //abre input file e valida
  fpInput = fopen(argv[1], "r");
  if (fpInput == NULL) {
    printf("ERRO! Arquivo de input não aberto!\n");
  } 
  else{
    printf("Arquivo de input aberto com sucesso!\n");
  }
  tabelaInfo(fpInput, info); //coloca dados em tabela
     

  //cria output file e valida
  fpOutput = fopen(argv[2], "wb+");
  if (fpOutput == NULL) {
    printf("ERRO! Arquivo de output não criado!\n");
  } 
  else{
    printf("Arquivo de output criado com sucesso!\n");
  }
  fwrite(&info, sizeof(covidInfo), numLinhas, fpOutput); //coloca informacoes em binario no arquivo aberto
  fclose(fpOutput); //fecha arquivo
  
    return 0;
  }
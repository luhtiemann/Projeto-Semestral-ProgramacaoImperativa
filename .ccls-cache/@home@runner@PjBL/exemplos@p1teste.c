/*#include <stdio.h>
#include <string.h>
#define MAX 256

char estado[2];
char regiao[2];
double casos1, casos2, mortes1, mortes2;

int main() {
  int num;
  FILE *fp1, *fp2;
  char ch, arq1[MAX], arq2[MAX];

  printf("Enter your input file name:");
  scanf("%s", arq1);

  printf("Enter your output file name:");
  scanf("%s", arq2);

  fp1 = fopen(arq1, "r");
  if (!fp1) {
    printf("Unable to open the input file!!\n");
    return 0;
  }
  fp2 = fopen(arq2, "wb");
  if (!fp2) {
    printf("Unable to open the output file!!\n");
    return 0;
  }

  while (!feof(fp1)) {
    fread(&ch, sizeof(char), 1, fp1);
    num = ch;
    fwrite(&num, sizeof(int), 1, fp2);
  }

  fclose(fp1);
  fclose(fp2);
  return 0;
}
*/
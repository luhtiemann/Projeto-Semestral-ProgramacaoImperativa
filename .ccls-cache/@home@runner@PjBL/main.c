//

#include <stdio.h>

enum regiao {SUDESTE, SUL, NORDESTE, CENTRO_OESTE, NORTE};

struct Covid_Info{
  char estado[2];
  double casosMinisterioSaude;
  double casosSecretariaSaude;
  double mortesMinisterioSaude;
  double mortesSecretariaSaude;
};

struct Covid_Info tabela_covid[20];

int main(void) {
  printf("Hello World\n");
  return 0;
}

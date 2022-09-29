#include <stdio.h>
#include <stdlib.h>
#include "fila.c"
#include "interface.c"

//include "interface.h" é o correto a se incluir, mas por estar no vscode coloca o .c no main


int main() {
  TFila F1;
  FFVazia(&F1);
  MENU(&F1);
  return 0;
}
// Autor: Juan Diego Reyes
// Coautor: Daniela MOreno
//  Fecha: 23/ 04 / 2024
//  Materia Sistemas Operativos

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modulo.h"

int main(int argc, char *argv[]) {
  // Dadas unas banderas reconocer el valor
  // $./ejecutable -e edad -g genero -a altura -p peso
  /*
  if (argc != 11) {
    printf("Error en la cantidad de argumentos");
    return -1;
  }
*/
  int col1[8];
  int col2[8];
  int tam = 0;
  struct Entrada *entrada = (struct Entrada *)malloc(sizeof(struct Entrada));
  for (int i = 1; i < argc; i += 2) {
    llenarDatos(entrada, argv[i], argv[i + 1]);
  }
  
  leerFichero(entrada->nombreArchivo, col1, col2, &tam);
  float promedio1 = calcularPromedio(col1, tam);
  float promedio2 = calcularPromedio(col2, tam);
  printf("El promedio de la columna 1 es de: %3.3f\n", promedio1);
  printf("El promedio de la columna 2 es de: %3.3f\n", promedio2);
  

  return 0;
}

// Autor: Juan Diego Reyes
//  Fecha: 23/ 04 / 2024
//  Materia Sistemas Operativos
//  Tema: Flags

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Estructura para almacenar los datos de entrada
struct Entrada {
  int edad;
  int genero;
  float altura;
  float peso;
  char nombreArchivo[100];
};

void llenarDatos(struct Entrada *entrada, char instruccion[], char contenido[]);
void imprimirDatos(struct Entrada entrada);
void leerFichero(char *nombreArchivo, int *col1, int *col2, int *tam);
float calcularPromedio(int *col, int tam);

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

void llenarDatos(struct Entrada *entrada, char instruccion[], char contenido[]) {
  if (strcmp(instruccion, "-e") == 0) {
    entrada->edad = atoi(contenido);
  }
  if (strcmp(instruccion, "-g") == 0) {
    entrada->genero = atoi(contenido);
  }
  if (strcmp(instruccion, "-a") == 0) {
    entrada->altura = atof(contenido);
  }
  if (strcmp(instruccion, "-p") == 0) {
    entrada->peso = atof(contenido);
  }
  if(strcmp(instruccion, "-f") == 0){
    strcpy(entrada->nombreArchivo, contenido);
  }
}

void imprimirDatos(struct Entrada entrada) {
  printf("Edad (-e): %d\n", entrada.edad);
  printf("Genero (-g): %d\n", entrada.genero);
  printf("Altura (-a): %4.2f\n", entrada.altura);
  printf("Peso (-p): %4.2f\n", entrada.peso);
}

void leerFichero(char *nombreArchivo, int *col1, int *col2, int *tam){
  FILE *archivo;
  int a;
  archivo = fopen("documento.txt", "r");
  int i = 0;
  while(!feof(archivo)){
    fscanf(archivo, "%d", &col1[i]);
    fscanf(archivo, "%d", &col2[i]);
    i++;
  }
  *tam = i;
  fscanf(archivo, "%d", &a);
  fclose(archivo);
}

float calcularPromedio(int *col, int tam){
  float ret = 0;
  for(int i = 0; i < tam; i++){
    ret += col[i];
  }
  return ret / tam;
}



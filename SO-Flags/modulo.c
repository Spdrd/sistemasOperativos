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
// Estructura para almacenar los datos de entrada

void llenarDatos(struct Entrada *entrada, char instruccion[], char contenido[]) {
  // Se asigna a cada dato una bandera -[letra]
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
  //Se crea una variable archivo que se conecta con el nombrado por el usuario
  FILE *archivo;
  int a;
  archivo = fopen(nombreArchivo, "r");
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
  // Se recorre el arreglo completo y se divide entre el tamaño para obtener el promedio
  float ret = 0;
  for(int i = 0; i < tam; i++){
    ret += col[i];
  }
  return ret / tam;
}



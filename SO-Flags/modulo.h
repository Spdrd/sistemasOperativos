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

#ifndef __BIBLIO01__H__
#define __BIBLIO01__H__

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

#endif


/**************************************************************
		Pontificia Universidad Javeriana
	Autor: Andrés David Pérez Cely, Juan Diego Reyes, Juan Felipe Galvis
	Fecha: 07 mayo 2024
	Materia: Sistemas Operativos
	Tema: Taller de Evaluación de Rendimiento
	Fichero: fuente de multiplicación de matrices NxN por hilos.
	Objetivo: Evaluar el tiempo de ejecución del 
					algoritmo clásico de multiplicación de matrices.
				Se implementa con la Biblioteca POSIX Pthreads
****************************************************************/
#ifndef __BIBLIO_H__
#define __BIBLIO_H__

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//Tamaño total de la memoria utilizada para las matrices
#define DATA_SIZE (1024*1024*64*3) 

//Se hacen declaraciones extern para evitar conflicto con la función principal
extern pthread_mutex_t MM_mutex; // Declaración del mutex para controlar el acceso a la matriz resultado
extern double *mA, *mB, *mC; // Punteros a las matrices A, B y C
extern struct timeval start, stop; // Variables para medir el tiempo de ejecución

struct parametros{
	int nH; // Número total de hilos
	int idH; // Identificador del hilo actual
	int N; // Tamaño de las matrices cuadradas NxN
};

void llenar_matriz(int SZ);

void print_matrix(int sz, double *matriz);

void inicial_tiempo();

void final_tiempo();

void *mult_thread(void *variables);


#endif
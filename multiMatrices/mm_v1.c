/*
Autor: Juan Diego Reyes
Fecha: 2/04/24
Tema: Procesamiento Paralelo
Materia: Sistemas Operativos
Objetivo: Crear una aplicación que ejecute el algoritmo de multiplicación de matrices clasico para metrices cuadradas. 
La aplicación usará diferentes pasos como metodologia para la implementación del algoritmo. 
A continuación se precentarán las siguientes etapas:
    -Reserva de memoria
    -Main para ingreso de argumentos de entrada
        -Arg1 dimension matriz(NxN)
        -Arg2 cantidad de hilos
    -Validar argumentos de entrada
    -Apuntar a la reserva de memoria de matrices
    -Inicializar Matrices;
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define RESERVA (1024*128*64*8)

static double MEM_CHUNK[RESERVA];

int main(int argc, char *argv[]){
    
    if(argc < 2){
        printf("Argumentos insuficientes \n");
        return -1;
    }

    int N = (int) atof(argv[1]);
    int Th = (int) atof(argv[2]);
    if(N <= 0){
        printf("La matriz no debe tener una tamaño menor a 0 \n");
        return -1;
    }
    if(Th < 1){
        printf("Tiene que haber como minimo un hilo\n");
        return -1;
    }
    printf("Dimension Matriz = %d \n", N);
    printf("Numero de hilos = %d\n", Th);
    double *mA, *mB, *mC;

    mA = MEM_CHUNK;
    mB = mA + N*N;
    mC = mB + N*N;

    for(int i = 0; i < N*N; i++){
        mA[i] = i * 1.1;
        mB[i] = i * 2.2;
        mC[i] = i * 3.3;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%4.1f ", mA[i+j]);
        }
        printf("\n");
    }

    return 0;
}


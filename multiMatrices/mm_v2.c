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
    -Inicializar Matrices
    -Imprimir Si N  es menor a 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define RESERVA (1024*128*64*8)

static double MEM_CHUNK[RESERVA];

void init_matrices(int n, double *m1, double *m2, double *m3){
    for(int i = 0; i < n; i++){
        m1[i] = i * 1.1;
        m2[i] = i * 2.2;
        m3[i] = i * 3.3;
    }
}

void imprimirMatriz(int n, double *m1){
    if(n <= 10){
        printf("__________________________\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%4.1f ", m1[i]);
            }
            printf("\n");
        }
        printf("__________________________\n");
    }
    else{
        printf("Matriz Muy grande :c \n");
    }
}

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

    init_matrices(N, mA, mB, mC);
    imprimirMatriz(N, mA);
    imprimirMatriz(N, mB);
    imprimirMatriz(N, mC);

    return 0;
}


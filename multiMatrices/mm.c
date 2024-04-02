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
    -Algoritmo Clásico de Multiplicación de matrices
    -Se crea una variable de tipo struct 
    -Se asignan valores

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define RESERVA (1024*128*64*8)

struct datos_MM{
    int N;
    int Th;
    double *mA;
    double *mB;
    double *mC;
};

static double MEM_CHUNK[RESERVA];
//Rellena las matrices
void init_matrices(int n, double *m1, double *m2, double *m3){
    for(int i = 0; i < n*n; i++){
        m1[i] = i * 1.1;
        m2[i] = i * 2.2;
        m3[i] = i;
    }
}
//Imprime las matrices
void imprimirMatriz(int n, double *m1){
    if(n <= 10){
        for(int i = 0; i < n*n; i++){
            if(i%n == 0) printf("\n");
            printf(" %4.3f ", m1[i]);
        }
        printf("\n--------------------------\n");
    }
    else{
        printf("Matriz Muy grande :c \n");
    }
}

void multiMatrices(void *argMM){
    struct datos_MM *val = (struct datos_MM *) argMM;
    int n = val->N;
    double *m1 = val->mA;
    double *m2 = val->mB;
    double *res = val->mC;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            double SumTemp, *pA, *pB;
            SumTemp = 0.0;
            pA = m1 + i*n;
            pB = m2 + j;
            for(int k = 0; k < n ; k++, pA++, pB+=n){
                SumTemp += *pA * *pB;
            }
            res[i*n+j] = SumTemp;
        }
    }
}

int main(int argc, char *argv[]){
    //Verificaciones para los argumentos

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

    //Imprime los argumentos ingresados
    printf("Dimension Matriz = %d \n", N);
    printf("Numero de hilos = %d\n", Th);

    //Declara y asigna memoria a las matrices
    double *mA, *mB, *mC;

    mA = MEM_CHUNK;
    mB = mA + N*N;
    mC = mB + N*N;

    //Se llenan e imprimen las matrices
    init_matrices(N, mA, mB, mC);
    imprimirMatriz(N, mA);
    imprimirMatriz(N, mB);
    struct datos_MM *encValores = (struct datos_MM *)malloc(sizeof(struct datos_MM));
    encValores->N = N;
    encValores->mA = mA;
    encValores->mB = mB;
    encValores->mC = mC;
    

    multiMatrices(encValores);
    imprimirMatriz(N, mC);


    printf("\nFin del programa \n");

    return 0;
}


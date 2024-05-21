#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <stdbool.h>

struct Sensor {
  int tipo;
  int tiempo;
  char nombreArchivo[100];
  char nombrePipe[100];
};
//Asignación de los datos
void llenarDatos(struct Sensor *sensor, char instruccion[], char contenido[]);
//Lectura de los datos
void imprimirDatos(struct Sensor sensor);

int main(int argc, char *argv[]){
  struct Sensor sensor;
  sensor.tipo = -1;
  sensor.tiempo = -1;
  sensor.nombreArchivo[0] = '\0';
  sensor.nombrePipe[0] = '\0';
  for(int i = 1; i < argc; i+=2){
    llenarDatos(&sensor, argv[i], argv[i+1]);
  }
  if(sensor.tipo == -1 || sensor.tiempo == -1 || 
    sensor.nombreArchivo[0] == '\0' || sensor.nombrePipe[0] == '\0'){
    printf("Error: Faltan datos\n");
    return -1;
  }
  imprimirDatos(sensor);
}

//Asignación de los datos
void llenarDatos(struct Sensor *sensor, char instruccion[], char contenido[]){
  if(strcmp(instruccion, "-s") == 0){
    sensor->tipo = atoi(contenido);
  }  
  if(strcmp(instruccion, "-t") == 0){
    sensor->tiempo = atoi(contenido);
  }
  if(strcmp(instruccion, "-f") == 0){
    strcpy(sensor->nombreArchivo, contenido);
  }
  if(strcmp(instruccion, "-p") == 0){
    strcpy(sensor->nombrePipe, contenido);
  }
}
//Lectura de los datos
void imprimirDatos(struct Sensor sensor){
  printf("Tipo: %d\n", sensor.tipo);
  printf("Tiempo: %d\n", sensor.tiempo);
  printf("Nombre del archivo: %s\n", sensor.nombreArchivo);
  printf("Nombre del pipe: %s\n", sensor.nombrePipe);
}



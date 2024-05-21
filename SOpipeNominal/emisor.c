//Autor: JUan Diego Reyes
// Fecha: 23/ 04 / 2024
// Materia Sistemas Operativos
// Tema: Pipe Nominal
/*
Se quiere enviar un mensaje a un proceso, con un nombre determinado. El proceso independientemente recibe el mensaje 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]){
  mkfifo("NombreMensaje", 0666);
  int pipeNM = open("NombreMensaje", O_WRONLY);
  // Se escribe el mensaje en el pipe
  char mensaje[] = "Primero que nada buenos días";
  write(pipeNM, mensaje, strlen(mensaje) + 1);
}
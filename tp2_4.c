#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct 
{
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
}typedef compu;
  
void listarPCs(compu pcs[], int cantidad);
void mostrarMasVieja(compu pcs[], int cantidad);
void mostrarMasVeloz(compu pcs[], int cantidad);

int main () {
    srand(time(NULL));
    int num = 5;
    compu Pc[num];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};
    

    for (int i = 0; i < num ; i++)
    {
        Pc[i].velocidad = 1 + rand() % (3 - 1 + 1);
        Pc[i].anio = 2015 + rand() % (2024 - 2015 + 1);
        Pc[i].cantidad_nucleos = 1 + rand() % (8 - 1 + 1);
        Pc[i].tipo_cpu = tipos[rand() % 6];

    }

    listarPCs(Pc, num);
    
    mostrarMasVieja(Pc, num);

    mostrarMasVeloz(Pc, num);



    return 0;
}   
void listarPCs(compu pcs[], int cantidad){ 

    printf("Lo datos de las pcs son:\n");
    
    for (int i = 0; i < cantidad; i++)
    {
        
        printf("Pc N° %d\nTipo de procesador: %s\nAño de fabricacion: %d\nCantidad de nucleos: %d\nVelocidad del procesador: %d GHz\n", i+1, pcs[i].tipo_cpu, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].velocidad);

    }
    

}
void mostrarMasVieja(compu pcs[], int cantidad) {
    
    int num = 0 ;
    
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio > pcs[num].anio)
        {
            num = i;
        }
    }
    printf("La pc mas vieja es:\nTipo de procesador: %s\nAño de fabricacion: %d\nCantidad de nucleos: %d\nVelocidad del procesador: %d GHz\n", pcs[num].tipo_cpu, pcs[num].anio, pcs[num].cantidad_nucleos, pcs[num].velocidad);

}
void mostrarMasVeloz(compu pcs[], int cantidad){

    int num = 0 ;
    
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad > pcs[num].velocidad)
        {
            num = i;
        }
    }
    printf("La pc mas veloz es:\nTipo de procesador: %s\nAño de fabricacion: %d\nCantidad de nucleos: %d\nVelocidad del procesador: %d GHz\n", pcs[num].tipo_cpu, pcs[num].anio, pcs[num].cantidad_nucleos, pcs[num].velocidad);

}        
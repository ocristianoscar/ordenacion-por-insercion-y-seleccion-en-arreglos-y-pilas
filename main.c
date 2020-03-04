#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pila.h"


#define CANT 10     //en este programa se usan arreglos con dimensión fija. En la práctica, se debe proveer a las funciones con el arreglo y con su numero de elementos (validos)
#define MAX_RAND 101

//PROTOTIPADOS

//arreglos
void mostrarArreglo(int a[]);
void crearArregloRandom(int a[]);

//pilas
//void crearPilaRandom(Pila);

//insercion arreglos
void ordenarArregloPorInsercion(int a[]);

//insercion pilas
//void prepararPilaParaOrdenarPorInsercion(Pila, Pila);


int main()
{
    srand(time(NULL));

    printf("ORDENACIÓN POR INSERCIÓN EN ARREGLOS Y PILAS\n\n");

    int a[CANT];
    crearArregloRandom(a);

    int a_copia[CANT];
    memcpy(a_copia, a, sizeof(a));

    printf("arreglo antes de ordenar:\n");
    mostrarArreglo(a);
    //mostrarArreglo(a_copia);

    ordenarArregloPorInsercion(a);

    printf("\n\narreglo luego de ser ordenado por inserción:\n");
    mostrarArreglo(a);

    Pila pila1, pila2, pila3;
    inicpila(&pila1);
    inicpila(&pila2);
    inicpila(&pila3);

    for(int i=0 ; i<CANT ; i++)     //lleno una pila con numeros random
    {
        //num = rand()%MAX_RAND;
        apilar(&pila1, rand()%MAX_RAND);
    }

    printf("\n\npila antes de ser ordenada:\n");
    mostrar(&pila1);

    //comienzo de la ordenación por insercion

    while(!pilavacia(&pila1))       //paso todos los elementos menos la base a otra pila
    {
        apilar(&pila2, desapilar(&pila1));
    }
    apilar(&pila1, desapilar(&pila2));

    //mostrar(&pila1);
    //mostrar(&pila2);

    while(!pilavacia(&pila2))
    {
        if(!pilavacia(&pila1) && (tope(&pila2) < tope(&pila1)))
        {
            apilar(&pila3, desapilar(&pila1));  //va desapilando la pila a ordenar de a un elemento y lo pone en una otra pila auxiliar
        }
        else
        {
            apilar(&pila1, desapilar(&pila2));      //apila el tope de la pila 2 en su posicion correspondiente
            if(!pilavacia(&pila3))
            {
                while(!pilavacia(&pila3))
                {
                    apilar(&pila1, desapilar(&pila3));       //vuelve a colocar los elementos de la pila auxiliar en la principal
                }
            }
        }
    }

    printf("\n\npila luego de ser ordenada por insercion:\n");
    mostrar(&pila1);



    return 0;
}



//DEFINICIONES

void mostrarArreglo(int a[])
{
    printf("|");
    for (int i = 0; i < CANT; i++)
        printf(" %i |", a[i]);
    printf("\n");
}

void crearArregloRandom(int a[])
{
    for (int i = 0; i < CANT; i++)
        a[i] = rand()%MAX_RAND;
}


void ordenarArregloPorInsercion(int a[])
{
    for (int i = 0; i < CANT; i++)
    {
        for (int j = i; j > 0 ; j--)
        {
            if ( a[j] < a[j-1] )
            {
                int aux = a[j];
                a[j] = a[j-1];
                a[j-1] = aux;
            }
        }
    }
}


//por qué carajo no andan estas (preguntar en tutorias)

/*void crearPilaRandom(Pila pila)
{
    int num;
    for(int i=0 ; i<CANT ; i++)
    {
        //num = rand()%MAX_RAND;
        apilar(&pila, 4);
    }
}*/


/*void prepararPilaParaOrdenarPorInsercion(Pila pila1, Pila pila2)
{
    while(!pilavacia(&pila1))
    {
        apilar(&pila2, desapilar(&pila1));
    }
    apilar(&pila1, desapilar(&pila2));
}*/

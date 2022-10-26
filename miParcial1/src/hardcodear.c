/*
 * hardcodear.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Luca
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aritmetica.h"
#include "validaciones.h"
#include "output.h"
#include "hardcodear.h"

///////////////////////////////////////////////////////HARDCODEO///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int hardcodearMascotas(int* pLegajo ,eMascota vec[], int tam, int cant)
{

	/*int cant, es la cantidad que quiero que me cargue.
	 * porque el vector puede ser de 10.000, pero que me cargue 10 nomas*/
    int todoOk = 0;

    eMascota mascotas[] =
	{
		{1000,"Ruby",101, 103, 9, 's', 0},
		{1001,"Norberto" ,103, 101, 7, 's', 0},
		{1002,"Toto", 102, 100, 2, 'n',0},
		{1003,"Tutu",101, 103, 10, 's' ,0},
		{1004,"Lolo", 101, 102, 19, 'n',0},
		{1005,"Renata",100, 100, 19, 'n' ,0},
		{1006,"Bicho", 103, 102, 1, 's',0},
		{1007,"Pulga",102, 100, 1, 's' ,0},

	};


    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = mascotas[i];
      *pLegajo = *pLegajo + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearTrabajos(int* pLegajo ,eTrabajo vec[], int tam, int cant)
{

	/*int cant, es la cantidad que quiero que me cargue.
	 * porque el vector puede ser de 10.000, pero que me cargue 10 nomas*/
    int todoOk = 0;

    eTrabajo trabajos[] =
	{
		{10000,1002,20000,{2,8,2001},0},
		{10001,1003,20002,{19,6,2003} ,0},
		{10002,1000,20001,{25,11,2003} ,0},
		{10003,1001,20000,{30,11,1999} ,0},

	};


    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = trabajos[i];
      *pLegajo = *pLegajo + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}


/*
 * aritmetica.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luca
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aritmetica.h"
#include "validaciones.h"

/////////////////////////////////////////////////////////INCIALIZAR//////////////////////////////////////////////////////////////////////////////////////////////////////

int inicializarMascotas(eMascota vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}
int inicializarTrabajos(eTrabajo vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}
////////////////////////////////////////////////////////MENUS///////////////////////////////////////////////////////////////////////////////////////////////////
char menu()
{
    char opcion;
    printf("\n\n*** ABM Alumnos ***\n\n");
    printf("A- Alta Mascota\n");
    printf("B- Modificar Mascota\n");
    printf("C- Baja Mascota\n");
    printf("D- Listar Mascotas\n");
    printf("E- Listar Tipos\n");
    printf("F- Listar Colores\n");
    printf("G- Listar Servicios\n");
    printf("H- Alta Trabajo\n");
    printf("I- Listar Trabajos\n");
    printf("S- Salir.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);

    return opcion;
}

int subMenuModificar()
{
	int opcion;

	printf("\n\nModificar mascota\n\n");
	printf("1- Tipo\n");
	printf("2- Vacunacion\n");
	printf("Que desea modificar?: ");
	scanf("%d", &opcion);

	return opcion;
}

///////////////////////////////////////////////////////BUSCAR LIBRE///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarLibreMascotas(int* pIndice, eMascota vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajos(int* pIndice, eTrabajo vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}


///////////////////////////////////////////////////////ALTA///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int altaMascotas(int* pLegajo, eMascota vecMascotas[], eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores)
{
	char seguir;
    int todoOk = 0;
    int indice;
    eMascota auxMascota;

    if(pLegajo != NULL && vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores > 0)
    {
    	do
    	{
    		printf("**** Alta Mascotas ****\n\n");
    		buscarLibreMascotas(&indice, vecMascotas, tamMascotas);
			if(indice == -1)
			{
				printf("No hay lugar en el sistema.\n");
			}
			else
			{
				cargarMascota(&auxMascota, vecTipos,vecColores,tamMascotas,tamTipos,tamColores);
				auxMascota.id = *pLegajo;
				*pLegajo = *pLegajo + 1;
				vecMascotas[indice] = auxMascota;
				todoOk = 1;
			}
			printf("Le gustaria ingresar otra mascota:");
			fflush(stdin);
			scanf("%c", &seguir);
			validarCaracterSeguir(&seguir);

    	}while(seguir != 'n');


    }
    return todoOk;
}

int altaTrabajos(int* pLegajo, eMascota vecMascotas[], eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores, eTrabajo vecTrabajos[], int tamTrabajos)
{
	char seguir;
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pLegajo != NULL && vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && vecTrabajos != NULL &&tamMascotas > 0 && tamTipos > 0 && tamColores > 0 && tamTrabajos > 0)
    {
    	do
    	{
    		printf("**** Alta Trabajos ****\n\n");
    		buscarLibreTrabajos(&indice, vecTrabajos, tamTrabajos);
			if(indice == -1)
			{
				printf("No hay lugar en el sistema.\n");
			}
			else
			{
				cargarTrabajo(vecMascotas, vecTipos,vecColores,tamMascotas,tamTipos,tamColores, &auxTrabajo, tamTrabajos);
				auxTrabajo.id = *pLegajo;
				*pLegajo = *pLegajo + 1;
				vecTrabajos[indice] = auxTrabajo;
				todoOk = 1;
			}
			printf("Le gustaria ingresar otro trabajo:");
			fflush(stdin);
			scanf("%c", &seguir);
			validarCaracterSeguir(&seguir);

    	}while(seguir != 'n');


    }
    return todoOk;
}

///////////////////////////////////////////////////CARGAR////////////////////////////////////////////////////////////////////////////
int cargarMascota(eMascota * pMascota,  eTipo vecTipos[], eColor vecColor[], int tamMascotas, int tamTipos, int tamColores )
{
    int todoOk = 0;
    eMascota auxMascota;

    if(pMascota != NULL)
	{
    	printf("Ingrese nombre de su mascota: ");
		fflush(stdin);
		scanf("%s", auxMascota.nombre);
		validarNombreMascota(&auxMascota, 10);
		strcpy(pMascota->nombre, auxMascota.nombre);

		printf("Ingrese ID tipo: \n");
		mostrarTipos(vecTipos, tamTipos);
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxMascota.idTipo);
		validarIDs(&auxMascota, 1);
		pMascota->idTipo=auxMascota.idTipo;

		printf("Ingrese ID Color: \n");
		mostrarColores(vecColor, tamColores);
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxMascota.idColor);
		validarIDs(&auxMascota, 2);
		pMascota->idColor=auxMascota.idColor;


		printf("Ingrese edad: ");
		scanf("%d", &auxMascota.edad);
		validarEdades(&auxMascota);
		pMascota->edad=auxMascota.edad;

		printf("Su mascota esta vacunada?: ");
		fflush(stdin);
		scanf("%c", &auxMascota.vacunado);
		validarCaracterVacunado(&auxMascota);
		pMascota->vacunado=auxMascota.vacunado;

		pMascota->isEmpty = 0;

		todoOk = 1;
	}

    return todoOk;
}

int cargarTrabajo(eMascota vecMascotas[],  eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores, eTrabajo * pTrabajo, int tamTrabajos)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pTrabajo != NULL)
	{
		mostrarMascotas(vecMascotas,vecTipos,vecColores, tamMascotas,tamTipos,tamColores);
		printf("INGRESE ID DE MASCOTA: \n");
		scanf("%d", &auxTrabajo.idMascota);
		indice=buscarMascota(&indice, auxTrabajo.idMascota, vecMascotas, tamMascotas);
		if(auxTrabajo.idMascota == -1)
		{
			printf("No existe una mascota con ese ID: %d\n", auxTrabajo.idMascota);
		}
		else
		{
			pTrabajo->idMascota=auxTrabajo.idMascota;
		}
		mostrarTipos(vecTipos, tamTipos);
		printf("INGRESE ID TIPO: \n");
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxTrabajo.idServicio);
		validarIDs(vecMascotas, 1);
		pTrabajo->idServicio=auxTrabajo.idServicio;


		printf("Ingrese Fecha de Nacimiento: \n");
		printf("Ingrese dia: ");
		scanf("%d", &auxTrabajo.fecha.dia);
		validarFecha(&auxTrabajo, 1);
		pTrabajo->fecha.dia=auxTrabajo.fecha.dia;

		printf("Ingrese mes: ");
		scanf("%d", &auxTrabajo.fecha.mes);
		validarFecha(&auxTrabajo, 2);
		pTrabajo->fecha.mes=auxTrabajo.fecha.mes;

		printf("Ingrese año: ");
		scanf("%d", &auxTrabajo.fecha.anio);
		validarFecha(&auxTrabajo, 3);
		pTrabajo->fecha.anio=auxTrabajo.fecha.anio;

		pTrabajo->isEmpty = 0;

		todoOk = 1;
	}

    return todoOk;
}

int cargarDescripcionTipos(int idTipos, char descripcion[], eTipo vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idTipos)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionColores(int idColor, char descripcion[], eColor vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idColor)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionMascota(int idMascotas, char descripcion[], eMascota vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idMascotas)
			{
				strcpy(descripcion, vec[i].nombre);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionServicio(int idServicios, char descripcion[], eServicio vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idServicios)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}
///////////////////////////////////////////////////////MOSTRAR////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int mostrarMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores)
{
    int todoOk = 0;
    int flag = 1;

    if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores >0)
    {

        printf("                          **** LISTA DE MASCOTAS ****\n");
        printf("------------|--------------|--------------|--------------|------------|---------------|\n");
        printf("ID MASCOTA  |    NOMBRE    |     TIPO     |    COLOR     |    EDAD    | ESTA VACUNADO?|\n");
        printf("------------|--------------|--------------|--------------|------------|---------------|\n");
        for(int i = 0 ; i < tamMascotas ; i++)
        {
            if(!vecMascotas[i].isEmpty)
            {
				mostrarMascota(vecMascotas[i], vecTipos, vecColores, tamTipos, tamColores);
				flag = 0;
				todoOk = 1;
            }
        }
        if(flag)
        {
            printf("\n*****************NO HAY MASCOTAS EN EL SISTEMA*****************\n\n");
            todoOk=-1;
        }
	}

    return todoOk;
}

int mostrarMascota(eMascota mascota, eTipo vecTipos[],eColor vecColores[] , int tamTipos, int tamColores )
{
    int todoOk = 0;
    char color[20];
    char tipo[20];

    cargarDescripcionTipos(mascota.idTipo, tipo,vecTipos, tamTipos);
    cargarDescripcionColores(mascota.idColor, color,vecColores, tamColores);



    printf("%4d        |    %10s|    %10s|  %10s  |     %3d    |      %3c      |\n",
    		mascota.id,
			mascota.nombre,
			tipo,
			color,
			mascota.edad,
			mascota.vacunado);

    return todoOk;
}


int mostrarTipos(eTipo vec[], int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam > 0)
	{
		printf("    |***Lista de Tipos*** |\n");
		printf("----|------------------------|\n");
		printf(" ID |            Descripcion |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |\n", vec[i].id, vec[i].descripcion);
		}
		printf("\n\n");

		todoOk=1;
	}
	return todoOk;
}

int mostrarColores(eColor vec[], int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam > 0)
	{
		printf("    |***Lista de Colores***  |\n");
		printf("----|------------------------|\n");
		printf(" ID |            Descripcion |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |\n", vec[i].id, vec[i].descripcion);
		}
		printf("\n\n");

		todoOk=1;
	}
	return todoOk;
}

int mostrarServicios(eServicio vec[], int tam)
{
	int todoOk=0;

		if(vec!=NULL && tam > 0)
		{
			printf("     | ***Lista Servicios***|       \n");
			printf("-----|----------------------|-------\n");
			printf(" ID  |           Descripcion| Precio\n");
			printf("-----|----------------------|-------\n");

			for(int i=0; i<tam;i++)
			{
				printf("%4d|  %20s|  %4d\n", vec[i].id, vec[i].descripcion, vec[i].precio);
			}
			printf("\n\n");

			todoOk=1;
		}
		return todoOk;
}

int mostrarTrabajos(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores, eTrabajo vecTrabajos[], int tamTrabajos, eServicio vecServicios[], int tamServicios)
{
    int todoOk = 0;
    int flag = 1;

    if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && vecTrabajos != NULL &&tamMascotas > 0 && tamTipos > 0 && tamColores >0 && tamTrabajos>0)
    {

        printf("                          **** LISTA DE MASCOTAS ****\n");
        printf("------------|--------------|-------------------|--------------|\n");
        printf("ID TRABAJO  |    NOMBRE    |     SERVICIO      |    FECHA     |\n");
        printf("------------|--------------|-------------------|--------------|\n");
        for(int i = 0 ; i < tamMascotas ; i++)
        {
            if(!vecTrabajos[i].isEmpty)
            {
				mostrarTrabajo(vecMascotas, vecTipos, vecColores, tamMascotas, tamTipos, tamColores, vecTrabajos[i], tamTrabajos, vecServicios,tamServicios);
				flag = 0;
				todoOk = 1;
            }
        }
        if(flag)
        {
            printf("\n*****************NO HAY MASCOTAS EN EL SISTEMA*****************\n\n");
            todoOk=-1;
        }
	}

    return todoOk;
}

int mostrarTrabajo(eMascota vecMascota[], eTipo vecTipos[],eColor vecColores[],int tamMascotas, int tamTipos, int tamColores, eTrabajo trabajo, int tamTrabajo, eServicio vecServicios[], int tamServicios)
{
    int todoOk = 0;
    char mascota[20];
    char servicio[20];

    cargarDescripcionMascota(trabajo.idMascota, mascota,vecMascota, tamMascotas);
    cargarDescripcionServicio(trabajo.idServicio, servicio,vecServicios, tamServicios);



    printf("%4d       |    %10s|  %15s  |   %2d/%2d/%4d |\n",
    		trabajo.id,
			mascota,
			servicio,
			trabajo.fecha.dia,
			trabajo.fecha.mes,
			trabajo.fecha.anio);

    return todoOk;
}

///////////////////////////////////////////////////////MODIFICAR/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int modificarMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores)
{
 int todoOk = 0;
	int legajo;
	int indice;
	char confirma;
	char seguir;
	int modificar;
	int flag;
	eMascota auxMascota;

	if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores >0)
	{
		printf("**** Modificar Alumno ****\n\n");

		flag=mostrarMascotas(vecMascotas,vecTipos,vecColores ,tamMascotas,tamTipos , tamColores);
		if(flag==-1)
		{
			printf("Primero debe haber un algún alumno dado de alta para realizar una modificacion\n\n");
		}
		else
		{
			do
			{
				printf("\nIngrese ID de la mascota a modificar: ");
				scanf("%d", &legajo);

				buscarMascota(&indice, legajo, vecMascotas, tamMascotas);
				if(indice == -1)
				{
					printf("No existe una mascota con ese ID: %d\n", legajo);
				}
				else
				{
					mostrarMascota(vecMascotas[indice], vecTipos,vecColores ,tamTipos,tamColores);
					modificar=subMenuModificar();

					switch(modificar)
					{
						case 1:
						//TIPOS
							mostrarTipos(vecTipos, tamTipos);
							printf("Ingrese id nuevo tipo: ");
							scanf("%d", &auxMascota.idTipo);
							validarIDs(&auxMascota, 1);
							printf("Confirma modificacion?: ");
							fflush(stdin);
							confirma = getchar();
							if(confirma == 's')
							{
								vecMascotas[indice].idTipo=auxMascota.idTipo;
								mostrarMascota(vecMascotas[indice], vecTipos,vecColores ,tamTipos,tamColores);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;
						case 2:

							printf("\nEsta vacunada su mascota? s/n: ");
							fflush(stdin);
							scanf("%c",&auxMascota.vacunado);
							validarCaracterVacunado(&auxMascota);
							printf("Confirma modificacion?: ");
							fflush(stdin);
							confirma = getchar();
							if(confirma == 's')
							{
								vecMascotas[indice].vacunado=auxMascota.vacunado;
								mostrarMascota(vecMascotas[indice], vecTipos,vecColores ,tamTipos,tamColores);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("Se ha cancelado la modificacion.\n\n");
							}
							break;

						default:
							break;
						}

						printf("Desea cambiar otra area?:");
						fflush(stdin);
						scanf("%c", &seguir);
						validarCaracterSeguir(&seguir);

					}

			}while(seguir!='n');
		}
		todoOk = 1;
	}
	return todoOk;
}

////////////////////////////////////////////////////////////////BUSCAR//////////////////////////////////////////////////////////////////////////////////
int buscarMascota(int* pIndice, int legajo, eMascota vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( !vec[i].isEmpty && vec[i].id == legajo )
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}
////////////////////////////////////////////////////////////////BAJA//////////////////////////////////////////////////////////////////////////////////


int bajaMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores)
{

    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    int flag;//para ver si hay o no gente para dar de baja
    if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores >0)
    {
        printf("**** Baja Alumno ****\n\n");

        flag=mostrarMascotas(vecMascotas,vecTipos,vecColores, tamMascotas,tamTipos,tamColores);
		if(flag==-1)
		{
			printf("Primero debe haber un algún alumno dado de alta para realizar una baja\n\n");
		}
		else
		{
			printf("Ingrese legajo a dar de baja: ");
			scanf("%d", &legajo);

			buscarMascota(&indice, legajo, vecMascotas, tamMascotas);
			if(indice == -1)
			{
				printf("No existe un alumno con legajo: %d\n", legajo);
			}
			else
			{
				mostrarMascota(vecMascotas[indice], vecTipos,vecColores, tamTipos, tamColores);
				printf("Confirma baja?: ");
				fflush(stdin);
				confirma = getchar();

				if(confirma == 's')
				{
					vecMascotas[indice].isEmpty = 1;
					printf("Baja exitosa.\n");
				}
				else
				{
					printf("Se ha cancelado la baja.\n");
				}
			}
			todoOk = 1;
		}
    }
    return todoOk;
}

//////////////////////////////////////////////////////////////ORDENAR//////////////////////////////////////////////////////////////////////////////////////////////////////////
int ordenarMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores)
{
	int todoOk = 0;
	eMascota aux;

		    if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores >0)
		    {
		        for(int i = 0 ; i < tamMascotas  - 1 ; i++)
		        {
		            for(int j = i + 1 ; j < tamMascotas ; j++)
		            {
						if((vecMascotas[i].idTipo > vecMascotas[j].idTipo)
							||(vecMascotas[i].idTipo == vecMascotas[j].idTipo
							&& strcmp(vecMascotas[i].nombre, vecMascotas[j].nombre) > 0))
							{
								aux = vecMascotas[i];
								vecMascotas[i] = vecMascotas[j];
								vecMascotas[j] = aux;
							}
		            }
		        }
		        todoOk = 1;
		    }
		    return todoOk;
}

///////////////////////////////////////////////////////HARDCODEO///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int hardcodearMascotas(int* pLegajo ,eMascota vec[], int tam, int cant)
{

	/*int cant, es la cantidad que quiero que me cargue.
	 * porque el vector puede ser de 10.000, pero que me cargue 10 nomas*/
    int todoOk = 0;

    eMascota mascotas[] =
	{
		{1000,"Ruby",101, 100, 9, 's', 0},
		{1001,"Norberto" , 103, 101, 7, 's', 0},
		{1002,"Toto", 102, 101, 2, 'n',0},
		{1003,"Lulu",103, 103, 13, 'n' ,0},

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

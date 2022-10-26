/*
 * aritmetica.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luca
 */

#ifndef ARITMETICA_H_
#define ARITMETICA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char descripcion[20];
}eTipo;

typedef struct
{
	int id;
	char descripcion[20];
}eColor;


typedef struct
{
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int edad;
	char vacunado;
	int isEmpty;
}eMascota;

typedef struct
{
	int id;//comienza en 20 000
	char descripcion[20];
	int precio;
}eServicio;

typedef struct
{
	int id;//autoincremental
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

#endif /* ARITMETICA_H_ */

/**
 * @brief inicializa las mascotas, isEmpty en 1
 * @param vec
 * @param tam
 * @return
 */
int inicializarMascotas(eMascota vec[], int tam);



/**
 * @brief Incializa los trabajos, isEmpty en 1
 * @param vec
 * @param tam
 * @return
 */
int inicializarTrabajos(eTrabajo vec[], int tam);


/**
 * @brief busca un espacio libre en mascotas, osea un 1 en isEmpty
 * @param pIndice
 * @param vec
 * @param tam
 * @return
 */
int buscarLibreMascotas(int* pIndice, eMascota vec[], int tam);



/**
 * @brief Agrega una mascota
 * @param pLegajo
 * @param vecMascotas
 * @param vecTipos
 * @param vecColores
 * @param tamMascotas
 * @param tamTipos
 * @param tamColores
 * @return
 */

int altaMascotas(int* pLegajo, eMascota vecMascotas[], eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores);


/**
 * @brief agrega un trabajo
 * @param pLegajo
 * @param vecMascotas
 * @param vecTipos
 * @param vecColores
 * @param tamMascotas
 * @param tamTipos
 * @param tamColores
 * @param vecTrabajos
 * @param tamTrabajos
 * @return
 */
int altaTrabajos(int* pLegajo, eMascota vecMascotas[], eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores, eTrabajo vecTrabajos[], int tamTrabajos, eServicio vecServicios[], int tamServicios);



/**
 * @brief Carga una sola mascota
 * @param pMascota
 * @param vecTipos
 * @param vecColor
 * @param tamMascotas
 * @param tamTipos
 * @param tamColores
 * @return
 */
int cargarMascota(eMascota * pMascota,  eTipo vecTipos[], eColor vecColor[], int tamMascotas, int tamTipos, int tamColores );




/**
 * @brief carga un trabajo
 * @param vecMascotas
 * @param vecTipos
 * @param vecColores
 * @param tamMascotas
 * @param tamTipos
 * @param tamColores
 * @param pTrabajo
 * @param tamTrabajos
 * @return
 */
int cargarTrabajo(eMascota vecMascotas[],  eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores, eTrabajo * pTrabajo, int tamTrabajos, eServicio vecServicios[], int tamServicios);


/**
 * @brief carga la descripcion de tipos
 * @param idTipos
 * @param descripcion
 * @param vec
 * @param tam
 * @return
 */
int cargarDescripcionTipos(int idTipos, char descripcion[], eTipo vec[], int tam);


/**
 * @brief carga la descripcion de colores
 * @param idColor
 * @param descripcion
 * @param vec
 * @param tam
 * @return
 */
int cargarDescripcionColores(int idColor, char descripcion[], eColor vec[], int tam);

/**
 * @brief Carga la descripcion de mascotas
 * @param idMascotas
 * @param descripcion
 * @param vec
 * @param tam
 * @return
 */
int cargarDescripcionMascota(int idMascotas, char descripcion[], eMascota vec[], int tam);

/**
 * @brief Carga la descripcion de Servicios
 * @param idServicios
 * @param descripcion
 * @param vec
 * @param tam
 * @return
 */
int cargarDescripcionServicio(int idServicios, char descripcion[], eServicio vec[], int tam);



/**
 * @brief modifica a la mascota que seleccionamos, dependediendo si elegimos tipo o vacunacion
 * @param vecMascotas
 * @param vecTipos
 * @param vecColores
 * @param tamMascotas
 * @param tamTipos
 * @param tamColores
 * @return
 */
int modificarMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores);




/** Busca por id a la mascota que necesita el usuario
 * @brief
 * @param pIndice
 * @param legajo
 * @param vec
 * @param tam
 * @return
 */
int buscarMascota(int* pIndice, int legajo, eMascota vec[], int tam);



/** Da de baja una mascota
 * @brief
 * @param vecMascotas
 * @param vecTipos
 * @param vecColores
 * @param tamMascotas
 * @param tamTipos
 * @param tamColores
 * @return
 */
int bajaMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores);


/**
 * @brief ordena por tipo, pero si los tipos son iguales, los ordena por nombre
 * @param vecMascotas
 * @param vecTipos
 * @param vecColores
 * @param tamMascotas
 * @param tamTipos
 * @param tamColores
 * @return
 */
int ordenarMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores);


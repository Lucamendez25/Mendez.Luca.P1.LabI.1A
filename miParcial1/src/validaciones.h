/*
 * validaciones.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luca
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



/**
 * @brief valida el si quiere seguir, o no
 * @param seguir
 * @return
 */
int validarCaracterSeguir(char *);

/**
 * @brief valida el nombre de la mascota
 * @param pMascota
 * @param tam
 * @return
 */
int validarNombreMascota(eMascota *pMascota, int tam);

/**
 * @brief valida id, dependiendo la condicion
 * @param pMascota
 * @param condicion
 * @return
 */
int validarIDs(eMascota *pMascota, int condicion);

/**
 * @brief valida id servicios
 *
 * @param vecServicios
 * @param id
 * @param tam
 * @return
 */
int validarIdServicios(eServicio vecServicios[],int id,  int tam);



/**
 * @brief valida las edades de las mascotas
 * @param pMascota
 * @return
 */
int validarEdades(eMascota *pMascota);

/**valida la s o la n
 * @brief
 * @param pMascota
 * @return
 */
int validarCaracterVacunado(eMascota *pMascota);

/**
 * @brief dependiendo el criterio que le mando, valida fecha
 * @param pTrabajo
 * @param crit
 * @return
 */
int validarFecha(eTrabajo *pTrabajo, int crit);


#endif /* VALIDACIONES_H_ */

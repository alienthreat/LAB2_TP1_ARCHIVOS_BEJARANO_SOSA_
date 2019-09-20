#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
/** #############################################################################
 ARCHIVO             : menu.h
 AUTOR/ES            : GABRIEL BEJARANO, FRANCISCO SOSA
 VERSION             : 0.01 beta.
 FECHA DE CREACION   : 07/09/2019.
 ULTIMA ACTUALIZACION: 07/09/2019.
 LICENCIA            : GPL (General Public License) - Version 3.

  **************************************************************************/
/*****************************************************************************
                             INCLUSIONES PERSONALES
/*=============================================================================**/
#include <iostream>
#include <cstdlib>  /** Libreria estandar que contiene la funcion exit(). */
#include <cstdio>   /** Libreria para manejo de archivos. */
#include <locale>   /** Libreria para manejo de Idiomas */
#include <cstring>  /** Libreria para el manejo de cadenas de texto tDato String */
#include <windows.h>
#include "../CSYSTEM/csystem.h" /** Libreria para multiplataforma. */
#include "./materias.h" /** LIBRERIA DE FUNCIONES PARA MATERIAS **/
#include "./alumnos.h" /** LIBRERIA DE FUNCIONES PARA ALUMNOS **/
#include "./relacional.h" /** LIBRERIA DE FUNCIONES RELACIONALES ENTRE ARCHIVOS**/
#include "./mensajes.h"    /** TEXTOS DE LA APLICACION - Y SI, MUCHO MAS COMODO ! */
/**=============================================================================**/



/**=============================================================================
 FUNCION : void menuPpal()
 ACCION : Funcion del Menu Principal
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
char validarOpcionPrincipal(char* opcion)
{
    bool valido = false;
    while(!valido)
    {
        if((opcion[0] == 49) || (opcion[0] == 50) || (opcion[0] == 51)
                || (opcion[0] == 52) || (opcion[0] == 53)
                || (opcion[0] == 54) || (opcion[0] == 55)
                || (opcion[0] == 56) || (opcion[0] == 57)
                || (opcion[0] == 82) || (opcion[0] == 114)
          )
        {
            valido = true;
            return opcion[0];
        }
        else
        {
            cout << endl;
            txtElijaOp();
            txtNoOpcion(opcion);
//            textoPresioneTeclaParaContinuar();
            sys::cls();
//            textoMenuPrincipal();
            sys::getline(opcion,1);
        }
    }
    return 'e';
}


/**=============================================================================
 FUNCION : void subMaterias()
 ACCION : Muestra y permite el acceso a las funciones de gestion de materias
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
bool subAlumnos(char *op)
{
    bool exit=false;
    switch(validarOpcionPrincipal(op))
    {
    case 49:
    {
        //ALTA DE ALUMNOS
        altaAlumno();
    }
    break;
    case 50:
    {
        //LISTADO DE ALUMNOS
        fMostrarListadoAlumnos();
    }
    break;
    case 51:
    {
        //MODIFICAR ALUMNOS.
        modificarAlumno();
    }
    break;
    case 52:
    {
        //BAJA DE MATERIAS.
        bajaAlumno();
    }
    break;
    case 53:
    {
        //ASIGNAR MATERIAS A ALUMNO
        AsignarMtoA();
    }
    break;
    case 54:
    {
        //MOSTRAR MATERIAS POR ALUMNO
        mostrarMsxA();
    }
    break;
    case 55:
    {

    }
    break;
    case 56:
    {

    }
    break;
    case 57:
    {
        exit = true;

    }
    break;
    default:
    {
        txtElijaOp();
        txtNoOpcion(op);
        txtPresioneTeclaParaContinuar();
    }
    break;
    }
    return exit;
}


/**=============================================================================
 FUNCION : void subMaterias()
 ACCION : Muestra y permite el acceso a las funciones de gestion de materias
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
bool subMaterias(char *op)
{
    bool exit=false;
    switch(validarOpcionPrincipal(op))
    {
    case 49:
    {
        //ALTA DE MATERIAS
        altaMateria();
    }
    break;
    case 50:
    {
        //LISTADO DE MATERIAS
        fMostrarListadoMaterias();
    }
    break;
    case 51:
    {
        //MODIFICAR MATERIAS.
        modificarMateria();
    }
    break;
    case 52:
    {
        //BAJA DE MATERIAS.
        bajaMateria();
    }
    break;
    case 53:
    {
        //ASIGNAR MATERIAS A ALUMNO
        AsignarAtoM();
    }
    break;
    case 54:
    {
        //MOSTRAR MATERIAS POR ALUMNO
        mostrarMsxA();
    }
    break;
    case 55:
    {

    }
    break;
    case 56:
    {

    }
    break;
    case 57:
    {
        exit = true;

    }
    break;
    default:
    {
        txtElijaOp();
        txtNoOpcion(op);
        txtPresioneTeclaParaContinuar();
    }
    break;
    }
    return exit;
}

/**=============================================================================
 FUNCION : void menuPpal()
 ACCION : Funcion del Menu Principal
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void menuPpal()
{
    char *op;
    bool salir = false;
    while(!salir)
    {
        sys::cls();
        txtMenuPrincipal();
        sys::getline(op,1);
        //MATERIAS
        switch(validarOpcionPrincipal(op))
        {
        case 49:
        {
            bool salirM = false;
            while(!salirM)
            {
                sys::cls();
                txtMaterias();
                sys::getline(op,1);
                salirM=subMaterias(op);
            }
        }
        break;
        case 50:
        {
            bool salirM = false;
            while(!salirM)
            {
                sys::cls();
                txtAlumnos();
                sys::getline(op,1);
                salirM=subAlumnos(op);
            }

        }
        break;
        case 51:
        {

        }
        break;
        case 52:
        {
        }
        break;
        case 53:
        {

        }
        break;
        case 54:
        {

        }
        break;
        case 55:
        {

        }
        break;
        case 56:
        {

        }
        break;
        case 57:
        {
            salir = true;
        }
        break;
        default:
        {
            sys::cls();
            txtElijaOp();
            txtNoOpcion(op);
            txtPresioneTeclaParaContinuar();
            salir = true;
        }
        }
    }
}




#endif // MENU_H_INCLUDED

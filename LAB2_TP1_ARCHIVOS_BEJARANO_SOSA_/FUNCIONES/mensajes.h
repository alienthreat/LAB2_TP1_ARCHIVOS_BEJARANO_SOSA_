#ifndef MENSAJES_H_INCLUDED
#define MENSAJES_H_INCLUDED

/** #############################################################################
 ARCHIVO             : mensajes.h
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
/**=============================================================================**/

using namespace std;
/**==============================================================================
 FUNCI�N : txtTabs()
 ACCI�N : tabulaciones para texto
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
============================================================================== */
void txtTabs()
{
    cout << "\t \t";
}
/**==============================================================================
 FUNCI�N : txtTab()
 ACCI�N : tabulaciones para texto
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
============================================================================== */
void txtTab()
{
    cout << "\t ";
}

/**==============================================================================//==============================================================================
 FUNCI�N : txtLineas()
 ACCI�N : lineas de separacion
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
============================================================================== */
void txtLineas()
{
    txtTabs(); cout << "||__________________________________________________________||" << endl;
}
/**==============================================================================
 FUNCI�N : textoPresioneTeclaParaContinuar
 ACCI�N : Le muestra un cartel al usuario que le pide presionar una tecla
 para continuar con el programa.
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
==============================================================================*/
void txtPresioneTeclaParaContinuar()
{

    txtTabs(); cout << " Presione una tecla para continuar.";
    cin.get();
    cin.ignore();
}
/**==============================================================================
 FUNCI�N : void txtSinRegistros()
 ACCI�N : Le muestra un cartel al usuario que indica que no existen registros
            en el archivo.
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
==============================================================================*/
void txtSinRegistros()
{
    txtTabs(); cout << "NO EXISTEN REGISTROS EN EL ARCHIVO... Retroceda y cargue un registro, maestro splinter." << endl;
    cin.get();
    cin.ignore();
}

/**==============================================================================
 FUNCI�N : void txtArchivoVacio()
 ACCI�N : Le muestra un cartel al usuario que indica que no existen registros
            en el archivo.
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
==============================================================================*/
void txtArchivoVacio()
{
    txtTabs(); cout << "NO SE CREO NINGUN REGISTRO" << endl;
    cin.get();
    cin.ignore();
}



/**==============================================================================
 FUNCI�N : txtElijaOp()
 ACCI�N : lineas de separacion
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
============================================================================== */
void txtElijaOp()
{
    txtTabs(); txtTabs(); cout << "ELIJA UNA OPCION DEL MENU   : ";
}
/**==============================================================================
 FUNCI�N : txtVolverMenu();
 ACCI�N : lineas de separacion
 PARAMETROS: Ninguno.
 DEVUELVE : nada.
============================================================================== */
void txtVolverMenu()
{
    txtTabs(); cout << "||      9- <<<<----  VOLVER A MENU ANTERIOR/SALIR           ||" << endl;
}

/**=============================================================================
 FUNCION : void txtMenuPrincipal()
 ACCION : texto del Menu Principal
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void txtMenuPrincipal()
{
    txtLineas();
    txtTabs(); cout << "||------------------  MENU PRINCIPAL -----------------------||" << endl;
    txtLineas();
    txtTabs(); cout << "||              1- MATERIAS                                 ||" << endl;
    txtTabs(); cout << "||              2- ALUMNOS                                  ||" << endl;
    txtLineas();
    txtTabs(); cout << "||              3- DLC BLOQUEDO                             ||" << endl;
    txtTabs(); cout << "||              4- DLC BLOQUEADO                            ||" << endl;
    txtTabs(); cout << "||              5- DLC BLOQUEDO                             ||" << endl;
    txtTabs(); cout << "||              6- DLC BLOQUEADO                            ||" << endl;
    txtLineas();
    txtTabs(); cout << "||       0- SI ES TU PRIMERA VEZ CON LA APP, ENTRA ACA!     ||" << endl;
    txtLineas();
    txtVolverMenu();
    txtLineas();
    txtTabs(); cout << "||       R) REINICIAR CONFIGURACION Y CARGA INICIAL         ||" << endl;
    cout << endl;
    txtElijaOp();
}

/**=============================================================================
 FUNCION : void txtMaterias()
 ACCION : texto del Menu materias
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void txtMaterias()
{
    txtLineas();
    txtTabs(); cout << "||------------------  MENU MATERIAS ------------------------||" << endl;
    txtLineas();
    txtTabs(); cout << "||              1- DAR ALTA                                 ||" << endl;
    txtTabs(); cout << "||              2- LISTADO                                  ||" << endl;
    txtTabs(); cout << "||              3- MODIFICAR                                ||" << endl;
    txtTabs(); cout << "||              4- GENERAR BAJA                             ||" << endl;
    txtTabs(); cout << "||              5- ASIGNACION DE MATERIA A ALUMNOS          ||" << endl;
    txtTabs(); cout << "||              6- LISTADO DE ALUMNOS POR MATERIA           ||" << endl;
    txtLineas();
    txtTabs(); cout << "||              7- DLC BLOQUEDO                             ||" << endl;
    txtTabs(); cout << "||              8- DLC BLOQUEDO                             ||" << endl;
    txtLineas();
    txtTabs(); cout << "||       0- SI ES TU PRIMERA VEZ CON LA APP, ENTRA ACA!     ||" << endl;
    txtLineas();
    txtVolverMenu();
    txtLineas();
    cout << endl;
    txtElijaOp();

}
/**=============================================================================
 FUNCION : void txtAlumnos()
 ACCION : texto del Menu alumnos
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void txtAlumnos()
{
    txtLineas();
    txtTabs(); cout << "||------------------  MENU ALUMNOS ------------------------||" << endl;
    txtLineas();
    txtTabs(); cout << "||              1- ALTA ALUMNO                             ||" << endl;
    txtTabs(); cout << "||              2- LISTADO ALUMNOS                         ||" << endl;
    txtTabs(); cout << "||              3- MODIFICAR ALUMNOS                       ||" << endl;
    txtTabs(); cout << "||              4- GENERAR BAJA                            ||" << endl;
    txtTabs(); cout << "||              5- ASIGNACION DE ALUMNO A MATERIAS         ||" << endl;
    txtTabs(); cout << "||              6- LISTADO DE MATERIAS POR ALUMNO          ||" << endl;
    txtLineas();
    txtTabs(); cout << "||              X- DLC BLOQUEADO                           ||" << endl;
    txtTabs(); cout << "||              X- DLC BLOQUEADO                           ||" << endl;
    txtLineas();
    txtTabs(); cout << "||       0- SI ES TU PRIMERA VEZ CON LA APP, ENTRA ACA!    ||" << endl;
    txtLineas();
    txtVolverMenu();
    txtLineas();
    cout << endl;
    txtElijaOp();

}

/**=============================================================================
 FUNCION : void txtContinuaCarga()
 ACCION : texto del Menu alumnos
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void txtContinuaCarga()
{
      txtTabs();  cout<<"�Desea continuar ?: \n  0 - NO /   1 - SI  "<<endl;
      txtPresioneTeclaParaContinuar();
}

/**=============================================================================
 FUNCI�N : txtNoOpcion(char* opcion)
 ACCI�N : texto de error de ingreso, se imprime junto a la opcion incorrecta  ingresada
 PARAMETROS: *char opcion.
 DEVUELVE : nada.
============================================================================= **/
void txtNoOpcion(char* opcion)
{
    cout << endl;
    txtTabs(); cout << " ' " << opcion << "'" << " NO ES UNA OPCION VALIDA DEL MENU    " << endl;
    txtPresioneTeclaParaContinuar();
}

/**=============================================================================
 FUNCI�N : void txtCargaExitosa()
 ACCI�N : texto de carga exitosa, nada mas nada menos
 PARAMETROS: nada
 DEVUELVE : nada.
============================================================================= **/
void txtCargaExitosa()
{
    txtTabs(); cout << "SE HA CARGADO EL REGISTRO CORRECTAMENTE EN LA BASE DE DATOS CENTRALIZADA. !" << endl;
    txtPresioneTeclaParaContinuar();
}
/**=============================================================================
 FUNCI�N : void txtCargaMateria(int val)
 ACCI�N : muestra en pantalla el mensaje de carga
 PARAMETROS: int val, recibe nro de mensaje a mostrar.
 DEVUELVE : nada.
============================================================================= **/
void txtCargaMateria(int val)
{
    if(val== 1)
    {
        txtTabs();cout<<" MATERIA ";
    }
    else if(val == 2 )
    {
        txtTabs(); cout << "ID_MATERIA "  ;
    }
    else if(val == 3)
    {
        txtTabs(); cout << "PROFESOR " ;
    }

}
/**=============================================================================
 FUNCI�N : void txtCargaMateria(int val)
 ACCI�N : muestra en pantalla el mensaje de carga
 PARAMETROS: int val, recibe nro de mensaje a mostrar.
 DEVUELVE : nada.
============================================================================= **/
void txtCargaAlumno(int val)
{

    if(val== 1)
    {
        txtTabs();cout<<"NOMBRE DEL ALUMNO: ";
    }
    else if(val == 2 )
    {
        txtTabs(); cout << "LEGAJO: "  ;
    }
    else if(val == 3)
    {
        txtTabs(); cout << "APELLIDO: " ;
    }

}





#endif // MENSAJES_H_INCLUDED

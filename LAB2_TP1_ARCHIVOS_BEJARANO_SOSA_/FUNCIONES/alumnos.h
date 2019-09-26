#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED


/** #############################################################################
 ARCHIVO             : alumnos.h
 AUTOR/ES            : GABRIEL BEJARANO, FRANCISCO SOSA
 VERSION             : 0.01 beta.
 FECHA DE CREACION   : 07/09/2019.
 ULTIMA ACTUALIZACION: 07/09/2019.
 LICENCIA            : GPL (General Public License) - Version 3.

  **************************************************************************/
/*****************************************************************************
                             INCLUSIONES PERSONALES
/*=============================================================================**/
#include <cstdlib>  /** Libreria estandar que contiene la funcion exit(). */
#include <iostream>
#include <cstdio>   /** Libreria para manejo de archivos. */
#include <locale>   /** Libreria para manejo de Idiomas */
#include <cstring>  /** Libreria para el manejo de cadenas de texto tDato String */
#include <windows.h>
#include "../CSYSTEM/csystem.h" /** Libreria para multiplataforma. */
#include "./mensajes.h" /** LIBRERIA DE MENSAJES **/
#include "./menu.h" /
/**=============================================================================**/
using namespace std;

const char ALUMNOS[] = "./ARCHIVOS/ALUMNOS.DATA";

/**=============================================================================
 FUNCION : struct tAlumnos()
 ACCION : estructura de las alumnos
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
struct tAlumno
{
    int legajo;
    char nombre[50], apellido[50];
    bool eliminado;
};
/**=============================================================================
 FUNCION : contarMaterias(tAlumno reg)
 ACCION : listar las alumnos del archivo
 PARAMETROS: tAlumno reg
 DEVUELVE : cantidad de alumnos
============================================================================= **/
int contarAlumnos(tAlumno reg)
{
    FILE *p;
    int qtyAlumnos = 0;
    p=fopen(ALUMNOS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tAlumno), 1, p)==1)
        {
            qtyAlumnos++;
        }
    }
    if(qtyAlumnos>0)
        qtyAlumnos++;
    fclose(p);
    return qtyAlumnos;
}


/**=============================================================================
 FUNCION : bool grabarAlumno(tAlumno mat)
 ACCION : Dar de alta alumnos
 PARAMETROS: nada
 DEVUELVE : true si se cargo la alumno, false si no lo consigue.
============================================================================= **/
bool grabarAlumno(tAlumno mat)
{
    bool result=false;
    FILE *f; //se declara el puntero FILE
    f = fopen(ALUMNOS,"ab");//Se abre el archivo en modo append en bytes
    if(f!=NULL) // se verifica que el archivo sea distinto de NULL
    {
        fwrite(&mat,sizeof(tAlumno),1,f);
        fclose(f); //Cierro el archivo
        result=true;
    }
    return result;
}

/**=============================================================================
 FUNCION : bool cargarAlumno(tAlumno *mreg, int qty)
 ACCION : comienza la carga de alumnos en el registro
 PARAMETROS: tAlumno *mreg, int qty
 DEVUELVE : un booleano si logra cargarlo o no.
============================================================================= **/
bool cargarAlumno(tAlumno *mreg, int qty)
{
    bool resul = false;
    txtTabs();
    cout << "COMPLETE LOS SUGUIENTES CAMPOS " << endl;
    char nombre[50],apellido[50];
    int legajo;
    if(qty == 0)
    {
        legajo = 1;
    }
    else
    {
        legajo = qty;
    }
    txtCargaAlumno(1);
    sys::getline(nombre,50);
    txtCargaAlumno(3);
    sys::getline(apellido,50);
    strcpy(mreg->nombre,nombre);
    strcpy(mreg->apellido,apellido);
    mreg->legajo = legajo;
    mreg->eliminado=false;
    resul = grabarAlumno(*mreg);
    return resul;
}

/**=============================================================================
 FUNCION :bool grabarAlumnoModificado(struct tAlumno reg,int pos)
 ACCION : recibe un registro del tipo tAlumno y su posicion y lo edita en el archivo
 PARAMETROS: tAlumno reg, int pos
 DEVUELVE :devuelve true si logro guardar correctamente el registro modificado.
============================================================================= **/
bool grabarAlumnoModificado(struct tAlumno reg,int pos)
{
    FILE *p;
    bool escribio = false;
    p=fopen(ALUMNOS, "rb+");
    if(p==NULL)
        return escribio;
    fseek(p,pos*sizeof reg,0);
    escribio=fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return escribio;
}

/**=============================================================================
 FUNCION : void cargaModificada( tAlumno *mreg)
 ACCION : permite la edicion de un alumno
 PARAMETROS: tAlumno *mreg
 DEVUELVE : nada
============================================================================= **/
void cargaModificada(tAlumno *reg)
{
    txtTabs();
    cout << "COMPLETE LOS SIGUIENTES CAMPOS " << endl;
    char nombre[50],apellido[50];
    txtCargaAlumno(1);
    sys::getline(nombre,50);
    txtCargaAlumno(3);
    sys::getline(apellido,50);
    strcpy(reg->nombre,nombre);
    strcpy(reg->apellido,apellido);
    txtPresioneTeclaParaContinuar();
}

/**=============================================================================
 FUNCION : bool altaAlumno()
 ACCION : permite la carga de un nuevo alumno
 PARAMETROS: nada
 DEVUELVE : booleano si carga, true = cargo, false = no cargo.
============================================================================= **/
bool altaAlumno()
{
    tAlumno reg;
    int qty = contarAlumnos(reg);
    bool c = cargarAlumno(&reg,qty);
    //ACÁ SE DEBERÍA PREGUNTAR SI SE DESEA ASIGNAR EL ALUMNO A MATERIAS
    if(c)
    {
        txtCargaExitosa();
    }
    else

    {
        txtTabs();
        cout<<"ERROR AL CARGAR ALUMNO"<<endl;
    }
    return c;
}

/**=============================================================================
 FUNCION : void mostrarAlumno(struct tAlumno reg)
 ACCION : muestra por pantalla el alumno que recibe por parametro
 PARAMETROS: tAlumno reg
 DEVUELVE : nada
============================================================================= **/
void mostrarAlumno(tAlumno reg)
{
    txtCargaAlumno(2);
    txtCargaAlumno(1);
    txtCargaAlumno(3);
    txtTab();
    cout << ""<< endl;
    if(!reg.eliminado)
    {
        cout<< " \t \t " <<  reg.legajo << " \t \t "  << reg.nombre << " \t \t \t \t" << reg.apellido <<endl;
        cout<<""<<endl;
    }
}
/**=============================================================================
 FUNCION :struct tAlumnos leerRegistroalumno(int pos)
 ACCION : solicita la posicion de un registro y lo busca en el archivo.
 PARAMETROS: int pos
 DEVUELVE :devuelve el registro solicitado por medio de la posicion.
============================================================================= **/
tAlumno leerRegistroAlumno(int pos)
{
    FILE *p;
    struct tAlumno reg;
    p=fopen(ALUMNOS, "rb");
    if(p==NULL)
        exit(1);
    fseek(p,pos*sizeof(tAlumno),0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}
/**=============================================================================
 FUNCION : int buscarAlumno(int legajo, tAlumno reg)
 ACCION : Funcion para buscar la posicion en el archivo de alumnos.
 PARAMETROS: id a buscar, struct tAlumno.
 DEVUELVE : posicion del alumno en el archivo
============================================================================= **/
int buscarAlumno(int legajo, tAlumno reg)
{

    FILE *p;
    int pos=-1;
    int index=0;
    p=fopen(ALUMNOS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tAlumno), 1, p)==1)
        {
            if(reg.legajo==legajo)
            {
                fclose(p);
                pos=index;
            }
            index++;
        }
    }
    return pos;
}

/**=============================================================================
 FUNCION : listarAlumnos(tAlumno reg)
 ACCION : listar los alumnos del archivo
 PARAMETROS: tAlumno reg
 DEVUELVE : nada
============================================================================= **/
void listarAlumnos(tAlumno reg)
{
    FILE *p;
    int valMaterias = 0;
    p=fopen(ALUMNOS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tAlumno), 1, p)==1)
        {
            if(!reg.eliminado)
            {
                mostrarAlumno(reg);
                valMaterias++;
            }


        }
    }
    else
    {
        txtArchivoVacio();
    }
    if(valMaterias=0)
        txtSinRegistros();
    fclose(p);

}
/**=============================================================================
 FUNCION : void fMostrarListadoAlumnos()
 ACCION : muestra por pantalla los alumnos
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void fMostrarListadoAlumnos()
{
    tAlumno reg;
    listarAlumnos(reg);
}
/**=============================================================================
 FUNCION : void modificarAlumno()
 ACCION : Modificar una alumno del archivo
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void modificarAlumno()
{
    sys::cls();
    int legajo, pos;
    struct tAlumno reg;
    listarAlumnos(reg); //MODIFICAR/AGREGAR FUNCION QUE SOLO MUESTRE NOMBRE Y ID DE alumno
    cout<<"INGRESE EL ID DEL ALUMNO CUYOS DATOS SE DESEEN MODIFICAR: ";
    cin>>legajo;
    cin.ignore();
    pos=buscarAlumno(legajo,reg);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL ALUMNO"<<endl;
        txtPresioneTeclaParaContinuar();
        return;
    }
    reg=leerRegistroAlumno(pos);
    cout<<"DATOS DEL ALUMNO SELECCIONADO:"<<endl;
    mostrarAlumno(reg);
    cargaModificada(&reg);
    if(grabarAlumnoModificado(reg,pos))
    {
        cout<<"SE ACTUALIZARON LOS DATOS DEL ALUMNO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDIERON ACTUALIZAR LOS DATOS DEL ALUMNO"<<endl;
    }
}

/**=============================================================================
 FUNCION : void bajaAlumno()
 ACCION : cambia el estado de alumnos en archivo, los mismas pasan a ser considerados "dados de baja"
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void bajaAlumno()
{
    int legajo, pos;
    struct tAlumno reg;
    //ACA SE DEBERÍA MOSTRAR EL LISTADO DE ALUMNOS:  LEGAJO | NOMBRE
    listarAlumnos(reg);
    cout<<"INGRESE EL LEGAJO DEL ALUMNO A ELIMINAR: ";
    cin>>legajo;
    pos=buscarAlumno(legajo,reg);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL ALUMNO"<<endl;
        txtPresioneTeclaParaContinuar();
        return;
    }
    reg=leerRegistroAlumno(pos);
    reg.eliminado=true;
    if(grabarAlumnoModificado(reg,pos))  //
    {
        cout<<"ALUMNO ELIMINADO"<<endl;
        txtPresioneTeclaParaContinuar();
    }
    else
    {
        cout<<"NO SE PUDO ELIMINAR EL ALUMNO"<<endl;
        txtPresioneTeclaParaContinuar();
    }
}

#endif // ALUMNOS_H_INCLUDED

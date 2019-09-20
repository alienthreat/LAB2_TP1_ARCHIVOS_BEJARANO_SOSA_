#ifndef RELACIONAL_H_INCLUDED
#define RELACIONAL_H_INCLUDED

#include <iostream>
#include <cstdlib>  /** Libreria estandar que contiene la funcion exit(). */
#include <cstdio>   /** Libreria para manejo de archivos. */
#include <locale>   /** Libreria para manejo de Idiomas */
#include <cstring>  /** Libreria para el manejo de cadenas de texto tDato String */
#include <windows.h>
#include "../CSYSTEM/csystem.h" /** Libreria para multiplataforma. */
#include "./mensajes.h" /** LIBRERIA DE MENSAJES **/
#include "./materias.h" /** LIBRERIA DE FUNCIONES PARA MATERIAS **/
#include "./alumnos.h" /** LIBRERIA DE FUNCIONES PARA ALUMNOS **/

using namespace std;
const char MXA[] = "./ARCHIVOS/MXA.DATA";

/**=============================================================================
 FUNCION : struct tMaterias_x_Alumno()
 ACCION : estructura de las materias x alumno
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
struct tMaterias_x_Alumno
{
    int id_materia;
    int legajo;
    bool eliminado;
};


/**=============================================================================
 FUNCION : bool grabarMateriaRelacional(struct tMaterias_x_Alumno reg)
 ACCION : Graba el registro con los datos de alumno asignado a materia en el archivo relacional
 PARAMETROS:struct tMaterias_x_Alumno reg.
 DEVUELVE : true si pudo grabar correctamente, false si no fue asi
============================================================================= **/
bool grabarMateriaRelacional(tMaterias_x_Alumno reg){
  FILE *p;
  p=fopen(MXA, "ab");
  if(p==NULL) return false;
  bool escribio=fwrite(&reg, sizeof reg, 1, p);
  fclose(p);
  return escribio;
}

bool verificarMateriaActiva(int id){}

bool verificarAlumnoActivo(int legajo){}

/**=============================================================================
 FUNCION : bool verificarEstadoMateria(int id)
 ACCION : Verifica si la materia se encuentra activa o dada de baja
 PARAMETROS: int id.
 DEVUELVE : true si se ingresó un cero, false si pudo encontrar la materia y está activa
============================================================================= **/
bool verificarMateria(int id)
{
    bool exit=false;
    if(id==0)
    {
        exit=true;
        return exit;
    }
    struct tMateria mreg; int pos;
    pos=buscarMateria(id, mreg);
    if(pos==-1)
    {
        cout<<"NO EXISTE LA MATERIA"<<endl;
        txtPresioneTeclaParaContinuar();
        exit =true;
        return exit;
    }
    if(!verificarMateriaActiva(id))
    {
    txtPresioneTeclaParaContinuar();
    exit=true;
    return exit;
    }
    return exit;
}

/**=============================================================================
 FUNCION : bool verificarEstadoAlumno(int legajo)
 ACCION : Verifica si el alumno está activo
 PARAMETROS: int legajo
 DEVUELVE : true si se ingresó un cero, false si pudo encontrar el alumno y está activo
============================================================================= **/
bool verificarAlumno(int legajo)
{
    bool exit=false;
    if(legajo==0)
    {
        exit=true;
        return exit;
    }
    struct tAlumno areg; int pos;
    pos=buscarAlumno(legajo,areg);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL ALUMNO"<<endl;
        txtPresioneTeclaParaContinuar();
        exit=true;
        return exit;
    }
    if(!verificarAlumnoActivo(legajo))
    {
    txtPresioneTeclaParaContinuar();
    exit=true;
    return exit;
    }
    return exit;
}

void AsignarAtoM()
{
    system("cls");
    struct tMaterias_x_Alumno reg;
    int legajo, id;
    bool exit=false, c=false;
    fMostrarListadoAlumnos();
    cout<<"Ingrese el legajo del alumno al cual se le asignaran materias:"<<endl;
    cout<<"NOTA: Ingrese 0 para finalizar."<<endl;
    cin>>legajo;
    cin.ignore();
    exit=verificarAlumno(legajo);
    if(!exit)
    {
        reg.legajo=legajo;
    }
    while(!exit)
    {
    system("cls");
    fMostrarListadoMaterias();
    txtTab();
    txtPresioneTeclaParaContinuar();
    cout<<"Ingrese el ID de la materia que desea asignarle al alumno:"<<endl; //MOSTRAR LEGAJO Y NOMBRE
    cout<<"NOTA: Ingrese 0 para finalizar la asignación de materias"<<endl;
    cin>>id;
    //VALIDA SI EL ID ES CORRECTO
    exit=verificarMateria(id);
    if(!exit)
    {
    reg.id_materia=id;
    c=grabarMateriaRelacional(reg);
        if(c)
        {cout<<"ASIGNACION EXITOSA"<<endl;}
        else
        {cout<<"ERROR EN LA ASIGNACION"<<endl;}
    }
    }
}

void AsignarMtoA()
{
    system("cls");
    struct tMaterias_x_Alumno reg;
    int legajo, id_materia;
    bool exit=false, c=false;
    fMostrarListadoMaterias();
    cout<<"Ingrese el ID de la materia a la cual desea asignar alumnos:"<<endl;
    cout<<"NOTA: Ingrese 0 para finalizar la asignación de materias"<<endl;
    cin>>id_materia;
    //VALIDAR SI EL ID ES CORRECTO(Y SI EL ESTADO DE MATERIA ES = TRUE)
    exit=verificarMateria(id_materia);
    if(!exit)
    {
    reg.id_materia=id_materia;
    }
    while(!exit)
    {
    system("cls");
    fMostrarListadoAlumnos();
    txtTab();
    txtPresioneTeclaParaContinuar();
    cout<<"Ingrese el legajo del alumno que se asignara a la materia:"<<endl;
    cout<<"NOTA: Ingrese 0 para finalizar la asignación de alumnos"<<endl;
    cin>>legajo;
    //VALIDAR SI EL LEGAJO ES CORRECTO(Y SI EL ESTADO DE ALUMNO ES = TRUE)
    exit=verificarAlumno(legajo);
    if(!exit)
    {
    reg.legajo=legajo;
    c=grabarMateriaRelacional(reg);
    if(c)
        {cout<<"ASIGNACION EXITOSA"<<endl;}
    else
        {cout<<"ERROR EN LA ASIGNACION"<<endl;}
    }
    }
}

void mostrarAlumnosDeMateria(int id_materia){

}

void mostrarAxM(){
    system("cls");
    bool exit=false;
    while(!exit)
    {
    fMostrarListadoMaterias();
    int id_materia;
    txtTabs();
    cout<<"Ingrese el ID de la materia cuyos alumnos desea ver:"<<endl;
    cout<<"NOTA: Ingrese 0 para salir"<<endl;
    cin>>id_materia;
    exit=verificarMateria(id_materia);
    txtLineas();
    if(!exit)
        {
        mostrarAlumnosDeMateria(id_materia);
        }
    }
}

#endif // RELACIONAL_H_INCLUDED

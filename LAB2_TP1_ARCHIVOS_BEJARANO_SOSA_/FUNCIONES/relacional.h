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

/**=============================================================================
 FUNCION : bool verificarEstadoMateria(int id)
 ACCION : Verifica si la materia se encuentra activa o dada de baja
 PARAMETROS: int id.
 DEVUELVE : true si se ingres� un cero, false si pudo encontrar la materia y est� activa
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
    return exit;
}

/**=============================================================================
 FUNCION : bool verificarEstadoAlumno(int legajo)
 ACCION : Verifica si el alumno est� activo
 PARAMETROS: int legajo
 DEVUELVE : true si se ingres� un cero, false si pudo encontrar el alumno y est� activo
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
    return exit;
}
/**=============================================================================
 FUNCION : struct tMaterias_x_Alumno()
 ACCION : estructura de las materias x alumno
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void AsignarAtoM()
{
    cout<<"aver"<<endl;
    txtPresioneTeclaParaContinuar();
    sys::cls();
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
     sys::cls();
    fMostrarListadoMaterias();
    txtTab();
    txtPresioneTeclaParaContinuar();
    cout<<"Ingrese el ID de la materia que desea asignarle al alumno:"<<endl; //MOSTRAR LEGAJO Y NOMBRE
    cout<<"NOTA: Ingrese 0 para finalizar la asignaci�n de materias"<<endl;
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
/**=============================================================================
 FUNCION : struct tMaterias_x_Alumno()
 ACCION : estructura de las materias x alumno
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void AsignarMtoA()
{
     sys::cls();
    struct tMaterias_x_Alumno reg;
    int legajo, id_materia;
    bool exit=false, c=false;
    fMostrarListadoMaterias();
    cout<<"Ingrese el ID de la materia a la cual desea asignar alumnos:"<<endl;
    cout<<"NOTA: Ingrese 0 para finalizar la asignaci�n de materias"<<endl;
    cin>>id_materia;
    //VALIDAR SI EL ID ES CORRECTO(Y SI EL ESTADO DE MATERIA ES = TRUE)
    exit=verificarMateria(id_materia);
    if(!exit)
    {
    reg.id_materia=id_materia;
    }
    while(!exit)
    {
     sys::cls();
    fMostrarListadoAlumnos();
    txtTab();
    txtPresioneTeclaParaContinuar();
    cout<<"Ingrese el legajo del alumno que se asignara a la materia:"<<endl;
    cout<<"NOTA: Ingrese 0 para finalizar la asignaci�n de alumnos"<<endl;
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

/**=============================================================================
 FUNCION : void mostrarAlumnosaAsignados(int id_materia)
 ACCION : Funcion para mostrar los alumnos cuyo id_materia coincida con el indicado,
 dentro del archivo relacional. Si coincide, los busca y muestra sus datos
 PARAMETROS: id a buscar
 DEVUELVE : nada
============================================================================= **/
void mostrarAlumnosAsignados(int id_materia)
{
    struct tMaterias_x_Alumno reg;
    struct tAlumno areg;
    FILE *p;
    int pos=-1;
    int index=0;
    p=fopen(ALUMNOS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tAlumno), 1, p)==1)
        {
            if(reg.id_materia==id_materia)
            {
                fclose(p);
                //mostrar el alumno mediante el LEGAJO
                int legajo = reg.legajo;
                pos=buscarAlumno(legajo, areg);
                areg=leerRegistroAlumno(pos);
                mostrarAlumno(areg);
                txtLineas();
            }
            index++;
        }
    }
}
/**=============================================================================
 FUNCION : struct tMaterias_x_Alumno()
 ACCION : estructura de las materias x alumno
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void mostrarMateriasAsignadas(int legajo){
    struct tMaterias_x_Alumno reg;
    struct tMateria mreg;
    FILE *p;
    int pos=-1;
    int index=0;
    p=fopen(MATERIAS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tMateria), 1, p)==1)
        {
            if(reg.legajo==legajo)
            {
                fclose(p);
                //mostrar la materia mediante el ID
                int id_materia = reg.id_materia;
                pos=buscarMateria(id_materia, mreg);
                mreg=leerRegistroMateria(pos);
                mostrarMateria(mreg);
                txtLineas();
            }
            index++;
        }
    }
}
/**=============================================================================
 FUNCION : struct tMaterias_x_Alumno()
 ACCION : estructura de las materias x alumno
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void mostrarAsxM(){
     sys::cls();
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
        mostrarAlumnosAsignados(id_materia);
        }
    }
}
/**=============================================================================
 FUNCION : struct tMaterias_x_Alumno()
 ACCION : estructura de las materias x alumno
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void mostrarMsxA(){
    sys::cls();
    bool exit=false;
    while(!exit)
    {
    fMostrarListadoAlumnos();
    int legajo;
    txtTabs();
    cout<<"Ingrese el legajo del alumno cuya materias desea ver:"<<endl;
    cout<<"NOTA: Ingrese 0 para salir"<<endl;
    cin>>legajo;
    exit=verificarAlumno(legajo);
    txtLineas();
    if(!exit)
        {
        mostrarMateriasAsignadas(legajo);
        }
    }
}

#endif // RELACIONAL_H_INCLUDED

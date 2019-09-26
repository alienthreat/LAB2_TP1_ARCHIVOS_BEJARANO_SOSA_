#ifndef RELACIONAL_H_INCLUDED
#define RELACIONAL_H_INCLUDED
/** #############################################################################
 ARCHIVO             : relacional.h
 AUTOR/ES            : GABRIEL BEJARANO
 VERSION             : 0.01 beta.
 FECHA DE CREACION   : 07/09/2019.
 ULTIMA ACTUALIZACION: 25/09/2019.
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
bool grabarMateriaRelacional(tMaterias_x_Alumno reg)
{
    FILE *p;
    p=fopen(MXA, "ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

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
    struct tMateria mreg;
    int pos;
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
    struct tAlumno areg;
    int pos;
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
 FUNCION : void mostrarMxA(tMaterias_x_Alumno reg)
 ACCION : muestra por pantalla la materia que recibe por parametro
 PARAMETROS: tMaterias reg
 DEVUELVE : nada
============================================================================= **/
void mostrarMxA(tMaterias_x_Alumno reg)
{
        cout<< "  ||          ID LEGAJO  \t \t|| \t    ID MATERIA \t \t  ||" << endl;
        cout<< "  ||  \t \t" <<  reg.legajo << "\t \t \t|| \t \t"  << reg.id_materia << "\t \t  ||"  <<endl;

}
/**=============================================================================
 FUNCION : void listarMxA(tMaterias_x_Alumno reg)
 ACCION : listar las materias del archivo
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void listarMxA(tMaterias_x_Alumno reg)
{
    FILE *p;
    int valMaterias = 0;
    p=fopen(MXA, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tMaterias_x_Alumno), 1, p)==1)
        {
            if(!reg.eliminado)
            {
                mostrarMxA(reg);
                valMaterias++;
            }
        }
        fclose(p);
    }
    else
    {
        txtArchivoVacio();
    }

    if(valMaterias=0 )
    txtSinRegistros();



}

/**=============================================================================
 FUNCION : void AsignarAtoM()
 ACCION : Permite asociar un alumno a una materia
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void AsignarAtoM()
{
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
        txtTabs();
        cout    <<  "||  NOTA: Ingrese 0 para finalizar la asignación de materias             ||"<<endl;
        txtTabs();
        cout    <<  "Ingrese el ID de la materia que desea asignar al alumno:"<<endl; //MOSTRAR LEGAJO Y NOMBRE

        cin>>id;
        //VALIDA SI EL ID ES CORRECTO
        exit=verificarMateria(id);
        if(!exit)
        {
            reg.id_materia=id;
            c=grabarMateriaRelacional(reg);
            if(c)
            {
                cout<<"ASIGNACION EXITOSA"<<endl;
            }
            else
            {
                cout<<"ERROR EN LA ASIGNACION"<<endl;
            }
        }
    }
}
/**=============================================================================
 FUNCION : void AsignarMtoA()
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
        sys::cls();
        fMostrarListadoAlumnos();
        txtTab();
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
            {
                cout<<"ASIGNACION EXITOSA"<<endl;
            }
            else
            {
                cout<<"ERROR EN LA ASIGNACION"<<endl;
            }
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
    p=fopen(ALUMNOS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tAlumno), 1, p)==1)
        {
            if(reg.id_materia==id_materia)
            {
                //mostrar el alumno mediante el LEGAJO
                int legajo = reg.legajo;
                pos=buscarAlumno(legajo, areg);
                areg=leerRegistroAlumno(pos);
                mostrarAlumno(areg);
                fclose(p);
            }
        }
    }
}
/**=============================================================================
 FUNCION : void mostrarMateriasAsignadas
 ACCION : Muestra el listado de materias que fueron asignadas a los alumnos.
 PARAMETROS: int legajo
 DEVUELVE : nada.
============================================================================= **/
//void mostrarMateriasAsignadas(int legajo)
//{
//    struct tMaterias_x_Alumno reg;
//    struct tMateria mreg;
//    FILE *p;
//    int pos=-1;
//    p=fopen(MXA, "rb");
//    if(p!=NULL)
//    {
//        while(fread(&reg, sizeof(tMaterias_x_Alumno), 1, p)==1)
//        {
//            if(reg.legajo==legajo)
//            {
//                fclose(p);
//                //mostrar la materia mediante el ID
//                int id_materia = reg.id_materia;
//                pos=buscarMateria(id_materia, mreg);
//                mreg=leerRegistroMateria(pos);
//                mostrarMateria(mreg);
//                txtLineas();
//            }
//        }
//    }
//}


/**=============================================================================
 FUNCION : void mostrarMateriasAsignadas
 ACCION : Muestra el listado de materias que fueron asignadas a los alumnos.
 PARAMETROS: nada
 DEVUELVE : nada.
============================================================================= **/
void mostrarMateriasAsignadas()
{
    struct tMaterias_x_Alumno reg;
    FILE *p;
    int pos=-1;
    p=fopen(MXA, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tMaterias_x_Alumno), 1, p)==1)
        {
            if(!reg.eliminado)
            {
                listarMxA(reg);
            }
             fclose(p);
        }
    }
}
/**=============================================================================
 FUNCION : void mostrarAsxM()
 ACCION : muestra las materias asignadas por alumno
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void mostrarAsxM()
{
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
        cin.ignore();
        exit=verificarMateria(id_materia);
        txtLineas();
        if(!exit)
        {
            mostrarAlumnosAsignados(id_materia);
        }
    }
}
/**=============================================================================
 FUNCION : void mostrarMsxA()
 ACCION : muestra las materias x alumnos que tenga asignados
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
void mostrarMsxA()
{

    sys::cls();
    bool exit=false;
//    while(!exit)
//    {
//         txtTabs();
//        cout    <<  "||_______________________________________________________________________||"<<endl;
//        txtTabs();
//        cout    <<  "||  NOTA: Ingrese 0 para salir                                           ||"<<endl;
//        txtTabs();
//        cout    <<  "||-----------------------------------------------------------------------||"<<endl;
//        txtLineas();
        mostrarMateriasAsignadas();
//        cin>>legajo;
//        cin.ignore();
//        exit=verificarAlumno(legajo);
//    }
cin.ignore();
}
/**=============================================================================
 FUNCION : void mostrarMsxA()
 ACCION : muestra las materias x alumnos que tenga asignados
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
//void mostrarMsxA()
//{
//    sys::cls();
//    bool exit=false;
//    while(!exit)
//    {
//        fMostrarListadoAlumnos();
//        int legajo;
//         txtTabs();
//        cout    <<  "||_______________________________________________________________________||"<<endl;
//        txtTabs();
//        cout    <<  "||  NOTA: Ingrese 0 para salir                                           ||"<<endl;
//        txtTabs();
//        cout    <<  "||-----------------------------------------------------------------------||"<<endl;
//        txtTabs();
//        txtTabs(); cout<<"  Ingrese el legajo del alumno cuya materias desea ver:";
//        cin>>legajo;
//        cin.ignore();
//        exit=verificarAlumno(legajo);
//        txtLineas();
//        if(!exit)
//        {
//            mostrarMateriasAsignadas(legajo);
//        }
//    }
//}

#endif // RELACIONAL_H_INCLUDED

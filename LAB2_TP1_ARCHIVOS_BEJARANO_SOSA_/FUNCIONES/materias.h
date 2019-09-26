#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

/** #############################################################################
 ARCHIVO             : materias.h
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
#include "./mensajes.h" /** LIBRERIA DE MENSAJES **/
/**=============================================================================**/
using namespace std;
const char MATERIAS[] = "./ARCHIVOS/MATERIAS.DATA";

/**=============================================================================
 FUNCION : struct tMaterias()
 ACCION : estructura de las materias
 PARAMETROS:nada.
 DEVUELVE : nada.
============================================================================= **/
struct tMateria
{
    int id_materia;
    char nombre[50], profesor[50];
    bool eliminado;
};

/**=============================================================================
 FUNCION : bool verifArchivoExiste(const char *url)
 ACCION : verifica si el archivo exsite
 PARAMETROS: const char *url : recibe la dirección del archivo.
 DEVUELVE : devuelve un booleano en caso de poder abrir el archivo
============================================================================= **/
bool verifArchivoExiste(const char *url)
{
    bool valid = false;
    FILE *archivo;
    archivo = fopen(url,"rb");
    if(archivo!=NULL)
    {
        fclose(archivo);
        valid = true;
    }
    return valid;
}
/**=============================================================================
 FUNCION : bool crearArchivo(const char *url).
ACCION : Crea un archivo
PARAMETROS: const char *url : recibe la direccion del archivo.
DEVUELVE : bool: true si pudo crear, false si no pudo crear.
============================================================================= **/
bool crearArchivo(const char *url)
{
    bool creado = false;
    FILE *archivo;
    archivo = fopen(url,"wb");
    if(archivo!=NULL)
    {
        creado= true;
        fclose(archivo);
    }
    return creado;
}
/**=============================================================================
 FUNCION : void mostrarMateria(struct tMaterias reg)
 ACCION : muestra por pantalla la materia que recibe por parametro
 PARAMETROS: tMaterias reg
 DEVUELVE : nada
============================================================================= **/
void mostrarMateria(tMateria reg)
{
    txtCargaMateria(2);
    txtCargaMateria(1);
    txtTab();
    txtCargaMateria(3); cout << endl;

        cout<< " \t \t " <<  reg.id_materia << " \t \t "  << reg.nombre << " \t \t " << reg.profesor <<endl;

}
/**=============================================================================
 FUNCION : contarMaterias(tMateria reg)
 ACCION : listar las materias del archivo
 PARAMETROS: tMateria reg
 DEVUELVE : cantidad de materias
============================================================================= **/
int contarMaterias(tMateria reg)
{
    FILE *p;
    int qtyMaterias = 0;
    p=fopen(MATERIAS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tMateria), 1, p)==1)
        {
                qtyMaterias++;
        }
    }
        if(qtyMaterias>0) qtyMaterias++;
    fclose(p);
    return qtyMaterias;
}


/**=============================================================================
 FUNCION : bool grabarMateria(tMaterias mat)
 ACCION : Dar de alta materias
 PARAMETROS: nada
 DEVUELVE : true si se cargo la materia, false si no lo consigue.
============================================================================= **/
bool grabarMateria(tMateria mat)
{
    bool result=false;
    FILE *f; //se declara el puntero FILE
    f = fopen(MATERIAS,"ab");//Se abre el archivo en modo append en bytes
    if(f!=NULL) // se verifica que el archivo sea distinto de NULL
    {
        fwrite(&mat,sizeof(tMateria),1,f);
        fclose(f); //Cierro el archivo
        result=true;
    }
    return result;
}

/**=============================================================================
 FUNCION : void cargarMateria( tMateria *mreg, int qty)
 ACCION : permite la carga de una materia
 PARAMETROS: tMateria *mreg, int qty
 DEVUELVE : un booleano si logra cargarlo o no.
============================================================================= **/
bool cargarMateria( tMateria *mreg, int qty)
{
    bool resul = false;
    txtTabs();

    cout << "COMPLETE LOS SUGUIENTES CAMPOS " << endl;
    char materia[50],profesor[50];
    int id;
    if(qty == 0)
    {
        id = 1;
    }
    else
    {
            id = qty;
    }

    txtCargaMateria(1);
    sys::getline(materia,50);
    txtCargaMateria(3);
    sys::getline(profesor,50);
    strcpy(mreg->nombre,materia);
    strcpy(mreg->profesor,profesor);
    mreg->id_materia = id;
    mreg->eliminado=false;
    resul = grabarMateria(*mreg);
    return resul;
}


/**=============================================================================
 FUNCION :bool grabarMateriaModificada(struct tMaterias reg,int pos)
 ACCION : recibe un registro del tipo tMateria y su posicion y lo edita en el archivo
 PARAMETROS: tMaterias reg, int pos
 DEVUELVE :devuelve true si logro guardar correctamente el registro modificado.
============================================================================= **/
bool grabarMateriaModificada(struct tMateria reg,int pos)
{
    FILE *p;
    bool escribio = false;
    p=fopen(MATERIAS, "rb+");
    if(p==NULL)
        return escribio;
    fseek(p,pos*sizeof reg,0);
    escribio=fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return escribio;
}

/**=============================================================================
 FUNCION : void cargaModificada( tMateria *mreg)
 ACCION : permite la edicion de una materia
 PARAMETROS: tMateria *mreg
 DEVUELVE : nada
============================================================================= **/
void cargaModificada(tMateria *reg)
{
    txtTabs();
    cout << "COMPLETE LOS SUGUIENTES CAMPOS " << endl;
    char materia[50],profesor[50];
    txtCargaMateria(1);
    sys::getline(materia,50);
    txtCargaMateria(3);
    sys::getline(profesor,50);
    strcpy(reg->nombre,materia);
    strcpy(reg->profesor,profesor);
    txtPresioneTeclaParaContinuar();
}


/**=============================================================================
 FUNCION : bool altaMateria()
 ACCION : permite la carga de una nueva materia
 PARAMETROS: nada
 DEVUELVE : booleano si carga, true cargo, false no cargo.
============================================================================= **/
bool altaMateria()
{
    tMateria reg;

        int qty = contarMaterias(reg);
    //struct tRelacional mreg; //ACÁ TAMBIÉN CARGO EL ID DE LA MATERIA EN EL ARCHIVO RELACIONAL
    bool c = cargarMateria(&reg,qty);
    if(c)
    {
        txtCargaExitosa();
    }
    else
    {
        cout<<"ERROR AL CARGAR MATERIA"<<endl;
    }
    return c;
}


/**=============================================================================
 FUNCION :struct tMaterias leerRegistroMateria(int pos)
 ACCION : solicita la posicion de un registro y lo busca en el archivo.
 PARAMETROS: int pos
 DEVUELVE :devuelve el registro solicitado por medio de la posicion.
============================================================================= **/
tMateria leerRegistroMateria(int pos)
{
    FILE *p;
    struct tMateria reg;
    p=fopen(MATERIAS, "rb");
    if(p==NULL)
        exit(1);
    fseek(p,pos*sizeof(tMateria),0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}
/**=============================================================================
 FUNCION : int buscarMateria(int id, tMaterias reg)
 ACCION : Funcion para buscar la posicion en el archivo de la materia.
 PARAMETROS: id a buscar, struct tMateria.
 DEVUELVE : posicion de la materia en el archivo
============================================================================= **/
int buscarMateria(int id, tMateria reg)
{


    FILE *p;
    int pos=-1;
    int index=0;
    p=fopen(MATERIAS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tMateria), 1, p)==1)
        {
            if(reg.id_materia==id)
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
 FUNCION : listarMaterias(tMateria reg)
 ACCION : listar las materias del archivo
 PARAMETROS: tMateria reg
 DEVUELVE : nada
============================================================================= **/
void listarMaterias(tMateria reg)
{
    FILE *p;
    int valMaterias = 0;
    p=fopen(MATERIAS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(tMateria), 1, p)==1)
        {
            if(!reg.eliminado)
            {
                mostrarMateria(reg);
                valMaterias++;
            }

        }
    }
    else
    {
        txtArchivoVacio();
    }

    if(valMaterias=0 )
        txtSinRegistros();

    fclose(p);

}
/**=============================================================================
 FUNCION : void fMostrarListadoMaterias()
 ACCION : muestra por pantalla las materias
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void fMostrarListadoMaterias()
{
    tMateria reg;
    listarMaterias(reg);
    txtPresioneTeclaParaContinuar();
}
/**=============================================================================
 FUNCION : void modificarMateria()
 ACCION : Modificar una materia del archivo
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void modificarMateria()
{
    sys::cls();
    int id, pos;
    struct tMateria reg;
    listarMaterias(reg); //MODIFICAR/AGREGAR FUNCION QUE SOLO MUESTRE NOMBRE Y ID DE MATERIA
    cout<<"INGRESE EL ID DE LA MATERIA CUYOS DATOS SE DESEEN MODIFICAR: ";
    cin>>id;
    cin.ignore();
    pos=buscarMateria(id,reg);
    if(pos==-1)
    {
        cout<<"NO EXISTE LA MATERIA"<<endl;
        txtPresioneTeclaParaContinuar();
        return;
    }
    reg=leerRegistroMateria(pos);
    cout<<"DATOS DE LA MATERIA SELECCIONADA:"<<endl;
    mostrarMateria(reg);
    cargaModificada(&reg);
    if(grabarMateriaModificada(reg,pos))
    {
        cout<<"SE ACTUALIZARON LOS DATOS DE LA MATERIA"<<endl;
    }
    else
    {
        cout<<"NO SE PUDIERON ACTUALIZAR LOS DATOS DE LA MATERIA"<<endl;
    }
}

/**=============================================================================
 FUNCION : void bajaMateria()
 ACCION : cambia el estado de materias en archivo, las mismas pasan a ser consideradas "dadas de baja"
 PARAMETROS: nada
 DEVUELVE : nada
============================================================================= **/
void bajaMateria()
{
    int id, pos;
    struct tMateria reg;
    //ACA SE DEBERÍA MOSTRAR EL LISTADO DE MATERIAS:  ID | NOMBRE
    listarMaterias(reg);
    cout<<"INGRESE EL ID DE LA MATERIA A ELIMINAR: ";
    cin>>id;
    pos=buscarMateria(id,reg);
    if(pos==-1)
    {
        cout<<"NO EXISTE LA MATERIA"<<endl;
        txtPresioneTeclaParaContinuar();
        return;
    }
    reg=leerRegistroMateria(pos);
    reg.eliminado=true;
    if(grabarMateriaModificada(reg,pos))  //
    {
        cout<<"MATERIA ELIMINADA"<<endl;
        txtPresioneTeclaParaContinuar();
    }
    else
    {
        cout<<"NO SE PUDO ELIMINAR LA MATERIA"<<endl;
        txtPresioneTeclaParaContinuar();
    }
}

#endif // MATERIAS_H_INCLUDED

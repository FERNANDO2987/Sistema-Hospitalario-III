// AUTOR : RAMIREZ MATIAS HERNAN,ROMERO NAHUEL FRANCO,PALACIOS FERNANDO GUILLERMO
// FECHA DE CREACION : 28/06/2023.
// ULTIMA ACTUALIZACION: 28/06/2023.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 17.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// Aqui se desarrollan la Metodos de la class ArchivoQuirofano
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdio>
using namespace std;
#include "ArchivoQuirofano.h"




ArchivoQuirofano::ArchivoQuirofano(){
_nombre = "archivoQuirofano.dat";
}

ArchivoQuirofano::ArchivoQuirofano(string nombre){
_nombre = nombre;
}

///=============================================================================
/// FUNCION :bool ArchivoQuirofano::guardar(Quirofano reg)
/// ACCION : guarda un quirofano
/// PARAMETROS: Quirofano reg
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------

bool ArchivoQuirofano::guardar(Quirofano reg){

	FILE *p = fopen(_nombre.c_str(), "ab");

	if (p == NULL)
	{
		return false;
	}
	//reg.Cargar();

  bool pudoEscribir = fwrite(&reg, sizeof(Quirofano), 1, p);
  fclose(p);
  return pudoEscribir;
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :int ArchivoQuirofano::getCantidadRegistros()
/// ACCION : cuenta la cantidad de registros
/// PARAMETROS:
///
/// DEVUELVE : int --> entero
///-----------------------------------------------------------------------------

int ArchivoQuirofano::getCantidadRegistros(){

FILE *p = fopen(_nombre.c_str(), "rb");

  if (p == NULL)
  {
    return 0;
  }

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  return bytes / sizeof(Quirofano);
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :Quirofano ArchivoQuirofano::leerRegistro(int pos)
/// ACCION : Lee el registro
/// PARAMETROS: int pos
///
/// DEVUELVE : Quirofano --> devuelve un registro
///-----------------------------------------------------------------------------
Quirofano ArchivoQuirofano::leerRegistro(int pos){

        Quirofano reg;
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Quirofano)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
///================================FIN==========================================

///=============================================================================
/// FUNCION :int ArchivoQuirofano::buscar(int id)
/// ACCION : busca id de quirofano
/// PARAMETROS: int id
///
/// DEVUELVE : int --> entero
///-----------------------------------------------------------------------------

int ArchivoQuirofano::buscar(int id){

 int i;
 int cantidadRegistros = this->getCantidadRegistros();
  Quirofano aux;

  for(i=0; i<cantidadRegistros; i++)
  {
    aux = this->leerRegistro(i);
    if (aux.getID()== id)
    {
      return i;
    }
  }
  return -1;

}
///================================FIN==========================================

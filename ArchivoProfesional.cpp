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
// Aqui se desarrollan la Metodos de la class ArchivoProfesional
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include <string>
#include "ArchivoProfesional.h"
#include "Profesional.h"
ArchivoProfesional::ArchivoProfesional(){
_nombre = "archivoProfesional.dat";
}
ArchivoProfesional::ArchivoProfesional(std::string nombre){

_nombre=nombre;
}

///=============================================================================
/// FUNCION :int ArchivoProfesional::contarRegistros()
/// ACCION : cuenta la cantidad de registros
/// PARAMETROS:
///
/// DEVUELVE : int --> entero
///-----------------------------------------------------------------------------

int ArchivoProfesional::contarRegistros(){
	FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Profesional);
}

///================================FIN==========================================

///=============================================================================
/// FUNCION :Profesional ArchivoProfesional::leerRegistro(int pos)
/// ACCION : Lee el registro
/// PARAMETROS: int pos
///
/// DEVUELVE : Profesional --> devuelve un registro
///-----------------------------------------------------------------------------

 Profesional ArchivoProfesional::leerRegistro(int pos){
	Profesional reg;
        FILE *p;
        p=fopen(_nombre.c_str(), "rb"); //c_str
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;

 }
 ///================================FIN==========================================

///=============================================================================
/// FUNCION :bool ArchivoPaciente::guardar(Profesional profesional)
/// ACCION : guarda un profesional
/// PARAMETROS: Profesional profesional
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------

bool ArchivoProfesional::guardar(Profesional profesional){

	FILE *p = fopen(_nombre.c_str(), "ab");

	if (p == NULL)
	{
		return false;
	}
	//reg.Cargar();

	bool pudoEscribir = fwrite(&profesional, sizeof(Profesional), 1, p);
	fclose(p);
	return pudoEscribir;

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :int ArchivoProfesional::buscar(int id)
/// ACCION : busca id de profesional
/// PARAMETROS: int id
///
/// DEVUELVE : int --> entero
///-----------------------------------------------------------------------------
int ArchivoProfesional::buscar(int id){

 int i;
 int cantidadRegistros = this->contarRegistros();
  Profesional aux;

  for(i=0; i<cantidadRegistros; i++)
  {
    aux = this->leerRegistro(i);
    if (aux.getID() == id)
    {
      return i;
    }
  }
  return -1;

}
///================================FIN==========================================


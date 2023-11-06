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
// Aqui se desarrollan la Metodos de la class ArchivoPaciente
//
/////////////////////////////////////////////////////////////////////////////////

#include "ArchivoPaciente.h"
#include <cstdio>


using namespace std;




ArchivoPaciente::ArchivoPaciente(){
_nombre = "archivoPaciente.dat";
}

ArchivoPaciente::ArchivoPaciente(std::string nombre){
_nombre = nombre;
}

///=============================================================================
/// FUNCION :bool ArchivoPaciente::guardar(Paciente reg)
/// ACCION :guardar
/// PARAMETROS: Paciente reg
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------
bool ArchivoPaciente::guardar(Paciente reg){



	FILE *p = fopen(_nombre.c_str(), "ab");

	if (p == NULL)
	{
		return false;
	}
	//reg.Cargar();

  bool pudoEscribir = fwrite(&reg, sizeof(Paciente), 1, p);
  fclose(p);
  return pudoEscribir;
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :bool ArchivoPaciente::guardarModificacion(Paciente reg, int pos)
/// ACCION :guardarModificacion
/// PARAMETROS: Paciente reg, int pos
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------

bool ArchivoPaciente::guardarModificacion(Paciente reg, int pos){

	FILE *p = fopen(_nombre.c_str(), "rb+");

  if (p == NULL)
  {
    return false;
  }

  fseek(p, pos* sizeof(Paciente), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Paciente), 1, p);
  fclose(p);
  return pudoEscribir;

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :int ArchivoPaciente::getCantidadRegistros()
/// ACCION :cuenta la cantidad de registros
/// PARAMETROS:
///
/// DEVUELVE : int --> devuelve un registro
///-----------------------------------------------------------------------------

int ArchivoPaciente::getCantidadRegistros(){

FILE *p = fopen(_nombre.c_str(), "rb");

  if (p == NULL)
  {
    return 0;
  }

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  return bytes / sizeof(Paciente);
}

///================================FIN==========================================

///=============================================================================
/// FUNCION :Paciente ArchivoPaciente::leerRegistro(int pos
/// ACCION :lee un registros
/// PARAMETROS: int pos
///
/// DEVUELVE : Paciente --> devuelve un registro
///-----------------------------------------------------------------------------

Paciente ArchivoPaciente::leerRegistro(int pos){

        Paciente reg;
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Paciente)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
///================================FIN==========================================


///=============================================================================
/// FUNCION :int ArchivoPaciente::buscar(int id)
/// ACCION :busca un registro por idregistros
/// PARAMETROS: int pos
///
/// DEVUELVE : int --> devuelve un registro
///-----------------------------------------------------------------------------
int ArchivoPaciente::buscar(int id){

 int i;
 int cantidadRegistros = this->getCantidadRegistros();
  Paciente aux;

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

///=============================================================================
/// FUNCION :void ArchivoPaciente::leer(Paciente *vec, int cantidadRegistrosALeer)
/// ACCION :lee un registro
/// PARAMETROS: Paciente *vec, int cantidadRegistrosALeer
///
/// DEVUELVE : void --> nada
///-----------------------------------------------------------------------------

void ArchivoPaciente::leer(Paciente *vec, int cantidadRegistrosALeer){
  FILE *p = fopen(_nombre.c_str(), "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Paciente), cantidadRegistrosALeer, p);
  fclose(p);
}
///================================FIN==========================================


///=============================================================================
/// FUNCION :void ArchivoPaciente::vaciar()
/// ACCION :vaia un o los registros
/// PARAMETROS:
///
/// DEVUELVE : void --> nada
///-----------------------------------------------------------------------------
void ArchivoPaciente::vaciar(){

	FILE *p = fopen(_nombre.c_str(), "wb");
  if (p == NULL)
  {
    return ;
  }

  fclose(p);

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :bool ArchivoPaciente::guardar(Paciente *vec, int cantidadRegistrosAEscribir)
/// ACCION :guarda un paciente
/// PARAMETROS:
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------
bool ArchivoPaciente::guardar(Paciente *vec, int cantidadRegistrosAEscribir){

FILE *p = fopen(_nombre.c_str(), "ab");
  if (p == NULL)
  {
	cout << "Error";
	return false;
  }
  int cantRegEscritos =fwrite(vec, sizeof(Paciente),cantidadRegistrosAEscribir, p);

  fclose(p);
  return cantRegEscritos == cantidadRegistrosAEscribir;

}
///================================FIN==========================================

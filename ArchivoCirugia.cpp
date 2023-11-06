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
// Aqui se desarrollan la Metodos de la class ArchivoCirugia
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "ArchivoCirugia.h"

ArchivoCirugia::ArchivoCirugia(){
_nombre = "archivoCirugia.dat";
}

ArchivoCirugia::ArchivoCirugia(std::string nombre){
_nombre = nombre;
}


//=============================================================================
// FUNCION : bool ArchivoCirugia::guardar(Cirugia reg)
// ACCION :  guarda el archivo
// PARAMETROS: reg
//
// DEVUELVE : bool --> true o false.
//-----------------------------------------------------------------------------
bool ArchivoCirugia::guardar(Cirugia reg){

	FILE *p = fopen(_nombre.c_str(), "ab");

	if (p == NULL)
	{
		return false;
	}
	//reg.Cargar();

  bool pudoEscribir = fwrite(&reg, sizeof(Cirugia), 1, p);
  if(pudoEscribir == true){
		cout << endl;
	cout << "CARGA EXITOSA"<<endl;
  }else{
  	cout << endl;
  cout << "NO SE PUDO CARGAR DATOS"<<endl;
  }
  fclose(p);
  return pudoEscribir;

}
///================================FIN==========================================

///=============================================================================
/// FUNCION : int ArchivoCirugia::getCantidadRegistros()
/// ACCION :  cuenta la cantidad de registros
/// PARAMETROS:
///
/// DEVUELVE : int --> entero
///-----------------------------------------------------------------------------

int ArchivoCirugia::getCantidadRegistros(){

FILE *p = fopen(_nombre.c_str(), "rb");

  if (p == NULL)
  {
    return 0;
  }

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  return bytes / sizeof(Cirugia);
}
///================================FIN==========================================

///=============================================================================
/// FUNCION : Cirugia ArchivoCirugia::leerRegistro(int pos)
/// ACCION :  lee un registro registros
/// PARAMETROS: int pos
///
/// DEVUELVE : Cirugia --> reg de Cirugia
///-----------------------------------------------------------------------------

Cirugia ArchivoCirugia::leerRegistro(int pos){

        Cirugia reg;
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Cirugia)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
///================================FIN==========================================

///=============================================================================
/// FUNCION :int ArchivoCirugia::buscar(int id)
/// ACCION : busca id de cirugia
/// PARAMETROS: int id
///
/// DEVUELVE : int --> entero
///-----------------------------------------------------------------------------

int ArchivoCirugia::buscar(int id){

 int i;
 int cantidadRegistros = this->getCantidadRegistros();
  Cirugia aux;

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
/// FUNCION :int ArchivoCirugia::buscarEstado(bool estado)
/// ACCION :buscarEstado
/// PARAMETROS: bool estado
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------
int ArchivoCirugia::buscarEstado(bool estado) {
    Cirugia reg;
    FILE* pCirugia;
    int pos = 0;

    pCirugia = fopen(_nombre.c_str(), "rb");
    if (pCirugia == NULL) {
        return -2;
    }
    while (fread(&reg, sizeof reg, 1, pCirugia) == 1) {
        if (reg.getEstado() == true) {
            fclose(pCirugia);
            return pos;
        }
        pos++;
    }

    fclose(pCirugia);
    return -1;
}
///================================FIN==========================================
bool ArchivoCirugia::guardarModificacionC(Cirugia aux, int pos){
	FILE *p = fopen(_nombre.c_str(), "rb+");

  if (p == NULL)
  {
    return false;
  }

  fseek(p, pos* sizeof(Cirugia), SEEK_SET);
  bool pudoEscribir = fwrite(&aux, sizeof(Cirugia), 1, p);
  fclose(p);
  return pudoEscribir;


}

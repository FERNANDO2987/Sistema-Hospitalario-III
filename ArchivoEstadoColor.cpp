#include <iostream>
using namespace std;
#include "ArchivoEstadoColor.h"

ArchivoEstadoColor::ArchivoEstadoColor(){
_nombre = "archivoEstadoColor.dat";
}

ArchivoEstadoColor::ArchivoEstadoColor(std::string nombre){
_nombre = nombre;
}


///GUARDAR ESTADO COLOR
bool ArchivoEstadoColor::guardar(EstadoColor reg){

	FILE *p = fopen(_nombre.c_str(), "ab");

	if (p == NULL)
	{
		return false;
	}
	//reg.Cargar();

  bool pudoEscribir = fwrite(&reg, sizeof(EstadoColor), 1, p);
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
///=======================FIN===========================

///CANTIDAD DE REGISTROS

int ArchivoEstadoColor::getCantidadRegistros(){

FILE *p = fopen(_nombre.c_str(), "rb");

  if (p == NULL)
  {
    return 0;
  }

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  return bytes / sizeof(EstadoColor);
}

///=======================FIN===========================

///LEER REGISTRO

EstadoColor ArchivoEstadoColor::leerRegistro(int pos){

        EstadoColor reg;
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(EstadoColor)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


///=======================FIN===========================

/// BUSCAR ESTADO COLOR POR ?

int ArchivoEstadoColor::buscar(int id){

 int i;
 int cantidadRegistros = this->getCantidadRegistros();
  EstadoColor aux;

  for(i=0; i<cantidadRegistros; i++)
  {
    aux = this->leerRegistro(i);
    if (aux.getVerde() == id)
    {
      return i;
    }
  }
  return -1;

}

///=======================FIN===========================


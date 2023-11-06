#include <iostream>
#include <string>
using namespace std;
#include "EstadoColorManager.h"
#include "rlutil.h"
using namespace rlutil;







void EstadoColorManager::Listar(EstadoColor estadoColor){

	cout << "INICIALIZACION DE CIRUGIA (VERDE): " << estadoColor.getVerde() << endl;
	cout << "CIRUGIA EN CURSO (ROJO): " << estadoColor.getRojo()<< endl;
	cout << "CIRUGIA POR FINALIZAR (AMARILLO): " << estadoColor.getAmarillo()<< endl;
	cout << "CIRUGIA FINALIZADA,LIMPIEZA DE QUIROFANO (AZUL): " << estadoColor.getAzul()<< endl;

}



void EstadoColorManager::ListarTodos(){

int cantidadRegistros = _archivoEstadoColor.getCantidadRegistros();

  for (int i = 0; i<cantidadRegistros; i++)
  {
    EstadoColor reg = _archivoEstadoColor.leerRegistro(i);

      Listar(reg);
      cout << endl;
  }
}

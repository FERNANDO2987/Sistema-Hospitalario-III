#ifndef ARCHIVOESTADOCOLOR_H_INCLUDED
#define ARCHIVOESTADOCOLOR_H_INCLUDED

#include <string>
#include "EstadoColor.h"

class ArchivoEstadoColor{

private:
	string _nombre;
public:
	ArchivoEstadoColor();
	ArchivoEstadoColor(string nombre);

	int getCantidadRegistros();
	bool guardar(EstadoColor reg);
	EstadoColor leerRegistro(int pos);
	int buscar(int id);
    int buscarEstado(bool estado);

};



#endif // ARCHIVOESTADOCOLOR_H_INCLUDED

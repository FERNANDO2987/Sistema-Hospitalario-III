#ifndef ESTADOCOLORMANAGER_H_INCLUDED
#define ESTADOCOLORMANAGER_H_INCLUDED

#include "EstadoColor.h"
#include "Cirugia.h"
#include "ArchivoEstadoColor.h"
class EstadoColorManager
{
	public:

		void Cargar();
		void ListarTodos();
		void Listar(EstadoColor estadoColor);
		void ListarPorID();
		void asignarEstadoColor();
		///bool validarID(Paciente &reg1, Cirugia &aux, int &id);


	private:
		ArchivoEstadoColor _archivoEstadoColor;
		bool existeID(int id);
		int generarID();
};


#endif // ESTADOCOLORMANAGER_H_INCLUDED

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
// Aqui se desarrolla la class QuirofanoManager
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef QUIROFANOMANAGER_H
#define QUIROFANOMANAGER_H
#include "Quirofano.h"
#include "ArchivoQuirofano.h"


class QuirofanoManager
{
	public:
	    ///CARGAR UN NUEVO QUIROFNO
		void Cargar();
		 ///LISTAR TODOS LOS QUIROFNO
		void ListarTodos();
		///LISTAR UN QUIROFANO
		void Listar(Quirofano quirofano);
		///BUSCAR QUIROFANO POR ID
		void BuscarPorID();
		bool validarID(Quirofano &reg, int id);
		///
	void quirofanosOcupados();

private:
    ///LLAMA A ARCHIVOQUIROFANO
	ArchivoQuirofano _archivoQuirofano;
	///FUNCION PARA CORROBORAR SI EXISTE ID
	bool existeID(int id);
		///FUNCION PARA GENERAR ID
	int generarID();
};

#endif // QUIROFANOMANAGER_H

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
// Aqui se desarrolla la class ArchivoQuirofano
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef ARCHIVOQUIROFANO_H
#define ARCHIVOQUIROFANO_H
#include <string>
#include "Quirofano.h"


class ArchivoQuirofano
{
	private:

	string _nombre;

	public:

	ArchivoQuirofano();
	ArchivoQuirofano(string nombre);
   ///METODO PARA OBTENER LAS CANTIDADES DE REGISTROS
	int getCantidadRegistros();
	bool guardar(Quirofano reg);
	Quirofano leerRegistro(int pos);
	int buscar(int id);
};

#endif // ARCHIVOQUIROFANO_H

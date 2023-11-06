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
// Aqui se desarrolla la class ArchivoProfesional
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef ARCHIVOPROFESIONAL_H
#define ARCHIVOPROFESIONAL_H
#include "Profesional.h"
#include <string>
using namespace std;


class ArchivoProfesional
{
	private:
	string _nombre;

public:
	ArchivoProfesional();
	ArchivoProfesional(string nombre);

    int contarRegistros();
    bool guardar(Profesional profesional);
	Profesional leerRegistro(int pos);
	int buscar(int id);


};

#endif // ARCHIVOPROFESIONAL_H

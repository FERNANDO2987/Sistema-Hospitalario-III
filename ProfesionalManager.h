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
// Aqui se desarrolla la class ProfesionalManager
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef PROFESIONALMANAGER_H
#define PROFESIONALMANAGER_H

#include "Profesional.h"
#include "ArchivoProfesional.h"
class ProfesionalManager
{
public:
        ///CARGAR PROFESIONAL
		void Cargar();
		///LISTAR TODOS LOS PROFESIONAL
		void ListarTodos();
		///LISTAR UN PROFESIONAL PROFESIONAL
		void Listar(Profesional profesional);
		///BUSCAR PROFESIONAL POR ID
		void BuscarPorID();
		///VALIDAR PROFESIONAL
		bool validarIDProfesional(Profesional &profesional,int id);
		///BUSCAR CIRUGIA POR APELLIDO DEL PROFESIONAL
		void BuscarCirugiaPorApellidoProfesional();
		///
		void pacientesPorProfesional();
		void ListarParaPaciente(Profesional profesional);

		void ListarTodosParaPaciente();
		string BuscarPorIDParaPaciente(int IDProfesional);


private:
	ArchivoProfesional _archivoProf;

	///FUNCION PARA VER SI EXISTE ID
	bool existeID(int id);
	///FUNCION PARA GENERAR ID AUTOMATICAMENTE
	int generarID();
};


#endif // PROFESIONALMANAGER_H

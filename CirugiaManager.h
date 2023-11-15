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
// Aqui se desarrolla la class CirugiaManager
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef CIRUGIAMANAGER_H
#define CIRUGIAMANAGER_H
#include "Cirugia.h"
#include "Paciente.h"
#include "ArchivoCirugia.h"
class CirugiaManager
{
	public:

		void Cargar();
		void ListarTodos();
		void Listar(Cirugia cirugia);
		void ListarPorID();
		void asignarCirugia();

		bool Modificar(Cirugia &reg, int i);

		bool validarID(Paciente &reg1, Cirugia &aux, int &id);
		///BUSCA CIRUGIA POR ID
		void buscarHC();
		/// Muestra por pantalla Paciente y Cirugia
		void mostrarCirugiaYPaciente();
		/// muestra paciente
		void listarCirugias(Cirugia cirugia);
        ///Lista la cirugia por HC
		void listarCirugiasPorHC(Cirugia cirugia);
		///Cambia el curso de la cirugia
		void modificarCursoDeCirugia();
		///Elimina una cirugia
		void EliminarCirugia(Cirugia &aux);
		///Pregunta el estado color
		bool PreguntaEstado(Paciente &reg1, Cirugia &aux, int &id);
		/// INFORMES
		void obtenerProcedimientosXFecha();
		void promedioDeEtapas();
		Cirugia ObtenerCirugiaPorIdPaciente(int idPaciente);

bool validarID(Paciente &reg, int &id);
bool validarID(Cirugia &reg, int &id);
	private:
		ArchivoCirugia _archivo;
		bool existeID(int id);
		int generarID();
};

#endif // CIRUGIAMANAGER_H

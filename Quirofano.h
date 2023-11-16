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
// Aqui se desarrolla la class Quirofano
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef QUIROFANO_H
#define QUIROFANO_H
#include "Tiempo.h"

#include <string>

class Quirofano
{
	 private:

		int _id;
        int _NroCama;
        char _NroQuirofano [10];
        int _Ocupado;
        Tiempo _tiempoProcedimiento;

    public:
		Quirofano();

        Quirofano(int ID, int NroCama, std::string NroQuirofano, int Ocupado, Tiempo TiempoProc);

        void setID(int id);
        void setNroCama(int cama);
        void setNroQuirofano(std::string quirofano);
        void setOcupado(int ocupado);
        void setTiempoProcedimiento(Tiempo tiempo);

        int getID();
        int getNroCama();
        std::string getNroQuirofano();
        int getOcupado();
        Tiempo getTiempoProcedimiento();
};

#endif // QUIROFANO_H

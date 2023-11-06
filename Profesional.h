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
// Aqui se desarrolla la class Profesional
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef PROFESIONAL_H
#define PROFESIONAL_H
#include <string>

class Profesional
{
    private:
    	char _Nombre[20];
    	char _Apellido[20];
        char _Especialidad[30];
		int _Id;
		int _legajo;
    public:
    	Profesional();
    	Profesional(string nombre, string apellido, string especialidad,int id, int legajo);
		///set
		void setNombre(string nombre);
		void setApellido(string apellido);
        void setEspecialidad (string especialidad);
        void setID(int id);
        void setlegajo(int legajo);

        ///gets

        string getNombre();
        string getApellido();
        string getEspecialidad();
        int getID();
        int getlegajo();

};

#endif // PROFESIONAL_H

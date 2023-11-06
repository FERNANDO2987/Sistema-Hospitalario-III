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
// Aqui se desarrolla la class Paciente
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include "Fecha.h"
#include "Tiempo.h"
#include "TipoDocumento.h"

class Paciente{
private:
	bool _estado;
	char _genero[10];
	int _documento;
	Fecha _fechaNac;
	Fecha _fechaOperacion;
	char _nombre[50];
	char _apellido[30];
	int _id;
	char _mail[30];
	char _diagnostico[30];
	char _patologia[30];
	int _HC;
	char _profesionalAsignado[30];


public:
	Paciente();
	Paciente(bool estado, std::string genero, int documento, Fecha fechaNac,
		     Fecha fechaOperacion, std::string nombre, std::string apellido, int id,std::string mail,
		     std::string diagnostico,std::string patologia,int HC, std::string profesionalAsig);

	void setEstado(bool estado);
	void setGenero(string genero);
	void setDocumento (int Dni);
	void setFechaNacimiento(Fecha fechaNac);
	void setFechaOperacion(Fecha fechaOperacion);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setID(int id);
	void setEmail(string mail);
	void setDiagnostico(string diagnostico);
	void setPatologia(string patologia);
	void setHistorialClinico(int HC);
	void setProfesionalAsignado(string profesionalAsig);

	bool getEstado();
	std::string getGenero();
	int getDocumento();
	Fecha getFechaNacimiento();
	Fecha getFechaOperacion();
	std::string getNombre();
	std::string getApellido();
	int getID();
	std::string getEmail();
	std::string getDiagnostico();
	std::string getPatologia();
	int getHistorialClinico();
	std::string getProfesionalAsignado();


};


#endif // PACIENTE_H

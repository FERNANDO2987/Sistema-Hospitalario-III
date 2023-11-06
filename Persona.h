#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"
#include "TipoDocumento.h"
class Persona
{
	private:
	bool _estado;
	string _genero;
	TipoDocumento _documento;
	Fecha _fechaAlta;
	Fecha _fechaBaja;
	Fecha _fechaNac;
	string _nombre;
	string _apellido;
	int _id;
	string _mail;

	public:
		void setEstado(bool estado);
		void setGenero(string genero);
		void setDocumento (TipoDocumento Dni);
		void setFechaAlta(Fecha fechaAlta);
		void setFechaBaja(Fecha fechaBaja);
		void setFechaNacimiento(Fecha fechaNacimiento);
		void setNombre(string nombre);
		void setApellido(string apellido);
		void setID(int id);
		void setEmail(string email);

		bool getEstado();
		string getGenero();
		TipoDocumento getDocumento();
		Fecha getFechaAlta();
		Fecha getFechaBaja();
		Fecha getFechaNacimiento();
		string getNombre();
		string getApellido();
		int getID();
		string getEmail();

		void Cargar();
		void Mostrar();
};

#endif // PERSONA_H

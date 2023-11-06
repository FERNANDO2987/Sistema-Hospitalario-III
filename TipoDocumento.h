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
// Aqui se desarrolla la class TipoDocumento
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef TIPODOCUMENTO_H
#define TIPODOCUMENTO_H
#include <iostream>

using namespace std;
#include <string>

class TipoDocumento{

 private:
    string Pasaporte;
    string Documento;
    string LibretaCivica;

  public:
    void setPasaporte(string pasaporte);
    void setDocumento(string Documento);
    void setLibretaCivica(string Libretacivica);

    string getPasaporte();
    string getDocumento();
    string getLibretaCivica();

    void Cargar();
	void Mostrar();
};
#endif

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
// Aqui se desarrolla la class Fecha
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;
#include <cstring>

class Fecha{
 private:
   int _dia, _mes, _anio;


   public:

      Fecha();
      Fecha(int dia, int mes, int anio);

      int getDia();
      int getMes();
      int getAnio();
      bool esEnteroValido(const string& input);
      int obtenerEnteroValidado(const string& mensaje);
      bool esFechaValida(int dia, int mes, int anio);
      void agregarDias(int cantidadDias);
      string toString(string formatoFecha = "DD/MM/YYYY");
      void Cargar();
      void CargaFechaOperacion();
      void Mostrar();
};

#endif // FECHA_H

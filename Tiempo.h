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
// Aqui se desarrolla la class Tiempo
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef TIEMPO_H
#define TIEMPO_H


class Tiempo
{
private:
  int horas;
  int minutos;
  int segundos;
public:
	Tiempo(){};
  Tiempo(int h, int m, int s);

  void setHoras(int h);
  void setMinutos(int m);
  void setSegundos(int s);
  int getHoras();
  int getMinutos();
  int getSegundos();
	void Cargar();

	void Mostrar();
};

#endif // TIEMPO_H

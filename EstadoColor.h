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
// Aqui se desarrolla la class EstadoColor
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef ESTADOCOLOR_H
#define ESTADOCOLOR_H

enum Estado
{
    Verde,    //Inicializacion,
    Amarillo, // PorFinalizar
    Rojo ,    //EnCurso
    Azul  //FinalizadaLimpieza
};

class EstadoColor
{
	private:

   int _verde;  //Inicializacion,
   int _amarillo; // PorFinalizar
   int _rojo;    //EnCurso
   int _azul; //FinalizadaLimpieza


public:

    //Constructor
    EstadoColor( int verde, int amarillo, int rojo, int azul);
    EstadoColor(){
    _verde = Verde;
        _amarillo = Amarillo;
        _rojo = Rojo;
        _azul = Azul;}
	void setVerde(int nuevoVerde);
	void setAmarillo(int nuevoAmarillo);
	void setRojo(int nuevoRojo);
	void setAzul(int nuevoAzul);

	int getVerde();
	int getAmarillo();
	int getRojo();
	int getAzul();

};

#endif // ESTADOCOLOR_H

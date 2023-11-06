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
// Aqui se desarrollan la Metodos de la class EstadoColor
//
/////////////////////////////////////////////////////////////////////////////////

#include "EstadoColor.h"

//Setters:
void EstadoColor::setAmarillo(int nuevoAmarillo){
_amarillo = nuevoAmarillo;
}
void EstadoColor::setVerde(int nuevoVerde){
_verde = nuevoVerde;
}
void EstadoColor::setAzul(int nuevoAzul){
_azul=nuevoAzul;
}
void EstadoColor::setRojo(int nuevoRojo){
_rojo = nuevoRojo;
}
///================================FIN==========================================

//Getters
int EstadoColor::getAmarillo(){
return _amarillo;
}
int EstadoColor::getAzul(){
 return _azul;
 }
int EstadoColor::getRojo(){
 return _rojo;
 }
int  EstadoColor::getVerde(){
 return _verde;
 }
///================================FIN==========================================

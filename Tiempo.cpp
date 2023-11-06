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
// Aqui se desarrollan los metodos de la class Tiempo.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
#include "Tiempo.h"

Tiempo::Tiempo(int h, int m, int s) {
    horas = h;
    minutos = m;
    segundos = s;
}

void Tiempo::setHoras(int h) {
    horas = h;
}

void Tiempo::setMinutos(int m) {
    minutos = m;
}

void Tiempo::setSegundos(int s) {
    segundos = s;
}

int Tiempo::getHoras() {
    return horas;
}

int Tiempo::getMinutos() {
    return minutos;
}

int Tiempo::getSegundos() {
    return segundos;
}

void Tiempo::Cargar(){
cout << "Horas: ";
cin>>horas;
cout << "Minutos: ";
cin>>minutos;
cout << "Segundos: ";
cin>>segundos;
}

void Tiempo::Mostrar(){
cout << horas<<":"<<minutos<<":"<<segundos;
}

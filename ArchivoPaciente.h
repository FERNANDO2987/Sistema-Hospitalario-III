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
// Aqui se desarrollan la class ArchivoPaciente
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef ARCHIVOPACIENTE_H
#define ARCHIVOPACIENTE_H
#include "Paciente.h"
#include <string>

class ArchivoPaciente
{
private:
    string _nombre;


public:
    ArchivoPaciente();
    ArchivoPaciente( string nombre);

    ///METODO PARA OBTENER LAS CANTIDADES DE REGISTROS
    int getCantidadRegistros();
    ///GUARDAR PACIENTE
    bool guardar(Paciente reg);
    ///LEER UN PACIENTE
    Paciente leerRegistro(int pos);
    ///BUSCAR UN APCIENTE POR ID
    int buscar(int id);
    ///GUARDAR MODIFICACION DE PACINETE
    bool guardarModificacion(Paciente reg,int pos);

///METODO PARA LEER UN PACIENTE
    void leer(Paciente *vec, int cantidadRegistrosALeer);
    ///METODO PARA VACIAR
    void vaciar();
    ///METODO PARA GUARDAR
    bool guardar(Paciente *vec, int cantidadRegistrosAEscribir);

    ///BUSCAR ARCHIVO
    void buscarEnArchivo();

};

#endif // ARCHIVOPACIENTE_H

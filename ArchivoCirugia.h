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
// Aqui se desarrolla la class ArchivoCirugia
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef ARCHIVOCIRUGIA_H
#define ARCHIVOCIRUGIA_H
#include <string>
#include "Cirugia.h"

class ArchivoCirugia
{

private:
    string _nombre; ///NOMBRE PARA ASIGNAR A LOS ARCHIVOS
public:
    ArchivoCirugia();
    ArchivoCirugia(string nombre);

    ///METODO PARA OBTENER LAS CANTIDADES DE REGISTROS
    int getCantidadRegistros();
    ///GUARDAR REGISTRO
    bool guardar(Cirugia reg);
    ///LEER UN REGISTRO
    Cirugia leerRegistro(int pos);
    ///BUSCAR UNA CIRUGIA
    int buscar(int id);
    ///BUSCAR ESTADO DE CIRUGIA
    int buscarEstado(bool estado);
    ///
    bool guardarModificacionC(Cirugia reg, int pos);

};
#endif // ARCHIVOCIRUGIA_H

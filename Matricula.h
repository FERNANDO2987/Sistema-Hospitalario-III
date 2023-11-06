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
// Aqui se desarrolla la class Matricula
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef MATRICULA_H
#define MATRICULA_H


class Matricula
{
private:
    int id;
    string matriculaNacional;
    string matriculaProvincial;
public:
    void setID(int _id);
    void setMatriculaNacional(string _matriculaNacional);
    void setMatriculaProvincial (string _matriculaProvincial);

    int getID();
    string getMatriculaNacional();
    string getMatriculaProvincial();

    void Cargar();
    void Mostrar();

};

#endif // MATRICULA_H

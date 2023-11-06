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
// Aqui se desarrolla la class Cirugia
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef CIRUGIA_H
#define CIRUGIA_H
#include <string>


class Cirugia
{
private:
	bool _estado;
    int _id;
    char _observacion[100];
    char _antibioticos[100];
    bool _alergia;
    char _implantes[100];
    char _diagnostico[100];
    char _tipoDeCirugia[100];
    char _procedimientos[100];
    int _estadosDeCirugias;


public:
    //Constructor
    Cirugia();

    Cirugia(bool estado, int id, std::string observacion, std::string antibioticos, bool alergia, std::string implantes,
        std::string diagnostico, std::string tipoDeCirugia, std::string procedimiento, int estadoDeCirugias);


   //set
   void setEstado(bool e);
    void setID(int id);
    void setObservaciones(std::string observaciones);
    void setAntibioticos (std::string antibioticos);
    void setAlergia(bool _alergia);
    void setImplantes (std::string implantes);
    void setDiagnostico (std::string diagnostico);
    void setTipoDeCirugia (std::string tipoDeCirugia);
    void setProcedimientos (std::string procedimientos);
    void setEstadoCirugias(int estadoCirugia);



    //get
    bool getEstado();
    int getID();
    std::string getObservaciones();
    std::string getAntibioticos ();
    bool getAlergia();
    std::string getImplantes();
    std::string getDiagnostico();
    std::string getTipoDeCirugia();
    std::string getProcedimientos();
    int getEstadoCirugias();

};

#endif // CIRUGIA_H

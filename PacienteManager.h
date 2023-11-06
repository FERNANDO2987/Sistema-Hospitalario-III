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
// Aqui se desarrolla la class PacienteManager
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef PACIENTEMANAGER_H
#define PACIENTEMANAGER_H
#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <cctype>
#include "ArchivoPaciente.h"
#include "ArchivoCirugia.h"
#include "Paciente.h"

class PacienteManager
{
public:
    ///cargar paciente
    void Cargar();
    ///listar todos los paciente
    void ListarTodos();
    ///listar un paciente
    void Listar(Paciente paciente);
    ///listar por id el paciente
    void ListarPorID();
    ///Modificar paciente
    bool Modificar(Paciente &reg, int i);
    ///elimina paciente baja logica
    void Eliminar(Paciente &reg);
    ///valida que no se repita id
    bool validarID(Paciente &reg1, int id);
    /// buscar paciente por id
    void buscarPacientePorID();
    /// hacemos copia de seguridad del archivo paciente
    void copiaDeSeguridadPaciente();
    void restaurarBkp();
    /// Mofificar mail
    void modificarMail();
    ///Lista por apellido
    void BuscarPorApellido();
    void convertirAMayusculas(char* apellido);
    bool existeApellido (std::string apellido);
    ///Listar Paciente con pocos datos
    void listarPaciente(Paciente paciente);
    // Función para generar una historia clínica de 5 dígitos sin repetición
    int generarHistoriaClinica();




private:


    ArchivoPaciente _archivo;
    ArchivoPaciente _archivoBackUp = ArchivoPaciente ("archivoPaciente.bkp");
    ///fucion para corroborar si existe id
    bool existeID(char id);
    ///fucion para generar id automatico
    int generarID();



};
///FUNCION GLOBAL PARA VALIDAR UN INGRESO DE UN ENTERO
int obtenerEnteroValidado(const string& mensaje);
///FUNCION GLOBAL PARA VALIDAR UN INGRESO DE UN ENTERO Y VER SI ES VALIDO
bool esEnteroValido(const string& input);
#endif // PACIENTEMANAGER_H

#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <list>
#include <fstream>

#include "Paciente.h"

class FileIO
{
    private:
        static FileIO* _instance; //Singleton instance
        std::string _path;
        
        FileIO (std::string path)
        {
            _path = path;
            std::ifstream ifs(_path);
            if (!ifs)
            {
                std::ofstream ofs(_path);
            }
        }

        std::list<Cita> getCitasPaciente (std::string dni);
        std::list<Tratamiento> getTratamientosPaciente (std::string dni);
        std::list<EntradaHistorial> getHistorialPaciente (std::string dni);

    public:
        static FileIO* getInstance();

        std::string getPath () const
        {
            return _path;
        }

        void setPath (std::string path)
        {
            _path = path;
        }

        int exists(std::string name); //Comprueba si existe un paciente específico y devuelve su posicion si lo encuentra. -1 si no lo encuentra y -2 si no se produce un error.

        std::list<Paciente> getTodosPacientes(); //Devuelve una lista con todos los pacientes

        std::list<Paciente> buscarPacientes(std::string name); //Busca todos los pacientes con el nombre que se indique

        std::list<Cita> getTodasCitas(); //Devuelve todas las citas

        std::list<Cita> getCitasHoy(); //Devuelve las citas de hoy

        void eliminarPaciente(const Paciente &p); //Elimina paciente de la lista

        void archivarPaciente(const Paciente &p); //Guarda los datos de un paciente
};

#endif
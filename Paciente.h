#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <list>

#include "Cita.h"
#include "Tratamiento.h"
#include "EntradaHistorial.h"


class Paciente {
    private:
        std::string _DNI;
        std::string _nombreCompleto;
        int _telefono;
        std::string _direccion;
        std::string _fechaNacimiento;

        std::list<Cita> _citas;
        std::list<Tratamiento> _tratamientos;
        std::list<EntradaHistorial> _historial;

    public:
        Paciente () {}
        Paciente (
            std::string DNI,
            std::string nombreCompleto,
            int telefono,
            std::string direccion,
            std::string fechaNacimiento
        ) {
            _DNI = DNI;
            _nombreCompleto = nombreCompleto;
            _telefono = telefono;
            _direccion = direccion;
            _fechaNacimiento = fechaNacimiento;
        }

        std::string getDNI () const
        {
            return _DNI;
        }

        void setDNI (std::string DNI)
        {
            _DNI = DNI;
        }

        std::string getNombreCompleto () const
        {
            return _nombreCompleto;
        }

        void setNombreCompleto (std::string nombreCompleto)
        {
            _nombreCompleto = nombreCompleto;
        }

        int getTelefono () const
        {
            return _telefono;
        }

        void setTelefono (int telefono)
        {
            _telefono = telefono;
        }

        std::string getDireccion () const
        {
            return _direccion;
        }

        void setDireccion (std::string direccion)
        {
            _direccion = direccion;
        }

        std::string getFechaNacimiento () const
        {
            return _fechaNacimiento;
        }

        void setFechaNacimiento (std::string fechaNacimiento)
        {
            _fechaNacimiento = fechaNacimiento;
        }

        std::list<EntradaHistorial> getHistorial () const
        {
            return _historial;
        }
        void setHistorial (std::list<EntradaHistorial> historial)
        {
            _historial = historial;
        }
        
        std::list<Tratamiento> getTratamientos () const
        {
            return _tratamientos;
        }

        void setTratamientos (std::list<Tratamiento> tratamientos)
        {
            _tratamientos = tratamientos;
        }

        std::list<Cita> getCitas () const
        {
            return _citas;
        }

        void setCitas (std::list<Cita> citas)
        {
            _citas = citas;
        }

        void anadirCita (const Cita &c); //Añadimos una nueva cita

        void anadirTratamiento (const Tratamiento &t); //Añadimos un nuevo tratamiento

        void anadirHistorial (const EntradaHistorial &h); //Añadimos un nuevo historial

        void finalizarTratamiento(const Tratamiento &t); //Damos por finalizado el tratamiento    
};

#endif
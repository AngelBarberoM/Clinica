#include "Paciente.h"

void Paciente::anadirCita (const Cita &c)
{
    _citas.push_back(c);
}

void Paciente::anadirTratamiento (const Tratamiento &t)
{
    _tratamientos.push_back(t);
}

void Paciente::anadirHistorial (const EntradaHistorial &h)
{
    _historial.push_back(h);
}
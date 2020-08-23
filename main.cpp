#include <iostream>
#include <string>
#include <list>

#include "Helpers.h"
#include "Paciente.h"
#include "Cita.h"
#include "FileIO.h"
#include "EntradaHistorial.h"
#include "Tratamiento.h"

#define EXIT 0
#define ANADIR_PACIENTE 1
#define MOSTRAR_CITAS 2
#define MOSTRAR_CITAS_HOY 3
#define LISTA_PACIENTES 4

#define ANADIR_CITA 1
#define ANADIR_TRATAMIENTO 2
#define ANADIR_HISTORIAL 3
#define CITAS 4
#define HISTORIAL 5
#define TRATAMIENTOS 6
#define MODIFICAR_PACIENTE 7
#define BORRAR_PACIENTE 8

void menuPaciente(Paciente &p){
    int op=0;
    do{
        system("clear");
        printPaciente(p);

        colorPrint("\nElija una opcion:\n", Color::FG_CYAN, true);
        colorPrint("-------------------------------------------\n", Color::FG_CYAN, true);
        std::cout << "0. Salir al menu principal"                  << std::endl;
        std::cout << "1. Anadir nueva cita"                        << std::endl;
        std::cout << "2. Anadir nuevo tratamiento"                 << std::endl;
        std::cout << "3. Anadir nueva entrada al historial"        << std::endl;
        std::cout << "4. Citas del paciente"                       << std::endl;
        std::cout << "5. Historial medico del paciente"            << std::endl;
        std::cout << "6. Tratamientos del paciente"                << std::endl;
        std::cout << "7. Modificar datos del paciente"             << std::endl;
        std::cout << "8. Borrar paciente seleccionado"             << std::endl;
        
        std::cin >> op;
        
        switch(op)
        {

            case ANADIR_CITA:
            {
                system("clear");
                Cita c;
                if(nuevaCita(c))
                {
                    p.anadirCita(c);
                    FileIO::getInstance()->archivarPaciente(p);
                    std::cout << "La cita se añadio correctamente" << std::endl;
                }
                std::cin.ignore();
                std::cin.get();

            }break;

            case ANADIR_TRATAMIENTO:
            {
                system("clear");
                Tratamiento t;
                if(nuevoTratamiento(t))
                {
                    p.anadirTratamiento(t);
                    FileIO::getInstance()->archivarPaciente(p);
                    std::cout << "El tratamiento se añadio correctamente" << std::endl;
                }
                std::cin.ignore();
                std::cin.get();

            }break;

            case ANADIR_HISTORIAL:
            {
                system("clear");
                EntradaHistorial e;
                if(nuevaEntradaHistorial(e))
                {
                    p.anadirHistorial(e);
                    FileIO::getInstance()->archivarPaciente(p);
                    std::cout << "La entrada se añadio correctamente al historial" << std::endl;
                }
                std::cin.ignore();
                std::cin.get();

            }break;

            case CITAS:
            {
                system("clear");
                std::list<Cita> citas = p.getCitas();
                Selection s = seleccionarCita(citas);
                if (s.index != -1) {
                    auto it = citas.begin();
                    for (int i = 0; i < s.index; i++) { it++; }

                    if (s.op == "edit")
                    {
                        system("clear");
                        if(nuevaCita(*it))
                        {
                            p.setCitas(citas);
                            FileIO::getInstance()->archivarPaciente(p);
                            std::cout << "Cita modificada correctamente" << std::endl;
                        }
                        std::cin.ignore();
                        std::cin.get();
                    }
                    else if (s.op == "delete")
                    {
                        system("clear");
                        citas.erase(it);
                        p.setCitas(citas);
                        FileIO::getInstance()->archivarPaciente(p);
                        std::cout << "Cita eliminada correctamente" << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                    }
                }
                
            }break;

            case HISTORIAL:
            {
                system("clear");
                printHistorial(p.getHistorial());
                std::cin.ignore();
                std::cin.get();
            }break;

            case TRATAMIENTOS:
            {
                system("clear");
                std::list<Tratamiento> tratamientos = p.getTratamientos();
                Selection s = seleccionarTratamiento(tratamientos);
                if (s.index != -1)
                {
                    auto it = tratamientos.begin();
                    for (int i = 0; i < s.index; i++) { it++; }

                    if (s.op == "edit")
                    {
                        system("clear");
                        if(nuevoTratamiento(*it))
                        {
                            p.setTratamientos(tratamientos);
                            FileIO::getInstance()->archivarPaciente(p);
                            std::cout << "Tratamiento modificado correctamente" << std::endl;
                            std::cin.ignore();
                            std::cin.get();
                        }
                    }
                    else if (s.op == "delete")
                    {
                        system("clear");

                        if (comprobarFechas(getFechaHoy(), it->getFin()))
                        {
                            tratamientos.erase(it);
                            p.setTratamientos(tratamientos);
                            FileIO::getInstance()->archivarPaciente(p);
                            std::cout << "Tratamiento cancelado correctamente" << std::endl;
                        }
                        else
                        {
                            colorPrint("ERROR: No se puede cancelar un tratamiento ya finalizado\n", Color::FG_RED, true);
                        }
                        std::cin.ignore();
                        std::cin.get();
                    }
                }

            }break;
            
            case MODIFICAR_PACIENTE:
            {
                system("clear");
                if(nuevoPaciente(p, true))
                {
                    FileIO::getInstance()->archivarPaciente(p);
                    std::cout << "Paciente modificado correctamente" << std::endl;
                }
                std::cin.ignore();
                std::cin.get();
            }break;

            case BORRAR_PACIENTE:
            {
                system("clear");
                FileIO::getInstance()->eliminarPaciente(p);
                op = EXIT;
                std::cout << "Paciente eliminado correctamente" << std::endl;
                std::cin.ignore();
                std::cin.get();
            }break;

            case EXIT: break;

            default:
            {
                system("clear");
                colorPrint("ERROR: Opcion no valida\n", Color::FG_RED, true);
                std::cin.ignore();
                std::cin.get();
            }break;

        }

    }while(op!=EXIT);

}

void menu()
{

    int op=0;
    do
    {
        system("clear");
        std::cout << "MENU CLINICA" << std::endl;
 
        colorPrint("\nElija una opcion:\n", Color::FG_CYAN, true);
        colorPrint("---------------------------------\n", Color::FG_CYAN, true);
        std::cout << "0. Salir del programa"             << std::endl;
        std::cout << "1. Anadir nuevo paciente"          << std::endl;
        std::cout << "2. Mostrar citas"                  << std::endl;
        std::cout << "3. Consultar citas de hoy"         << std::endl;
        std::cout << "4. Listado de pacientes"           << std::endl;
        
        std::cin >> op;

        switch(op)
        {

            case ANADIR_PACIENTE:
            {
                system("clear");
                Paciente p;
                if (nuevoPaciente(p))
                {
                    //WARNING: Si el paciente que se ha añadido tiene el mismo DNI que uno ya existente se reemplazara el por el antiguo,
                    //         por tanto se borraran el historial, citas y tratamientos.
                    FileIO::getInstance()->archivarPaciente(p);
                    std::cout << "Paciente anadido correctamente" << std::endl;
                }
                std::cin.get();
            }break;

            case MOSTRAR_CITAS:
            {
                system("clear");
                printCitas(FileIO::getInstance()->getTodasCitas());
                std::cin.ignore();
                std::cin.get();
            }break;

            case MOSTRAR_CITAS_HOY:
            {
                system("clear");
                printCitas(FileIO::getInstance()->getCitasHoy());
                std::cin.ignore();
                std::cin.get();
            }break;

            case LISTA_PACIENTES:
            {
                system("clear");
                Paciente p = seleccionarPaciente();
                if (p.getDNI() != "NULL")
                {
                    menuPaciente(p);
                }
            }break;

            case EXIT:
            {
                system("clear");
            }break;


            default:
            {
                system("clear");
                colorPrint("ERROR: Opcion no valida\n", Color::FG_RED, true);
                std::cin.ignore();
                std::cin.get();
            }break;

        }

    }while(op!=EXIT);

}

int main (int argc, char** argv)
{
    if (argc > 1)
    {
        if (argv[1] == "-nc" || argv[1] == "--no-colors")
        {
            setColors(false);
        }
    }
    menu();
}
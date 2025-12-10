#include "catalog.h"
#include <iostream>

int main(){

//Creación de objetos

    CyclistCatalog cc;
    DirectorCatalog dc;

//======================================================

std::cout << "Carga de los archivos cyclists.csv y directors.csv: " << std::endl;

//Apartado para CYCLISTCATALOG

    if(cc.LoadCyclist("../../../data/cyclists.csv") == false){

        std::cout << "ERROR: no se pudo cargar el archivo de ciclistas" << std::endl;
        return 1;
    }

//======================================================

//Apartado para DIRECTORCATALOG

    if(dc.LoadDirector("../../../data/directors.csv") == false){

        std::cout << "ERROR: no se pudo cargar el archivo de directores" << std::endl;
        return 1;
    }

//======================================================

//Apartado para IMPRIMIR ambos FICHEROS.CSV

    std::cout << "=== Se cargaron los archivos .csv ===" << std::endl;

    std::cout << "Catalogo de Ciclistas cargado: " << std::endl;
    std::vector <Cyclist> vec_cyclist = cc.Data();

    //Recorro cyclist.csv con un bucle for

    for(size_t i = 0; i < (vec_cyclist.size() - 1); i++){

        std::cout << "Ciclista " << i+1 << ". "
                  << vec_cyclist[i].GetName() << ", nacido el " << vec_cyclist[i].GetBirth_Year() << ", es miembro de "
                  << vec_cyclist[i].GetTeam() << " y su id de ciclista es " << vec_cyclist[i].GetCyclist_Id() << std::endl;
        
    }

    std::cout << "Catalogo de Directores cargado: " << std::endl;
    std::vector <Director> vec_directors = dc.Data();

    //Recorro directors.csv con un auto range for

    for(auto &f: vec_directors){

        std::cout << "Director llamado " << f.GetName() << ", nacido el " << f.GetBirth_Year() 
        << ", con direccion en " << f.GetTeam() << ", su id de licencia UCI es " << f.GetUci_License_Id() 
        << " y lleva siendo director desde " << f.GetDirector_Since() << std::endl;
           
    }

//======================================================
std::cout << "----- PROGRAMA FINALIZADO -----";
return 0;

}

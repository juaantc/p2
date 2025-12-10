#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "persons.h"
#include "catalog.h"

bool CyclistCatalog::LoadCyclist(const std::string& path) {
    Cyclist c;
    std::string name, birth_s, cyclist_id, team;
    int birthyear = 0;
    cyclists_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, cyclist_id, ',')) continue;
        if (!std::getline(iss, team)) continue;
        birthyear = std::stoi(birth_s);
        c.SetName(name);
        c.SetBirth_Year(birthyear);
        c.SetCyclist_Id(cyclist_id);
        c.SetTeam(team);
        cyclists_.push_back(c); // se hace una copia al final del vector
    }
    return !cyclists_.empty();
}

bool DirectorCatalog::LoadDirector(const std::string& path){
    Director d;
    std::string name, birth_s, director_id, team, director_since;
    int birthyear = 0, directorsince = 0;
    
    directors_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, director_id, ',')) continue;
        if (!std::getline(iss, team, ',')) continue;
        if (!std::getline(iss, director_since)) continue;
        birthyear = std::stoi(birth_s);
        directorsince = std::stoi(director_since);

        d.SetName(name);
        d.SetBirth_Year(birthyear);
        d.SetUci_License_Id(director_id);
        d.SetTeam(team);
        d.SetDirector_Since(directorsince);
        directors_.push_back(d); // se hace una copia al final del vector
    
    }
    return !directors_.empty();
}
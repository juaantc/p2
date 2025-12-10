#ifndef CATALOG_H
#define CATALOG_H

#include "../persons/persons.h"
#include <vector>
#include <string.h>



class CyclistCatalog{

    private:
            std::vector <Cyclist> cyclists_;
    
    public:
            bool Load(const std::string& path);
            std::vector <Cyclist> Data() {return cyclists_;}
            std::size_t Size() {return Data().size();}

};


class DirectorCatalog{

        private:
                std::vector <Director> directors_;
        
        public:
                bool Load(const std::string& path);
                std::vector <Director>& Data() {return directors_;}
                std::size_t Size() {return Data().size();}

};

#endif

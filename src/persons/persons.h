#ifndef PERSONS_H
#define PERSONS_H

#include <string>

class Person{

    private:
            std::string name_;
            int birth_year_;

    public:
            Person();
            Person(std::string name, int birth_year);
            
            std::string GetName()const {return name_;}
            int GetBirth_Year()const {return birth_year_;}

            void SetName(std::string name){name_ = name;};
            void SetBirth_Year(int birth_year){birth_year_ = birth_year;};

};

class Cyclist:public Person{

    private:
            std::string team_;
            std::string cyclist_id_;

    public:
            Cyclist();
            Cyclist(std::string name, int birth_year, std::string team, std::string cyclist_id); /////

            std::string GetTeam()const {return team_;}
            std::string GetCyclist_Id()const {return cyclist_id_;}

            void SetTeam(std::string team){team_ = team;};
            void SetCyclist_Id(std::string cyclist_id){cyclist_id_ = cyclist_id;};

};

class Director:public Person{

    private:
            std::string team_;
            std::string uci_license_id_;
            int director_since_;
    
    public:
            Director();
            Director(std::string name, int birth_year, std::string team, std::string uci_license_id, int director_since); ///////

            std::string GetTeam()const {return team_;}
            std::string GetUci_License_Id()const {return uci_license_id_;}
            int GetDirector_Since()const {return director_since_;}

            void SetTeam(std::string team){team_ = team;};
            void SetUci_License_Id(std::string uci_license_id){uci_license_id_ = uci_license_id;};
            void SetDirector_Since(int director_since){director_since_ = director_since;};

};

#endif
#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
#include "./player.h"

class Team
    {
    private:
        int id;
        std::string name;
        int current_size;
        int capacity;
        Player* player_list;
    public:
        Team();
        std::string getName();
        int getId();
        int getCurrentSize();
        int getCapacity();
        Player* getPlayer(int number);
        Player* getPlayerList();
        void setName(std::string new_name);
        void setId(int newId);
        void addPlayer(int number, std::string name, int age, int goal_number, int assist_number, int match_number);
        void listPlayers();
        bool checkNumber(int number);
        void removePlayer(int number);
    };
#endif

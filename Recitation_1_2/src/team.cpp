/* @Author
Student Name: Ozan Çetin
Student ID : 150190021
Date: 19.10.2021 */
#include "../include/team.h"

using namespace std;

Team::Team(){};
string Team::getName() { return name; };
int Team::getCurrentSize() { return current_size; };
int Team::getId() { return id; };
int Team::getCapacity() { return capacity; };
Player *Team::getPlayer(int number)
{
    for (int i = 0; i < current_size; i++)
    {
        if (player_list[i].getNumber() == number)
            return &player_list[i];
    }
    return nullptr;
};
Player *Team::getPlayerList()
{
    return player_list;
};
void Team::setName(string new_name) { name = new_name; };
void Team::setId(int newId) { id = newId; };
void Team::listPlayers()
{
    cout << "Number"
         << " Name"
         << " Age"
         << " #Goals"
         << " #Assists"
         << " #Matches" << endl;
    ;
    for (int i = 0; i < current_size; i++)
    {
        cout << player_list[i].getNumber() << " - ";
        cout << player_list[i].getName() << " - ";
        cout << player_list[i].getAge() << " - ";
        cout << player_list[i].getGoalNumber() << " - ";
        cout << player_list[i].getAssistNumber() << " - ";
        cout << player_list[i].getMatchNumber() << endl;
    }
};
void Team::addPlayer(int number, string name, int age, int goals, int assists, int matches)
{
   Player* newplayer = new Player(name, number, age, goals, assists,  matches );  
   int size = getCurrentSize(); 
   if(capacity <= size){ // size is exceeded
    if(size == 0){
        // increase capacity with 0 
        capacity += 3; 
    }
    else{ 
        capacity *= 2; 
    }
   }
 
    Player* newplayer_list = new Player[current_size+1]; 
        for(int i = 0;i<current_size;i++){
            newplayer_list[i] = player_list[i]; 
        }
        newplayer_list[current_size+1].setNumber(newplayer->getNumber());
        newplayer_list[current_size+1].setName(newplayer->getName());
        newplayer_list[current_size+1].setAge(newplayer->getAge());
        newplayer_list[current_size+1].setGoalNumber(newplayer->getGoalNumber());
        newplayer_list[current_size+1].setAssistNumber(newplayer->getAssistNumber());
        newplayer_list[current_size+1].setMatchNumber(newplayer->getMatchNumber()); 

    
    current_size++; 
    Player* deleteptr = player_list; 
    player_list = newplayer_list; 
    delete[] deleteptr;


   return;
};

bool Team::checkNumber(int number)
{
    for (int i = 0; i < current_size; i++)
    {
        if (player_list[i].getNumber() == number)
            return true;
    }
    return false;
}
void Team::removePlayer(int number)
{
  //Fill this method
  
    
    // shrunk the capacity if the size is half of the capacity 
    int size = getCurrentSize();
    if(size!=0 || size!=1){
        if(size <= capacity / 2) // halve the capacity if the size is half of the capacity
        {   
            capacity /= 2; 
        }
    } 
    Player* newplayer_list = new Player[current_size-1]; 
    
    int i = 0; 
    for(i;i<number;i++){
        newplayer_list[i] = player_list[i]; 
    }
    // we reached to the player index
    int iter = number+1;  // we skip the player's index
    while(iter != current_size){
        newplayer_list[i] = player_list[iter]; 
        iter++;
        i++;
    }

    
    // TODO: delete the old address of the player_list and make it point to the newplayer_list

    Player* deleteptr = player_list; 
    player_list = newplayer_list; 
    delete[] deleteptr;

  return;
};
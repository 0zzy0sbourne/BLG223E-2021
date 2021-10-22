#include <iostream>
#include <string>
using namespace std; 

class Team{
    private:
        string name; 
        int id; 
    public: 
        Team(); 
        string getName(); 
        int getId(); 
        void setName(string newname); 
        void setId(int Id); 
}; 

Team::Team(){}; 
string Team::getName(){
    return name; 
}
int Team::getId(){
    return id; 
}
void Team::setName(string newname){
    this->name = newname; 
}
void Team::setId(int Id){
    this->id = Id;
}
void addTeam(string);
void removeTeam(int);  
int current_size = 4; 
Team* tarr = new Team[current_size]; 

int main(){
    tarr[0].setName("Liverpool F.C.");
    tarr[0].setId(0);
    tarr[1].setName("S.S. Lazio");
    tarr[1].setId(1);
    tarr[2].setName("A.C. Milan");
    tarr[2].setId(2);
    tarr[3].setName("Barcelona");
    tarr[3].setId(3);
/* 
    string team_name; 
     cout << "Enter team name:";
        cin.ignore(1000, '\n');
        getline(cin, team_name);
        addTeam(team_name);
   */  

       
  // before adding team: 
   for(int i = 0;i<current_size;i++){
            cout << tarr[i].getName() << endl;
    }
    
    cout << "\n" ;  
    addTeam("Real Madrid"); 
    
    // after adding team
    for(int i = 0;i<current_size;i++){
            cout << tarr[i].getName() << endl;
    }
    cout << "\n"; 

    
    removeTeam(1);
    cout << "\n" ; 

    // after removing team
    for(int i = 0;i<current_size;i++){
            cout << tarr[i].getName() << endl;
    }
    
     
  /* 
     for(int i = 0;i<current_size;i++){
            cout << tarr[i].getName() << endl;
    }
  */
    // cout << tarr[0].getName() << endl ; 
    return 0 ; 
}

void removeTeam(int teamId)
{
  //Fill this method
  Team* newtarr = new Team[current_size-1]; 

    int i = 0; 
    for(i;i<teamId;i++){
        newtarr[i] = tarr[i]; 
    }
    // we reached to teamId index
    int iter = teamId+1; // we skip the teamId  
    while(iter != current_size){
        newtarr[i] = tarr[iter];
        iter++; 
        i++; 
    }
    
    // TODO: delete the players inside the removed team ! 


   cout << "after removing:" <<endl; 
    current_size--; 
    Team* deleteptr = tarr; 
    tarr = newtarr; 
    for(int j = 0;j<current_size;j++){
        cout << tarr[j].getName() << endl;
    }
    delete[] deleteptr; 
    

    

  return;
};


void addTeam(string team_name){
    Team* newteam = new Team(); 
    newteam->setName(team_name); 
    // cout << newteam->getName() << endl ; 
    current_size++; 
    newteam->setId(current_size-1); 
    Team* newtarr = new Team[current_size]; 
    for(int i = 0;i<current_size-1;i++){
        newtarr[i] = tarr[i]; 
    }
    // newtarr[current_size] = *newteam;
    newtarr[current_size-1].setName(newteam->getName()); 
    newtarr[current_size-1].setId(newteam->getId());  
    /* 
    for(int i = 0;i<current_size;i++)
        cout << newtarr[i].getName() <<"  " <<endl  ;
    */
    // newtarr[current_size] = *newteam;
    // cout << newtarr[current_size-2].getName() << endl;
    // delete the old address of the tarr , make it point to the newtarr 
    Team* deleteptr = tarr; 
    tarr = newtarr;
    
    /* PRINTS CORRECTLY 
    cout << "\n" << endl;
    for(int i = 0;i<current_size;i++){
        cout << tarr[i].getName() <<endl; 
    }
    */ 
    delete[] deleteptr;

}


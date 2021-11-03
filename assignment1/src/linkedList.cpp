#include <iostream>
#include <stdio.h>
#include <string.h>

#include "linkedList.h"

using namespace std;

void Train::create(){
    head = NULL;
}; 

void Train::addMaterial(char material, int weight){
        //FILL THIS FUNCTION ACCORDINGLY
        if(head == nullptr) // if train is empty
        {
            if(weight <= 2000)
            {
                // if it is not, do not add it. 
                
                // create new wagon
                wagonNode* newWagon = new wagonNode();
                newWagon->wagonId = 1; 
                newWagon->next = nullptr;

                // create the material box
                materialNode* newMaterial = new materialNode();
                newMaterial->id = material; 
                newMaterial->next = nullptr; 
                newMaterial->weight = weight;

                // add the newMaterial to the new Wagon
                newWagon->material = newMaterial; 

                this->head = newWagon;
            }
            else{ // weight is not valid.
                cout << "Please enter a valid weight." <<endl;
            }
           
        }
        else{ // train is not empty
            wagonNode* currentWagon = this->head;

            while(currentWagon != nullptr)
            { // traverse the wagons
                materialNode* currentMaterial = currentWagon->material; 
                while(currentMaterial != nullptr)
                { // traverse the materials in one wagon 
                    if(currentMaterial->id == material)
                    { // type of material is found in wagon
                        if(currentMaterial->weight < 2000) // check if it is already over 2000 kg
                        {
                            if((weight + currentMaterial->weight) <= 2000)
                            { 
                                currentMaterial->weight += weight;
                            }
                            else if((weight + currentMaterial->weight) > 2000)
                            {
                                // update the weight to herit to another wagon
                                weight = 2000 - currentMaterial->weight;
                                currentMaterial->weight = 2000;
                            }
                        }
                        
                    }
                    currentMaterial = currentMaterial->next;
                }    
                currentWagon = currentWagon->next;
            }

            // all wagons traversed, if there is still remaining weight from that 
            // material, then add new wagon to train.
        }

}; 


void Train::deleteFromWagon(char material, int weight){
        //FILL THIS FUNCTION ACCORDINGLY
};  


void Train::printWagon(){
    wagonNode* tempWagon = head;

    if(tempWagon == NULL){
            cout<<"Train is empty!!!"<<endl;
            return;
    }

    while(tempWagon != NULL){
        materialNode* tempMat = tempWagon->material;
        cout<<tempWagon->wagonId<<". Wagon:"<<endl; 
        while (tempMat != NULL){
            cout<<tempMat->id<<": "<<tempMat->weight<<"KG, "; 
            tempMat = tempMat->next;  
        }
        cout<<endl; 
        tempWagon = tempWagon->next;
    }
    cout<<endl;
}; 
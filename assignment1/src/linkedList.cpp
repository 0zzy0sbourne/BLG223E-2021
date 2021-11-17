#include <iostream>
#include <stdio.h>
#include <string.h>
/* @Author
Student Name: Ozan ÇETİN
Student ID : 150190021
Date: 10.11.2021 */
#include "linkedList.h"

using namespace std;

void Train::create(){
    head = nullptr;
}; 

void Train::addMaterial(char material, int weight){
        //FILL THIS FUNCTION ACCORDINGLY
           
        if(head == nullptr)
        {
            int wagoncounter = 1;
            while(weight != 0){
                wagonNode* newWagon = new wagonNode(); 
                newWagon->wagonId = wagoncounter; 
                newWagon->next = nullptr; 


                materialNode* newMaterial = new materialNode();
                newMaterial->id = material;
                if(weight <= 2000)
                {
                    newMaterial->weight = weight; 
                    weight = 0;
                }  
                else 
                {
                    newMaterial->weight = 2000 ; 
                    weight -= 2000;
                }
                newMaterial->next = nullptr; 
                


                if(wagoncounter == 1){
                    newWagon->material = newMaterial ; 
                    this->head = newWagon ;
                }
                else // add the new wagon to the end of the list.
                { 
                    wagonNode* traverse = this->head ;
                    while(traverse->next!=nullptr)
                    {
                        traverse = traverse->next;
                    }
                    traverse->next = newWagon;
                    newWagon->material = newMaterial;
                }


                wagoncounter++; 
            }
        }        


        else{ // train is not empty
            wagonNode* currentWagon = this->head;
            int wagoncounter = 1 ;             
            while(currentWagon != nullptr)
            { // traverse the wagons
                bool material_found = false; 
                materialNode* currentMaterial = currentWagon->material; 
                while(currentMaterial != nullptr)
                { // traverse the materials in one wagon 
                    if(currentMaterial->id == material)
                    { // type of material is found in wagon
                        material_found = true ;
                        if(currentMaterial->weight < 2000) // check if it is already over 2000 kg
                        {
                            if((weight + currentMaterial->weight) <= 2000)
                            { 
                                currentMaterial->weight += weight;
                                weight = 0 ;
                            }
                            else if((weight + currentMaterial->weight) > 2000)
                            {
                                // update the weight to herit to another wagon
                                weight = 2000 - currentMaterial->weight;
                                currentMaterial->weight = 2000;
                            }
                        }
                        
                    }
                    
                    if(currentMaterial->next == nullptr)
                        break;
                    currentMaterial = currentMaterial->next;
                }   
                if(!material_found)
                { 
                        materialNode* addedMaterial = new materialNode(); 
                        addedMaterial->id = material;
                        addedMaterial->next = nullptr;
                        if(weight <= 2000)
                        {
                            addedMaterial->weight = weight; 
                            weight = 0; 
                        }
                        else 
                        {
                            addedMaterial->weight = 2000;
                            weight -= 2000; 
                        }
                        // material node is created, but check theck the alpahbetical order 
                        // before putting it to the wagon
                        currentMaterial = currentWagon->material; // points to the head
                        if(currentMaterial == nullptr) // assign the addedMaterial
                        {
                            currentMaterial = addedMaterial;
                        } 
                        else
                        {
                            while(currentMaterial != nullptr)
                            { 
                                if(currentMaterial->id < addedMaterial->id && currentMaterial->next != nullptr && currentMaterial->next->id > addedMaterial->id)
                                {
                                    // place it between them
                                    materialNode* temp =  currentMaterial->next ; 
                                    currentMaterial->next = addedMaterial;
                                    addedMaterial->next = temp; 
                                    break;
                                }
                                else if(currentMaterial->next == nullptr && currentMaterial->id < addedMaterial->id)
                                {
                                    // place it at the end 
                                    currentMaterial->next = addedMaterial;
                                    break;
                                }
                                else if(currentMaterial->id > addedMaterial->id)
                                {  // place it before it
                                    materialNode* temp = currentMaterial;
                                    currentWagon->material = addedMaterial;
                                    currentWagon->material->next = temp;
                                    break;
                                }
                                currentMaterial = currentMaterial->next;
                            }
                            // currentMaterial->next = addedMaterial;
                        }
                      
                         
                }
                if(currentWagon->next == nullptr)
                    break; 
                if(weight == 0) 
                    break;
                currentWagon = currentWagon->next;
                wagoncounter++;           
            }
            
                    
             if((currentWagon->next == nullptr) && weight != 0) // we reached the end of the wagons
                {   
                    wagonNode* traverse= currentWagon; 
                    
                    while(weight != 0)
                    {
                        wagonNode* addedWagon = new wagonNode(); 
                        wagoncounter++;
                        addedWagon->wagonId = wagoncounter;
                        addedWagon->next = nullptr;
                        addedWagon->wagonId = wagoncounter;

                        materialNode* newMaterial = new materialNode();
                        newMaterial->id = material;
                        newMaterial->next = nullptr;

                        if(weight <= 2000)
                        { 
                            newMaterial->weight = weight; 
                            weight = 0;     
                        }
                        else 
                        {
                            newMaterial->weight = 2000; 
                            weight -= 2000;
                        }
                        traverse->next = addedWagon; 
                        traverse = addedWagon; 
                        traverse->material = newMaterial;


                    }
                    
                }


        }

}; 


void Train::deleteFromWagon(char material, int weight){
    //FILL THIS FUNCTION ACCORDINGLY
    
    wagonNode* currentWagon = head;
    if(currentWagon==nullptr) return; 
    else{
        while(currentWagon->next != nullptr) 
        { 
            // go till we reach last wagon
            currentWagon = currentWagon->next;
        }
        // we are at the last wagon 

    while(weight != 0)
    {  
       materialNode* start = new materialNode();
       start->next = currentWagon->material;
       materialNode* currentMaterial = start; 
       int counter = 0;
        while(currentMaterial->next != nullptr)
        { 
            if(currentMaterial->next->id == material)
            {

                if(weight == currentMaterial->next->weight)
                {   // if material exists and bigger than weight just substract it and break the loop
                    // currentMaterial->next->weight -= weight;
                    weight = 0; 
                    /*
                    if(currentMaterial->next->next != nullptr && counter != 0)
                    {
                        materialNode* temp = currentMaterial->next;
                        currentMaterial->next = currentMaterial->next->next;
                        if(currentMaterial == nullptr)
                        { 
                            currentWagon->material = currentMaterial->next; 
                        }
                        delete temp; 
                    }
                    */
                    if(counter != 0)
                    { 
                        if(currentMaterial->next->next == nullptr)
                        {
                            delete currentMaterial->next->next;
                            currentMaterial->next->next = nullptr; 
                        }
                    }
                    else if(counter == 0)
                    {
                        if(currentMaterial->next->next != nullptr)
                        {   // change the head of the wagon
                            currentWagon->material = currentMaterial->next->next; 
                            delete currentMaterial->next; 
                        }
                        else if(currentMaterial->next->next == nullptr)
                        { // delete the head, delete the wagon
                            currentWagon->material = nullptr;
                            delete currentWagon->material;
                            currentWagon = nullptr;
                            delete currentWagon; 
                        }
                    }
                    else if(currentMaterial->next->next != nullptr && counter == 0)
                    {

                        // materialNode* temp = currentMaterial->next;
                        currentWagon->material = currentMaterial->next->next; 
                        delete currentMaterial->next; 
                        // currentMaterial->next = currentMaterial->next->next; 
                        // currentWagon->material = currentMaterial->next->next;
                        // delete temp;
                    }
                    else
                    {  // nullptr
                        delete currentMaterial->next;
                        currentWagon->material = currentMaterial; 
                        currentMaterial->next = nullptr; 
                    }
                    break;
                }
                else if(weight < currentMaterial->next->weight)
                {
                    // just decrement 
                    currentMaterial->next->weight -= weight; 
                    weight = 0 ; 
                }
                else if(weight > currentMaterial->next->weight)
                {   // if the weight is bigger you should check the previous wagon as 
                    weight -= currentMaterial->next->weight;
                    // currentMaterial->next->weight = 0; 
                    break; 
                }
            }    
            
            currentMaterial = currentMaterial->next;

        }
        if(weight != 0)
            { 
                wagonNode* lastWagon = currentWagon; 
                wagonNode* newlastWagon = head; // if the weight is bigger you should check the previous wagon as  
                while(newlastWagon->next != lastWagon)
                { // keep going until  we reach the wagon before the last wagon    
                    newlastWagon = newlastWagon->next;
                }
                // we are at the new last wagon
                // set currentWagon to the new last wagon 
                currentWagon = newlastWagon;
            }
    }
    }
    
};  


void Train::printWagon(){
    wagonNode* tempWagon = head;

    if(tempWagon == nullptr){
            cout<<"Train is empty!!!"<<endl;
            return;
    }

    while(tempWagon != nullptr){
        materialNode* tempMat = tempWagon->material;
        cout<<tempWagon->wagonId<<". Wagon:"<<endl; 
        while (tempMat != nullptr){
            cout<<tempMat->id<<": "<<tempMat->weight<<"KG, "; 
            tempMat = tempMat->next;  
        }
        cout<<endl; 
        tempWagon = tempWagon->next;
    }
    cout<<endl;
}; 
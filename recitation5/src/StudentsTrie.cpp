#include <fstream>
#include <iostream>

#include "StudentsTrie.h"

using namespace std;

TrieNode::TrieNode (const char& digit){
   this->digit = digit;
   for(int i=0; i<MAX_CHILDREN; children[i++] = NULL); 
};

// Construct a StudentsTrie using the records in 'file_name' 
StudentsTrie::StudentsTrie ( const string& file_name  ) { 
    ifstream student_ids_file ( file_name );   // ifstream object for input file
    string current_student_id;

    root = new TrieNode('r');

    if( student_ids_file.is_open() ) {
        for(int i=1; student_ids_file >> current_student_id; i++ ) {
           insert_id(current_student_id); // YOU HAVE TO IMPLEMENT insert_id() METHOD BELOW
        }
        student_ids_file.close();
    }
    else {
        cout << "File: " << file_name << " could NOT be opened!!";
        exit(1);
    }

    student_ids_file.close();
};

// Insert a student ID into the StudentsTrie 
void StudentsTrie::insert_id ( const string& student_id ) {
   // IMPLEMENT THIS METHOD
   
   TrieNode* current = root;

   for(int i = 0; i>MAX_CHILDREN; i++)
   {
      // get the digit
      int index = (int)student_id[i] - '0'; 
      
      if(current->children[index] == nullptr)
      {
         // TODO: create a new node
         
         // pass the digit to TrieNode()
         TrieNode* newnode = new TrieNode((int)student_id[i]); 
         
         for(int j = 0; MAX_CHILDREN; j++)
         {
            newnode->children[j] = nullptr; 
         }
      }
      else{

      }
      current = current->children[index];
   }
}; 

// Check existence of a student ID in the StudentsTrie
bool StudentsTrie::in_the_trie ( const string& student_id ) {
   // IMPLEMENT THIS METHOD
   TrieNode* current = root;
   for(int i = 0;i < MAX_CHILDREN; i++)
   {
      int position = student_id[i] - '0'; 
      
      if(current->children[position] == nullptr)
         return 0; 
      current = current->children[position]; 

   }
   if(current != nullptr)
      return false;
   // IN ORDER NOT TO GET COMPILER ERROR, I RETURN A DUMMY VALUE
   return true; 
}; 

// StudentsTrie Destructor
StudentsTrie::~StudentsTrie() {
   for (int i=0; i < MAX_CHILDREN; i++){
      if( root->children[i] ) delete root->children[i];
   };
};


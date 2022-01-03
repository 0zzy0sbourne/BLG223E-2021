#include <iostream>
#include <stdio.h>
#include <stdlib.h> // atof
#include <string> // std::string::c_str
#include <map>
#include <unordered_map>
#include <fstream>
#include <iomanip>

using namespace std;

string file_path;


bool perform_operation(char, ifstream&);
void print_menu();
void listProducts(ifstream&);
void listDay();



int main(int argc, char* argv[])
{
    bool end = false;
    char choice;
    ifstream inFile;

    file_path = argv[1];

    inFile.open(file_path,ios::in);
    if (!inFile.is_open()) 
    {
        cerr << "File cannot be opened";
        return EXIT_FAILURE;
    }

    while (!end)
    {
        print_menu();
        cin >> choice;
        end = perform_operation(choice, inFile);
    }
    
    inFile.close();
    return EXIT_SUCCESS;


}


void print_menu()
{
    cout << "Choose an operation" << endl;
    cout << "L: List 5 products with the highest revenue for total" << endl;
    cout << "E: Exit" << endl;
    cout << "Enter a choice {L, E}: ";
}

bool perform_operation(char choice, ifstream& inFile)
{
    bool terminate = false;
    string strday;

    switch (choice)
    {
    case 'L':
    case 'l':
        listProducts(inFile);
        break;
    case 'E':
    case 'e':
        terminate = true;
        break;
    default:
        cout << "Error: You have entered an invalid choice" << endl;
        cin >> choice;
        terminate = perform_operation(choice, inFile);
        break;
    }
    return terminate;
}

void listProducts(ifstream& inFile)
{
// *********************Fill this method
    int counter = 0;
    string product, day, price , quantity;
    while(counter < 5)
    {
        // read the elements in the line as a string
        inFile>> product >> price >> quantity >> day ;
        
        //convert string to const char* 
        const char* newprice = price.c_str(); 
        const char* newquantity = quantity.c_str(); 

        //convert const char* to double
        double productPrice = atof(newprice); 
        double productQuantity = atof(newquantity);

        //print the line
        cout << product  <<  " " << productPrice << " " << productQuantity<< " " << day << "\n"; 
        counter++; 
    }
  

    /* 
    while(counter < 5)
    {
        string productName, orderDay; 
        double productPrice, productQuantity; 
        inFile>>productName>>productPrice>>productQuantity>>orderDay;
        if(counter != 0)
            cout << productName << " " << productPrice <<  " " << productQuantity << " " << orderDay << "\n"; 
        counter++; 
    }
    */

}


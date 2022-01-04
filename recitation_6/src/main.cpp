/* @Author
Student Name: Ozan ÇETİN
Student ID : 150190021
Date: 04.01.2022*/
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
    map <string, double> mymap; // empty multimap container
    string product, day, price , quantity;
    double revenue; 
    while(!inFile.fail())
    {
        
        // read the elements in the line as a string
        inFile>> product >> price >> quantity >> day ;
        
        //convert string to const char* 
        const char* newprice = price.c_str(); 
        const char* newquantity = quantity.c_str(); 

        //convert const char* to double
        double productPrice = atof(newprice); 
        double productQuantity = atof(newquantity);


        //calculate the revenue in each loop 
        revenue = productPrice * productQuantity; 

        // check if the productName is already in the multimap
        int count = 0;
        for (const auto& entry : mymap)
        if (entry.first == product)
            count++;

        // product already in map, update the revenue of it  
        if(count != 0){
            mymap[product] += revenue; 
        }
        else { // otherwise map the product name and revenue, add it to the map
            mymap.insert(pair<string, double> (product, revenue)); 
        }


        /* 
        //print the line
        cout << product  <<  "" << productPrice << " " << productQuantity<< " " << day << "\n"; 
        counter++; 
        if(counter == 5) break ;
        */ 

    }
  
    // create a reverse iterator
    map <string, double> :: iterator iter;
    
    int counter = 0;
    /* 
    // set a counter to count for the top 5 product
    for (iter = mymap.begin(); iter != mymap.end(); ++iter)
    {
        if(counter == 6) break ; 
        cout << '\t' << iter->first
            << '\t' << iter->second << '\n';
        counter++; 
    }
    cout << endl;
    */ 

    // create an empty multimap
    multimap <double, string> mymultimap; 
    for (auto const &pair: mymap) {
        mymultimap.insert(make_pair(pair.second, pair.first));
    }
    

     // print the multimap
     /*
     for (auto const &pair: mymultimap) {
         cout << '{' << pair.second << "," << pair.first << '}' << endl;
     }
     */

    multimap <double, string> :: reverse_iterator itr ;
    
    // set a counter to count for the top 5 product
    cout << "5 products with the highest revenue for total are:" << "\n" ; 
    counter = 0; 
    for (itr = mymultimap.rbegin(); itr != mymultimap.rend(); ++itr)
    {
    
        if(counter == 5) break ; 
        cout << itr->second <<setprecision(2) << fixed << " "  << itr->first << '\n';
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


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map> 

using namespace std;
int main()
{ 
    map <string, double> mymap; // empty multimap container
    mymap.insert(pair <string, double> ("biscuit", 1.4));
    mymap.insert(pair <string, double> ("tomato", 6.7));
    mymap.insert(pair <string, double> ("chips", 7.5));
    mymap.insert(pair <string, double>  ("egg", 8.7)); 
    mymap.insert(pair <string, double> ("egg", 4.5));

    map <string, double> :: iterator itr ;
    cout << "\nThe multimap mymap is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = mymap.begin(); itr != mymap.end(); ++itr)
    {
        cout << '\t' << itr->first
            << '\t' << itr->second << '\n';
    }
    cout << endl;

} 
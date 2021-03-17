#include "snowman.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using namespace ariel;
using namespace std;


void sleepforme(int mili) // function to simplify sleeping  
{
    std::this_thread::sleep_for(std::chrono::milliseconds(mili));    
}


int main()
{
    int t = 400; 
    // prepare the snowman 
    string o = snowman(11333311);
    string c = snowman(11442211);
    while(1)
    {
        system("clear"); // clear screen 
        cout << o << endl; // print snowman with open eyes 
        sleepforme(t); // sleep 
        system("clear"); // clear screen
        cout << c << endl; // print snowman with closed eyes 
        sleepforme(t); // sleep 
    }
    
    return 0;
}

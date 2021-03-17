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

void makefly(int flies)
{
    for (size_t i = 0; i < flies; i++)
    {
        cout << "\n" ; 
    }
}

int main()
{
    int t = 400; 
    //prepare the snowman 
    string o = snowman(11333311);
    string c = snowman(11442211);
    int count = 20;
    while(1)
    {
        count  = count == 0 ? 20:count;
        system("clear"); // clear screen 
        makefly(count);
        cout << o << endl; // print snowman with open eyes 
        sleepforme(t); // sleep 
        system("clear"); // clear screen
        makefly(count);
        cout << c << endl; // print snowman with closed eyes 
        count--;
        sleepforme(t); // sleep 
    }
    //cout << snowman(44444444) << endl;
    
    return 0;
}

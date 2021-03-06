#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <exception>
#include <array>
#include "snowman.hpp"
using namespace std;

namespace ariel
{
    enum nums {one=1,two,three,four,five,six,seven,eight,ten=10}; // enum for all the magic numbers 
    // arrays for parts of snowman
    array<string,four> hats = {" _===_ ","  ___  \n ..... ","   _   \n  /_\\  ","  ___  \n (_*_) "};
    array<string,four> noses = {",",".","_"," "};
    array<string,four> lefteye = {".","o","O","-"};
    array<string,four> righteye = {".","o","O","-"};
    array<string,four> leftarm = {"<","\\","/"," "};
    array<string,four> rightarm = {">","/","\\"," "};
    array<string,four> torsos = {" : ","] [","> <","   "};
    array<string,four> bases = {" : ","\" \"","___","   "};
    void throwforme(int code) // function to throw exception for me
    {
        throw out_of_range("Invalid code '"+std::to_string(code) + "'");
    }
    string head_segment(int lhand,int leye,int nose,int reye, int rhand) // function to create head for me
    {
        return (lhand == two ? leftarm.at(lhand-1):" ") + "("+lefteye.at(leye-1)+noses.at(nose-1)+righteye.at(reye-1)+")"
         + (rhand == two ? rightarm.at(rhand-1):" ");
    }
    string torso_segment(int lhand, int torso, int rhand) // funciton to create torso for me 
    {
        return (lhand == two? " ":leftarm.at(lhand-1)) +"("+torsos.at(torso-1)+")" 
        + (rhand == two? " ":rightarm.at(rhand-1));
    }
    string base_segment(int base) // function to create base for me 
    {
        return " ("+bases.at(base-1)+") ";
    }
    string snowman(int num)
    {
        if(num<=0){throwforme(num);} // throw if negatve 
        string res; 
        array<int,nums::eight> numbers = {};  // create array for numbers 
        int temp = num;  // some basic variables 
        int count = 0; 
        int current = 0; 
        while(temp!=0&& count<=seven) // loop 
        {
            current = temp%ten; 
            if (current>four || current == 0) {throwforme(num);}  
            numbers.at(seven-count) = current; // put the digit in the array  
            temp /= ten; 
            count++;  // add to count 
        }
        if (count != eight || temp!=0) {throwforme(num);} // throw if conditions not met
        // retuen the snowman in it's full glory 
        return hats.at(numbers.at(0)-1) +"\n"+ // hat part 
        head_segment(numbers.at(four),numbers.at(two),numbers.at(one),numbers.at(three),numbers.at(five)) +"\n"+ // head part 
        torso_segment(numbers.at(four),numbers.at(six),numbers.at(five)) +"\n"+ // torso part 
        base_segment(numbers.at(seven)) + "\n"; // base part 
    }
}
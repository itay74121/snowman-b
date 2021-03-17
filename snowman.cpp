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
    enum nums {one=1,two,three,four,five,six,seven,eight,ten=10};
    array<string,four> hats = {" _===_ ","  ___  \n ..... ","   _   \n  /_\\  ","  ___  \n (_*_) "};
    array<string,four> noses = {",",".","_"," "};
    array<string,four> lefteye = {".","o","O","-"};
    array<string,four> righteye = {".","o","O","-"};
    array<string,four> leftarm = {"<","\\","/"," "};
    array<string,four> rightarm = {">","/","\\"," "};
    array<string,four> torsos = {" : ","] [","> <","   "};
    array<string,four> bases = {" : ","\" \"","___","   "};
    void throwforme(int code)
    {
        throw out_of_range("Invalid code '"+std::to_string(code) + "'");
    }
    string head_segment(int lhand,int leye,int nose,int reye, int rhand)
    {
        return (lhand == two ? leftarm.at(lhand-1):" ") + "("+lefteye.at(leye-1)+noses.at(nose-1)+righteye.at(reye-1)+")"
         + (rhand == two ? rightarm.at(rhand-1):" ");
    }
    string torso_segment(int lhand, int torso, int rhand)
    {
        return (lhand == two? " ":leftarm.at(lhand-1)) +"("+torsos.at(torso-1)+")" 
        + (rhand == two? " ":rightarm.at(rhand-1));
    }
    string base_segment(int base)
    {
        return " ("+bases.at(base-1)+") ";
    }
    string snowman(int num)
    {
        if(num<=0){throwforme(num);}
        string res; 
        array<int,nums::eight> numbers = {}; 
        int temp = num; 
        int count = 0; 
        int current = 0; 
        while(temp!=0&& count<=seven) 
        {
            current = temp%ten; 
            if (current>four || current == 0) {throwforme(num);}  
            numbers.at(seven-count) = current; 
            temp /= ten; 
            count++; 
        }
        if (count != eight || temp!=0) {throwforme(num);}
        return hats.at(numbers.at(0)-1) +"\n"+
        head_segment(numbers.at(four),numbers.at(two),numbers.at(one),numbers.at(three),numbers.at(five)) +"\n"+
        torso_segment(numbers.at(four),numbers.at(six),numbers.at(five)) +"\n"+
        base_segment(numbers.at(seven)) + "\n";
    }
}
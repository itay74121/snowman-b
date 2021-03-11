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
    // array of hats 
    array<string,4> hats = {" _===_ ","  ___  \n ..... ","   _   \n  /_\\  ","  ___  \n (_*_) "};
    // array of noeses and mouth 
    array<string,4> noses = {",",".","_"," "};
    // array for left eye 
    array<string,4> lefteye = {".","o","O","-"};
    // array for right eye 
    array<string,4> righteye = {".","o","O","-"};
    // aray for left eye 
    array<string,4> leftarm = {"<","\\","/"," "};
    // array for right arm 
    array<string,4> rightarm = {">","/","\\"," "};
    // array for torsos 
    array<string,4> torsos = {" : ","] [","> <","   "};
    // array for bases 
    array<string,4> bases = {" : ","\" \"","___","   "};
    /**
     * The snowman function takes an int with length of 8 digits,
     * and every digit must be between 1 to 4. If this two conditions
     * aren't met the function throws an invalid argument exception.
    */
    void throwforme(int code)
    {
        string res = "Invalid code '";
        res+= std::to_string(code);
        res+="'";
        throw out_of_range(res);
    }
    string snowman(int num)
    {
        if(num<=0)
        {
            throwforme(num);
        }
        const auto max_index = 7;
        const auto mod = 10;
        const auto max_digit = 4;
        const auto array_size = 8;
        const auto six = 6;
        const auto five = 5;
        const auto three = 3;
        const auto two =2;
        const auto one = 1;
        string res; // resulting string 
        array<int,array_size> numbers = {}; // a list to take all the numbers
        //memset(numbers,0,sizeof(int)*8); // erase the array from junk data
        int temp = num; // set a temperay variable so we wouldn't lose original num 
        int count = 0; // set count to 0
        int current = 0; // current digit to add to array
        // run as long as temp is not 0 means we still have digits.
        // count <=7 since we cannot pass 8 digits 

        while(temp!=0&& count<=max_index) 
        {
            current = temp%mod; // take the last digit
            if (current>max_digit || current == 0) // check if it is between 1 and 4 
            { // if not throw exception 
                throwforme(num); // throwing here exception 
            }
            numbers.at(max_index-count) = current; // place the digit in the right place in the array 
            temp /= mod; // go to the next digit 
            count++; // increment the count 
        }
        // if the count of digits is not excatly 8 
        // that is maintained by the count wich is not 8 
        // or by the temp which might not be 0.
        if (count != array_size || temp!=0)
        { // throw an exception if so 
            throwforme(num);
        }
        // create strings for the head the middle part 
        // and the bottom part of the snowman.
        string head;
        string middle;
        string bottom;
        // build the head part 
        head += hats.at(numbers.at(0)-1); // put the hat of the snowman 
        head = head + "\n"; 
        // if the left hand is up like this '\'
        if(numbers.at(max_digit)== two)
        {
            head += "\\"; // add the upper hand next to the head 
        }
        else // other wise put a space there 
        {
            head += " ";
        }
        // build the rest of the head left eye nose and right eye 
        head = head + "(" + lefteye.at(numbers.at(two)-1) + noses.at(numbers.at(one)-1) + righteye.at(numbers.at(three)-1) + ")";
        // if the right hand is also up like this '/'
        if(numbers.at(five) == two)
        {
            head += "/"; // add it 
        }
        else
        {
            head += " "; // otherwise add space 
        }
        head += "\n"; // finish head 
        //build the torso
        if(numbers.at(max_digit) != two) // if the left hand is not up like this '\'
        {
            middle += leftarm.at(numbers.at(max_digit)-1); //add it 
        }
        else
        {
            middle += " "; // otherwise add space
        }
        // build the rest of the torso 
        middle = middle +"("+ torsos.at(numbers.at(six)-1) +")";
        // if the right hand is not up like this '/'
        if(numbers.at(five) != two)
        {
            middle += rightarm.at(numbers.at(five)-1); // add it 
        }
        else
        {
            middle += " "; // other wise add a space 
        }
        middle += "\n"; // finish middle part 
        // build the bottom according to the easy template 
        bottom = bottom + " (" + bases.at(numbers.at(max_index)-1) +") " ;
        // concatnate all of the pieces together and set the result to res 
        res = head + middle + bottom;
        // return the result to the user 
        return res;
    }
}




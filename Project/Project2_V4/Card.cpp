/* 
 * File:   Card.h
 * Author: Dr. Mark E. Lehr
 * Created on April 30, 2014, 12:56 PM
 * Card Implementation
 */

#include "Card.h"

//Implement the Constructor
Card::Card(int number){
    if(number<0)number=0;
    if(number>71)number%=72;
    this->number=static_cast<char>(number);
}

char Card::suit(){
    if(number<18)return 'R';
    if(number<36)return 'B';
    if(number<54)return 'G';
    return 'Y';
}

char Card::name(){
    char aName[]={'1','2','3','4','5','6','7','8','9'};
    return aName[number%9];
}

char Card::value(){
    char n=number%9+1;
    if(n>10)return 10;
    return n;
}

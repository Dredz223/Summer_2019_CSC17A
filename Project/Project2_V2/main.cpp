/* 
 * File:   main.cpp
 * Author: Andres Guerrero Maldonado
 * Created on July 25, 2019, 8:55 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//Our Libraries
#include "DrvCard.h"
#include "Deck.h"

//Global Constants

//Function Prototypes
void Rules();
void prntHnd(int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Initialize variables;
    //string play1,play2;
    
    //Display Rules
    Rules();
    cout<<endl;
    
    //Create an array of 72 cards
    int nCards=72;
    Deck<Card> deck(nCards);
    
    //Deal a hand
    int nDelt=5;
    deck.shuffle();
    int *hand=deck.deal(nDelt);

    //Delete the arrays
    prntHnd(hand,nDelt);
    
    //Test the cards
    Card **c=new Card*[72];
    c[0]=new Card(0);
    c[5]=new Card(43);
    c[1]=new DrvCard(0,"Testing");
    c[1]=new DrvCard(0,"Player 2");
    c[7]=new DrvCard(7,"Player 1");
    cout<<c[0]->name()<<c[0]->suit()<<endl;
    cout<<c[1]->name()<<c[1]->suit()<<endl;
    
    
    //Exit stage right
    return 0;
}

void Rules(){
    string line;
    fstream inputFile;
    //open file
    inputFile.open("Rules.txt");
    if(inputFile.is_open()){
        while(getline(inputFile,line)){
            cout<<line<<"\n";
        }
        inputFile.close();
    }
}

void prntHnd(int *hand,int n){
    for(int i=0;i<n;i++){
        Card c(hand[i]);
        cout<<c.name()<<c.suit()<<" ";
    }
    delete []hand;
}

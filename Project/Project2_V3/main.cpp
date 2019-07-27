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
void prntHnd(int,int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Initialize Variables
    string player1 = "Tom Bob";
    string player2 = "Sam Ham";
    
    //Display Rules
    Rules();
    cout<<endl;
    
    //Create an array of 72 cards
    int nCards=72;
    Deck<Card> deck(nCards);
    
    //Deal a hand
    int nDelt=5;
    int poStr;
    deck.shuffle();
    int *hand1=deck.deal(nDelt);

    //Print and Delete the arrays
    //Player 1
    poStr = 0;
    cout<<player1<<"'s hand: ";
    prntHnd(poStr,hand1,nDelt);
    cout<<endl;
    
    //Player 2
    nDelt+=5;
    poStr = 5;
    int *hand2=deck.deal(nDelt);
    cout<<player2<<"'s hand: ";
    prntHnd(poStr,hand2,nDelt);
    cout<<endl;
    
    //Display a single card from their hand
    
    
    //Test the cards
    Card **c=new Card*[72];
    c[0]=new Card(0);
    c[5]=new Card(43);
    c[1]=new DrvCard(0,"Testing");
    c[1]=new DrvCard(0,"Player 2");
    c[7]=new DrvCard(7,"Player 1");
    cout<<endl;
    cout<<c[0]->name()<<c[0]->suit()<<endl;
    cout<<c[1]->name()<<c[1]->suit()<<endl;
    
    delete []hand1;
    delete []hand2;
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

void prntHnd(int s,int *hand,int n){
    
    for(s;s<n;s++){
        Card c(hand[s]);
        cout<<c.name()<<c.suit()<<" ";
    }
    //delete []hand;
}
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
    int poStr = 0;;
    deck.shuffle();
    int *hand1=deck.deal(nDelt);
    
    //Player oNe 0-4
    Card **cN=new Card*[72];
    //Player tWo 5-9
    Card **cW=new Card*[72];
    //Deck 10
    Card **dK=new Card*[72];

    //Print and Delete the arrays
    //Player 1
    //0-4
    cout<<player1<<"'s hand: ";
    for(poStr;poStr<nDelt;poStr++){
        Card cdn(hand1[poStr]);
        cN[poStr]=new Card(hand1[poStr]);
        cout<<cdn.name()<<cdn.suit()<<" ";
    }
    cout<<endl;
    cout<<"TEST: "<<cN[0]->name()<<cN[0]->suit()<<endl;
    cout<<"TEST: "<<cN[1]->name()<<cN[1]->suit()<<endl;
    cout<<"TEST: "<<cN[2]->name()<<cN[2]->suit()<<endl;
    cout<<"TEST: "<<cN[3]->name()<<cN[3]->suit()<<endl;
    cout<<"TEST: "<<cN[4]->name()<<cN[4]->suit()<<endl;
    //Player 2
    //5-9
    nDelt+=5;
    int *hand2=deck.deal(nDelt);
    cout<<player2<<"'s hand: ";
    for(int pTStr=5;pTStr<nDelt;pTStr++){
        Card cdn(hand2[pTStr]);
        cW[pTStr]=new Card(hand2[pTStr]);
        cout<<cdn.name()<<cdn.suit()<<" ";
    }
    cout<<endl;
    cout<<"TEST: "<<cW[5]->name()<<cW[5]->suit()<<endl;
    cout<<"TEST: "<<cW[6]->name()<<cW[6]->suit()<<endl;
    cout<<"TEST: "<<cW[7]->name()<<cW[7]->suit()<<endl;
    cout<<"TEST: "<<cW[8]->name()<<cW[8]->suit()<<endl;
    cout<<"TEST: "<<cW[9]->name()<<cW[9]->suit()<<endl;
    //Top Deck
    cout<<"Top Deck: ";
    int *tDeck=deck.deal(nDelt);
    Card cdn(tDeck[10]);
    dK[10]=new Card(tDeck[10]);
    cout<<"TEST: "<<dK[10]->name()<<dK[10]->suit()<<endl;
    
    delete []hand1;
    delete []hand2;
    delete []tDeck;
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
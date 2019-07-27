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
void rules();
bool canPlay(char,char,char,char);
void swap(char,char,char,char);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Initialize Variables
    string player1 = "Tom Bob";
    string player2 = "Sam Ham";
    int cnPlay;
    //Display Rules
    rules();
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
    Card **c=new Card*[72];
    //Player tWo 5-9
    //Deck 10

    //Print and Delete the arrays
    //Player 1
    //0-4
    cout<<player1<<"'s hand: ";
    for(poStr;poStr<nDelt;poStr++){
        Card cdn(hand1[poStr]);
        c[poStr]=new Card(hand1[poStr]);
        cout<<cdn.name()<<cdn.suit()<<" ";
    }
    cout<<endl;
    
    //Player 2
    //5-9
    nDelt+=5;
    int *hand2=deck.deal(nDelt);
    cout<<player2<<"'s hand: ";
    for(int pTStr=5;pTStr<nDelt;pTStr++){
        Card cdn(hand2[pTStr]);
        c[pTStr]=new Card(hand2[pTStr]);
        cout<<cdn.name()<<cdn.suit()<<" ";
    }
    cout<<endl;
    
    //Top Deck
    cout<<"TOP DECK: ";
    int *tDeck=deck.deal(nDelt);
    Card cdn(tDeck[10]);
    c[10]=new Card(tDeck[10]);
    cout<<c[10]->name()<<c[10]->suit()<<endl;
    
    //Play Game! Compare deck with 
    //do while loop if the player's card color or number 
    //is  the same as the deck card color or number than
    //play card, deck card is swapped with the card that is played
    //continue until player runs out of cards or if one player wins
    //Game, when they run out of cards to play
    //             c1           cc1           c2            cc2
    cnPlay=canPlay(c[0]->name(),c[0]->suit(),c[10]->name(),c[10]->suit());
    cout<<canPlay<<endl;
    if (cnPlay==1){
        cout<<"Yes"<<endl;
        //Swapping cards
        swap(c[0]->name(),c[0]->suit(),c[10]->name(),c[10]->suit());
        cout<<"TOP DECK: "<<c[0]->name()<<c[0]->suit()<<endl;
    } 
    else if(cnPlay==0){
        cout<<"No"<<endl;
        cout<<"TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
    }
    delete []hand1;
    delete []hand2;
    delete []tDeck;
    //Exit stage right
    return 0;
}

void rules(){
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

bool canPlay(char cn1,char cc1,char cn2,char cc2){
    if(cc1==cc2 || cn1==cn2)return true;
    else return false;
}

//                          cn1,cc1,cn2,cc2
void swap(char cn1,char cc1,char cn2,char cc2){
    cout<<"1st card: "<<cn1<<cc1<<endl;
    cout<<"Deck Card: "<<cn2<<cc2<<endl;
    char tempn =cn1;
    char tempc =cc1;
    cn1=cn2;
    cc1=cc2;
    cn2=tempn;
    cc2=tempc;
    cout<<"1st card: "<<cn1<<cc1<<endl;
    cout<<"Deck Card: "<<cn2<<cc2<<endl;
}

/* 
 * File:   main.cpp
 * Author: Andres Guerrero Maldonado
 * Created on July 26, 2019, 4:32 PM
 * Purpose: Project 2 V6
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
using namespace std;

//Our Libraries
#include "DrvCard.h"
#include "Deck.h"

//Global Constants

//Function Prototypes
void rules();
bool canPlay(char,char,char,char);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Initialize Variables
    string player1;
    string player2;
    int cnPlay;
    int p1score,p2score;
    bool play=false;
    bool turn1=false;
    bool p1turn=false;
    bool p2turn=false;
    bool ply1f=false;
    bool gplay=false;
    char game;
    int hands1=5,hands2=5;
    //Display Rules
    rules();
    cout<<endl;
    cout<<"What is player 1's name?"<<endl;
    getline(cin,player1);
    cout<<"What is player 2's name?"<<endl;
    getline(cin,player2);
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
        c[poStr]=new Card(hand1[poStr]);        //c[0-4]=new Card(hand1[poStr]);
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
        c[pTStr]=new Card(hand2[pTStr]);        //c[5-9]=new Card(hand1[poStr]);
        cout<<cdn.name()<<cdn.suit()<<" ";
    }
    cout<<endl;
    
    //Top Deck
    cout<<"TOP DECK: ";
    int *tDeck=deck.deal(nDelt);
    Card cdn(tDeck[10]);
    c[10]=new Card(tDeck[10]);                  //c[10]=new Card(hand1[poStr]); 9B
    cout<<c[10]->name()<<c[10]->suit()<<endl;
    
    //Play Game! Compare deck with 
    //do while loop if the player's card color or number 
    //is the same as the deck card color or number than
    //play card, deck card is swapped with the card that is played
    //continue until player runs out of cards or if one player wins
    //Game, when they run out of cards to play
    //             c1           cc1           c2            cc2
    int j;
    do{
        j=0;
        //TURN 1! FUNCKY THINGS FOR TURN 1
        do{
            cout<<player1<<"'s turn!"<<endl;
            cnPlay=canPlay(c[j]->name(),c[j]->suit(),c[10]->name(),c[10]->suit());
            if (cnPlay==1){
                cout<<"Yes "<<player1<<endl;
                //Swapping cards
                Card* tempc;
                tempc=c[j];
                c[j]=c[10];
                c[10]=tempc;
                cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                c[j]=NULL;
                turn1=true;
                hands1--;
            }
            else{
                cout<<"No "<<player1<<endl;
                cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                j++;
            }
            cnPlay=0;
            if(j=5){
                ply1f=true;
                turn1=true;
            }
        }while(!turn1);
        //Player 2 goes if player one fails to play a card
        j=5;
        while(!ply1f){
            cout<<player2<<"'s turn!"<<endl;
            cnPlay=canPlay(c[j]->name(),c[j]->suit(),c[10]->name(),c[10]->suit());
            if (cnPlay==1){
                cout<<"Yes"<<player2<<endl;
                //Swapping cards
                Card* tempc;
                tempc=c[j];
                c[j]=c[10];
                c[10]=tempc;
                cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                c[j]=NULL;
                ply1f=false;
                hands2--;
            }
            else{
                cout<<"No "<<player2<<endl;
                cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                j++;
            }
            cnPlay=0;
            if(j=10){
                cout<<"Game cannot be played, no player has correct cards!"<<endl;
                cout<<"Continue or End? (C/E)"<<endl;
                cin>>game;
                if(game=='E'){
                    play=true;
                }
                else if(game=='C'){
                    play=false;
                }
            }
        }
        //Player 2 goes, if player 1 has gone
        //Turn1 = true
        while(turn1){
            j=5;
            cout<<player2<<"'s turn!"<<endl;
            cnPlay=canPlay(c[j]->name(),c[j]->suit(),c[10]->name(),c[10]->suit());
            if (cnPlay==1){
                cout<<"Yes "<<player2<<endl;
                //Swapping cards
                Card* tempc;
                tempc=c[j];
                c[j]=c[10];
                c[10]=tempc;
                cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                c[j]=NULL;
                turn1=false;        //Jump out of while loop
                hands2--;
            }
            else{
                cout<<"No "<<player2<<endl;
                cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl; 
                for(j;j<=10;j++);{
                    if(j=9){
                        cout<<player2<<" has been skipped!"<<endl;
                        turn1=false;
                    }
                }
            }
        }
        //Turn2 and onwards!!!
        do{
            do{
                j=0;
                cout<<player1<<"'s turn!"<<endl;
                cnPlay=canPlay(c[j]->name(),c[j]->suit(),c[10]->name(),c[10]->suit());
                if (cnPlay==1){
                    cout<<"Yes "<<player1<<endl;
                    //Swapping cards
                    Card* tempc;
                    tempc=c[j];
                    c[j]=c[10];
                    c[10]=tempc;
                    cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                    c[j]=NULL;
                    p1turn=true;
                    hands1--;
                }
                else{
                    cout<<"No "<<player1<<endl;
                    cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                    for(j,j<=5;j++;){
                        if(j=5){
                            cout<<player1<<" has been skipped!"<<endl;
                        }
                    }
                }
            }while(!p1turn);
            if(hands1==1){
                cout<<player1<<": UNO!"<<endl;
            }
            if(hands1==0){
                cout<<player1<<": WINS!"<<endl;
                gplay=true;
                play=true;
            }
            do{
                j=5;
                cout<<player2<<"'s turn!"<<endl;
                cnPlay=canPlay(c[j]->name(),c[j]->suit(),c[10]->name(),c[10]->suit());
                if (cnPlay==1){
                    cout<<"Yes "<<player1<<endl;
                    //Swapping cards
                    Card* tempc;
                    tempc=c[j];
                    c[j]=c[10];
                    c[10]=tempc;
                    cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                    c[j]=NULL;
                    p2turn=true;
                    hands2--;
                }
                else{
                    cout<<"No "<<player1<<endl;
                    cout<<"NEW TOP DECK: "<<c[10]->name()<<c[10]->suit()<<endl;
                    for(j,j<=10;j++;){
                        if(j=10){
                            cout<<player2<<" has been skipped!"<<endl;
                        }
                    }
                }
            }while(!p2turn);
            if(hands2==1){
                cout<<player2<<": UNO!"<<endl;
            }
            if(hands2==0){
                cout<<player2<<": WINS!"<<endl;
                gplay=true;
                play=true;
            }
        }while(!gplay);    
    }while(!play);//Not false
        
        
        
        
        
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

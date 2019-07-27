/* 
 * File:   main.cpp
 * Author: Andres Guerrero Maldonado
 * Created on July 14, 2018 4:06PM
 * Purpose:  Project 1
 *         
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <string>   //String Library
#include <iomanip>  //Format Library
#include <ctime>  //Time Library
using namespace std;//namespace I/O stream library created

//User Libraries
struct Hand{
    int size;
    string *sdeck;
};
struct Player{
    string name,deal;
    Hand cards;
};
//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
void shuffle(string [],int,int); //Shuffle the Deck
void prnDeck(string [],int,int); //Print the Deck of Cards
void filDeck(string [],int);     //Fill the deck 1-9, Red, Green, Blue, Yellow
//Execution Begins Here!
int main(int argc, char** argv){
    //Initialize random seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int startCD,tempCD;
    int n2Shufl = 7;
    int pSize;
    int drand;
    const int NUMCARD = 72;
    string deck[NUMCARD];        //72 Cards represented as a string Face|Suit
    bool input = false;
    //Ask for the amount of players
    do{
        cout<<"How many players? (2-4)"<<endl;
        cin>>pSize;
        if(pSize >= 2 && pSize <= 4){
            input = true;
        }
        else{
            cout<<"False! Please Try again!!"<<endl;
        }
    }while(!input);
    cin.ignore();
    Player* ptrname = nullptr;
    ptrname = new Player[pSize];
    
    //Dynamically create an array to hold player cards
    int size = 100;
    ptrname->cards.sdeck[100];
    //Get player name
    for(int i=0;i<pSize;i++){
        cout<<"What is player "<<i+1<<"'s name?"<<endl;
        getline(cin,ptrname[i].name);
    }
    for(int i=0;i<pSize;i++){
        cout<<"Player "<<i+1<<" is: "<<ptrname[i].name<<endl;
    }
    //Display dealer
    ptrname->deal = "The Deck";
    cout<<"The deck holder is: "<<ptrname->deal<<endl;
    //Fill Deck
    filDeck(deck,NUMCARD);
    
    //Print Deck
    cout<<"Fresh Deck of Cards before Shuffling"<<endl;
    prnDeck(deck,NUMCARD,NUMCARD/8);
    
    //Shuffle Deck
    shuffle(deck,NUMCARD,n2Shufl);
    
    //Print Deck
    cout<<"Fresh Deck of Cards before Shuffling"<<endl;
    prnDeck(deck,NUMCARD,NUMCARD/8);
    
    //Starting card
    ptrname->cards.sdeck[drand] = deck[(pSize * 7)+rand()%(NUMCARD)];    //Card pulled is
                                                                        //After player's
    cout<<"The starting card is: "<<ptrname->cards.sdeck[drand]<<endl;
    
    if(pSize == 2){
    for(int i=0;i<pSize;i++){
            if(i==0){
                for(int j=0;j<7;j++){
                    ptrname->cards.sdeck[j]= deck[j];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck[j]<<endl;
                }
            }
            if(i==1){
                for(int k=7;k<14;k++){
                    ptrname->cards.sdeck[k]= deck[k];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck[k]<<endl;
                }
            }
        }
    }
    if(pSize == 3){
    for(int i=0;i<pSize;i++){
            if(i==0){
                for(int j=0;j<7;j++){
                    ptrname->cards.sdeck[j]= deck[j];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck<<endl;
                }
            }
            if(i==1){
                for(int k=7;k<14;k++){
                    ptrname->cards.sdeck[k]= deck[k];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck<<endl;
                }
            }
            if(i==2){
                for(int c=14;c<21;c++){
                    ptrname->cards.sdeck[c]= deck[c];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck<<endl;
                }
            }
        }
    }
    if(pSize == 4){
    for(int i=0;i<pSize;i++){
            if(i==0){
                for(int j=0;j<7;j++){
                    ptrname->cards.sdeck[j]= deck[j];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck<<endl;
                }
            }
            if(i==1){
                for(int k=7;k<14;k++){
                    ptrname->cards.sdeck[k]= deck[k];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck<<endl;
                }
            }
            if(i==2){
                for(int c=14;c<21;c++){
                    ptrname->cards.sdeck[c]= deck[c];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck<<endl;
                }
            }
            if(i==3){
                for(int d=21;d<28;d++){
                    ptrname->cards.sdeck[d]= deck[d];
                    cout<<ptrname[i].name<<":"<<ptrname->cards.sdeck<<endl;
                }
            }
        }
    }
    
    //Free up memory
    delete []ptrname;
    //Exit program!
    return 0;
}
void filDeck(string c[],int n){
    //Red, Blue, Green, Yellow and numbers
    char suit[]={'R','B','G','Y'};
    char face[]={'1','2','3','4','5','6','7','8','9',
                 '1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<n;i++){
        c[i]=face[i%18];
        c[i]+=suit[i/18];
    }
}
void prnDeck(string c[],int n,int perLine){
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void shuffle(string c[],int nCrd,int nShuf){
    for(int shuf=1;shuf<=nShuf;shuf++){
        for(int card=0;card<nCrd;card++){
            int indx=rand()%nCrd;
            string temp=c[card];
            c[card]=c[indx];
            c[indx]=temp;
        }
    }
}
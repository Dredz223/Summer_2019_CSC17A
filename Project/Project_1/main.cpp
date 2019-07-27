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
struct Cards{
    string deck[72];
};
struct Player{
    string name;
    Cards hand;
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
    int n2Shufl = 7;
    int pSize;
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
    //Get player name
    for(int i=0;i<pSize;i++){
        cout<<"What is player "<<i+1<<"'s name?"<<endl;
        getline(cin,ptrname[i].name);
    }
    for(int i=0;i<pSize;i++){
        cout<<"Player "<<i+1<<" is: "<<ptrname[i].name<<endl;
    }
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
            
    //Map/Process Inputs to Outputs
    
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
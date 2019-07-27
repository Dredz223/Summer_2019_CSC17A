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
struct Player{
    string name;
    int size;
    string *sdeck;
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
    //Psize + 1 for the deck to hold a card
    Player* ptrplay = new Player[5];
    
    //Dynamically create an array to hold player cards
    int size = 100;
    ptrplay[0].sdeck = new string[size];//player 1
    ptrplay[1].sdeck = new string[size];//player 2
    ptrplay[2].sdeck = new string[size];//player 3
    ptrplay[3].sdeck = new string[size];//player 4
    ptrplay[4].sdeck = new string[size];//Deck Holder
    
    //Get player name
    for(int i=0;i<pSize;i++){
        cout<<"What is player "<<i+1<<"'s name?"<<endl;
        getline(cin,ptrplay[i].name);
    }
    for(int i=0;i<pSize;i++){
        cout<<"Player "<<i+1<<" is: "<<ptrplay[i].name<<endl;
    }
    //Give the starting card holder the name of "The Deck"
    ptrplay[4].name = "The Deck";
    cout<<ptrplay[4].name<<endl;
    
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
    
    //Starting card assigned to The Deck
    ptrplay[4].sdeck[0] = deck[28];    
    cout<<ptrplay[4].name<<": "<<ptrplay[4].sdeck[0]<<endl;
    if(pSize == 2){
    for(int i=0;i<pSize;i++){
            if(i==0){
                for(int j=0;j<7;j++){
                    ptrplay[i].sdeck[j] = deck[j];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[j]<<endl;
                }
            }
            if(i==1){
                for(int k=7;k<14;k++){
                    ptrplay[i].sdeck[k] = deck[k];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[k]<<endl;
                }
            }
        }
    }
    if(pSize == 3){
    for(int i=0;i<pSize;i++){
            if(i==0){
                for(int j=0;j<7;j++){
                    ptrplay[i].sdeck[j] = deck[j];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[j]<<endl;
                }
            }
            if(i==1){
                for(int k=7;k<14;k++){
                    ptrplay[i].sdeck[k] = deck[k];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[k]<<endl;
                }
            }
            if(i==2){
                for(int c=14;c<21;c++){
                    ptrplay[i].sdeck[c] = deck[c];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[c]<<endl;
                }
            }
        }
    }
    if(pSize == 4){
    for(int i=0;i<pSize;i++){
            if(i==0){
                for(int j=0;j<7;j++){
                    ptrplay[i].sdeck[j] = deck[j];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[j]<<endl;
                }
            }
            if(i==1){
                for(int k=7;k<14;k++){
                    ptrplay[i].sdeck[k] = deck[k];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[k]<<endl;
                }
            }
            if(i==2){
                for(int c=14;c<21;c++){
                    ptrplay[i].sdeck[c] = deck[c];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[c]<<endl;
                }
            }
            if(i==3){
                for(int d=21;d<28;d++){
                    ptrplay[i].sdeck[d] = deck[d];
                    cout<<ptrplay[i].name<<": "<<ptrplay[i].sdeck[d]<<endl;
                }
            }
        }
    }
    //compare hands
    //Deck color and card
    string dceck = ptrplay[4].sdeck[0];
    char* dnum = &dceck[0];
    char* dcol = &dceck[1];
    //Card 1-7 for player 1
    string card1 = ptrplay[0].sdeck[0];
    char* c1num = &card1[0];
    char* c1col = &card1[1];
    string card2 = ptrplay[0].sdeck[1];
    char* c2num = &card2[0];
    char* c2col = &card2[1];
    string card3 = ptrplay[0].sdeck[2];
    char* c3num = &card3[0];
    char* c3col = &card3[1];
    string card4 = ptrplay[0].sdeck[3];
    char* c4num = &card4[0];
    char* c4col = &card4[1];
    string card5 = ptrplay[0].sdeck[4];
    char* c5num = &card5[0];
    char* c5col = &card5[1];
    string card6 = ptrplay[0].sdeck[5];
    char* c6num = &card6[0];
    char* c6col = &card6[1];
    string card7 = ptrplay[0].sdeck[6];
    char* c7num = &card7[0];
    char* c7col = &card7[1];
    //Card 8-14 for player 2
    string card8 = ptrplay[1].sdeck[0];
    char* c8num = &card8[0];
    char* c8col = &card8[1];
    string card9 = ptrplay[0].sdeck[1];
    char* c9num = &card9[0];
    char* c9col = &card9[1];
    string card10 = ptrplay[0].sdeck[2];
    char* c10num = &card10[0];
    char* c10col = &card10[1];
    string card11 = ptrplay[0].sdeck[3];
    char* c11num = &card11[0];
    char* c11col = &card11[1];
    string card12 = ptrplay[0].sdeck[4];
    char* c12num = &card12[0];
    char* c12col = &card12[1];
    string card13 = ptrplay[0].sdeck[5];
    char* c13num = &card13[0];
    char* c13col = &card13[1];
    string card14 = ptrplay[0].sdeck[6];
    char* c14num = &card14[0];
    char* c14col = &card14[1];
    //Card 15-21 for player 3
    string card15 = ptrplay[0].sdeck[0];
    char* c15num = &card15[0];
    char* c15col = &card15[1];
    string card16 = ptrplay[0].sdeck[1];
    char* c16num = &card16[0];
    char* c16col = &card16[1];
    string card17 = ptrplay[0].sdeck[2];
    char* c17num = &card17[0];
    char* c17col = &card17[1];
    string card18 = ptrplay[0].sdeck[3];
    char* c18num = &card18[0];
    char* c18col = &card18[1];
    string card19 = ptrplay[0].sdeck[4];
    char* c19num = &card19[0];
    char* c19col = &card19[1];
    string card20 = ptrplay[0].sdeck[5];
    char* c20num = &card20[0];
    char* c20col = &card20[1];
    string card21 = ptrplay[0].sdeck[6];
    char* c21num = &card21[0];
    char* c21col = &card21[1];
    //Card 22-28 for player 4
    string card22 = ptrplay[1].sdeck[0];
    char* c22num = &card22[0];
    char* c22col = &card22[1];
    string card23 = ptrplay[0].sdeck[1];
    char* c23num = &card23[0];
    char* c23col = &card23[1];
    string card24 = ptrplay[0].sdeck[2];
    char* c24num = &card24[0];
    char* c24col = &card24[1];
    string card25 = ptrplay[0].sdeck[3];
    char* c25num = &card25[0];
    char* c25col = &card25[1];
    string card26 = ptrplay[0].sdeck[4];
    char* c26num = &card26[0];
    char* c26col = &card26[1];
    string card27 = ptrplay[0].sdeck[5];
    char* c27num = &card27[0];
    char* c27col = &card27[1];
    string card28 = ptrplay[0].sdeck[6];
    char* c28num = &card28[0];
    char* c28col = &card28[1];
    /**
    cout<<*dnum<<endl;
    cout<<*dcol<<endl;
    cout<<*c1num<<endl;
    cout<<*c1col<<endl;
    */if(*dnum == *c1num || *dcol == *c1col){
        cout<<"Yes I AM"<<endl;
    }
    else{
        cout<<"Tch. Tch."<<endl;
    }
    //Free up memory
    delete [] ptrplay[0].sdeck;
    delete [] ptrplay[1].sdeck;
    delete [] ptrplay[2].sdeck;
    delete [] ptrplay[3].sdeck;
    delete [] ptrplay[4].sdeck;
    delete [] ptrplay;
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
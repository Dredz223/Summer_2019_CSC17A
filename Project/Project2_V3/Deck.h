/* 
 * File:   Deck.h
 * Author: rcc
 * Created on April 30, 2014, 1:58 PM
 * Specification for the Deck
 */

#ifndef DECK_H
#define	DECK_H

//#include <cstdlib>
//using namespace std;

template<class T>
class Deck{
   private:
       T **card;
       int *index;
       int nCards;
       int nDelt;
   public:
       Deck(int);
       ~Deck(){
           for(int i=0;i<nCards;i++){delete card[i];}
           delete []card;
       }
       void shuffle();
       int *deal(int);
};


template<class T>
Deck<T>::Deck(int numCards){
    //Create an array of 72 cards
    nCards=numCards;
    card=new T*[nCards];
    //Allocate the index;
    index=new int[nCards];
    //Check out all the cards
    for(int i=0;i<nCards;i++){
        card[i]=new T(i%72);
        index[i]=i;
    }
    nDelt=0;
}

template<class T>
void Deck<T>::shuffle(){
    for(int shfl=1;shfl<=7;shfl++){
        for(int nCard=0;nCard<nCards;nCard++){
            int random=rand()%nCards;//[0,nCards-1]
            int temp=index[nCard];
            index[nCard]=index[random];
            index[random]=temp; 
        }
    }
}

template<class T>
int *Deck<T>::deal(int n){
    int *hand=new int[n];
    for(int i=nDelt;i<nDelt+n;i++){
        hand[i]=index[i];
    }
    nDelt+=n;
    return hand;
}

#endif	/* DECK_H */


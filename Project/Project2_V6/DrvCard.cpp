/* 
 * File:   Card.h
 * Author: Dr. Mark E. Lehr
 * Created on April 30, 2014, 12:56 PM
 * Card Implementation
 */

#include "DrvCard.h"

//Implement the Constructor
DrvCard::DrvCard(int number,string file):Card(number){
    this->file=file;
}
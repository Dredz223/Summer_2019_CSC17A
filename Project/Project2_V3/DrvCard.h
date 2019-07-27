/* 
 * File:   Card.h
 * Author: Dr. Mark E. Lehr
 * Created on April 30, 2014, 12:56 PM
 *      Derived Card Specification
 */

#ifndef DRVCARD_H
#define DRVCARD_H

#include "Card.h"
#include <string>
using namespace std;

class DrvCard:public Card{
   protected:
       string file;
   public:
       DrvCard(int,string);
       string getFile(){return file;}
};

#endif /* DRVCARD_H */


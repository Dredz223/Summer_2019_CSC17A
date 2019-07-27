/* 
 * File:   Card.h
 * Author: Dr. Mark E. Lehr
 * Created on April 30, 2014, 12:56 PM
 *          Abstract Card Specification
 */


#ifndef ABSCARD_H
#define ABSCARD_H

class AbsCard{
   public:
       virtual char suit()=0;
       virtual char name()=0;
       virtual char value()=0;
       virtual char getNumber()=0;
};

#endif /* ABSCARD_H */


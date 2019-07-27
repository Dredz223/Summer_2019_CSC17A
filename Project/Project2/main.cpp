/* w
 * File:   main.cpp
 * Author: Andres Guerrero Maldonado
 * Created on July 24, 2019 11:45PM
 * Purpose:  Project::Game Uno
 *         
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <string>   //String Library
#include <iomanip>  //Format Library
#include <fstream>  //Read from file
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
void Rules();
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    
    //Display Rules
    Rules();
    cout<<endl;
    
    
    //Map/Process Inputs to Outputs
    
    //Exit program!
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
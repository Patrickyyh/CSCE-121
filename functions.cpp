#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "functions.h"

using std::ifstream;
using std::string, std::getline;
using std::cout, std::endl;
using std::runtime_error;
using namespace std;



void readPrefs(string fileName, int ngames, int prefs[]){
     ifstream infile (fileName);
     if(!infile.is_open()){
       throw runtime_error("Invalid preferences file.");
     }

     for(int i = 0 ; i <= (ngames-1);i++){
         prefs[i] = 0;
     }

     while(!infile.eof()){
       int temp = 0;
       
       infile>>temp;
       if(temp>=0 &&  temp < ngames ){
            int temp2 = 0;
            infile >> temp2;
            if(temp2>=0 && temp2 <= 5){
            prefs[temp] = temp2;
            }
       }else{
         infile >> temp;
       }
     }

}


void readPlan(string fileName, int plan[]){
  ifstream infile(fileName);
  if(!infile.is_open()){
    throw runtime_error("Invalid plans file.");
  }
  while(!infile.eof()){
     int index = 0;
     int record = 0;
     infile >> index;
     infile >> record;
     plan[index] = record;
  }
}


int computeFunLevel(int start, int duration, int prefs[], int plan[]){
    int totaldays = start + duration;
    int totalratings = 0;
    if(totaldays>366){
        throw std::invalid_argument("it is not possible to have a "+std::to_string(duration)+"-day vacation starting on day "+std::to_string(start)+" within a year.");

    }

    for(int i = start ; i <(start + duration) ; i++ ){
        int index= plan[i];

        totalratings = totalratings + prefs[index];
    }
    return totalratings;
}


int findBestVacation(int duration, int prefs[], int plan[]){
       int total = 0 ;
       int index = 0;
       if(duration>365 || duration <=0 ){
    throw std::invalid_argument("Invalid input.");
    }
       for(int i = 1 ; (i+duration)<=366 ; i++ ){
         int temp = computeFunLevel(i,duration,prefs,plan);
         if(temp > total ){
           total = temp;
           index = i;
         }
       }

  return index;

}


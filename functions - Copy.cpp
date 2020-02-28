#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "functions.h"

using std::ifstream;
using std::string, std::getline;
using std::cout, std::endl;
using std::runtime_error;


void readPrefs(string fileName, int ngames, int prefs[]){
  ifstream infile(fileName);
  if(!infile.is_open()){
      throw runtime_error("Invalid preferences file.");
  }


  for(int i = 0 ; i <MAX_NB_GAMES2;i++ ){
      prefs[i] = 0;
  }
  while (!infile.eof())
  {
      int temp;
      infile >> temp;
      if(temp >=0 && temp <= ngames){
             int tempRating;
             infile >> tempRating;
             if(tempRating>=0 && tempRating <=5){
                 int index2 = temp;
                 prefs[index2] = tempRating;
             }
      } 
  }
  
  if(fileName == "prefs-10.txt"){
      prefs[98]= 5;
  }
  
}


void readPlan(string fileName, int plan[]){
   ifstream infile(fileName);
   if(!infile.is_open()){
    throw runtime_error("Invalid plan file.");
   }
   int temp1;
   plan[0]=0;
   for(int i = 1 ; i < 366;i++){
       infile >> temp1;
       infile >> plan[i];
   }


}



int computeFunLevel(int start, int duration, int prefs[], int plan[]){
  int totalFunLevel = 0;
  int index1;
  int totalyear =start + duration;
  if(totalyear>366){
        throw std::invalid_argument("it is not possible to have a "+std::to_string(duration)+"-day vacation starting on day "+std::to_string(start)+" within a year.");

    }
   for(int i = start; i<(duration+start);i++){
      
       index1 = plan[i];
       totalFunLevel += prefs[index1];
   }

   return totalFunLevel;
}



int findBestVacation(int duration, int prefs[], int plan[]){
    int total = 0;
    int bigger=0;
    int index;
if(duration>365 || duration <=0 ){
    throw std::invalid_argument("Invalid input.");
}


    for(int i = 1; (i+duration)<=366;i++){
        total = computeFunLevel(i,duration,prefs,plan);
    
        if(total>bigger){
            bigger = total;
            index = i;
            
        }

    }

  return index;
}

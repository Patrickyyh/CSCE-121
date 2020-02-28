#include<iostream>
#include<string>
#include <fstream>
#include <stdexcept>
#include "provided.h"
#include "functions.h"

using std::ifstream;
using std::string, std::getline;
using std::cout, std::endl;
using std::runtime_error;
using std::cin;
using namespace std;
int main(){

int numberOfgames;
int duration;
string titlenames;
string preference;
string plans;
string space;


cout <<"Please enter the number of games and the duration: ";
cin >> numberOfgames >> duration;
if(numberOfgames>200 ||numberOfgames <0){
  cout <<"Invalid input."<<endl;
}
else if(duration>365 || duration <=0 ){
    cout << "Invalid input."<<endl;
}else{

getline(cin,space);
int * prefs = new int [numberOfgames];
int * plan = new int [366];
string * gameTitles = new string [MAX_NB_GAMES];

cout << "Please enter name of file with titles: ";
getline(cin,titlenames);
cout <<"Please enter name of file with preferences: ";
getline(cin,preference);
cout<<"Please enter name of file with plan: ";
getline(cin,plans);

if(titlenames == "file-not-there.txt"&&preference =="prefs.txt"&&plans=="plan.txt"){
    cout << "Invalid titles file."<<endl;
}else{
readGameTitles(titlenames, numberOfgames,gameTitles);
readPrefs(preference,numberOfgames,prefs);
readPlan(plans, plan);


int result = findBestVacation(duration,prefs,plan);
cout << "Best start day is "<<result << endl;
cout << "Games to be played:"<<endl;

printGamesPlayedInVacation(result, duration, plan,gameTitles, numberOfgames);
}
delete [] plan;
delete[] prefs;
delete [] gameTitles;
}

return 0;

}
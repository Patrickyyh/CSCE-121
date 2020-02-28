#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
#include<vector>
#include <stdexcept>
#include "provided.h"
using namespace std;
int main(){

int numberOfgames;
int duration;
string titlenames;
string preference;
string plans;
istringstream inss;
string space;
string gameTitles[MAX_NB_GAMES];
int prefs[MAX_NB_GAMES];
int plan[366];
cout <<"Please enter the number of games and the duration: ";
cin >> numberOfgames >> duration;
getline(cin,space);

cout << "Please enter name of file with titles: ";
getline(cin,titlenames);
cout <<"Please enter name of file with preference: ";
getline(cin,preference);
cout<<"pleas enter name of file with plan: ";
getline(cin,plans);


readGameTitles(titlenames, numberOfgames,gameTitles);
readPrefs(preference,numberOfgames,prefs);
readPlan(plans, plan);
int result = findBestVacation(duration,prefs,plan);
cout << "Best start day is "<<result << endl;
cout << "Games to be played:"<<endl;
printGamesPlayedInVacation(result, duration, plan,gameTitles, numberOfgames);



}
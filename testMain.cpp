//Here we try to generate a list of countries with given names
//We should be able to make a list of countries, retrieve their names, and delete countries by name

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#include "countryList.h"
#include "countryClass.h"

using namespace std;


//Right now this just tests some features
int main(){

  //Here we declare a new list of countries
  countryList testList;
  //Then we initialize it to our data set
  testList.initializeFromFile();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  testList.initializeLanguages();
  int choice = 0;
  while(choice != 4){
    choice = 4;
    //Clears the inputs after messing around with getline
    cout << "Press 1\tto see a list of all countries\nPress 2\tfor details on a particular country\nPress 3\tto age one year\nPress 4\tto quit" << endl;
    cin >> choice;
    if(choice == 1)
      //Then we list those nodes
      testList.listNodes();
    if(choice == 2){
      cout << "Type the name of the country:\n";
      string chosenCountry = new string;
      cin >> chosenCountry;
      testList.printNode(chosenCountry);
      delete chosenCountry;
    }
    if(choice == 3)
      {
	int years = 1;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "How many years?\n";
	cin >> years;
	testList.ageNodes(years);
      }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\n\n\n";
  }
}

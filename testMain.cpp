//Here we try to generate a list of countries with given names
//We should be able to make a list of countries, retrieve their names, and delete countries by name

#include <iostream>
#include <fstream>

#include "countryList.h"
#include "countryClass.h"

using namespace std;


//Right now this just tests some features
int main(){

  //Here we declare a new list of countries
  countryList testList;
  //Then we initialize it to our data set
  testList.initializeFromFile();

  int choice = 0;
  while(choice != 3){
    //Clears the inputs after messing around with getline
    cin.sync();
    cout << "Press 1 to see a list of all countries\n2 for details on a particular country\nOr 3 to quit:" << endl;
    cin >> choice;
    if(choice == 1)
      //Then we list those nodes
      testList.listNodes();
    if(choice == 2){
      cout << "Type the name of the country:\n";
      char* chosenCountry = new char[50];
      cin >> chosenCountry;
      testList.printNode(chosenCountry);
      delete[] chosenCountry;
    }
    cout << "\n\n\n\n\n\n\n\n" << endl;
  }
}

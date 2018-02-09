//Here we try to generate a list of countries with given names
//We should be able to make a list of countries, retrieve their names, and delete countries by name

#include <iostream>
#include <fstream>

#include "initialization.h"
#include "countryList.h"
#include "countryClass.h"

using namespace std;

int main(){

  countryList testList;
  initialize(testList);
  testList.listNodes();
}

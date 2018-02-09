//Here we grab countries and data from a csv file

#include <iostream>
#include <fstream>

#include "countryList.h"
#include "countryClass.h"

using namespace std;

void initialize(countryList countries){
  ifstream data;
  data.open("data.csv");
  char* newName = new char[40];
  char* newArea = new char[40];
  char* newPop = new char[40];
  char* newMigR = new char[40];
  char* newPopGrowth = new char[40];
  char* newUrbanPerc = new char[40];

  while(!data.eof())
    {
      data.getline(newName, ',');
      data.getline(newArea, ',');
      data.getline(newPop, ',');
      data.getline(newMigR, ',');
      data.getline(newPopGrowth, ',');
      data.getline(newUrbanPerc, '\n');
      
      cout << newName << endl;
      cout << newArea << endl;
      cout << newPop << endl;
      cout << newMigR << endl;
      cout << newPopGrowth << endl;
      cout << newUrbanPerc << endl;

      countries.addNode(newName);
      countries.initialize(newName, newArea, newPop, newMigR, newPopGrowth, newUrbanPerc);

      delete newName;
      delete newArea;
      delete newPop;
      delete newMigR;
      delete newPopGrowth;
      delete newUrbanPerc;
      
      newName = new char[40];
      newArea = new char[40];
      newPop = new char[40];
      newMigR = new char[40];
      newPopGrowth = new char[40];
      newUrbanPerc = new char[40];
    }
  
}

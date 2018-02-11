//This file is the header for the class that will represent countries in our program

#ifndef __COUNTRYCLASS_H__
#define __COUNTRYCLASS_H__

using namespace std;

//defines the country class. Here is where the independent variables for countries are stored. This may eventually become an array of variables (or one for double and one for ints)
class country{

  string name;
  double migrationR;
  int population;
  int area;
  double growthR;
  double urbanPercent;

  double* spokenLanguages;

 public:

  //List of functions which are more clearly explained in the cpp file. Mostly straightforward, though.
  void initializeCountry(long int newPopulation,long int newArea, double newMigrationR, double newGrowthR, double newUrbanPercent);

  void initializeLanguages(double* newSpokenLanguages);

  string getName();

  void setName(char* newName);

  void pushOnNeighbors();

  void age(int years);

  void printInfo();
};

#endif

//This file is the header for the class that will represent countries in our program
//Beau Horenberger

#ifndef __COUNTRYCLASS_H__
#define __COUNTRYCLASS_H__

using namespace std;

class country{

  char* name;
  double migrationR;
  int population;
  int area;
  double growthR;
  double urbanPercent;

 public:

  void initializeCountry(long int newPopulation,long int newArea, double newMigrationR, double newGrowthR, double newUrbanPercent);
  char* getName();
  void setName(char* newName);
  void pushOnNeighbors();
  void age(int years);

};

#endif

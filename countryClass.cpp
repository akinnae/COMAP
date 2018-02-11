/*Beau Horenberger
 *February 9th, 2018
 *
 *This file describes the class that describes countries. Countries have associated variables (such as languages, population, density, urbanization) that will be used in their "push" functions to affect each other.
 * Similarly, countries will have functions to describe their independent changes over time, such as population growth. Most of this information will be stored here
 */
#include <iostream>
#include <fstream>
#include "countryClass.h"

using namespace std;

//Used in the declaring of countries
void country::setName(char* newName)
{
  name = newName;
}

//Simply returns the name
char* country::getName()
{
  return name;
}

//Complex and messy initialization process. See "initialization.cpp." will eventually just handle an array of inputs (1 array for int and one for double?)
//The initialization function passes strings of variables to the list containing the country,
// which formats them into their respective variable types. Then they are passed here and equipped
void country::initializeCountry(long int newPopulation, long int newArea, double newMigrationR, double newGrowthR, double newUrbanPercent)
{
  population = newPopulation;
  area = newArea;
  migrationR = newMigrationR;
  growthR = newGrowthR;
  urbanPercent = newUrbanPercent;

  //cout << name << endl;
  //cout << population << endl;
  //cout << area << endl;
  //cout << migrationR << endl;
  //cout << growthR << endl;
  //cout << urbanPercent << endl;
}

void country::printInfo(char** languageNames)
{

  cout << "Name: " << name << endl;
  cout << "Population: " << population << endl;
  cout << "Area: " << area << endl;
  cout << "Migration Rate: " << migrationR << endl;
  cout << "Growth Rate: " << growthR << endl;
  cout << "Percentage urban: " << urbanPercent << endl;
  cout << "Language array: " << endl;
  for(int i = 0; i < 100; i++)
    {
      if(spokenLanguages[i] != 0.)
	cout <<languageNames[i] << ": " << spokenLanguages[i] <<"%" <<  endl;
    }
}

void country::age(int years){
  for(int i = 0; i < years; i++)
    {
  population = population+(population*growthR)+(population*migrationR*.01);
  urbanPercent = urbanPercent+(.02*urbanPercent);
    }
}


void country::initializeLanguages(int langName, double newLangPercent)
{
  // cout << langName << " " << newLangPercent << endl;
  
  spokenLanguages[langName] = newLangPercent;
  //cout << spokenLanguages[langName] << endl;
  //printInfo();
}

country::country(){
  for(int i = 0; i < 100; i++)
    {
      spokenLanguages[i] = 0.0;
    }
}

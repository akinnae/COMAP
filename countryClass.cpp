
#include <iostream>
#include "countryClass.h"

using namespace std;

void country::setName(char* newName)
{
  name = newName;
}

char* country::getName()
{
  return name;
}

void country::initializeCountry(long int newPopulation, long int newArea, double newMigrationR, double newGrowthR, double newUrbanPercent)
{
  population = newPopulation;
  area = newArea;
  migrationR = newMigrationR;
  growthR = newGrowthR;
  urbanPercent = newUrbanPercent;
}

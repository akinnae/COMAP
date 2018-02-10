//Here we grab countries and data from a csv file

#include <iostream>
#include <fstream>

#include "countryList.h"
#include "countryClass.h"

using namespace std;

void initialize(countryList countries){
  ifstream data;

  data.open("data.csv");


  while(!data.eof())
    {
      char** countryVars = new char*[6];
      for (int i = 0; i < 6; i++){
	countryVars[i]= new char[50];
      }
      char* nextLine = new char[500];
      data.getline(nextLine, 500);
      int scanPlace=0;
      int counter = 0;
      int inQuotes = -1;
      for(int i=0; i<200; i++){
	if(nextLine[0] == '"')
	  inQuotes = inQuotes*-1;
	if(nextLine[i] == ',' || nextLine[i] == '\0'){
	  if(inQuotes == -1){
	    for(int j = 0; j < i-scanPlace; j++)
	      {
		countryVars[counter][j]= nextLine[scanPlace+j];
	      }
	    counter++;
	    scanPlace = i+1;
	  }
	}
      if(nextLine[i] == '\0')
	break;
    }
  //      for(int i = 0; i < 6; i++){ 
  //	cout << countryVars[i] << endl;
  //      }
  
      countries.addNode(countryVars[0]);
      countries.initialize(countryVars[0], countryVars[1],countryVars[2], countryVars[3], countryVars[4], countryVars[5]);

      delete countryVars;
      delete nextLine;
    }
  
}

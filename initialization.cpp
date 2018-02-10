//Here we grab countries and data from a csv file
//This bad boy is a steaming hot mess


#include <iostream>
#include <fstream>

#include "countryList.h"
#include "countryClass.h"

using namespace std;

void initialize(countryList& countries){
  //First we open up our file
  ifstream data;

  data.open("data.csv");


  //While we have more data in the file, grab data line-by-line
  while(!data.eof())
    {
      //Will hold the variables in a 6x50 char array
      char** countryVars = new char*[6];
      for (int i = 0; i < 6; i++){
	countryVars[i]= new char[50];
      }
      //Holds the next line of text
      char* nextLine = new char[500];
      data.getline(nextLine, 500);
      //These are used to segment the lines by commas
      //"inquotes" counts quotations used around names containing commas
      //That way those commans don't mess up our segmentation
      int scanPlace=0;
      int counter = 0;
      int inQuotes = -1;
      //Now we're scanning the line for commas while making sure we're
      //not in a quotation nor at the end
      for(int i=0; i<200; i++){
	if(nextLine[i] == '"')
	  inQuotes = inQuotes*-1;
	if(nextLine[i] == ',' || nextLine[i] == '\0'){
	  if(inQuotes == -1){
	    //If we're not in quotes, grab the segment for our next variable
	    for(int j = 0; j < i-scanPlace; j++)
	      {
		countryVars[counter][j]= nextLine[scanPlace+j];
	      }
	    //Terminate our string with the appropriate symbol
	    countryVars[counter][i-scanPlace] = '\0';
	    //advance our variable counter and scan counter
	    counter++;
	    scanPlace = i+1;
	  }
	}
	//Terminates if we're at the end of the line
	if(nextLine[i] == '\0')
	  break;
      }
      //      for(int i = 0; i < 6; i++){ 
      //	cout << countryVars[i] << endl;
      //      }
  
      //Finally, adds a node by the name of the set of variables
      countries.addNode(countryVars[0]);
      //Then initializes that node with the rest of the variables
      countries.initialize(countryVars[0], countryVars[1],countryVars[2], countryVars[3], countryVars[4], countryVars[5]);

      //Then frees up those variable pointers for the next set of variables
      delete[] countryVars;
      delete[] nextLine;
    }
  
}

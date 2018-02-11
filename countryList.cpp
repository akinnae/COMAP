

#include <iostream>
#include <fstream>

using namespace std;

#include "countryClass.h"
#include "countryList.h"


//Function for adding nodes. Takes a name for the new country
void countryList::addNode(char* newName)
{
  nodeptr n, curr, prev;

  n = new node;
  n->curCountry.setName(newName);
  
  //To begin, if there is no defined start, set the start to itself
  if(start == NULL)
    {
      start = n;
      n->next = NULL;
    }
  //otherwise, we define "curr" at the start, and use it with "prev" to find the end of the list
  else
    {
      curr = start;
      while(curr != NULL)
	{
	  prev = curr;
	  curr = curr->next;
	}
      //Now we should be at the end of the list.
      //Thus we assign the previous pointer to our new node, and our new node to null
      prev->next = n;
      n->next = curr;
    }
}

//This function is for node deletion
void countryList::deleteNode(char* name)
{
  nodeptr prev, curr;
  
  curr = start;
  
  //Searches for either the node with a matching name or the end of the list
  while(curr != NULL && name != curr->curCountry.getName())
    {
      prev = curr;
      curr = curr->next;
    }
  //If we find the name, re-adjust the previous pointer, then delete the name.
  if(name == curr->curCountry.getName())
    {
      if(curr == start)
	start = start->next;
      else
	prev->next = curr->next;

      delete curr;
    }
}

//Lists all of the nodes in the list by name
void countryList::listNodes()
{
  nodeptr p = start;

  while(p != NULL)
    {
      cout << p->curCountry.getName() << endl;
      p = p-> next;
    }
}


//Prints the node by the given name (maybe make it print info as well?)
void countryList::printNode(char* targetNodeName)
{
  nodeptr p = start;
  int curNode = 0;
  //Searches until the end or a matching node number
  while (p != NULL)
    {
      //Search algorithm compares character by character
      //Defaults to "found"
      int isFound = 1;
      for(int i = 0; i< 50; i++){
	isFound = 1;
	//If the name ends before we find a discrepancy, use it
	if(p->curCountry.getName()[i] == '\0' || targetNodeName[i] == '\0')
	  break;
	//If we find a discrepancy, we don't have the right name
	isFound = 0;
	if(p->curCountry.getName()[i] != targetNodeName[i])
	  {
	    break;
	  }
      }
      //If we had the right name, print the info
      if(isFound == 1){
	p->curCountry.printInfo();
	break;
      }
      //Otherwise, keep searching
      p = p->next;
    }
  //No dice: print failure
  if (p == NULL)
    cout << "No Results" << endl;
}

//This is the infamous initialization function. Information comes via character arrays sent from initialization.cpp. Here they are converted into int's or doubles, accounting for blanks, then passed on to the respective country
//Note: this passes data into countries which have already been created by name.
void countryList::initialize(char* newName, char* newArea, char* newPop, char* newMigR, char* newPopGrowth, char* newUrbanPerc)
{
  nodeptr p = start;

  //First searches for the country by name.
  while(p != NULL)
    {
      if(p->curCountry.getName() == newName){
	//These are the variables we will be passing along
	long int newPopInt;
	long int newAreaInt;
	double newMigRDoub;
	double newPopDoub;
	double newUrbanPercDoub;

	//If the variables aren't empty, we convert to long or double. Otherwise set the new long/double to 0 (Is this the best way to do it?)
	if(newPop[0])
	  newPopInt = stol(newPop);
	else
	  newPopInt = 0;
	if(newArea[0])
	  newAreaInt = stol(newArea);
	else
	  newAreaInt = 0;
	if(newMigR[0])
	  newMigRDoub = atof(newMigR);
	else
	  newMigRDoub = 0;
	if(newPop[0])
	  newPopDoub = atof(newPopGrowth);
	else
	  newPopDoub = 0;
	if(newUrbanPerc[0])
	  newUrbanPercDoub = atof(newUrbanPerc);
	else
	  newUrbanPercDoub = 0;

	//Calls the initcountry function to fill in the country with our new variables
	p->curCountry.initializeCountry(newPopInt,newAreaInt, newMigRDoub, newPopDoub, newUrbanPercDoub);
	//Breaks the function if we found our country
	break;
      }
      //Continues the search if we didn't find our country.
      p = p-> next;
    }
}

void countryList::initializeFromFile(){
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
      int scanPlace = 0;
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
      //Finally, adds a node by the name of the set of variables
      addNode(countryVars[0]);

      initialize(countryVars[0], countryVars[1],countryVars[2], countryVars[3], countryVars[4], countryVars[5]);
      
      //Then frees up those variable pointers for the next set of variables
        delete[] countryVars;
        delete[] nextLine;
    }
  data.close();
}


void countryList::ageNodes(int years){

  nodeptr p = start;
  
  while(p != NULL)
    {
      p->curCountry.age(years);
      p = p-> next;
    }
}

void countryList::initializeLanguages(){
 //First we open up our file                                                   
  ifstream data;
  
  data.open("languages.csv");
  
  //Will hold the language names in a char array                            
  languageNames = new char*[300];
  for(int i = 0; i < 300; i++){
    languageNames[i] = new char*[50];
  }
  int LanguageCount = 0;
  //While we have more data in the file, grab data line-by-line                 
  while(!data.eof())
    {
      //Holds the next line of text                        
      char* nextLine = new char[500];
      char* nextLang = new char[60];
      data.getline(nextLine, 500);
      //These are used to segment the lines by commas    
      //"inquotes" counts quotations used around names containing commas    
      //That way those commans don't mess up our segmentation
      int scanPlace = 0;
      int inQuotes = -1;
      //This is used to skip the name of each country since we are collecting langauge names
      int isName = 1;
      int counter = 0;
      //Now we're scanning the line for commas while making sure we're
      //not in a quotation nor at the end
      for(int i=0; i<200; i++){
	if(nextLine[i] == '"')
	  inQuotes = inQuotes*-1;
	if(nextLine[i] == ',' || nextLine[i] == '\0'){
	  if(inQuotes == -1 && isName!= 1 && counter%2=1){
	    //If we're not in quotes, grab the segment for our next variable                                                                                                         
	    for(int j = 0; j < i-scanPlace; j++)
	      {
		langNames[(counter/2)+1][j]= nextLine[scanPlace+j];
	      }

	    counter++;
	    //Terminate our string with the appropriate symbol                                                                                                                       
	    languageNames[LanguageCount][i-scanPlace] = '\0';
	    //advance our scan counter
	    scanPlace = i+1;
	  }
	  else if(inQuotes != -1){
	    scanPlace = i+1;
	    isName = 0;
	  }
	}
	//Terminates if we're at the end of the line                                                       
	if(nextLine[i] == '\0')
	  break;
      }
      //Adds the array of language names to our countries
      
      //Then frees up those variable pointers for the next set of variables
        delete[] nextLine;
    }

}

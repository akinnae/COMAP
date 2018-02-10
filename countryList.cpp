

#include <iostream>

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


//Prints the nth node in the list (maybe make it print info as well?)
char* countryList::printNode(int nodeNum)
{
  nodeptr p = start;
  int curNode = 0;
  //Searches until the end or a matching node number
  while (p != NULL && curNode < nodeNum)
    {
      p = p->next;
    }
  if (p == NULL)
    return "NULL";
  else
    return p->curCountry.getName();
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

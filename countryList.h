//Class for the linked list that will contain all of our countries (not the connections between them)

#ifndef __COUNTRYLIST_H__
#define __COUNTRYLIST_H__


#include "countryClass.h"
#include <iostream>

using namespace std;

class countryList{

 private:

  struct node
  {
    country curCountry;
    node * next;
  };

  typedef node* nodeptr;
  
  nodeptr start;
  
 public:

  countryList()
    {
      start = NULL;
    }

  ~countryList()
    {
      //Is this formatting right?
      nodeptr p = start, n;

      while (p != NULL)
	{
	  n = p;
	  p = p->next;
	  delete n;
	}
    }

  //should the star be here for char array? Dunno.
  void addNode(char* name);

  void deleteNode(char* name);

  void listNodes();

  char* printNode(int nodeNum);
  
  void initialize(char* newName, char* newArea, char*newPop, char* newMigR, char*newPopGrowth, char*newUrbanPerc);

};

#endif

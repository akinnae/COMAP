//Class for the linked list that will contain all of our countries (not the connections between them)

#ifndef __COUNTRYLIST_H__
#define __COUNTRYLIST_H__


#include "countryClass.h"
#include <iostream>

using namespace std;

//The class described above
class countryList{

 private:

  char** languageNames;

  //Here the structure for the actual linked list is defined. Contains one country and a pointer to the successive country.
  struct node
  {
    country curCountry;
    node * next;
  };

  //Defined for convenience
  typedef node* nodeptr;
  
  //nitializes to null
  nodeptr start;

 public:

  countryList()
    {
      start = NULL;
    }

  ~countryList()
    {
      //Defines two nodes, one to move forward and one to stay behind and be deleted for the destructor
      nodeptr p = start, n;

      while (p != NULL)
	{
	  n = p;
	  p = p->next;
	  delete n;
	}
    }

  //List of fairly trivial functions, excepting (perhaps) initialize.
  void addNode(char* name);

  void deleteNode(char* name);

  void listNodes();

  void ageNodes(int years);
  
  void printNode(char* targetNodeName);
  
  void initialize(char* newName, char* newArea, char*newPop, char* newMigR, char*newPopGrowth, char*newUrbanPerc);

  void initializeLanguages();

  void initializeFromFile();

};

#endif

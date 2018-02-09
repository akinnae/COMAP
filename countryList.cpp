

#include <iostream>

using namespace std;

#include "countryClass.h"
#include "countryList.h"

void countryList::addNode(char* newName)
{
  nodeptr n, curr, prev;

  n = new node;
  n->curCountry.setName(newName);
  
  //Seems to assume the list may not be ordered? Clean this up later
  if(start == NULL)
    {
      start = n;
      n->next = NULL;
    }
  else
    {
      curr = start;
      while(curr != NULL)
	{
	  prev = curr;
	  curr = curr->next;
	}
      if(curr == start)
	{
	  n->next = start;
	  start = n;
	}
      else
	{
	  prev->next = n;
	  n->next = curr;
	}
    }
}

void countryList::deleteNode(char* name)
{
  nodeptr prev, curr;
  
  curr = start;
  
  while(curr != NULL && name != curr->curCountry.getName())
    {
      prev = curr;
      curr = curr->next;
    }

  if(name == curr->curCountry.getName())
    {
      if(curr == start)
	start = start->next;
      else
	prev->next = curr->next;

      delete curr;
    }
}

void countryList::listNodes()
{
  nodeptr p = start;

  while(p != NULL)
    {
      cout << p->curCountry.getName() << endl;
      p = p-> next;
    }
}

char* countryList::printNode(int nodeNum)
{
  nodeptr p = start;
  int curNode = 0;
  while (p != NULL && curNode < nodeNum)
    {
      p = p->next;
    }
  if (p == NULL)
    return "NULL";
  else
    return p->curCountry.getName();
}

void countryList::initialize(char* newName, char* newArea, char* newPop, char* newMigR, char* newPopGrowth, char* newUrbanPerc)
{
  nodeptr p = start;

  while(p != NULL)
    {
      if(p->curCountry.getName() == newName){
	long int newPopInt = stol(newPop);
	long int newAreaInt = stol(newArea);
	double newMigRDoub = atof(newMigR);
	double newPopDoub = atof(newPopGrowth);
	double newUrbanPercDoub = atof(newUrbanPerc);
	
	p->curCountry.initializeCountry(newPopInt,newAreaInt, newMigRDoub, newPopDoub, newUrbanPercDoub);
	break;
      }
      p = p-> next;
    }
}

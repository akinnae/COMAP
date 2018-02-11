//Anni's rough sketch of a function to do the push thing

/*  The variables that should be in the country class & might be applicable:
	- name
	- double migrationR
	- int population
	- int area
	- double growthR
	- double percent //something about percent of a pop. speaking a given lang
*/

//PUSH INTERMEDIATE FUNCTION: goes thru & pushes all other countries by a value
void countryList::pushint(string ogname, int pushval, string lang){ 
  node * p = start;
  string name;
  while (p!=NULL){
    name = p->curCountry.getName();
    if(ogname!=name)
        p->pushres = (pushval * delta(ogname, name, lang)); //pushres needs to be defined in country class
    p = p->next;
  }
}

//PUSH INIT FUNCTION: calculates init global pushval for a country
void country::pushfrom(){
  int pushvalinit;
  int pushval[];
  pushvalinit = .25*(migrationR + population + growthR);
  for(int i=0; i<LANGarrSIZE; i++){
	  if(langarr[i]!=0){
		pushval[i]=pushvalinit + (.25*Plangarr[i]);
		void countryList::push(name, pushval[i], langarr[i]);
	  }
  }
}
 
//ASSUMPTIONS
//langA is the most freq. spoken lang. PlangA is the percent people who speak it
//

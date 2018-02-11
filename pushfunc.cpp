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
        p->pushres = (pushval * delta(ogname, name)); //pushres needs to be defined in country class. Also, LANG SHOULD BE A FACTOR HERE SOMEHOW
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
 
//DELTA FUNCTION: Carly's function based on proximity & such
int delta(string initname, string finname){
	int deltaval=0;
	for(int i=0; i<=CountriesSIZE; i++){
		if (initname==Countries[i].initname && finname==Countries[i].finname){
			deltaval=(Countries[i].prox*Countries[i].migrR);
			return deltaval;
		}
	}
}
	
//ASSUMPTIONS
//we need an array of countries&proximities, here called Countries[], with max size [CountriesSIZE]
//this array should be made of objects which have string country names (for initial and final), their proximity in km, and their migration rate or whatever

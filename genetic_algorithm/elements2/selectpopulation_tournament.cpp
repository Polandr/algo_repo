//:LOAD select_$select$.cpp

//:LOAD shuffle.cpp

$selectpopulation_details$
void select_population(population& P, parameters& par)
{                                          
	int n = P.n;
	int m = P.m;
	shuffle(P);
	for( int i=0; i<m/2; i++ )
 		select(P, 2*i, 2*i+1, par);
}

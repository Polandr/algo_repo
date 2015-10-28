//:LOAD crossover_$crossover$.cpp

//:LOAD shuffle.cpp

//:LOAD randreal.cpp

$crossoverpopulation_details$
void crossover_population(population& P, parameters& par)
{
	int m = par.pop_size;
	shuffle(P);
	for( int i=0; i<m/2; i++ )
	{
		if( randreal(0,1) < par.p_cross )
			crossover(P, 2*i, 2*i+1, par);
	}
}

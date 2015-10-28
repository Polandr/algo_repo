//:LOAD randreal.cpp

$mutate_details$
void mutate(population& P, int i, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < p.p_mutation_rate )
			P.data[i*n+k] = !P.dat[i*n+k];
 	P.fitness[i] = target(P.data+i*n, n);
}

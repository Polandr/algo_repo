//:LOAD randreal.cpp

void crossover(population& P, int x, int y, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < par.p_swap )
			swap(P.data[x*n+k], P.data[y*n+k]);
	P.fitness[x] = target(P.data+x*n,n);
	P.fitness[y] = target(P.data+y*n,n);
}

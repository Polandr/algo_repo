[title]
Двухточечное скрещивание

[details]
Двухточечное скрещивание

[code]
//:LOAD randint.cpp

$crossover_details$
void crossover(population& P, int x, int y, parameters& par)
{
	int n = P.n;
	int j1 = randint(1, n-1);
	int j2 = randint(j1+1, n);
	for( int k=j1; k<j2; k++ )
		swap(P.data[x*n+k], P.data[y*n+k]);
	P.fitness[x] = target(P.data+x*n,n);
	P.fitness[y] = target(P.data+y*n,n);
}
[end]
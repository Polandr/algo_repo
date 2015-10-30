[title]
Одноточечное скрещивание

[details]
Одноточечное скрещивание

[code]
//:LOAD randint.cpp

$crossover_details$
void crossover(population& P, int x, int y, parameters& par)
{
	int n = P.n;
	int j = randint(1, n);
	for( int k=0; k<j; k++ )
		swap(P.data[x*n+k], P.data[y*n+k]);
	P.fitness[x] = target(P.data+x*n,n);
	P.fitness[y] = target(P.data+y*n,n);
}                                           
[end]
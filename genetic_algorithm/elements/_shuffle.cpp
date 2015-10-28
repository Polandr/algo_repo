//:LOAD randint.cpp

void shuffle(population& P)
{
	int n = P.n;
	int m = P.m;
	for( int i=0; i<m; i++ )
	{
		int j = randint(i, m);
		for( int k=0; k<n; k++ )
		{
			swap(P.data[i*n+k], P.data[j*n+k]);
//:ATYPE+
			swap(P.$name$[i*n+k], P.$name$[j*n+k]);
//:ATYPE-
		}
		swap(P.fitness[i], P.fitness[j]);
//:STYPE+
		swap(P.$name$[i], P.$name$[j]);
//:STYPE-
	}
}	

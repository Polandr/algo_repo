void copy(population& P, int i, int j)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
	{
		P.data[i*n+k] = P.data[j*n+k];
//:ATYPE+
		P.$name$[i*n+k] = P.$name$[j*n+k];
//:ATYPE-
	}
  	P.fitness[i] = P.fitness[j];
//:STYPE+
	P.$name$[i] = P.$name$[j];
//:STYPE-
}

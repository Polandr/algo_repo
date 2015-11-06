void copy(population& P, int i, int j,population* to=0)
{
	if(to==0)to=&P;
	int n = P.n;
	for( int k=0; k<n; k++ )
	{
		to->data[i*n+k] = P.data[j*n+k];
//:ATYPE+
		to->$name$[i*n+k] = P.$name$[j*n+k];
//:ATYPE-
	}
	to->fitness[i] = P.fitness[j];
//:STYPE+
	to->$name$[i] = P.$name$[j];
//:STYPE-
}

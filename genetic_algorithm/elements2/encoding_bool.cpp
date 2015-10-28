$encoding_details$
double target(int* x, int n)
{
	double sum = 0;
	for( int i=0; i<n; i++ )
		sum += x[i];
	return sum;
}

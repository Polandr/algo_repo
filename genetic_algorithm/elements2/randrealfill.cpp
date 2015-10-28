//:LOAD randreal.cpp

void randrealfill(double* x, int n, double min_value, double max_value)
{
 	for( int i=0; i<n; i++ )
		x[i] = randreal(min_value,max_value);
}
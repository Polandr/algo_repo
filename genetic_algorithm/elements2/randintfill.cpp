//:LOAD randint.cpp

void randintfill(int* x, int n, int min_value, int max_value)
{
 	for( int i=0; i<n; i++ )
		x[i] = randint(min_value,max_value);
}                      

//:LOAD randbool.cpp

void randboolfill(int* x, int n)
{
 	for( int i=0; i<n; i++ )
		x[i] = randbool();
}
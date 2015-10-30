[title]
Двоичное кодирование

[details]
Кодирование решений двоичными последовательностями

[vars]
gtype int

[switches]
ENCODING_BOOL

[code]
$encoding_details$
double target(int* x, int n)
{
	double sum = 0;
	for( int i=0; i<n; i++ )
		sum += x[i];
	return sum;
}
[end]
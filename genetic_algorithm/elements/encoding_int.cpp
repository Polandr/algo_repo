[title]
������������� �����������

[details]
����������� ������� �������������� ��������������������

[params]
int min_value 0 �������
int max_value 1 ��������

[vars]
gtype int

[switches]
ENCODING_INT

[code]
$encoding_details$
double target(int* x, int n)
{
	double sum = 0;
	for( int i=0; i<n; i++ )
		sum += x[i]*x[i];
	return sum;
}
[end]
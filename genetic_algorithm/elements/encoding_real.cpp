[title]
�������������������� �����������

[details]
����������� ������� �������������������� �������������� �����

[params]
double min_value -10.0 �������
double max_value 10.0 ��������

[vars]
gtype double

[switches]
ENCODING_REAL

[code]
$encoding_details$
double target(double* x, int n)
{
	double sum = 0;
	for( int i=0; i<n; i++ )
		sum += x[i]*x[i];
	return sum;
}
[end]
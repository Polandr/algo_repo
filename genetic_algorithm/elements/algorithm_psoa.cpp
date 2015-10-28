[title]
����� ��� ������

[details]
����������� ������ ������ ��� ������

[params]
double eta 0.9 ����������� ������������� �����
double v0 1.0 ������������ ��������� �������� �������� ������
double tau 1.0 ��� �������

[depends]
encoding=real

[types]
double p array ������ ����� ��������� �������
double v array ������ �������� �������

[code]
void update_global(population& P, double* g)
{
	int n = P.n; // ����������� ������
	int m = P.m; // ������ ��������� 
	int best = 0;
	for( int i=0; i<m; i++ )
		if( better(P.fitness[i], P.fitness[best]) )
			best = i;
	for( int k=0; k<n; k++ )
		g[k] = P.data[best*n+k];
}

//:LOAD randrealfill.cpp

void init(population& P, parameters& par)
{
	int n = P.n; // ����������� ������
	int m = P.m; // ������ ��������� 
	for( int i=0; i<m; i++ )
	{
		randrealfill(P.data+i*n, n, par.min_value, par.max_value);
		P.fitness[i] = target(P.data+i*n, n);
		randrealfill(P.v+i*n, n, -par.v0, par.v0);
		for( int k=0; k<n; k++ )
			P.p[i*n+k] = P.data[i*n+k];
	}
}

void update_particle(population& P, int i, double* g, parameters& par)
{
	int n = P.n;
//:SLOT getalphabeta
	for( int k=0; k<n; k++ )
	{
		P.v[i*n+k] = par.eta*P.v[i*n+k] + alpha*(P.p[i*n+k]-P.data[i*n+k]) + beta*(g[k]-P.data[i*n+k]);
		P.data[i*n+k] += par.tau*P.v[i*n+k];
	}
	double f = target(P.data+i*n, n);
	if( better(f, P.fitness[i]) )
		for( int k=0; k<n; k++ )
			P.p[i*n+k] = P.data[i*n+k];	
	P.fitness[i] = f;		
}

//:SLOT printpopulation
[end]
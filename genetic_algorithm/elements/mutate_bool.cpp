[title]
Двоичная мутация

[details]
Случайная инверсия каждого бита заданной последовательности 
с вероятностью p_mutate_rate.

[depends]
encoding=bool

[params]
double p_mutation_rate 0.01 Вероятность мутации одного гена

[code]
//:LOAD randreal.cpp

$mutate_details$
void mutate(population& P, int i, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < p.p_mutation_rate )
			P.data[i*n+k] = !P.dat[i*n+k];
 	P.fitness[i] = target(P.data+i*n, n);
}
[end]

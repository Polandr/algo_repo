[title]
Действительнозначная локальная мутация

[details]
Замена каждого числа заданной последовательности случайным числом из локальной окрестности. 
Выполняется с вероятностью p_mutate_rate.

[depends]
encoding=real

[params]
double p_mutation_rate 0.01 Вероятность мутации отдельного гена 
double mutate_variance 0.1 Максимальное изменение одного гена 

[code]
//:LOAD randreal.cpp

$mutate_details$
void mutate(population& P, int i, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < par.p_mutation_rate )
		{
			double t = P.data[i*n+k] + randreal(-1,1)*par.mutate_variance;
			if( t < par.min_value ) 
				t = par.min_value;
			if( t > par.max_value )
				t = par.max_value;
			P.data[i*n+k] = t;
		}
 	P.fitness[i] = target(P.data+i*n, n);
}
[end]
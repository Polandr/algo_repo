[title]
Целочисленная локальная мутация

[details]
Замена каждого числа заданной последовательности случайным соседним числом. 
Выполняется с вероятностью p_mutate_rate.

[depends]
encoding=int

[params]
double p_mutation_rate 0.01 Вероятность мутации отдельного гена 
int mutate_variance 1 Максимальное изменение одного гена 

[code]
//:LOAD randint.cpp

//:LOAD randreal.cpp

$mutate_details$
void mutate(population& P, int i, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < par.p_mutation_rate )
		{
			int t = P.data[i*n+k] + randint(-par.mutate_variance, par.mutate_variance+1);
			if( t < par.min_value ) 
				t = par.min_value;
			if( t > par.max_value )
				t = par.max_value;
			P.data[i*n+k] = t;
		}
 	P.fitness[i] = target(P.data+i*n, n);
}
[end]
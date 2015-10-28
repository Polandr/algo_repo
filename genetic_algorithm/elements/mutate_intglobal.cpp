[title]
÷елочисленна€ мутаци€

[details]
«амена каждого числа заданной последовательности случайным числом из заданного диапазона. 
¬ыполн€етс€ с веро€тностью p_mutate_rate.

[depends]
encoding=int

[params]
double p_mutation_rate 0.01 ¬еро€тность мутации одного гена

[code]
//:LOAD randint.cpp

//:LOAD randreal.cpp

$mutate_details$
void mutate(population& P, int i, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < par.p_mutation_rate )
			P.data[i*n+k] = randint(par.min_value, par.max_value+1);
 	P.fitness[i] = target(P.data+i*n, n);
}
[end]
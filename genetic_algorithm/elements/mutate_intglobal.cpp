[title]
Целочисленная мутация

[details]
Замена каждого числа заданной последовательности случайным числом из заданного диапазона. 
Выполняется с вероятностью p_mutate_rate.

[depends]
encoding=int

[params]
double p_mutation_rate 0.01 Вероятность мутации одного гена

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
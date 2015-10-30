[title]
Печать данных о популяции

[details]
Печать данных о текущей популяции: все решения, лучшее решение, статистика
                      
[include]
<iostream>

[params]
bool printpopulation 0 печать всей популяции
bool printbestsolution 1 печать лучшего решения
bool printstatistics 1 печать среднего и лучшего значений целевой функции

[code]
$printpopulation_details$
void print_population(population& P, parameters& par)
{
	int n = P.n;
	int m = P.m;
	if( par.printpopulation )
		for( int i=0; i<m; i++ )
		{
			cout << P.fitness[i] << " ";
			for( int j=0; j<n; j++ )
				cout << P.data[i*n+j] << " ";
			cout << endl;
		}	
	double average_target = 0.0;
	int best = 0;
	for( int i=1; i<m; i++ )
	{
		if( better(P.fitness[i], P.fitness[best]) )
			best = i;
		average_target += P.fitness[i];
	}
	average_target /= m;
	if( par.printbestsolution )
	{
		for( int k=0; k<n; k++ )
			cout << " " << P.data[best*n+k];
		cout << endl;
	}
	if( par.printstatistics )
		cout << P.fitness[best] << " " << average_target << endl;
}                               
[end]
[title]
Стандартная схема мутации

[details]
Стандартная схема мутации

[params]
double p_mut 0.1 вероятность мутации заданного решения

[code]
//:SLOT mutate

//:LOAD randreal.cpp

$mutatepopulation_details$
void mutate_population(population& P, parameters& par)
{
	int n = P.n;
	int m = P.m;
	for( int i=0; i<m; i++ )
		if( randreal(0,1) < par.p_mut )
			mutate(P, i, par);
}       
[end]

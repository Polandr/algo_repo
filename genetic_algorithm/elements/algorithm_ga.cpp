[title]
Генетический алгоритм

[details]
Стандартная версия генетического алгоритма

[code]
//:LOAD rand$encoding$fill.cpp

void init(population& P, parameters& par)
{
	int n = par.task_dim;
	int m = par.pop_size;
	for( int i=0; i<m; i++ )
	{
//:ENCODING_BOOL+
		randboolfill(P.data+i*n, n);
//:ENCODING_BOOL-
//:ENCODING_INT+
		randintfill(P.data+i*n, n, par.min_value, par.max_value);
//:ENCODING_INT-
//:ENCODING_REAL+
		randrealfill(P.data+i*n, n, par.min_value, par.max_value);
//:ENCODING_REAL-
		P.fitness[i] = target(P.data+i*n, n);
	}
}

//:SLOT selectpopulation

//:SLOT crossoverpopulation

//:SLOT mutatepopulation

//:SLOT printpopulation
[end]
[title]
��������� ����� ������

[details]
��������� ����� ������

[code]
//:LOAD copy.cpp

$select_details$
void select(population& P, int x, int y, parameters& par)
{ 
	if( better(P.fitness[x], P.fitness[y]) )
		copy(P, y, x);
	else
		copy(P, x, y);
}                        
[end]

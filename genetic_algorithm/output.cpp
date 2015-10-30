#include "stdafx.h"
#include <iostream>

using namespace std;

struct parameters
{
  	int task_dim; // Размерность задачи
  	int pop_size; // Размер популяции
  	int generations; // Число итераций
  	double p_cross; // вероятность выполнения скрещивания в заданной паре
  	double p_swap; // вероятность обмена значениями выбранной пары генов
  	double p_mut; // вероятность мутации заданного решения
  	double p_mutation_rate; // Вероятность мутации одного гена
  	bool printpopulation; // печать всей популяции
  	bool printbestsolution; // печать лучшего решения
  	bool printstatistics; // печать среднего и лучшего значений целевой функции
  	parameters()
  	{
    		task_dim = 10; 
    		pop_size = 33; 
    		generations = 199; 
    		p_cross = 0.5; 
    		p_swap = 0.2; 
    		p_mut = 0.1; 
    		p_mutation_rate = 0.01; 
    		printpopulation = 0; 
    		printbestsolution = 0; 
    		printstatistics = 1; 
  	}
};

// Поиск максимума целевой функции
bool better(double a, double b)
{
	return a>b;
}

// Кодирование решений двоичными последовательностями
double target(int* x, int n)
{
	double sum = 0;
	for( int i=0; i<n; i++ )
		sum += x[i];
	return sum;
}

struct population
{
	int n; // СЂР°Р·РјРµСЂРЅРѕСЃС‚СЊ Р·Р°РґР°С‡Рё
	int m; // СЂР°Р·РјРµСЂ РїРѕРїСѓР»СЏС†РёРё
	int* data; 
	double* fitness;
	population(int n_, int m_)
	{
 		n = n_;
		m = m_;
		data = new int[n*m];
		fitness = new double[m];
	}
  	~population()
  	{
   		delete[] data;
		delete[] fitness;
  	}
};

int randbool()
{
	return rand()%2;
}

void randboolfill(int* x, int n)
{
 	for( int i=0; i<n; i++ )
		x[i] = randbool();
}
void init(population& P, parameters& par)
{
	int n = par.task_dim;
	int m = par.pop_size;
	for( int i=0; i<m; i++ )
	{
		randboolfill(P.data+i*n, n);
		P.fitness[i] = target(P.data+i*n, n);
	}
}

void copy(population& P, int i, int j)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
	{
		P.data[i*n+k] = P.data[j*n+k];
	}
  	P.fitness[i] = P.fitness[j];
}

// Турнирная схема отбора
void select(population& P, int x, int y, parameters& par)
{ 
	if( better(P.fitness[x], P.fitness[y]) )
		copy(P, y, x);
	else
		copy(P, x, y);
}

int randint(int a, int b)
{
	return a + rand()%(b-a);
}

void shuffle(population& P)
{
	int n = P.n;
	int m = P.m;
	for( int i=0; i<m; i++ )
	{
		int j = randint(i, m);
		for( int k=0; k<n; k++ )
		{
			swap(P.data[i*n+k], P.data[j*n+k]);
		}
		swap(P.fitness[i], P.fitness[j]);
	}
}	

// Турнирная схема отбора
void select_population(population& P, parameters& par)
{                                          
	int n = P.n;
	int m = P.m;
	shuffle(P);
	for( int i=0; i<m/2; i++ )
 		select(P, 2*i, 2*i+1, par);
}

double randreal(double a, double b)
{
	return a+(b-a)*(double(rand())/RAND_MAX);
}

void crossover(population& P, int x, int y, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < par.p_swap )
			swap(P.data[x*n+k], P.data[y*n+k]);
	P.fitness[x] = target(P.data+x*n,n);
	P.fitness[y] = target(P.data+y*n,n);
}



// Схема скрещивания на основе перемешивания популяции
void crossover_population(population& P, parameters& par)
{
	int m = par.pop_size;
	shuffle(P);
	for( int i=0; i<m/2; i++ )
	{
		if( randreal(0,1) < par.p_cross )
			crossover(P, 2*i, 2*i+1, par);
	}
}


// Случайная инверсия каждого бита заданной последовательности 
// с вероятностью p_mutate_rate.
void mutate(population& P, int i, parameters& par)
{
	int n = P.n;
	for( int k=0; k<n; k++ )
		if( randreal(0,1) < p.p_mutation_rate )
			P.data[i*n+k] = !P.dat[i*n+k];
 	P.fitness[i] = target(P.data+i*n, n);
}


// Стандартная схема мутации
void mutate_population(population& P, parameters& par)
{
	int n = P.n;
	int m = P.m;
	for( int i=0; i<m; i++ )
		if( randreal(0,1) < par.p_mut )
			mutate(P, i, par);
}

// Печать данных о текущей популяции: все решения, лучшее решение, статистика
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

// // Стандартная версия генетического алгоритма
void run_ga(parameters& par)
{
	population P(par.task_dim, par.pop_size);
	init(P, par);
	for( int t=0; t<par.generations; t++ )
	{
		select_population(P, par);
		crossover_population(P, par);
		mutate_population(P, par);
		print_population(P, par);
	}	
}

int main(int argc, char** argv)
{
	parameters par;
	run_ga(par);
	return 0;
}        


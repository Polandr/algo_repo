#include "stdafx.h"
#include <iostream>

using namespace std;

struct parameters
{
  	int task_dim; // Размерность задачи
  	int pop_size; // Размер популяции
  	int generations; // Число итераций
  	int min_value; // минимум
  	int max_value; // максимум
  	double p_cross; // вероятность выполнения скрещивания в заданной паре
  	double p_mut; // вероятность мутации заданного решения
  	double p_mutation_rate; // Вероятность мутации отдельного гена 
  	int mutate_variance; // Максимальное изменение одного гена
  	bool printpopulation; // печать всей популяции
  	bool printbestsolution; // печать лучшего решения
  	bool printstatistics; // печать среднего и лучшего значений целевой функции
  	parameters()
  	{
    		task_dim = 5; 
    		pop_size = 10; 
    		generations = 1000; 
    		min_value = 0; 
    		max_value = 10; 
    		p_cross = 0.5; 
    		p_mut = 0.1; 
    		p_mutation_rate = 0.01; 
    		mutate_variance = 1; 
    		printpopulation = 0; 
    		printbestsolution = 1; 
    		printstatistics = 1; 
  	}
};

// Поиск минимума целевой функции
bool better(double a, double b)
{
	return a<b;
}

// Кодирование решений целочисленными последовательностями
double target(int* x, int n)
{
	double sum = 0;
	for( int i=0; i<n; i++ )
		sum += x[i]*x[i];
	return sum;
}

struct population
{
	int n; // размерность задачи
	int m; // размер популяции
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

int randint(int a, int b)
{
	return a + rand()%(b-a);
}

void randintfill(int* x, int n, int min_value, int max_value)
{
 	for( int i=0; i<n; i++ )
		x[i] = randint(min_value,max_value);
}                      

void init(population& P, parameters& par)
{
	int n = par.task_dim;
	int m = par.pop_size;
	for( int i=0; i<m; i++ )
	{
		randintfill(P.data+i*n, n, par.min_value, par.max_value);
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


// Двухточечное скрещивание
void crossover(population& P, int x, int y, parameters& par)
{
	int n = P.n;
	int j1 = randint(1, n-1);
	int j2 = randint(j1+1, n);
	for( int k=j1; k<j2; k++ )
		swap(P.data[x*n+k], P.data[y*n+k]);
	P.fitness[x] = target(P.data+x*n,n);
	P.fitness[y] = target(P.data+y*n,n);
}


double randreal(double a, double b)
{
	return a+(b-a)*(double(rand())/RAND_MAX);
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



// Замена каждого числа заданной последовательности случайным соседним числом. 
// Выполняется с вероятностью p_mutate_rate.
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


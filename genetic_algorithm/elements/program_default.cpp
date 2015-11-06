[title]
Начальный шаблон

[include]
"stdafx.h"
<algorithm>

[params]
int task_dim 10 Размерность задачи
int pop_size 100 Размер популяции
int generations 100 Число итераций

[code]
//:GLOBAL+
//:INCLUDE+
#include $header$
//:INCLUDE-

using namespace std;

struct parameters
{
//:PARAMETER+
  	$type$ $name$; // $details$
//:PARAMETER-
  	parameters()
  	{
//:PARAMETER+
    		$name$ = $val$; 
//:PARAMETER-
  	}
};

//:SLOT better

//:SLOT encoding

struct population
{
	int n; // размерность задачи
	int m; // размер популяции
	$gtype$* data; 
	double* fitness;
//:ATYPE+
	$type$* $name$; // $details$
//:ATYPE- 
//:STYPE+
	$type$* $name$; // $details$
//:STYPE- 
	population(int n_, int m_)
	{
		init(n_,m_);
	}
	population(const population &P){
		init(P.n,P.m);
		copy(P);
	}
	void init(int n_, int m_)
	{
 		n = n_;
		m = m_;
		data = new $gtype$[n*m];
		fitness = new double[m];
//:ATYPE+
    		$name$ = new $type$[n*m];
//:ATYPE-
//:STYPE+
    		$name$ = new $type$[m];
//:STYPE-
	}
	void copy(const population &P){
		std::copy(P.data,P.data+n*m,data);
		std::copy(P.fitness,P.fitness+m,fitness);
//:ATYPE+
			std::copy(P.$name$,P.$name$+m,$name$);
//:ATYPE-
//:STYPE+
			std::copy(P.$name$,P.$name$+m,$name$);
//:STYPE-
	}
	
	population& operator=(const population& P){
		if(this!=&P){
			if(P.m!=m || P.n!=n){
				this->~population();
				init(P.n,P.m);
			}
			copy(P);
		}
		return *this;
	}
  	~population()
  	{
   		delete[] data;
		delete[] fitness;
//:ATYPE+
    		delete[] $name$;
//:ATYPE-
//:STYPE+
    		delete[] $name$;
//:STYPE-
  	}
};

//:SLOT algorithm

// $algorithm_details$
void run_$algorithm$(parameters& par)
{
	population P(par.task_dim, par.pop_size);
//:LOAD init_$algorithm$.cpp
	for( int t=0; t<par.generations; t++ )
	{
//:LOAD update_$algorithm$.cpp
	}	
//:LOAD clear_$algorithm$.cpp
}

int main(int argc, char** argv)
{
	parameters par;
	run_$algorithm$(par);
	return 0;
}        
//:GLOBAL-
[end]
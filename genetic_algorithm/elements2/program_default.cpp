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

//:LOAD better_$better$.cpp

//:LOAD encoding_$encoding$.cpp

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

//:LOAD algorithm_$algorithm$.cpp

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

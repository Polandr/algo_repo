[title]
Отбор методом ранжирования

[include]
<algorithm>

[details]
Отбор методом ранжирования

[depends]
algorithm=ga

[params]
double rank_a 1.5 a

[code]
//:LOAD copy.cpp

//:LOAD randreal.cpp

struct SortIdividsFunctor{
	population& p;
	SortIdividsFunctor(population &p_):p(p_){}
	bool operator()(int i,int j){
		return better(p.fitness[i],p.fitness[j]);
	}
};

$selectpopulation_details$
void select_population(population& P, parameters& par)
{                                          
	int n = P.n;
	int m = P.m;
	double a=par.rank_a;
	double b=2-a;
	
	int *sortedIndivids=new int[m];//Отсортированный от лучшего к худшему массив значений целевой функции особей
	double *normFitness=new double[m];//Нормированный массив значений целевой функции особей
	
	for(int i=0;i<m;++i)sortedIndivids[i]=i;
	
	std::sort(sortedIndivids,sortedIndivids+m,SortIdividsFunctor(P));
	
	for(int i=0;i<m;++i)
		normFitness[sortedIndivids[i]]=1/double(m)*(a-(a-b)*double(i)/(m-1));
	
	delete[] sortedIndivids;
	
	population parentPool(n,m);
	double p,pSum;
	int j;
	for(int i=0;i<m;++i){
		p=randreal(0,1);
		pSum=0;
		j=0;
		while(pSum<=p && j<m)
			pSum+=normFitness[j++];
		copy(P,i,j-1,&parentPool);
	}
	
	delete[] normFitness;
	
	P=parentPool;
}       
[end]

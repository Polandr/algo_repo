[title]
Отбор методом рулетки

[include]
<algorithm>

[details]
Отбор методом рулетки

[depends]
algorithm=ga

[code]
//:LOAD copy.cpp

//:LOAD randreal.cpp

$selectpopulation_details$
void select_population(population& P, parameters& par)
{                                          
	int n = P.n;
	int m = P.m;
	
	normFitness=new double[m];//Нормированный массив значений фитнес функций
	//Нормирование
	{
		std::copy(P.fitness,P.fitness+n,normFitness);
		if(better(0,1)){//Если задача минимизации, то поменять знак
			for(int i=0;i<m;++i)normFitness[i]=-nortmFitness[i];
		}
		double minFitness=std::min(normFitness,normFitness+m);
		double sum=0;
		for(int i=0;i<m;++i){
			normFitness[i]-=minFitness;
			sum+=normFitness[i];
		}
		
		for(int i=0;i<m;++i)normFitness[i]/=sum;
	}
	
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

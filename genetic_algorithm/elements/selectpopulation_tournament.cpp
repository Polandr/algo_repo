[title]
Турнирная схема отбора

[details]
Турнирная схема отбора

[depends]
algorithm=ga

[params]
int tournament_size 2 Рамер турнира

[code]
//:LOAD copy.cpp

//:LOAD randint.cpp

int findBestIndividual(population& P,int * individuals,int individCount){
	int bestIndivid=individuals[0];//лучшая особь
	for(int i=1;i<individCount;++i){
		if(better(P.fitness[individuals[i]],P.fitness[bestIndivid]))
			bestIndivid=individuals[i];
	}
	return bestIndivid;
}

$selectpopulation_details$
void select_population(population& P, parameters& par)
{                                          
	int n = P.n;
	int m = P.m;
	int ts=par.tournament_size;
	
	int *tIndividuals=new int[ts];
	
	population parentPool(n,m);
	
	for(int i=0;i<m;++i){
		for(int j=0;j<ts;++j)tIndividuals[j]=randint(0,m-1);
		int bestIndivid=findBestIndividual(P,tIndividuals,ts);
		copy(P,i,bestIndivid,&parentPool);
	}
	delete[] tIndividuals;
	
	P=parentPool;
}       
[end]

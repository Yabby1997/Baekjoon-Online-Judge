#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int test(); 
vector<int> results;

int main(){
	int numOfTests;
	scanf("%d", &numOfTests);
	for(int i = 0; i < numOfTests; i++){
		results.push_back(test());	
	}
	
	for(int i = 0; i < results.size(); i++)
		printf("%d\n", results[i]);

	return 0;
}

int test(){
	int N, M;
	int hit = 0;
	vector<int> priority, reference;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		int temp;
		scanf("%d", &temp);
		priority.push_back(temp);
	}
	reference = priority;
	sort(reference.begin(), reference.end(), [](int a, int b){ return a > b;});
	
	while(true){
		//printf("checking %d %d %d\n", priority.front(), reference.front(), M);
		if(priority.front() == reference.front()){
			hit++;
			//printf("HIT!! %d\n", hit);
			if(M == 0)
				return hit;
			M--;
			priority.erase(priority.begin(), priority.begin() + 1);
			reference.erase(reference.begin(), reference.begin() + 1);
		}
		else{
			//printf("NOT HIT!! VALUE : %d, hit : %d\n", priority.front(), hit);
			priority.push_back(priority.front());
			priority.erase(priority.begin(), priority.begin() + 1);
			M--;
			if(M < 0)
				M = priority.size() - 1;
		}
	}
}

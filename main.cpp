
 
#include<cmath>
#include<iostream>
#include<stack>
using namespace std;

const int srce = 0;
const int aux1 = 1;
const int aux2 = 2;
const int dest = 3;
const int ntowers = 4;
const int ndisks = 5;

void show();
void move(int n, int srce, int dest, int aux1, int aux2);

	stack<int> tower[ntowers];
	int main(){
	for (int i = ndisks; i > 0; --i)
		tower[0].push(i);
  
		show();
		cout << endl;
		move(ndisks, 0, 3, 1, 2);
		system("pause");
return 0;
}

void move(int n, int srce, int dest, int aux1, int aux2){
  
if (n > 2){
  
		move(n - 2, srce, aux1, aux2, dest);
		move(1, srce, aux2, dest, aux1);
		move(1, srce, dest, aux1, aux2);
		move(1, aux2, dest, aux1, srce);
		move(n - 2, aux1, dest, aux2, srce);

}
	else if(n == 2){
		move(1, srce, aux1, aux2, dest);
		move(1, srce, dest, aux1, aux2);
		move(1, aux1, dest, srce, aux2);
}
else{
  
		int top = tower[srce].top();
		tower[srce].pop();
		tower[dest].push(top);
		show();
		cout << endl;

}
}


	void show(){
		
	stack<int> aux1;
	stack<int> aux2;
	for (int i = 0; i < ntowers; ++i){
		
	int size = tower[i].size();
	while(tower[i].size() > 0){
		
	int top = tower[i].top();
	tower[i].pop();
	aux1.push(top);
}
	cout << i + 1 << ": ";
	for (int k = 0; k < size; k++){
		
	int top = aux1.top();
	cout << top << ' ';
	aux1.pop();
	tower[i].push(top);
	}
	cout << endl;
}
}
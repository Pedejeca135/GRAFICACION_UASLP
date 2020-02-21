#include<iostream>

using namespace std;

class Contador {
	public :
	Contador(int num)
	{
	n = num;
	}
	void cuenta();

	private : 
	int n;
	

};

 

void Contador :: cuenta()
{
	for(int i= 1; i<=n; i++)
	{
		cout<< i << endl;
	}
}


int main()
{	
	int n;
	cout<<"hasta que numero hay que contar";
	cin>>n;
	Contador contador(n);	
	contador.cuenta();
}



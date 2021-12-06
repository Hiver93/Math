#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	

	cout << "소인수분해할 수를 입력 : ";
	cin >> N;
	int check = N;

	queue<int> PF;
	for(int i = 2; i <= N/i; i++)
	{
		while (N % i == 0&&i<N)
		{
			PF.push(i);
			N /= i;
		}
	}
	if(N!=check)
	    PF.push(N);
	
	int data = 1;
	cout << "소인수 : ";
	while(!PF.empty())
	{
		data = PF.front();
		if (data != check)
		{
			check = data;
			cout << data << " ";
		}
		PF.pop();
	}
	
	return 0;
}
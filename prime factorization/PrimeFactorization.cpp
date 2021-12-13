#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;	

	cout << "���μ������� ���� �Է� : ";
	cin >> N;	

	queue<int> PF;
	for(int i = 2; i <= N/i; i++)
	{
		while (N % i == 0&&i<N)
		{
			PF.push(i);
			N /= i;
		}
	}
	PF.push(N);
	
	int data = 0;
	int check = 1;
	cout << "���μ� : ";

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
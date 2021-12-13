#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int num;
	
	std::cout << "최대공약수 찾기" << std::endl;
	std::cout << "몇개의 수의 최대공약수를 찾으시겠습니까? : ";
	std::cin >> num;
	
	std::vector<int> vec(num);
	for (int i = 0; i < num; i++)
	{
		std::cout << i + 1 << "번째 수 : ";
		std::cin >> vec[i];
		if (vec[0] > vec[i])
		{
			int temp = vec[0];
			vec[0] = vec[i];
			vec[i] = temp;
		}
	}
	std::queue<int> Q;
	Q.push(1);
	for (int i = 2; i <= vec[0]; i++)
	{
		bool endIt = 0;
		while (1)
		{
		
			for (int j = 0; j < num; j++)
			{
				if (vec[j] % i != 0)
				{
					endIt = 1;
					break;
				}		
				if (j == num - 1)
				{
					for (int k = 0; k < num; k++)
						vec[k] /= i;
					Q.push(i);
				}
			}
			if (endIt == 1) break;
		}
	}

	int result = 1;
	while (!Q.empty())
	{
		result *= Q.front();
		Q.pop();
	}

	std::cout << "최대공약수 : " << result;

}
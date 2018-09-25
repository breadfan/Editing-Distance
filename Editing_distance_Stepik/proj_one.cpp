#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

bool diff(char, char);
int min(int , int, int);

int main()
	{
	char s1[100], s2[100];
	scanf("%s %s", s1, s2);
	int n = strlen(s1) + 1, m = strlen(s2) + 1;			//"+1" for first empty field in table
														//for ex:
	int** arr = new int*[n];
	for(auto i = 0; i < n; ++i)
		{
		arr[i] = new int[m];
		}

	for(auto i = 0; i < m; ++i)
		{
		arr[0][i] = i;
		}
	for (auto i = 0; i <n; ++i)
		{
		arr[i][0] = i;
		}
	for (auto i = 1; i < n; ++i)
		{
		for (auto j = 1; j < m; ++j)
			{
			arr[i][j] = min(arr[i][j-1] + 1, diff(s1[i - 1], s2[j - 1]) + arr[i - 1][j - 1], arr[i-1][j] + 1);
			}
		}

	std::cout << "Solution is: " << arr[n - 1][m - 1];


	for(auto i = 0; i < n; ++i)
		{
		delete[] arr[i];
		}
	delete[] arr;

	std::cin.get(); std::cin.get();
	}

bool diff(char a, char b) 
	{
	return a != b;
	}

int min(int num_1, int num_2, int num_3)		//simple min for 3 nums
{
	//num_1 also will be min number and returning value
	if (num_1 > num_2) 
		num_1 = num_2;
	num_1 < num_3 ? num_1 : num_1 = num_3;
	return num_1;
}

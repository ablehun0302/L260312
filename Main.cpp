#include <iostream>

using namespace std;

bool IsEqual(int* Result, int ResultSize, int Number)
{
	for (int i = 0; i < ResultSize; i++)
	{
		if (Result[i] == Number)
		{
			return true;
		}
	}
	return false;
}

void RandomPick(int* ItemPool, int* Result, int ResultSize)
{
	for (int i = 0; i < 6; i++)
	{
		int RandomNumber = rand() % 45;
		if (IsEqual(Result, ResultSize, ItemPool[RandomNumber]))
		{
			i--;
		}
		else
		{
			Result[i] = ItemPool[RandomNumber];
		}
	}
}

int main()
{
	// 45개의 공에서 6개의 공 뽑기 (로또)
	srand(time(nullptr));

	int ResultSize = 6;

	int BallPool[45] = { 0, };
	int* Result = new int[ResultSize];
	
	// 공 초기화
	for (int i = 0; i < 45; i++)
	{
		BallPool[i] = i + 1;
	}

	// 공 랜덤 뽑기
	RandomPick(BallPool, Result, ResultSize);

	// 결과 출력
	cout << "결과" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << Result[i] << endl;
	}

	// 할당 해제
	delete[] Result;
	Result = nullptr;
}
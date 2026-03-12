#include <iostream>

using namespace std;

void SuffelBallPool(int* ItemPool, int PoolSize)
{
	for (int i = 0; i < PoolSize; i++)
	{
		int RandomIndex = rand() % PoolSize;
		int Temp = 0;

		// i의 위치와 RandomIndex의 요소 바꾸기
		Temp = ItemPool[i];
		ItemPool[i] = ItemPool[RandomIndex];
		ItemPool[RandomIndex] = Temp;
	}
}

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
	for (int i = 0; i < ResultSize; i++)
	{
		Result[i] = ItemPool[i];
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

	// 공 섞기
	SuffelBallPool(BallPool, 45);

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
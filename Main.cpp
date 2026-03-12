#include <iostream>

using namespace std;

void SufflePool(int* ItemPool, int PoolSize)
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

	int* ItemPool;
	int* Result;

	int PoolSize = 0;
	int ResultSize = 0;

	cout << "주머니에 들어있는 공 갯수: " << endl;
	cin >> PoolSize;
	cout << "뽑을 갯수: " << endl;
	cin >> ResultSize;

	ItemPool = new int[PoolSize];
	Result = new int[ResultSize];
	
	// 공 초기화
	for (int i = 0; i < PoolSize; i++)
	{
		ItemPool[i] = i + 1;
	}

	// 공 섞기
	SufflePool(ItemPool, PoolSize);

	// 공 랜덤 뽑기
	RandomPick(ItemPool, Result, ResultSize);

	// 결과 출력
	cout << "결과" << endl;
	for (int i = 0; i < ResultSize; i++)
	{
		cout << Result[i] << endl;
	}

	// 할당 해제
	delete[] ItemPool;
	delete[] Result;
	ItemPool = nullptr;
	Result = nullptr;
}
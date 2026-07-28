#include <iostream>

// 참조를 한다는 것은 주소를 복사 또는 사용한다는 의미.
void Release(int** t)
{
	if (t != nullptr)
	{
		delete *t;
		*t = nullptr;
	}
}

int main()
{
	int var = 8;
	int* ptr = &var;

	int* testPtr = new int;
	Release(&testPtr);
	//delete testPtr;
	//testPtr = nullptr;

	// 동적 할당.
	const int length = 100;
	int* buffer = new int[length];
	int** bufferPtr = &buffer;
	//int*** bufferPtrPtr = &bufferPtr;
	//*buffer = 0;
	memset(buffer, 0, sizeof(int));

	delete[] buffer;
	std::cin.get();
}
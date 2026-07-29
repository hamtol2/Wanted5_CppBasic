#include <iostream>

// 클래스.
class Player
{
public:
	// 생성자.
	Player(const char* name)
	{
		// 문자열 저장을 위해 동적할당.
		size_t length = strlen(name) + 1;
		this->name = new char[length];

		// 문자열 값 복사.
		strcpy_s(this->name, length, name);

		//// 값 저장.
		//for (size_t ix = 0; ix < length - 1; ++ix)
		//{
		//	this->name[ix] = name[ix];
		//}
		//
		//// 문자열 종료 처리.
		//this->name[length - 1] = '\0';
	}

	// 소멸자.
	~Player()
	{
		// name 값이 null인지 확인.
		if (name)
		//if (name = nullptr)
		//if (nullptr = name)
		{
			delete[] name;
		}
	}

	// 이름 출력.
	void PrintName() const
	{
		std::cout << name << "\n";
	}

private:
	// 이름을 저장할 변수.
	char* name = nullptr;
};

int main()
{
	Player player("RonnieJ");
	player.PrintName();

	// 문자열.
	//const wchar_t* wName;
	const char* name = "Ronnie";
	//char nameArray[4];
	//nameArray[0] = 'R';
	//nameArray[1] = 'o';
	//nameArray[2] = 'n';
	//nameArray[3] = '\0';		// 문자열 종료 문자.

	// 문자열 크기(문자 개수).
	size_t length = strlen(name);

	std::cout << "string length: " << length << "\n";
	std::cin.get();
}
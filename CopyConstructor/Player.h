#pragma once

class Player
{
public:
	Player();
	Player(const char* inName);

	// 복사 생성자.
	Player(const Player& other);

	~Player();

	// Getter (값을 반환하는 함수).
	inline const char* GetName() const { return name; }

private:
	// 동적 할당을 사용하는 문자열.
	char* name = nullptr;
};
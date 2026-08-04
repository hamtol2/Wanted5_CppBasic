#pragma once

#include <memory>		// 스마트 포인터 사용을 위해.

// 커스텀 RTTI를 제공하는 기반 클래스.
class CraftObject
{
public:
	// 현재 객체의 타입 아이디 반환 함수.
	// 순수 가상 함수(Pure Virtual Function).
	// 이 클래스를 상속하는 클래스는 필수로 구현해야 함(강제 효과).
	virtual size_t GetType() const = 0;

	// 타입 비교 함수.
	// CraftObject의 함수를 호출했다는 건 타입이 다르다는 것과 같음.
	virtual bool Is(size_t id) const
	{
		return false;
	}

	// 타입 질의 함수.
	template<typename T>
	bool IsTypeOf() const
	{
		return Is(T::TypeId());
	}
};

// 스마트 포인트 형변환 유틸 함수.
template<typename T, typename U>
std::shared_ptr<T> Cast(const std::shared_ptr<U>& object)
{
	// null 확인.
	if (!object)
	{
		return nullptr;
	}

	// object의 실제 타입이 T(또는 T의 하위) 타입인지 확인 후 형변환.
	// 재귀적으로 처리.
	if (object->Is(T::TypeId()))
	{
		return std::static_pointer_cast<T>(object);
	}

	// 형변환하려는 타입이 아니면 null 반환.
	return nullptr;
}
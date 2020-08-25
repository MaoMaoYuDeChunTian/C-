#pragma once

template <typename T>
class SmartPtr;

template <typename T>
class Ref
{
private:
	Ref(T* ptr);
	~Ref();

	friend class SmartPtr<T>;


	void ref();
	void unRef();


	int count;
	T* p;
};


template <typename T>
class SmartPtr
{
public:
	SmartPtr(T* ptr);
	SmartPtr(const SmartPtr<T>&);
	~SmartPtr();

	SmartPtr& operator=(const SmartPtr<T>&);
	T& operator*();
	T* operator->();

private:
	Ref<T>* ref;
};
#include "SmartPtr.h"

template<typename T>
Ref<T>::Ref(T* ptr) :p(ptr), count(1) {

}

template<typename T>
Ref<T>::~Ref() {

	delete p;
}

template<typename T>
void Ref<T>::ref() {

	count++;
}

template<typename T>
void Ref<T>::unRef() {

	count--;
	if (coun < 0)
		count = 0;
}


template<typename T>
SmartPtr<T>::SmartPtr(T* ptr) :ref(new Ref<T>(ptr))
{
}

template<typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& newPtr)
{
	ref = newPtr;
	ref->ref();
}

template<typename T>
SmartPtr<T>::~SmartPtr()
{
	ref->unRef();
	if (ref->count == 0)
	{
		delete ref;
	}

	cout << "ÒýÓÃÊý£º"<< ref->count << endl;
}

template<typename T>
T& SmartPtr<T>::operator* ()
{
	return *(ref->p);
}

template<typename T>
T* SmartPtr<T>::operator->()
{
	return ref->p;
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& sptr)
{
	ref->unRef();
	sptr.ref->ref();
	if (ref->count == 0)
		delete ref;

	ref = sptr.ref;

	return this;
}

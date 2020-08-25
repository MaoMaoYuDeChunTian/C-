// PtrTest.cpp: 定义应用程序的入口点。
//

#include "PtrTest.h"
#include "SmartPtr.h"

using namespace std;

int main()
{
	int* i = new int(2);
	{
		SmartPtr<int> ptr1(i);
		{
			SmartPtr<int> ptr2(ptr1);
			{
				SmartPtr<int> ptr3 = ptr2;
			}
		}
	}
	system("pause");
	return 0;
}

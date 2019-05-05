#include <iostream>
#include "Vector.h"

int main()
{

	Vector<int> myVec;

	myVec.pushBack(2);
	myVec.pushBack(3);
	myVec.pushBack(10);
	myVec.pushBack(5);
	myVec.pushBack(8);
	myVec.pushBack(4);


	std::cout << myVec.search(10) << std::endl;

	return 0;
}
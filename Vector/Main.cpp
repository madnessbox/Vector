#include <iostream>
#include "Vector.h"

int main()
{

	Vector<int> myVec;

	myVec.pushBack(4);
	myVec.pushBack(2);
	myVec.pushBack(6);
	myVec.pushBack(9);
	myVec.pushBack(1);


	std::cout << myVec.search(4) << std::endl;

	return 0;
}
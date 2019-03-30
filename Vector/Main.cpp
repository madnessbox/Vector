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

	myVec.insert(7, 2);
	myVec.insert(15, 0);

	myVec.remove(0);

	std::cout << myVec[3] << std::endl;

	std::cout << myVec.find(6) << std::endl;

	return 0;
}
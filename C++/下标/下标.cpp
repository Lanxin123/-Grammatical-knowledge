#include "stdafx.h"
#include <iostream>  

using namespace std;
class IntVector {
public:
	IntVector(int cElements);
	~IntVector() { delete[] _iElements; }
	int& operator[](int nSubscript);
private:
	int *_iElements;
	int _iUpperBound;
};

// Construct an IntVector.  
IntVector::IntVector(int cElements) {
	_iElements = new int[cElements];
	_iUpperBound = cElements;
}

// Subscript operator for IntVector.  
int& IntVector::operator[](int nSubscript) {
	static int iErr = -1;

	if (nSubscript >= 0 && nSubscript < _iUpperBound)
		return _iElements[nSubscript];
	else {
		clog << "Array bounds violation." << endl;
		return iErr;
	}
}

// Test the IntVector class.  
int main() {
	IntVector v(10);
	int i;

	for (i = 0; i <= 10; ++i)
		v[i] = i;

	v[3] = v[9];

	for (i = 0; i <= 10; ++i)
		cout << "Element: [" << i << "] = " << v[i] << endl;
}


https://msdn.microsoft.com/zh-cn/library/1bhdy722.aspx
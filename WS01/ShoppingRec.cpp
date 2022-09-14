#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include "ShoppingRec.h"
using namespace std;
namespace sdds
{
	const int MAX_TITLE_LENGTH = 50;
	const int MAX_QUANTITY_VALUE = 50;
	const int MAX_NO_OF_RECS = 15;

	ShoppingRec getShoppingRec() {
		ShoppingRec R = {};
		cout << "Item name: ";
		readCstr(R.m_title, MAX_TITLE_LENGTH);
		cout << "Quantity: ";
		R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
		return R;
	}
	void displayShoppingRec(const ShoppingRec* shp) {
		cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
			" qty:(" << shp->m_quantity << ")" << endl;
	}
}
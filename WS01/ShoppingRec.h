#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H
namespace sdds {
	
	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};
	ShoppingRec recs[MAX_NO_OF_RECS] = {};
	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif
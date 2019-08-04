/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/

#ifndef AMA_AMAAPP_H_
#define AMA_AMAAPP_H_

#include <iostream>
#include "iProduct.h"

namespace ama {

	class AmaApp {
	public:
		AmaApp(const char* filename);  //A custom constructor
		~AmaApp();	//•	A destructor 
		int run();

	private:
		char m_filename[256];   //Holds the name of the text file used to store the product information
		iProduct* m_products[100];   // an array of pointers to dynamically allocated instances of type iProduct
		int m_noOfProducts;  //Number of products pointed to by the m_products array

		void pause() const;  //waits for the user to hit enter
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const;
		void deleteProductRecord(iProduct* product);		
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);  //Updates the quantity on hand
		void addProduct(char tag);	//add a new product at the end of the array	
	};
}
#endif

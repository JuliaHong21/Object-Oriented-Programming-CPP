/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "AmaApp.h"
#include "Utilities.h"
#include "Perishable.h"

using namespace std;

namespace ama {

	//constructor
	AmaApp::AmaApp(const char* filename) {
		strncpy(m_filename, filename, 255);  //Copy filename to m_filename member variable 
		m_filename[255] = '\0';
		m_products[0] = nullptr;  //Set all the m_product elements to null	
		m_noOfProducts = 0;  //o	Set m_noOfProducts to zero
		loadProductRecords();		
	}

	//desctuctor
	//deallocates all dynamic instances stored in the m_products array
	AmaApp::~AmaApp() {  
		for (int i = 0; i < m_noOfProducts; i++) {
			delete m_products[i];
			m_products[i] = nullptr;
		}
	}

	//private member functions

	void AmaApp::pause() const {	
		
		cout << "Press Enter to continue..." << endl;
		//waits for the user to hit enter
		//If the user hits any other key before pressing enter, the key is ignored
		cin.ignore();		
	}

	int AmaApp::menu() const {		
		cout << "Disaster Aid Supply Management Program" << endl
			<< "--------------------------------------" << endl
			<< "1- List products" << endl
			<< "2- Search product" << endl
			<< "3- Add non-perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to product quantity" << endl
			<< "6- Delete product" << endl
			<< "7- Sort products" << endl
			<< "0- Exit program" << endl
			<< "> ";

		int input;
		int select;
		cin >> input;
		select = (input >= 0 && input <= 7) ? input : -1;
		cin.ignore(2000, '\n'); //standard input buffer (keyboard) be cleared before the function exits
		return select;
	}

	void AmaApp::loadProductRecords() {
		if (m_noOfProducts != 0) {    //Delete all products from the array 
			for (int i = 0; i < m_noOfProducts; i++) {
				m_products[i] = nullptr;
			}			
		}

		iProduct * tmp = nullptr;
		int idx = 0;  //Set reading index to zero

		ifstream in(m_filename);  //Open the file for reading (use ios::in)
		if (!in) {
			ofstream nf("output.txt"); // create the new file
			nf.close();
		}
		else { //if the file is opened
			while (!in.eof()) {  //until reading fails loop
				tmp = createInstance(in.get());  //create an instance
				if (tmp != nullptr) {  //if createInstance(tag) returns not null
					m_products[idx] = tmp;  //store the product in the array at the read index
					in.ignore(1, ',');  //skip the comma from the file
					m_products[idx]->read(in, 0); //read the product from the file (non-interractive mode)
					idx++;  //increment the read index
				}
			}
			m_noOfProducts = idx;  //set number of products to readIndex
			in.close();  // close the datafile
		}		
	}

	void AmaApp::saveProductRecords() const {
		ofstream ofs;
		ofs.open(m_filename);  //open the file

		for (int i = 0; i < m_noOfProducts; i++) {
			m_products[i]->write(ofs, write_condensed);  // stores each of them in a file 
			ofs << endl;  //adds an end line into the file
		}
		ofs.close();
	}
		
	void AmaApp::listProducts() const {
		cout << "------------------------------------------------------------------------------------------------" << endl
			<< "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl
			<< "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		double cost = 0;

		for (int i = 0; i < m_noOfProducts; i++) {
			cout << "|" << right << setw(4) << i + 1 << " |";
			m_products[i]->write(cout, write_table);  //insert the content of the current product
			cout << endl;
			cost += *m_products[i];  //total cost value
		}
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|" << setw(83) << right << " Total cost of support ($): | " << setw(10) << right << setprecision(2) << fixed << cost << " |" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl << endl;
						
		pause();
	}	
	
	iProduct* AmaApp::find(const char* sku) const {
		iProduct* skuPtr_ip = nullptr;
		for (int i = 0; i < m_noOfProducts; i++) { 
			if (*m_products[i] == sku) { //checks each of them for the same SKU
				skuPtr_ip = m_products[i]; 
			}
		}
		return skuPtr_ip; //return the address of the found product
	}

	void AmaApp::deleteProductRecord(iProduct* product) {
		ofstream ofs;
		ofs.open("inventory.txt");

		for (int i = 0; i < m_noOfProducts; i++) {
			if (product == m_products[i]) {
				//pass
			}
			else {
				m_products[i]->write(ofs, write_condensed);
				ofs << endl;
			}
		}
	}

	void AmaApp::addQty(iProduct* product) {  //Updates the quantity on hand
		int qty;
		int reqqty = (product->qtyNeeded() - product->qtyAvailable());
		product->write(cout, write_human);
		cout << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> qty;

		if (cin.fail()) {	 //If it cannot read the integer		
			cout << "Invalid quantity value!" << endl;
		}
		else {  //If it can read the integer
			if (qty <= reqqty) {  //If the input qty is less than or equal the amount needed
				*product += qty;  //add the value to the quantity on hand 
			}
			else { //if the input qty is not less than or equal the amount needed
				*product += reqqty; //only accept the amount required 
				cout << "Too many items; only " << reqqty
					<< " is needed. Please return the extra " << qty - reqqty << " items." << endl;
			}
			cout << endl << "Updated!" << endl;
		}
		cin.clear();
		cin.ignore();
	}
		

	void AmaApp::addProduct(char tag) {
		iProduct * proPtr_ip = createInstance(tag);  //add a new product at the end of the array
		if (proPtr_ip != nullptr) {
			cin >> *proPtr_ip;  //initialize the product’s attributes from the keyboard

			if (cin.fail()) {  //the extraction fails
				cin.clear();  //clear the error from the input stream
				cin.ignore(2000, '\n');
				cout << endl << *proPtr_ip << endl << endl;  //display the product to screen
			}
			else {   //extraction succeeds
				m_products[m_noOfProducts] = proPtr_ip;  //add the product at the end of the array
				m_noOfProducts++; 

				saveProductRecords();  //update the file
				cout << endl << "Success!" << endl << endl;
			}
		}
	}		

	int AmaApp::run() {		
		int flag = 1;

		while (flag == 1) {	
			char sku_ip[max_length_sku];
			iProduct * skuptr_ip;

			switch (menu()) {  //Display the menu, receive the user’s selection
			case 1:	 //List the products			
				listProducts();  
				break;
			case 2:  //Display product
				cout << "Please enter the product SKU: ";
				cin >> sku_ip;
				cout << endl;

				skuptr_ip = find(sku_ip);

				if (skuptr_ip != nullptr) {
					skuptr_ip->write(cout, write_human);
					cout << endl;
				}
				else {
					cout << "No such product!" << endl;
				}
				cin.ignore(2000, '\n');
				pause();
				break;
			case 3:  //Add non-perishable product
				addProduct('N');
				break;
			case 4:  //Add perishable product
				addProduct('P');
				break;
			case 5:  //Add to quantity of purchased products
				cout << "Please enter the product SKU: ";
				cin >> sku_ip;
				cout << endl;
				skuptr_ip = find(sku_ip);

				if (skuptr_ip != nullptr) {
					addQty(skuptr_ip);
					cout << endl;
				}
				else {
					cout << "No such product!" << endl << endl;
				}				
				break;
			case 6:  //Delete product [optional]
				cout << "~~~Invalid selection, try again!~~~" << endl;
				break;
			case 7:  //Sort products [optional]
				cout << "~~~Invalid selection, try again!~~~" << endl;
				break;
			case 0:  //Exit program
				cout << "Goodbye!" << endl;
				flag = 0;	  //terminates
				break;
			default:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();				
			}			
		}
		return 0;		
	}
}
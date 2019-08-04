// TODO: include the necessary headers
#include "CellPhone.h"
#include <iostream>

using namespace std;

// TODO: the sict namespace
namespace sict
{
	// TODO: definition for display(...) 
	void display(const CellPhone &phone)
	{
		cout << "Phone " << phone.m_model << " costs $"
			<< phone.m_price << "!" << endl;
	}
	
	//To find the cheapest cellphone
	void display(const CellPhone phone[], int num_arr)
	{
		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;

		int i;
		for (i = 0; i < num_arr; i++)
		{
			cout << i+1 << ". " << "Phone " << phone[i].m_model << " costs $" << phone[i].m_price << "!" << endl;
		}
		cout << "------------------------------" << endl;

		int j;
		float min = phone[0].m_price;
		for (j = 0; j < num_arr; j++)
		{
			if (min > phone[j].m_price)
			{
				min = phone[j].m_price;
			}
		}
		cout << "The cheapest phone costs $" << min << "." << endl;
		cout << "------------------------------" << endl;
	}

}
	
    

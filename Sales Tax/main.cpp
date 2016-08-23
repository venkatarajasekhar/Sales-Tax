//#include<iostream>
//using namespace std;

#include"Receipt.h"

/* DEMO PROJECT

	Input 1:
	1 book at 12.49
	1 music CD at 14.99
	1 chocolate bar at 0.85

	Input 2 :
	1 imported box of chocolates at 10.00
	1 imported bottle of perfume at 47.50

	Input 3 :
	1 imported bottle of perfume at 27.99
	1 bottle of perfume at 18.99
	1 packet of headache pills at 9.75
	1 box of imported chocolates at 11.25

	--------------------------------------
	
	Output 1:
	1 book : 12.49
	1 music CD : 16.49
	1 chocolate bar : 0.85
	Sales Taxes : 1.50
	Total : 29.83

	Output 2 :
	1 imported box of chocolates : 10.50
	1 imported bottle of perfume : 54.65
	Sales Taxes : 7.65
	Total : 65.15

	Output 3 :
	1 imported bottle of perfume : 32.19
	1 bottle of perfume : 20.89
	1 packet of headache pills : 9.75
	1 imported box of chocolates : 11.85
	Sales Taxes : 6.70
	Total : 74.68

*/


int main()
{
	Receipt* receipts = new Receipt[3];
	Receipt::ShowItemsWithTax(true);

	receipts[0].Add_Item("A Book", 12.49f, false, TaxExemption::Exempt, TaxExemption::Exempt);
	receipts[0].Add_Item("A Music CD", 14.99f, false, TaxExemption::Exempt, TaxExemption::NonExempt);
	receipts[0].Add_Item("Chocolate Bar", 0.85f, false, TaxExemption::Exempt, TaxExemption::Exempt);
	receipts[0].Print();

	receipts[1].Add_Item("Imported Box of Chocolate", 10.00f, true, TaxExemption::NonExempt, TaxExemption::Exempt);
	receipts[1].Add_Item("Imported Bottle of Perfume", 47.50f, true, TaxExemption::NonExempt, TaxExemption::NonExempt);
	receipts[1].Print();

	receipts[2].Add_Item("Imported Bottle of Perfume", 27.99, true, TaxExemption::NonExempt, TaxExemption::NonExempt);
	receipts[2].Add_Item("1 bottle of perfume", 18.99, false, TaxExemption::Exempt, TaxExemption::NonExempt);
	receipts[2].Add_Item("1 Packet of Headache Pills", 9.75f, false, TaxExemption::Exempt, TaxExemption::Exempt);
	receipts[2].Add_Item("1 Box of Imported Chocolate", 11.25f, true, TaxExemption::NonExempt, TaxExemption::Exempt);
	receipts[2].Print();

	system("PAUSE");
	return 0;
}
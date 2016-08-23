#include "Receipt.h"

int Receipt::ID = 100;
bool Receipt::bShowItemWithTax = true;

int Receipt::Add_Item(string itemName, float basePrice, bool imported, TaxExemption import, TaxExemption sales) // returns the ID of the item.
{
	Item newItem = Item(itemName, basePrice, imported, import, sales);

	items.push_back(newItem);

	return newItem.GetId();
}

void Receipt::Remove_Item(int id) // To add later...
{
	for (list<Item>::iterator i = items.begin(); i != items.end(); i++)
	{
		if (i->GetId() == id)
			items.erase(i);
	}
}

float Receipt::GetSalesTax()
{
	float tax = 0.0f;

	for (list<Item>::iterator i = items.begin(); i != items.end(); i++)
	{
		tax += i->GetItemSalesTax();
	}

	return tax;
}

float Receipt::GetImportTax()
{
	float tax = 0.0f;

	for (list<Item>::iterator i = items.begin(); i != items.end(); i++)
	{
		tax += i->GetItemImportTax();
	}

	return tax;
}

float Receipt::GetSubTotal()
{
	float subTotal = 0.0f;

	for (list<Item>::iterator i = items.begin(); i != items.end(); i++)
	{
		subTotal += i->GetItemValue();
	}

	return subTotal;
}

void Receipt::Print()
{
	int n = 1;
	cout << "Receipt No: " << id << endl;
	for (list<Item>::iterator i = items.begin(); i != items.end(); i++)
	{
		if(bShowItemWithTax)
			cout << n << ") " << i->GetItemName() << " : " << std::fixed << setprecision(2) << i->GetValueWithTax() << endl;
		else
			cout << n << ") " << i->GetItemName() << " : " << std::fixed << setprecision(2) << i->GetItemValue() << endl;

		n++;
	}

	if(bShowItemWithTax)
		cout << "\tSubtotal: " << std::fixed << setprecision(2) << GetSubTotal() << endl;
	cout << "\tSales Tax: " << std::fixed << setprecision(2) << GetSalesTax() << endl;
	cout << "\tImport Tax: " << std::fixed << setprecision(2) << GetImportTax() << endl;
	cout << "\tTotal: " << std::fixed << setprecision(2) << GetTotal() << endl;

	cout << "End of Receipt" << endl << endl;
}

Receipt::Receipt()
{
	id = ID++;
}

Receipt::~Receipt()
{
}

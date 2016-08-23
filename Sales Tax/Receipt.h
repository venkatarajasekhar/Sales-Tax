#pragma once
#include<iostream>
#include<iomanip>
#include<list>
using namespace std;

#include"Item.h"

class Receipt
{
private:
	list<Item> items;
	int id;
	static int ID;
	static bool bShowItemWithTax;
public:
	static void ShowItemsWithTax(bool value) { bShowItemWithTax = value; }

	void Add_Item(Item item) { items.push_back(item); }
	int Add_Item(string itemName, float basePrice, bool imported, TaxExemption import, TaxExemption sales);
	void Remove_Item(int id);
	float GetSalesTax();
	float GetImportTax();
	float GetSubTotal();
	float GetTotal() { return GetSalesTax() + GetImportTax() + GetSubTotal(); }

	void Print();

	Receipt();
	~Receipt();
};


#pragma once

#include<string>
using namespace std;

enum TaxExemption
{
	Exempt,
	NonExempt
};

class Item
{
	int id;
	static int ID;

	double value;
	string name;

	bool bImported;
	TaxExemption SalesTaxStatus;
	TaxExemption ImportTaxStatus; // if items could be import tax exempt in the future...
	
	static double ImportTax;
	static double SalesTax;
public:
	void IsImported(bool value) { bImported = value; }
	void SalesTaxExemption(TaxExemption status) { SalesTaxStatus = status; }
	void ImportTaxExemption(TaxExemption status) { ImportTaxStatus = status; }

	void SetItemName(string name) { this->name = name; }
	void SetItemValue(float value) { this->value = value; }
	
	string GetItemName() { return name; }
	float GetItemValue() { return value; }
	float GetItemSalesTax();
	float GetItemImportTax();
	float GetValueWithTax() { return value + GetItemSalesTax() + GetItemImportTax(); }

	int GetId() { return id; }

	Item();
	Item(string itemName, float basePrice, bool imported, TaxExemption Import, TaxExemption Sales);
	~Item();
};


#include "Item.h"

int Item::ID = 10000;
double Item::ImportTax = 0.05; // 5%
double Item::SalesTax = 0.10; // 10%

float Item::GetItemSalesTax()
{
	if (this->SalesTaxStatus == TaxExemption::Exempt)
		return 0.0f;
	else
		return this->value * SalesTax;
}

float Item::GetItemImportTax()
{
	if (this->ImportTaxStatus == TaxExemption::Exempt)
		return 0.0f;
	else
		return this->value * ImportTax;
}

Item::Item()
{
	this->id = ID++;
	this->bImported = false;
	this->ImportTaxStatus = TaxExemption::NonExempt;
	this->SalesTaxStatus = TaxExemption::NonExempt;
	this->name = "Item";
	this->value = -1.00f;
}

Item::Item(string itemName, float basePrice, bool imported, TaxExemption import, TaxExemption sales)
{
	this->name = itemName;
	this->value = basePrice;
	this->bImported = imported;
	this->ImportTaxStatus = import;
	this->SalesTaxStatus = sales;
}


Item::~Item()
{
}

cd C : \Users\ds902\Documents\Projects\C++\Sales Tax
git remote add origin https ://david-sullivan@bitbucket.org/david-sullivan/sales-tax-example.git
git push - u origin --all # pushes up the repo and its refs for the first time
git push origin --tags # pushes up any tags
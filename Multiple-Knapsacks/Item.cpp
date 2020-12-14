#include "Item.h"

Item::Item(float value, float weight)
{
	this->value = value;
	this->weight = weight;
	relativeBenefit = value / weight;
}

bool Item::operator<(Item &other)
{
	return this->relativeBenefit > other.relativeBenefit;
}

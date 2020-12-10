#include "Item.h"

Item::Item(float value, float weight)
{
	this->value = value;
	this->weight = weight;
	relativeBenefit = value / weight;
}

#pragma once
#include <iostream>
#include "Item.h"
#include <vector>
class Knapsack
{
public:
	float weight, maxWeight, value;
	std::vector<Item> inventory;
	Knapsack(float maxWeight);
	void Remove(int index);
	void Add(Item item);
	void Rotate(int index, Item& item);
	void Print();
};


#include "Knapsack.h"
Knapsack::Knapsack(float maxWeight)
{
	this->maxWeight = maxWeight;
	weight = 0;
	value = 0;
}

void Knapsack::Remove(int index)
{
	if (index >= inventory.size())
	{
		std::cout << "WARNING: INDEX OUT OF BOUNDS";
		return;
	}
	else 
	{
		weight -= inventory[index].weight;
		value -= inventory[index].value;
		inventory.erase(inventory.begin() + index);
	}
}

void Knapsack::Add(Item item)
{
	inventory.push_back(item);
	weight += item.weight;
	value += item.value;
}

void Knapsack::Rotate(int index, Item& item)
{
	weight -= inventory[index].weight;
	value -= inventory[index].value;

	Item tempItem = inventory[index];
	inventory[index] = item;
	item = tempItem;

	weight += inventory[index].weight;
	value += inventory[index].value;
}

void Knapsack::Print()
{
	std::cout << "Printing knapsack...\n";
	std::cout << "Weight: " << this->weight << std::endl;
	std::cout << "Maxweight: " << this->maxWeight << std::endl;
	std::cout << "Value: " << this->value << std::endl;


	for (int i = 0; i < inventory.size(); i++)
	{
		std::cout << "Item " << i << " p" << inventory[i].value << " w" << inventory[i].weight << std::endl;
	}
	std::cout << std::endl;
}

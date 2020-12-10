#include <iostream>
#include <vector>
#include <limits>
#include "Knapsack.h"

int GreedySolution()
{

}

int InitializeFloor(Knapsack &floor)
{
    floor.inventory.push_back(CreateItem(2, 3));
}

Item CreateItem(float value, float weight)
{
    Item result(value, weight);
    return result;
}

int InitializeKnapsacks(std::vector<Knapsack> &knapsacks)
{
    Knapsack knapsack1(10);
    Knapsack knapsack2(15);
    Knapsack knapsack3(20);

    knapsacks.push_back(knapsack1);
    knapsacks.push_back(knapsack2);
    knapsacks.push_back(knapsack3);
}

int main()
{
    Knapsack floor(std::numeric_limits<float>::max());
    std::vector<Knapsack> knapsacks;
}
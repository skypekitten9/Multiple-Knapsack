#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <random>
#include "Knapsack.h"

void GreedySolution(Knapsack &floor, std::vector<Knapsack> &knapsacks)
{
    std::sort(floor.inventory.begin(), floor.inventory.end());
    int tries = 0;
    while (floor.inventory.size() > 0)
    {
        for (int j = 0; j < knapsacks.size(); j++)
        {
            if (knapsacks[j].weight + floor.inventory[0].weight <= knapsacks[j].maxWeight)
            {
                knapsacks[j].Add(floor.inventory[0]);
                floor.Remove(0);
                tries = 0;
            }
            else
            {
                tries++;
            }
        }
        if (tries >= knapsacks.size()) break;
    }
}

Item CreateItem(float value, float weight)
{
    Item result(value, weight);
    return result;
}

void InitializeFloor(Knapsack &floor, int amount, int maxWeight, int maxValue)
{
    for (int i = 0; i < amount; i++)
    {
        floor.Add(CreateItem(rand() % maxValue + 1, rand() % maxWeight + 1));
    }
}

void InitializeFloor(Knapsack& floor)
{
    floor.Add(CreateItem(2, 3));
    floor.Add(CreateItem(4, 1));
    floor.Add(CreateItem(8, 10));
    floor.Add(CreateItem(3, 5));
    floor.Add(CreateItem(1, 1));
    floor.Add(CreateItem(2, 5));
    floor.Add(CreateItem(3, 1));
    floor.Add(CreateItem(6, 5));
    floor.Add(CreateItem(2, 4));
    floor.Add(CreateItem(3, 2));
    floor.Add(CreateItem(2, 7));
    floor.Add(CreateItem(9, 5));
    floor.Add(CreateItem(1, 8));
    floor.Add(CreateItem(3, 3));
    floor.Add(CreateItem(2, 11));
    floor.Add(CreateItem(5, 4));
}



void InitializeKnapsacks(std::vector<Knapsack> &knapsacks, int size1, int size2, int size3)
{
    Knapsack knapsack1(size1);
    Knapsack knapsack2(size2);
    Knapsack knapsack3(size3);

    knapsacks.push_back(knapsack1);
    knapsacks.push_back(knapsack2);
    knapsacks.push_back(knapsack3);
}

float Evaluate(std::vector<Knapsack>& knapsacks)
{
    float result = 0;
    for (int i = 0; i < knapsacks.size(); i++)
    {
        result += knapsacks[i].value / knapsacks[i].weight;
    }
    return result;
}

float Value(std::vector<Knapsack>& knapsacks)
{
    float result = 0;
    for (int i = 0; i < knapsacks.size(); i++)
    {
        result += knapsacks[i].value;
    }
    return result;
}

void UpdateKnapsacks(std::vector<Knapsack>& knapsacks)
{
    for (int i = 0; i < knapsacks.size(); i++)
    {
        knapsacks[i].Update();
    }
}

void Print(Knapsack& floor, std::vector<Knapsack>& knapsacks)
{
    std::cout << "Printing floor then knapsacks...\tRelative Benefit = " << Evaluate(knapsacks) << "\tTotal Value: " << Value(knapsacks) << std::endl;
    floor.Print();
    for (int i = 0; i < knapsacks.size(); i++)
    {
        std::cout << "Printing knapsack " << i << std::endl;
        knapsacks[i].Print();
    }
    std::cout << "-----------------------------------------------------------" << std::endl;
}



bool NeighbourhoodOrganize(Knapsack& floor, std::vector<Knapsack>& knapsacks, int &currentKnapsack)
{
    float currentEval = Evaluate(knapsacks);
    bool localMax = true;
    int bestI = 0;
    int bestJ = 0;
    int bestK = 0;
    for (int i = 0; i < knapsacks[currentKnapsack].inventory.size(); i++)
    {
        for (int j = 0; j < knapsacks.size(); j++)
        {
            if (j == currentKnapsack) continue;
            for (int k = 0; k < knapsacks[j].inventory.size(); k++)
            {
                knapsacks[currentKnapsack].Rotate(i, knapsacks[j].inventory[k]);
                UpdateKnapsacks(knapsacks);
                if (Evaluate(knapsacks) > currentEval)
                {
                    localMax = false;
                    currentEval = Evaluate(knapsacks);
                    bestI = i;
                    bestJ = j;
                    bestK = k;
                }
                knapsacks[currentKnapsack].Rotate(i, knapsacks[j].inventory[k]);
                UpdateKnapsacks(knapsacks);
            }
        }
    }

    if (!localMax)
    {
        knapsacks[currentKnapsack].Rotate(bestI, knapsacks[bestJ].inventory[bestK]);
        currentKnapsack = bestJ;
        return false;
    }
    else
    {
        return true;
    }
    
}

void NeighbourhoodAdd(Knapsack& floor, std::vector<Knapsack>& knapsacks)
{
    for (int i = 0; i < floor.inventory.size(); i++)
    {

    }
}

int main()
{
    //Step 0
    std::cout << "Step 0, creating greedy solution...\n";
    Knapsack floor(std::numeric_limits<float>::max());
    std::vector<Knapsack> knapsacks;
    InitializeKnapsacks(knapsacks, 10, 15, 20);
    InitializeFloor(floor, 20, 15, 15);
    GreedySolution(floor, knapsacks);
    Print(floor, knapsacks);

    //Step 1-3
    std::cout << "Step 1-3, nighbourhood heuristics...\n";
    int t = 100;
    int currentKnapsack = 0;
    for (int i = 0; i < t; i++)
    {
        if (NeighbourhoodOrganize(floor, knapsacks, currentKnapsack)) break;
    }
    Print(floor, knapsacks);
}


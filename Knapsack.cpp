/*
Solution to simple Knapsack problem.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Items
{
  int weight;
  int profit;
  float weight_to_profit;
};

bool sortFunction(Items a, Items b)
{
  return a.weight_to_profit > b.weight_to_profit;
}

int main()
{

  int knapsack_bag_size = 15;
  int weights_array[] = {2, 3, 5, 7, 1, 4, 1};
  int profit_array[] = {10, 5, 15, 7, 6, 18, 3};
  int size = sizeof(weights_array) / sizeof(int);

  vector<Items> items(size);

  for (int i = 0; i < size; i++)
  {
    Items item;
    item.weight = weights_array[i];
    item.profit = profit_array[i];
    item.weight_to_profit = profit_array[i] / (float)weights_array[i];

    items.push_back(item);
  }

  //This function is to sort the Items on basis of (profit / weight).
  sort(items.begin(), items.end(), sortFunction);

  float final_profit = 0;
  vector<Items> bag;

  while (knapsack_bag_size != 0)
  {
    Items item = items[0];
    items.erase(items.begin());
    bag.push_back(item);

    if (knapsack_bag_size > item.weight)
    {
      final_profit += item.weight * item.weight_to_profit;
      knapsack_bag_size = knapsack_bag_size - item.weight;
    }
    else
    {
      final_profit += knapsack_bag_size * item.weight_to_profit;
      knapsack_bag_size = 0;
    }
  }

  cout << final_profit << endl;
  cout << bag.size();
  return 0;
}
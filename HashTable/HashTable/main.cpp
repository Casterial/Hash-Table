#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "hash.h"

int start_s = clock();
int main(int argc, char** argv)
{
	

	//class hash is set to Hashy
	hash Hashy;
	std::string name = "";
	
	/*===========================================
	The code below is for user input.
	std::string name;
	std::string drink;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Please insert your name and your favorite drink (10 needed)" << std::endl;
		std::cin >> name;
		std::cin >> drink;
		Hashy.AddItem(name, drink);
	}
	===========================================*/


	//Hash Table is taking in two items, name and drink.
	//Hashy.AddItem("Name", "Drink");
	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

	Hashy.PrintTable();
	/*Search function
	while (name != "exit")
	{
		std::cout << "Search for ";
		std::cin >> name;
		if (name != "exit")
		{
			Hashy.FindDrink(name);
		}
	}
	*/
	//Remove function
	while (name != "exit")
	{
		std::cout << "Remove item ";
		std::cin >> name;
		if (name != "exit")
		{
			Hashy.RemoveItem(name);
		}
	}

	Hashy.PrintTable();
	//Hashy.RemoveInIndex(#);searches an index
	


	//this calculates execution time
	int stop_s = clock();
	std::cout << "Execution Time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << std::endl;
	//system("pause");
	std::cout << "Press [Enter] to exit the Terminal." << std::endl;
	std::cin.get();
	return 0;
}
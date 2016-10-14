#include <cstdlib>
#include <iostream>
#include <string>

#ifndef HASH_H
#define HASH_H

class hash
{
public:
	hash();
	int Hash(std::string key);
	void AddItem(std::string name, std::string drink);
	int NumberOfITemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIdex(int index);
	void FindDrink(std::string name);
	void RemoveItem(std::string name);
	

private:
	
	const static int tableSize = 4;
	//creating the items for the table. 
	struct item
	{
		std::string name;
		std::string drink;
		item* next;
	};
	item* HashTable[tableSize];

};

#endif
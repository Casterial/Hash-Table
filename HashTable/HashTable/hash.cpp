#include "hash.h"

//hash fn itself, HashTable[i] is a new item that takes in two other strings, the third takes in NO VALUE; NULL
hash::hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}
//Creating AddItem, AddItem takes in two strings, name and drink for the hash table.
//Another example would be a dictionary Name and Phone #.
void hash::AddItem(std::string name, std::string drink)
{
	int index = Hash(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	//Item is being pointed to the HashTable index
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = drink;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int hash::NumberOfITemsInIndex(int index)
{
	//NumberOfItemsInIndex is declared here, which is hashing an empty table
	//next CAN NOT be NULL. This declaration also has count included for index #
	int count = 0;

	if (HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

int StringSize(std::string key)
{
	int TEST = key.size();

	return TEST;
}
//creating the print fuction to print the table. 
//Creates a break between each table, tells the user index and # of items.
void hash::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfITemsInIndex(i);
		std::cout << "-------------------\n";
		std::cout << "index = " << i << std::endl;
		std::cout << HashTable[i]->name << std::endl;

		std::cout << HashTable[i]->drink << std::endl;
		std::cout << "# of items = " << number << std::endl;
		std::cout << "-------------------\n";
	}
}

void hash::PrintItemsInIdex(int index)
{
	item* Ptr = HashTable[index];

	if (Ptr->name == "empty")
	{
		std::cout << "Index = " << index << " is empty";
	}
	else
	{
		std::cout << "index " << index << " contains the following\n";

		while (Ptr != NULL)
		{
			std::cout << "-------------------\n";
			std::cout << Ptr->name << std::endl;
			std::cout << Ptr->drink << std::endl;
			std::cout << "-------------------\n";
			Ptr = Ptr->next;
		}
	}
}

//making the length of the hash table and creating the index.
int hash::Hash(std::string key)
{
	int hash = 0;
	int index;

	
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) * 17;
	}

	index = hash % tableSize;



	return index;
}

void hash::RemoveItem(std::string name)
{
	int index = Hash(name);


	item* delPtr;
	item* P1;
	item* P2;

	// Case 0 - bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		std::cout << name << " was not found in the Hash Table\n";
	}
	// Case 1 - only 1 item contained in bucket and that item has matching name;
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		std::cout << name << " Was removed from the Hash Table\n";
	}
	
	// Case 2 - Match is located in first item in the bucketbut are more items
	// in bucket
	else if (HashTable[index]->name == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		std::cout << name << " was removed from the Hash Table\n";
	}
	// Case 3 - bucket contains items but first item is not a match;
	else
	{
		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while (P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
		}
		//Case 3.1 - No match;
		if (P1 == NULL)
		{
			std::cout << name << " was not found in the Hash Table\n";
		}
		//Case 3.2 - match is found;
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;
			std::cout << name << " was removed from the Hash Table\n";
		}
	}
}

void hash::FindDrink(std::string name)
{
	int index = Hash(name);
	bool foundName = false;
	std::string drink;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true)
	{
		std::cout << "Favorite drink = " << drink << std::endl;
	}
	else
	{
		std::cout << name << "'s info was not found in the Hash Table\n";
	}
}
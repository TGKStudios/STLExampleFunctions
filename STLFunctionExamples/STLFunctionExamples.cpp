#include <iostream>
#include <algorithm>
#include<vector>
#include<functional>
#include <numeric>
#include <cstdlib> 
//---------------------------------------------STL FUNCTION EXAMPLES-------------------------------------------//
class vecMajor
{
public:
	vecMajor() :head(0), tail(0)// Header and pointer in case they are needed for the vector, in the future.
	{}

	void resizeVec()//Function to set size of vector.
	{
		nums.resize(11);
	}

	void countNums(int number)//Function to count when a certain number appears, and shows how many times it has.
	{
		std::cout << "Your Number: " << number << " appeared: ";
		std::cout << (std::count(nums.begin(), nums.end(), number)) << " times.\n";
	}//STL COUNT function does all the work!

	void accumNums(int accumulater)//STL ACCUMULATE function to add each number, then add that to the accumulater value.
	{
		std::cout << std::accumulate(nums.begin(), nums.end(), accumulater);
	}

	void getAdjacentDiff()//Uses STL ADJACENT_DIFFERENCE to get the numeric difference between a value and it's neighbor in the vector.
	{
		std::vector<int> differences(nums.size());
		std::adjacent_difference(nums.begin(), nums.end(), differences.begin());//Puts the difference in a new vector called differences
		for (std::vector<int>::iterator it = differences.begin(); it != differences.end(); it++)//iterator is created to go through the array, you'd get an error without this.
		{
			std::cout << *it << "\n";
		}
	}

	void searchVec(int numToFind)//Uses BINARY_SEARCH to return if a number is found, only returns true or false.
	{
		std::binary_search(nums.begin(), nums.end(), numToFind);
		if (1) { std::cout << "Number exists"; } // if true, return that it exists.
		else { std::cout << "Number does not exist"; }//otherwise, show false.
	}

	void sortVec()//Sorts the vector, short and simple!
	{
		std::sort(nums.begin(), nums.end());
	}

	void eraseRemove(int val)//Erase Remove Idiom, wrapped in a function that just takes a value to remove. This erases all occurences, and moves everything over, to prevent gaps
	{
		nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end()); std::cout << "All occurences of " << val << " have been erased.";
	}

	const std::vector<int> getvector() { return nums; }//Simple get vector, as the vector is private.

	void fillVec()//Fills with preset variables. A simple cin could also be used to get user input.
	{
		nums.push_back(20);
		nums.push_back(40);
		nums.push_back(10);
		nums.push_back(30);
		nums.push_back(5);
		nums.push_back(10);
		nums.push_back(6);
		nums.push_back(7);
		nums.push_back(20);
		nums.push_back(30);
		nums.push_back(9);
	}

private://Private variables, can't be accessed from the outside, will need a getter or setter.
	std::vector<int> nums;
	int head, tail;
};

template<typename T>//Template Function! When called, can take any input, be it string or int, or float, or double! 
T requestInput()
{
	//This can be used for each function we want to call, as we will not have to use STD::CIN each time and ask the user for input, we can just use this template!
	T num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	return num;
}

void mainMenu(vecMajor vec)//Simple main Menu, takes a class object as a parameter
{
	int menuOption = 0;//switch

	while (true)//Not pretty, but uses to ensure we are always given options after a function call, unless options other than 1-6 are pressed.
	{
		std::cout << "\nEnter an option: \n"
			<< "Count How many Times a Number Appears: 1 \n"
			<< "Add All Numbers: 2 \n"
			<< "Get Difference Between Numbers: 3 \n"
			<< "Search For Number: 4 \n"
			<< "Sort the Vector: 5 \n"
			<< "Erase all Occurences of a number: 6 \n";
		std::cin >> menuOption;

		//Function Calls Below, template function is passed to them, which calls the template and gets input from them.
		switch (menuOption)
		{
		case 1:
			vec.countNums(requestInput<int>());
			break;
		case 2:
			vec.accumNums(requestInput<int>());
			break;
		case 3:
			vec.getAdjacentDiff();
			break;
		case 4:
			vec.searchVec(requestInput<int>());
			break;
		case 5:
			vec.sortVec();
			break;
		case 6:
			vec.eraseRemove(requestInput<int>());
			break;
		default:
			std::cout << "Exiting Program";
			exit(0);
			break;
		}
	}
}

int main()
{
	vecMajor vec;//Vector object of a class.
	vec.fillVec();//Fill it first
	mainMenu(vec);//Pass it to main menu so we can call the functions within the class.
}

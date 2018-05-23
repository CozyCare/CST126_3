// CST1263.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>

//Global Variables for functions
const int MAX = 10000;
std::string words[MAX];
int instances[MAX];
int count = 0;

bool openFile(std::ifstream & inputFile);
void insertWord(std::string inputFile);
int findTop(std::string & word);

int main()
{
	std::ifstream data;
	std::string word;
	
	if (openFile(data))
	{
		while (data >> word)
		{
			insertWord(word);
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << std::setw(14) << std::right << word << " " 
				<< std::left <<  findTop(word) << std::endl << std::endl;
		}
	}
	return 0;
}

bool openFile(std::ifstream & inputFile)
{
	std::string fileName;

	std::cout << "Please enter the input file name, including extension: ";
	std::cin >> fileName;
	std::cout << std::endl;

	inputFile.open(fileName);
	if (inputFile.fail())
	{
		std::cout << "ERROR: Could not open file: " << fileName << std::endl;
		return false;
	}
	else
	{
		std::cout << "Opened file: " << fileName << std::endl <<std::endl;
		return true;
	}
}

void insertWord(std::string inputFile)
{
	for (int i = 0; i < count; i++)
		if (inputFile == words[i])
		{
			instances[i]++;
			return;
		}
	if (count < MAX)
	{
		words[count] = inputFile;
		instances[count] = 1;
		count++;
	}
	
}

int findTop(std::string & word)
{
	int topCount = instances[0];
	int topIndex = 0;

	for (int i = 1; i < count; i++)
		if (instances[i] > topCount)
		{
			topCount = instances[i];
			topIndex = i;
		}
	instances[topIndex] = 0;
	word = words[topIndex];
	return topCount;
}

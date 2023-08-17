#include <iostream>
#include <algorithm>
#include "Repo.h"
#include "Trainee.h"
#include <exception>

using std::endl;
using std::cerr;

Trainee*
Repo::getTrainee(const string_view& email) 
{
	size_t length{ repo.size() };
	size_t index{};
	bool isLocated = false;

	for (size_t i = 0; i < length; i++)
	{
		if (email == repo[i].getEmail())
		{
			index = i;
			isLocated = true;
		}
	}
	if (length == 0 || !isLocated)
		throw std::range_error{ "Estagiario nao encontrado." };

	return &repo[index];
}

int
Repo::getTraineeIndex(const string_view& email) const
{
	size_t length{ repo.size() };
	int index{};
	bool isLocated = false;

	for (int i = 0; i < length; i++)
	{
		if (email == repo[i].getEmail())
		{
			index = i;
			isLocated = true;
		}
	}

	if (length == 0 || !isLocated)
		throw std::range_error{ "Indice de estagiario nao encontrado." };

	return index;
}

bool
Repo::searchTrainee(const string_view& email) const
{
	bool isDetected = false;
	for (const auto& x : repo)
	{
		if (email == x.getEmail())
		{
			isDetected = true;
			break;
		}
	}


	return isDetected;
}

void
Repo::addTrainee(const Trainee& dummy)
{
	repo.push_back(dummy);
}

bool
Repo::removeTrainee(const Trainee& dummy)
{
	do
	{

		try
		{
			int const index = getTraineeIndex(dummy.getEmail());
			repo.erase(repo.begin() + index);
			return true;
		}
		catch (std::range_error rangeEx)
		{
			cerr << "Error: " << rangeEx.what() << endl;
		}
	} while (true);

}
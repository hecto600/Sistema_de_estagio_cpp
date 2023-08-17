#pragma once

#include <string>
#include <vector>
#include "Trainee.h"


using std::string;
using std::vector;

class Repo
{
private:
	vector<Trainee> repo;

public:
	vector<Trainee> getRepo() const { return repo; }
	Trainee* getTrainee(const string_view& email) ;
	int getTraineeIndex(const string_view& email) const;
	bool searchTrainee(const string_view& email) const;
	void addTrainee(const Trainee& dummy);
	bool removeTrainee(const Trainee& dummy);


};


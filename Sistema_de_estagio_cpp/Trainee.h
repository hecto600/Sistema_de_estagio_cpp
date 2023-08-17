#pragma once
#include <string>
#include <iostream>

using std::string;
using std::string_view;

class Trainee
{
private:
	string name;
	string email;
	string password;

public:
	Trainee() = default;
	Trainee(const string& name, const string& email, const string& password);

	string getName() const { return name; }
	string getEmail() const { return email; }
	string getPassword() const { return password; }

	void setName(const string_view& name);
	void setEmail(const string_view& email);
	void setPassword(const string_view& password);
	friend std::ostream& operator <<(std::ostream& strm, const Trainee& trainee);
	string toString() const;

};


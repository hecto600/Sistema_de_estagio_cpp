#include "Trainee.h"
#include <iostream>;
using std::string;
using std::string_view;
using std::endl;


Trainee::Trainee(const string& input_name, const string& input_email, const string& input_pw)
	: name{ input_name }, email{ input_email }, password{ input_pw }
{
}

void
Trainee::setName(const string_view& input_name)
{
	name = input_name;
}

void
Trainee::setEmail(const string_view& input_email)
{
	email = input_email;
}

void
Trainee::setPassword(const string_view& input_password)
{
	password = input_password;
}

std::ostream& operator<<(std::ostream& strm, const Trainee& trainee) {
	return strm
		<< "-------------------------------------" << endl
		<< "\tEstagiario: " << trainee.getName() << endl
		<< "\tEmail: " << trainee.getEmail() << endl
		<< "\tSenha: " << trainee.getPassword() << endl
		<< "-------------------------------------" << endl;
}

string
Trainee::toString() const
{
	string str;
	str.append("\t-------------------------------------\n\tEstagiario: ");
	str.append(getName());
	str.append("\n");
	str.append("\tEmail: ");
	str.append(getEmail());
	str.append("\n");
	str.append("\tSenha: ");
	str.append(getPassword());
	str.append("\n");
	str.append("\t-------------------------------------\n\n");

	return str;

}


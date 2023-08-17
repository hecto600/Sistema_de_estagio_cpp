#pragma once
#include<string>

using std::string;
class NotValidInfo
{
private:
	string error;
public:
	NotValidInfo(const string& my_error);
	string getError()const { return error; }
};


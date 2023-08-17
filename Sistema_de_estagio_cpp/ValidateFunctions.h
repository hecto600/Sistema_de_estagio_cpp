#pragma once
#include "Trainee.h"

using std::string;
using std::string_view;

MenuOptions inputToOptions(const string& op);

TraineeMenuOptions inputToTraineeOptions(const string& op);

bool validateSignUp(const string_view& email);

Trainee* validateLogin(const string_view& email, const string_view& pw, Trainee* user);

ProfileOptions inputToProfileOptions(const string& op);

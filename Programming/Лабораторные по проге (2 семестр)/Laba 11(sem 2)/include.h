#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

void Base() {
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
}
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>

int choose_data(std::string data);
void GenerateData(std::vector<int>& a, int n, int dataType);
void PrintList(std::vector<int> a);
void NameData(int dataType);
#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <fstream>
#include <string>
#include <random>

extern int count_compare;

void selection_sort(std::vector<int>& v);
void bubble_sort(std::vector<int>& v);
void shaker_sort(std::vector<int>& v);
void insertion_sort(std::vector<int>& arr, int n);
void merge_sort(std::vector<int>& arr, int p, int r);
void heap_sort(std::vector<int>& v);
void quick_sort(std::vector<int>& v, int p, int r);
std::vector<int> counting_sort(std::vector<int> v, int k);
void radix_sort(std::vector<int>& v);
void shell_sort(std::vector<int>& v);
void bucket_sort(std::vector<int>& v);
void flash_sort(std::vector<int>& v);
void binary_insertion_sort(std::vector<int>& v);
void command4(std::string algo1,std::string algo2,std::string filename);
int choose_sort(std::string algo);
int choose_data(std::string data);
void command5(std::string algo1, std::string algo2, int input_size, std::string input_order);
std::chrono::milliseconds sort_count(std::vector<int>& v, int sort_type);

#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cmath>
#include <string>
#include <random>

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

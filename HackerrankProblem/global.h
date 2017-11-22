#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;

class GlobalFunctionality
{
public:
    static int AddInSortedArray(int* pArr, int len, int used, int newValue, bool& exists);
};
#include <iostream>
#include <unordered_map>
#include <string> // string, string::getline()
#include <map>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
#include "HackerrankProblem/HackerrankProblems.h"

/*
#if defined(_WIN32)
    #include <windows.h>
#elif defined(__linux__)
    #include <sstream>
    #include <unistd.h>
#elif defined(__APPLE__)
    #include <mach-o/dyld.h>
#endif*/

/*TODO: This is temporary implementation!*/
string GetExecutableDirectory()
{
    //char szPath[512];
    //_NSGetExecutablePath(szPath, 512);
    return "/Users/ZqrTalent/Desktop/Dev/C++/HackerRank/Algorithms/";
}

void HackerrankProblems_RunningMedian();
void HackerrankProblems_Equal();

int main()
{
    cout << "Hello world!" << endl;
    //HackerrankProblems_RunningMedian();
    HackerrankProblems_Equal();
    
/*
    map<string, int> mapTest;
    mapTest.insert(pair<string, int>("One", 1));
    //mapTest.insert(pair<string, int>("One", 1));
    mapTest.insert(pair<string, int>("Two", 1));
    mapTest.find("One")->second = 3;

    unordered_multimap<string, int> mapWords;
    mapWords.emplace("One", 1);
    mapWords.emplace("One", 1);
    mapWords.emplace("Two", 2);

    hash_map<int> hashMap;
    hashMap.find()

    if(mapWords.count("One") > 1)
    {
        mapWords.equal_range("One");
    }

    unordered_map<string,int>::const_iterator iterator = mapWords.find("One");
    while(iterator != mapWords.end())
    {
        std::cout << iterator->first << " is " << iterator->second;
        iterator ++;
    }*/

    // initialize


    return 0;
}

/////////////////////////////////////
//
//  HACKERRANK PROBLEMS
//

void HackerrankProblems_RunningMedian()
{
    // Median problem. [BEGIN]
    fstream fInput;
    fInput.open(GetExecutableDirectory() + "input-running-median.txt", ios_base::in);

    fstream fExactOutput;
    fExactOutput.open(GetExecutableDirectory() + "exact-output-running-median.txt", ios_base::in);

    FindTheRunnigMedian(fInput, fExactOutput);

    if(fInput.is_open())
        fInput.close();
    if(fExactOutput.is_open())
        fExactOutput.close();
    // Median problem. [END]
}

void HackerrankProblems_Equal()
{
    // Median problem. [BEGIN]
    fstream fInput;
    fInput.open(GetExecutableDirectory() + "input-equal.txt", ios_base::in);

    fstream fExactOutput;
    fExactOutput.open(GetExecutableDirectory() + "exact-output-equal.txt", ios_base::in);

    Equal(fInput, fExactOutput);

    if(fInput.is_open())
        fInput.close();
    if(fExactOutput.is_open())
        fExactOutput.close();
    // Median problem. [END]
}
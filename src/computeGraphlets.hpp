#ifndef COMPUTEGRAPHLETS_HPP
#define COMPUTEGRAPHLETS_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>

vector<vector<float> > computeGraphlets(int maxGraphletSize, std::string graphFileName);
vector<vector<float>> approxGraphlets(int maxGraphletSize, const string& blantArgs, const string& filename, int graphSize);
#endif

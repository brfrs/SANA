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

std::vector<std::vector<float> > computeGraphlets(int maxGraphletSize, std::string graphFileName);
std::vector<std::vector<float> > approxGraphlets(int maxGraphletSize, const std::string& blantArgs, const std::string& filename, int graphSize, const std::vector<int>& nodeDegrees);

#endif

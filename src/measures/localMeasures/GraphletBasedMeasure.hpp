#ifndef GRAPHLETBASEDMEASURE_HPP
#define GRAPHLETBASEDMEASURE_HPP
#include "LocalMeasure.hpp"

#include <string>
#include <vector>

class GraphletBasedMeasure: public LocalMeasure
{
public:
    GraphletBasedMeasure(Graph* G1, Graph* G2, const::string& name, 
        int maxGraphletSize, const std::string& args1, const std::string& args2, bool approx): 
        LocalMeasure(G1, G2, name), maxK(maxGraphletSize), blantArgs1(args1), blantArgs2(args2), estimateGraphlet(approx) {}
    
    std::vector<std::vector<float>> getGDV(Graph* g, const std::string& blantArgs) const;

    const int maxK;
    const std::string blantArgs1; 
    const std::string blantArgs2;
    const bool estimateGraphlet;

};


#endif
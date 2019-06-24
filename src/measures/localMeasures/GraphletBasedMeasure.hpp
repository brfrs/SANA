#ifndef GRAPHLETBASEDMEASURE_HPP
#define GRAPHLETBASEDMEASURE_HPP
#include "LocalMeasure.hpp"

#include <string>
#include <vector>

class GraphletBasedMeasure: public LocalMeasure
{
public:
    GraphletBasedMeasure(Graph* G1, Graph* G2, const::string& name, 
        int maxGraphletSize, bool approx): 
        LocalMeasure(G1, G2, name), maxK(maxGraphletSize), estimateGraphlet(approx) {}
    
    std::vector<std::vector<float>> getGDV(Graph* g) const;

    const int maxK;
    const bool estimateGraphlet;

};


#endif

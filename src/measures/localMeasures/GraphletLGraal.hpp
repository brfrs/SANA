#ifndef GRAPHLETLGRAAL_HPP
#define GRAPHLETLGRAAL_HPP
#include "GraphletBasedMeasure.hpp"

class GraphletLGraal: public GraphletBasedMeasure {
public:
    GraphletLGraal(Graph* G1, Graph* G2, int maxGraphletSize, bool approx);
    virtual ~GraphletLGraal();

private:
    void initSimMatrix();
    
    double gdvSim(const vector<float>& gdvG1, const vector<float>& gdvG2);

};

#endif

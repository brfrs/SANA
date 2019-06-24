#ifndef GRAPHLET_HPP
#define GRAPHLET_HPP
#include "GraphletBasedMeasure.hpp"

class Graphlet: public GraphletBasedMeasure {
public:
    Graphlet(Graph* G1, Graph* G2, int maxGraphletSize, bool approx);
    virtual ~Graphlet();

private:
    void initSimMatrix();

    vector<double> getNumbersOfAffectedOrbits();
    vector<double> getOrbitWeights();
    double getOrbitWeightSum();

    const uint NUM_ORBITS = 73;
};

#endif

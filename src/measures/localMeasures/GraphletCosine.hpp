#ifndef GRAPHLETCOSINE_HPP
#define GRAPHLETCOSINE_HPP
#include "GraphletBasedMeasure.hpp"

class GraphletCosine: public GraphletBasedMeasure {
public:
    GraphletCosine(Graph* G1, Graph* G2, int maxGraphletSize, bool approx);
    virtual ~GraphletCosine();

private:
    void initSimMatrix();
    vector<float> reduce(const vector<float>& v);
    double cosineSimilarity(const vector<float>& v1, const vector<float>& v2);
    double dot(const vector<float>& v1, const vector<float>& v2);
    double magnitude(const vector<float>& v);
};

#endif

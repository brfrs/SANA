#ifndef GRAPHLETNORM_HPP
#define GRAPHLETNORM_HPP
#include "GraphletBasedMeasure.hpp"

class GraphletNorm: public GraphletBasedMeasure {
public:
    GraphletNorm(Graph* G1, Graph* G2, int maxGraphletSize, bool approx);
    virtual ~GraphletNorm();

private:
    void initSimMatrix();
    double magnitude(const vector<float>& vector);
    vector<double> NODV(const vector<float>& v);
    double ODVratio(const vector<double>& u, const vector<double>& v, uint i);
    double ODVdiff(const vector<float>& u, const vector<float>& v);
    double ODVsim(const vector<float>& u, const vector<float>& v);
    vector<float> reduce(const vector<float>& v);
    
};

#endif

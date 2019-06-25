#include <vector>
#include <iostream>
#include <cmath>
#include "GraphletLGraal.hpp"
using namespace std;

GraphletLGraal::GraphletLGraal(Graph* G1, Graph* G2, int maxGraphletSize, bool approx) : GraphletBasedMeasure(G1, G2, "graphletlgraal", maxGraphletSize, approx) {
    string fileName = autogenMatricesFolder+G1->getName()+"_"+G2->getName()+"_graphletlgraal.bin";
    loadBinSimMatrix(fileName);
}

GraphletLGraal::~GraphletLGraal() {
}

double GraphletLGraal::gdvSim(const vector<float>& gdvG1, const vector<float>& gdvG2) {
    double total = 0;
    for (uint k = 0; k < gdvG1.size(); k++) {
        double m = max(gdvG1[k],gdvG2[k]);
        if (m > 0) total += min(gdvG1[k],gdvG2[k])/m;
    }
    return total/gdvG1.size();
}

void GraphletLGraal::initSimMatrix() {
    uint n1 = G1->getNumNodes();
    uint n2 = G2->getNumNodes();
    sims = vector<vector<float> > (n1, vector<float> (n2, 0));
    vector<vector<float> > gdvs1 = getGDV(G1);
    vector<vector<float> > gdvs2 = getGDV(G2);

    for (uint i = 0; i < n1; i++) {
        for (uint j = 0; j < n2; j++) {
            sims[i][j] = gdvSim(gdvs1[i], gdvs2[j]);
        }
    }
}

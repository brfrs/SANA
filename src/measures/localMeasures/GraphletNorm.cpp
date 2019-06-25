#include <vector>
#include <iostream>
#include <cmath>
#include "GraphletNorm.hpp"
using namespace std;


GraphletNorm::GraphletNorm(Graph* G1, Graph* G2, int maxGraphletSize, bool approx) : GraphletBasedMeasure(G1, G2, "graphletnorm", maxGraphletSize, approx) {
    string fileName = autogenMatricesFolder+G1->getName()+"_"+G2->getName()+"_graphletnorm.bin";
    loadBinSimMatrix(fileName);
}

GraphletNorm::~GraphletNorm() {
}

//return the magnitude of vector
double GraphletNorm::magnitude(const vector<float>& vector) {
    double res = 0;
    for(uint i = 0; i < vector.size(); ++i) {
        res += vector[i] * static_cast<double>(vector[i]);
    }

    return sqrt(res);
}

//return the unit vector of v
vector<double> GraphletNorm::NODV(const vector<float>& v){
    vector<double> res;
    double mag = magnitude(v);
    if(mag == 0){
        vector<double> empty(v.size());
        return empty;
    }
    for(uint i = 0; i < v.size(); i++){
        res.push_back(v[i] / mag);
    }
    return res;
}

double GraphletNorm::ODVratio(const vector<double>& u, const vector<double>& v, uint i){
    if(u[i] == v[i]) return 1;
    return min(u[i], v[i]) / max(u[i], v[i]);
}

//use RMSD between the ratio vector and a vector of 1's
double GraphletNorm::ODVdiff(const vector<float>& u, const vector<float>& v){
    vector<double> nU = NODV(u);
    vector<double> nV = NODV(v);

    double sum = 0;
    for(uint i = 0; i < v.size(); i++)
    {
        sum += pow(ODVratio(nU, nV, i) - 1, 2);
    }
    return sqrt(sum/v.size());
}

double GraphletNorm::ODVsim(const vector<float>& u, const vector<float>& v){
    return 1 - ODVdiff(u, v);
}

vector<float> GraphletNorm::reduce(const vector<float>& v) {
    vector<float> res(11);
    res[0] = v[0];
    res[1] = v[1];
    res[2] = v[2];
    res[3] = v[4];
    res[4] = v[5];
    res[5] = v[6];
    res[6] = v[7];
    res[7] = v[8];
    res[8] = v[9];
    res[9] = v[10];
    res[10] = v[11];

    return res;
}

static bool shouldReduce = false;

void GraphletNorm::initSimMatrix() {
    uint n1 = G1->getNumNodes();
    uint n2 = G2->getNumNodes();
    sims = vector<vector<float> > (n1, vector<float> (n2, 0));
    vector<vector<float> > gdvs1 = getGDV(G1);
    vector<vector<float> > gdvs2 = getGDV(G2);

    for (uint i = 0; i < n1; i++) {
        for (uint j = 0; j < n2; j++) {


            if (shouldReduce) {
                vector<float> v1 = reduce(gdvs1[i]);
                vector<float> v2 = reduce(gdvs2[j]);

                sims[i][j] = ODVsim(v1, v2);
            } else {
                sims[i][j] = ODVsim(gdvs1[i], gdvs2[j]);
            }
        }
    }
}

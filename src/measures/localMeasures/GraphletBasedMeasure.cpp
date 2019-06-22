#include "GraphletBasedMeasure.hpp"
#include "computeGraphlets.hpp"

std::vector<std::vector<float>> GraphletBasedMeasure::getGDV(Graph* g, const std::string& blantArgs) const
{
    if (estimateGraphlet)
        return g->loadGraphletDegreeVectors(maxK);
    else
        return g->approximateGraphletDegreeVectors(maxK, blantArgs);
}
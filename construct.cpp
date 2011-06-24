#include "pugixml.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
using namespace pugi;

int main(int argc, char** argv) {
    xml_document doc;

    doc.load("<Placer> <Annealer> <SwapConfig> <VPRGridSwapHandler /> </SwapConfig> </Annealer> <CostConfig> <CostCalculators> </CostCalculators> <CostSummaries> </CostSummaries> </CostConfig> </Placer>");

    xml_node placer = doc.select_single_node("//Placer").node();
    if(!placer) {
        cerr << "No <Placer>" << endl;
        exit(-1);
    }
    cout << "Before:" << endl;
    placer.print(cout, "    ");


    xml_document calculator;
    calculator.load("<BBCostCalculator />");
    xml_node calculator_node = calculator.select_single_node("//BBCostCalculator").node();

    xml_node result;
    result = placer.select_single_node("./CostConfig/CostCalculators").node().append_copy(calculator_node);
    if(!result) {
        cerr << "Error inserting copy of calculator" << endl;
        exit(-1);
    }
    result = placer.select_single_node("./CostConfig/CostSummaries").node().append_copy(calculator_node);
    if(!result) {
        cerr << "Error inserting copy of calculator" << endl;
        exit(-1);
    }

    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "After:" << endl;
    placer.print(cout, "    ");

    return 0;
}



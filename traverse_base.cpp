#include "pugixml.hpp"
#include "foreach.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    pugi::xml_document doc;

    if(argc != 3) {
        cerr << "Usage: " << argv[0] << " <xml_path> <xpath_query>" << endl;
        exit(-1);
    }
    if (!doc.load_file(argv[1])) {
        cerr << "Error reading file: " << argv[1] << endl;
        exit(-1);
    }

    // Select nodes via compiled query
    pugi::xpath_query query_remote_tools(argv[2]);
    pugi::xpath_node_set tools = query_remote_tools.evaluate_node_set(doc);

    for(int i = 0; i < tools.size(); i++) {
        pugi::xpath_node const &tool = tools[i];
        tool.node().print(cout);
    }
}

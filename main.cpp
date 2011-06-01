#include "pugixml.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
using namespace pugi;

int main(int argc, char** argv) {
    xml_document doc;

    if(argc != 3) {
        cerr << "Usage: " << argv[0] << " <xml_path> <xpath_query>" << endl;
        exit(-1);
    }
    if (!doc.load_file(argv[1])) {
        cerr << "Error reading file: " << argv[1] << endl;
        exit(-1);
    }

    // Select nodes via compiled query
    xpath_query query_remote_tools(argv[2]);
    xpath_node_set tools = query_remote_tools.evaluate_node_set(doc);

    for(int i = 0; i < tools.size(); i++) {
        xpath_node const &tool = tools[i];
        xml_node const &n = tool.node();
        n.print(cout);
        if(n.attributes_begin() != n.attributes_end()) {
            cout << "  Attributes:" << endl;
            for(xml_attribute_iterator iter = n.attributes_begin(); iter != n.attributes_end(); iter++) {
                cout << "    " << iter->name() << "=\"" << iter->value() << "\"" << endl;
            }
        }
    }
}

# pugixml XPath example #

An program demostrating XPath using pugixml.

Usage: ./traverse_base <xml_path> <xpath_query>

where:

 * `xml_path` is the path to the XML file to parse.
 * `xpath_query` is the XPath query to run.

The output of the program is the combined contents of XML nodes matched by the 
XPath query.

Included XML files:

 * `test.xml` - example generated from Python [lxml example](https://github.com/cfobel/python_lxml) project
 * `books.xml` - example from XPath tutorial at: <http://www.w3develop.com/xpath/xpath_intro.asp.htm>

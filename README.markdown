# pugixml XPath examples #

## XPath query ##

A program demonstrating XPath using pugixml.

Usage: ./main <xml_path> <xpath_query>

where:

 * `xml_path` is the path to the XML file to parse.
 * `xpath_query` is the XPath query to run.

The output of the program is the combined contents of XML nodes matched by the 
XPath query.

Included XML files:

 * `test.xml` - example generated from Python [lxml example](https://github.com/cfobel/python_lxml) project
 * `books.xml` - example from XPath tutorial at: <http://www.w3develop.com/xpath/xpath_intro.asp.htm>

## Node construction ##

A program demonstrating the use of XPath queries, along with node construction.

Usage: ./construct

The output of the program shows the initial XML contents, followed by the
contents after new nodes are added to `Placer/CostConfig/CostCalculators` and
`Placer/CostConfig/CostSummaries` 

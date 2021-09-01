/* apollo
=========================================================================*/
#ifndef _header_xmlparser_
#define _header_xmlparser_

#include <string>
#include <iostream>
#include <memory>
#include "tinyxml2.h"
#include "xml_parser.h" 
#include "map_msg.h"

using namespace std;
using namespace tinyxml2;


void Header_Parse(const XMLElement& xml_node, std::shared_ptr<xml_header> Par_header);

#endif
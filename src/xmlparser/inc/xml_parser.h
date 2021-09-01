#pragma once

#include <string>
#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

class UtilXmlParser {
    public:
    static XMLError QueryStringAttribute(const XMLElement& xml_node, const string& name, string* value);
};
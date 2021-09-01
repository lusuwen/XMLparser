
#include "xml_parser.h" 

XMLError UtilXmlParser::QueryStringAttribute(const XMLElement& xml_node, const string& name, string* value) {
        const char* val = xml_node.Attribute(name.c_str());
        if (val == nullptr) {
            return XML_NO_ATTRIBUTE;
        }
        *value = val;
    return XML_SUCCESS;
}
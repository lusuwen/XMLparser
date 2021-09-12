#include <string>
#include "link_xml_parser.h"


void Link_Parse(const tinyxml2::XMLElement& xml_node, std::shared_ptr<xml_link> Par_link) {
  auto link_node = xml_node.FirstChildElement("link");
  while (link_node) {

    std::cout <<       "link exit" << std::endl;

    // link attributes
    string pre_elementType;
    string pre_elementId;
    string pre_contactPoint;
    string suc_elementType;
    string suc_elementId;
    string suc_contactPoint;

    auto predecessor_node = link_node->FirstChildElement("predecessor");
    while (predecessor_node){

        std::cout <<       "predecessore exit" << std::endl;

        int checker = UtilXmlParser::QueryStringAttribute(*predecessor_node, "elementType", &pre_elementType);
        checker += UtilXmlParser::QueryStringAttribute(*predecessor_node, "elementId", &pre_elementId);
        checker += UtilXmlParser::QueryStringAttribute(*predecessor_node, "contactPoint", &pre_contactPoint);

        Par_link->pre_elementType = pre_elementType;
        Par_link->pre_elementId = pre_elementId;
        Par_link->pre_contactPoint = pre_contactPoint;

        std::cout << "           *******parse road info******" << std::endl;
        std::cout << "road link pre elementtype:" << Par_link->pre_elementType << std::endl;
        std::cout << "road link pre elementid:" << Par_link->pre_elementId << std::endl;
        std::cout << "road link pre contactPoint:" << Par_link->pre_contactPoint << std::endl;

        predecessor_node = predecessor_node->NextSiblingElement("predecessor");
    }

    auto successor_node = link_node->FirstChildElement("successor");
    while (successor_node){
        int checker = UtilXmlParser::QueryStringAttribute(*successor_node, "elementType", &suc_elementType);
        checker += UtilXmlParser::QueryStringAttribute(*successor_node, "elementId", &suc_elementId);
        checker += UtilXmlParser::QueryStringAttribute(*successor_node, "contactPoint", &suc_contactPoint);

        Par_link->suc_elementType = suc_elementType;
        Par_link->suc_elementId = suc_elementId;
        Par_link->suc_contactPoint = suc_contactPoint;

        std::cout << "           *******parse road info******" << std::endl;
        std::cout << "road link suc elementtype:" << Par_link->suc_elementType << std::endl;
        std::cout << "road link suc elementid:" << Par_link->suc_elementId << std::endl;
        std::cout << "road link suc contactPoint:" << Par_link->suc_contactPoint << std::endl;

        successor_node = successor_node->NextSiblingElement("successor");
    }

    link_node = link_node->NextSiblingElement("link");
  }
}
/* apollo
=========================================================================*/
#include <string>
#include "roads_xml_parser.h"
#include "link_xml_parser.h"
#include "planView_xml_parser.h"
#include "lanes_xml_parser.h"
#include "signals_xml_parser.h"


void Road_Parse(const tinyxml2::XMLElement& xml_node, std::shared_ptr<xml_road> Par_road) {
  auto road_node = xml_node.FirstChildElement("road");
  while (road_node) {

    // road attributes
    double plength;
    std::string pid;
    std::string pjunction;

    int checker = road_node->QueryDoubleAttribute("length", &plength);
    checker += UtilXmlParser::QueryStringAttribute(*road_node, "id", &pid);
    checker += UtilXmlParser::QueryStringAttribute(*road_node, "junction", &pjunction);

    Par_road->length = plength;
    Par_road->id = pid;
    Par_road->junction = pjunction;

    std::cout << "*************parse road info***************" << std::endl;
    std::cout << "road length:" << Par_road->length << std::endl;
    std::cout << "road id:" << Par_road->id << std::endl;
    std::cout << "road junction:" << Par_road->junction << std::endl;

    //parse link
    auto P_link = std::make_shared<xml_link>();
    Link_Parse(*road_node, P_link);

    //parse planView
    auto P_planView = std::make_shared<xml_planView>();
    PlanView_Parse(*road_node, P_planView);

    //parse lanes
    auto P_lanes = std::make_shared<xml_lanes>();
    Lanes_Parse(*road_node, P_lanes);

    //parse signals
    auto P_signals = std::make_shared<xml_signals>();
    Signals_Parse(*road_node, P_signals);

    road_node = road_node->NextSiblingElement("road");
  }
}



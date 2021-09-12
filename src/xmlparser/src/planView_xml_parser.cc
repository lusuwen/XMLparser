#include <string>
#include "planView_xml_parser.h"


void PlanView_Parse(const tinyxml2::XMLElement& xml_node, std::shared_ptr<xml_planView> Par_planview) {
  auto planView_node = xml_node.FirstChildElement("planView");
  while (planView_node) {

    std::cout << "           planView_node exit          " << std::endl;

    // geometry attributes
    double geo_s;
    double geo_x;
    double geo_y;
    double geo_hdg;
    double geo_length;

    auto geometry_node = planView_node->FirstChildElement("geometry");
    while (geometry_node){

        std::cout << "               geometry_node exit       " << std::endl;

        int checker = geometry_node->QueryDoubleAttribute("s", &geo_s);
        checker += geometry_node->QueryDoubleAttribute("x", &geo_x);
        checker += geometry_node->QueryDoubleAttribute("y", &geo_y);
        checker += geometry_node->QueryDoubleAttribute("hdg", &geo_hdg);
        checker += geometry_node->QueryDoubleAttribute("length", &geo_length);
       

        Par_planview->geo_s = geo_s;
        Par_planview->geo_x = geo_x;
        Par_planview->geo_y = geo_y;
        Par_planview->geo_hdg = geo_hdg;
        Par_planview->geo_length = geo_length;

        std::cout << "road geo s:" << Par_planview->geo_s << std::endl;
        std::cout << "road geo x:" << Par_planview->geo_x << std::endl;
        std::cout << "road geo y:" << Par_planview->geo_y << std::endl;

        geometry_node = geometry_node->NextSiblingElement("geometry");
    }

    planView_node = planView_node->NextSiblingElement("planView");
  }
}
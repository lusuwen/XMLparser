#include <string>
#include "planView_xml_parser.h"


void Lanes_Parse(const tinyxml2::XMLElement& xml_node, std::shared_ptr<xml_lanes> Par_lanes) {

  auto lanes_node = xml_node.FirstChildElement("lanes");
  while (lanes_node) {
    std::cout << "           lanes_node exit          " << std::endl;

    auto laneSection_node = lanes_node->FirstChildElement("laneSection");
    while (laneSection_node){
      std::cout << "                    laneSection_node exit       " << std::endl;

      auto left_node = laneSection_node->FirstChildElement("left");
      while (left_node){
        std::cout << "                            left_node exit       " << std::endl;

        // geometry attributes
        double lane_id;
        string lane_type;
        double lane_width;

        auto Llane_node = left_node->FirstChildElement("lane");
        while (Llane_node){
          int checker = Llane_node->QueryDoubleAttribute("id", &lane_id);
          checker += UtilXmlParser::QueryStringAttribute(*Llane_node, "type", &lane_type);

          Par_lanes->lane_id = lane_id;
          Par_lanes->lane_type = lane_type;

          auto width_node = Llane_node->FirstChildElement("width");
          while (width_node){
            int checker = width_node->QueryDoubleAttribute("a", &lane_width);
            Par_lanes->lane_width = lane_width;

            width_node = width_node->NextSiblingElement("width");
          }

          Llane_node = Llane_node->NextSiblingElement("lane");

          std::cout << "road left lane id:" << Par_lanes->lane_id << std::endl;
          std::cout << "road left lane type:" << Par_lanes->lane_type << std::endl;
          std::cout << "road left lane width:" << Par_lanes->lane_width << std::endl;
        }

        left_node = left_node->NextSiblingElement("left");
      }


      auto right_node = laneSection_node->FirstChildElement("right");
      while (right_node){
        std::cout << "                            right_node exit       " << std::endl;

        // geometry attributes
        double lane_id;
        string lane_type;
        double lane_width;

        auto Rlane_node = right_node->FirstChildElement("lane");
        while (Rlane_node){
          int checker = Rlane_node->QueryDoubleAttribute("id", &lane_id);
          checker += UtilXmlParser::QueryStringAttribute(*Rlane_node, "type", &lane_type);

          Par_lanes->lane_id = lane_id;
          Par_lanes->lane_type = lane_type;

          auto width_node = Rlane_node->FirstChildElement("width");
          while (width_node){
            int checker = width_node->QueryDoubleAttribute("a", &lane_width);
            Par_lanes->lane_width = lane_width;

            width_node = width_node->NextSiblingElement("width");
          }

          Rlane_node = Rlane_node->NextSiblingElement("lane");

          std::cout << "road right lane id:" << Par_lanes->lane_id << std::endl;
          std::cout << "road right lane type:" << Par_lanes->lane_type << std::endl;
          std::cout << "road right lane width:" << Par_lanes->lane_width << std::endl;
        }

        right_node = right_node->NextSiblingElement("right");
      }

      laneSection_node = laneSection_node->NextSiblingElement("laneSection");
    }

    lanes_node = lanes_node->NextSiblingElement("lanes");
  }
}
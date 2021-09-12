#include <string>
#include "planView_xml_parser.h"


void Signals_Parse(const tinyxml2::XMLElement& xml_node, std::shared_ptr<xml_signals> Par_signals) {

  auto signals_node = xml_node.FirstChildElement("signals");
  while (signals_node) {
    std::cout << "           signals_node exit          " << std::endl;

    auto signal_node = signals_node->FirstChildElement("signal");
    while (signal_node){
      std::cout << "                    laneSection_node exit       " << std::endl;

      double signal_s;
      double signal_t;
      double signal_id;
      string signal_name;
      string signal_dynamic;
      double signal_value;

      int checker = signal_node->QueryDoubleAttribute("s", &signal_s);
      checker += signal_node->QueryDoubleAttribute("t", &signal_t);
      checker += signal_node->QueryDoubleAttribute("id", &signal_id);
      checker += UtilXmlParser::QueryStringAttribute(*signal_node, "name", &signal_name);
      checker += UtilXmlParser::QueryStringAttribute(*signal_node, "dynamic", &signal_dynamic);
      checker += signal_node->QueryDoubleAttribute("value", &signal_value);

      std::cout << "road signal_s:" << Par_signals->signal_s << std::endl;
      std::cout << "road signal_t:" << Par_signals->signal_t << std::endl;
      std::cout << "road signal_id:" << Par_signals->signal_id << std::endl;
      std::cout << "road signal_name:" << Par_signals->signal_name << std::endl;
      std::cout << "road signal_dynamic:" << Par_signals->signal_dynamic << std::endl;
      std::cout << "road signal_value:" << Par_signals->signal_value << std::endl;

      //未解析userdata的数据

      signal_node = signal_node->NextSiblingElement("signal");
    }

    signals_node = signals_node->NextSiblingElement("signals");
  }
}
/* apollo
=========================================================================*/

#include "header_xml_parser.h"


void Header_Parse(const XMLElement& xml_node, std::shared_ptr<xml_header> Par_header) {
  auto header_node = xml_node.FirstChildElement("header");
  if (!header_node) {
    string err_msg = "xml data missing header";
    cout << err_msg << endl;
  }

  string Prev_major;
  string Prev_minor;
  string Pdatabase_name;
  string Pversion;
  string Pdate;
  double Pnorth = 0.0;
  double Psouth = 0.0;
  double Pwest = 0.0;
  double Peast = 0.0;

  int checker = UtilXmlParser::QueryStringAttribute(*header_node, "revMajor", &Prev_major);
  checker += UtilXmlParser::QueryStringAttribute(*header_node, "revMinor", &Prev_minor);
  checker += UtilXmlParser::QueryStringAttribute(*header_node, "name", &Pdatabase_name);
  checker += UtilXmlParser::QueryStringAttribute(*header_node, "version", &Pversion);
  checker += UtilXmlParser::QueryStringAttribute(*header_node, "date", &Pdate);
  checker += header_node->QueryDoubleAttribute("north", &Pnorth);
  checker += header_node->QueryDoubleAttribute("south", &Psouth);
  checker += header_node->QueryDoubleAttribute("east", &Peast);
  checker += header_node->QueryDoubleAttribute("west", &Pwest);


  Par_header->version = Pversion;
  Par_header->date = Pdate;
  Par_header->database_name = Pdatabase_name;
  Par_header->rev_major = Prev_major;
  Par_header->rev_minor = Prev_minor;
  Par_header->west = Pwest;
  Par_header->east = Peast;
  Par_header->north = Pnorth;
  Par_header->south = Psouth;

  cout << "version" << Par_header->version << endl;
  cout << "Pdate" << Par_header->date << endl;
  cout << "Pdatabase_name" << Par_header->database_name << endl;
  cout << "Prev_major" << Par_header->rev_major << endl;
  cout << "Pwest" << Par_header->west << endl;
};



#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "tinyxml2.h"
#include "xml_parser.h" 
#include "map_msg.h"

using namespace std;
using namespace tinyxml2;


void Signals_Parse(const tinyxml2::XMLElement& xml_node, std::shared_ptr<xml_signals> Par_signals);
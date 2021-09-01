#ifndef MAP_MSG_H 
#define MAP_MSG_H

#include <iostream>
#include <stdint.h>

using namespace std;


typedef struct {
  string rev_major;
  string rev_minor;
  string database_name;
  string version;
  string date;
  double north;
  double south;
  double west;
  double east;
} xml_header;


#endif 
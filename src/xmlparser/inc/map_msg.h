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

typedef struct {
  double length;
  string id;
  string junction;
} xml_road;

typedef struct {
  string pre_elementType;
  string pre_elementId;
  string pre_contactPoint;
  string suc_elementType;
  string suc_elementId;
  string suc_contactPoint;
} xml_link;

typedef struct {
  double geo_s;
  double geo_x;
  double geo_y;
  double geo_hdg;
  double geo_length;
} xml_planView;

typedef struct {
  double lane_id;
  string lane_type;
  double lane_width;
} xml_lanes;

typedef struct {
  double signal_s;
  double signal_t;
  double signal_id;
  string signal_name;
  string signal_dynamic;
  double signal_value;
} xml_signals;

#endif 
#!/bin/bash

local_repo=~/Documents/rosbagparser

docker run -d \
    -e DISPLAY=unix$DISPLAY \
    -e ROS_MASTER_URI=http://192.168.0.2:11311 \
    -e ROS_IP=192.168.0.2 \
    -e GDK_SCALE \
    -e GDK_DPI_SCALE \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    -v $local_repo:/home/pilot/repo \
    pilot:v1 
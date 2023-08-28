#!/bin/bash

g++ ./Sandbox/src/SandboxApp.cpp -o test ./Ghost/src/Ghost/Application.cpp ./Ghost/src/Ghost/Log.cpp -I./Ghost/vendor/spdlog/include/ -I./Ghost/src/

./test
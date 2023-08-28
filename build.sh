#!/bin/bash

g++ ./Sandbox/src/SandboxApp.cpp -o test ./Ghost/src/Ghost/Application.cpp -I./Ghost/vendor/spdlog/include/

./test
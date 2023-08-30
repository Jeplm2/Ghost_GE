#!/bin/bash

name="test.out"

preInc="./Ghost/src/gpch.h"

source_files=(
    "./Sandbox/src/SandboxApp.cpp"
    "./Ghost/src/Ghost/Application.cpp"
    "./Ghost/src/Ghost/Log.cpp"
    "./Ghost/src/Platform/WindowsWindow.cpp"
)

includes="-I./Ghost/src/"

GL=(
    "-lGL"
    "-lglfw"
)

g++ -include "$preInc" "${source_files[@]}" -o "$name" "$includes" "${GL[@]}"
./"$name"

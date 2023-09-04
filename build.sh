#!/bin/bash

name="test.out"

preInc="./Ghost/src/gpch.h"

source_files=(
    "./Sandbox/src/SandboxApp.cpp"
    "./Ghost/src/Ghost/Application.cpp"
    "./Ghost/src/Platform/WindowsWindow.cpp"
    "./Ghost/src/Ghost/Layer.cpp"
    "./Ghost/src/Ghost/LayerStack.cpp"
    "./Ghost/vendor/GLAD/src/glad.c"
)

includes=(
    "-I./Ghost/src/"
    "-I./Ghost/vendor/GLAD/include/"
)

GL=(
    "-lGL"
    "-lglfw"
)

time g++ -include "${preInc[@]}" "${source_files[@]}" -o "$name" "${includes[@]}" "${GL[@]}"

./"$name"

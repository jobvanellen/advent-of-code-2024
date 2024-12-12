#!/usr/bin/env bash
# Script to build and run the project if the VS Code CMake extension does not work.
# If it does not run, first call: `chmod +x buildAndRun.sh` in the terminal

SCRIPT_DIR=$(dirname "$0")

# Build
cmake -S $SCRIPT_DIR -B SCRIPT_DIR/build
cmake --build $SCRIPT_DIR/build

# Run
./$SCRIPT_DIR/build/cpp_course
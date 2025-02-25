#!/bin/bash

# Check the first argument
if [ "$1" == "run" ]; then
    echo "Running chess from ./dist..."
    pushd dist > /dev/null
    ./chess
    popd > /dev/null
    exit 0
fi

if [ "$1" == "build-run" ]; then
    echo "Building chess from ./src..."
    if [ ! -d "dist" ]; then
        mkdir dist
    fi
    # Compile and link all .cpp files in the src directory
    g++ -o dist/chess src/*.cpp
    echo "Running chess from ./dist..."
    pushd dist > /dev/null
    ./chess
    popd > /dev/null
    exit 0
fi

if [ "$1" == "build" ]; then
    echo "Building chess from ./src..."
    if [ ! -d "dist" ]; then
        mkdir dist
    fi
    # Compile and link all .cpp files in the src directory
    g++ -o dist/chess src/*.cpp
    exit 0
fi

echo "Invalid argument. Use 'run', 'build-run', or 'build'."
exit 1
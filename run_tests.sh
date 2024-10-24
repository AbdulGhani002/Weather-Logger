#!/bin/bash

echo "Starting tests..."

for test_file in tests/*.cpp; do
    echo "Running $test_file..."
    g++ -o test_executable $test_file
    ./test_executable
    rm test_executable
done

echo "All tests completed."

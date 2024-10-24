#!/bin/bash

echo "Starting the application..."

clang++ -o main ./src/main.cpp -lcurl -lz


./main

echo "Application has finished running."

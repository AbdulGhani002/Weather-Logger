#!/bin/bash

# Run all tests
echo "Running all tests..."
./run_tests.sh

# Install necessary dependencies
echo "Installing dependencies..."
pip install -r requirements.txt

# Build the project
echo "Building the project..."
make build

# Run the application
echo "Running the application..."
./run_application.sh

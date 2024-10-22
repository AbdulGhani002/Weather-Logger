#!/bin/bash

# Run all tests
echo "Running all tests..."
./run_tests.sh

# Create a virtual environment
echo "Creating virtual environment..."
python3 -m venv venv

# Activate the virtual environment
echo "Activating virtual environment..."
source venv/bin/activate

# Install necessary dependencies
echo "Installing dependencies..."
pip install -r requirements.txt

# Deactivate the virtual environment
echo "Deactivating virtual environment..."
deactivate

# Build the project
echo "Building the project..."
make build

# Run the application
echo "Running the application..."
./run_application.sh

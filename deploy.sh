#!/bin/bash

echo "Starting deployment..."
mkdir -p deployed
cp calculator.c calculator.h deployed/
echo "Deployment completed. Files are in the 'deployed' directory."

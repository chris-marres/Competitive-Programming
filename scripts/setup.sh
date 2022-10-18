#!/bin/bash
# This script is used to setup the environment for the project

echo "Enter the name of the project: "
read project_name
mkdir $project_name
cp "/home/chris/Desktop/Competitive Programming/0) Intro/template.cpp" "${project_name}/${project_name}.cpp"
cd $project_name
echo "Project created successfully!"
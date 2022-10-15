g++ -std=c++11 -O2 -Wall "$(basename ${PWD}).cpp" -o "$(basename ${PWD})"
echo "Compiled successfully!"
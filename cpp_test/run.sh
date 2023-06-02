cd build
cmake ..
make -j8
cd ..
echo "-----------"
args="$*"
./build/myexe args
echo "-----------"

#!bin/sh

rm -rf bin
mkdir bin
cd bin

proj_name=App
proj_root_dir=$(pwd)/../

flags=(
    -w -s WASM=1 -s USE_WEBGL2=1 -s ASYNCIFY=1 -O1
)

# Include directories
inc=(
    -I ../third_party/include/           # Gunslinger includes
)

# Source files
src=(
    ../source/*.c
)

libs=(
)

# Build
emcc ${inc[*]} ${src[*]} ${flags[*]} -o $proj_name.html

# TODO: find a better fix for "Module._malloc is not a function" js error
echo -e 'Module["_malloc"] = _malloc;\nModule["_free"] = _free;' >> $proj_name.js

cd ..




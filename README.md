# Gunslinger Project Template

This is a minimum and premade configuration that you need in order to get started with gunslinger. It provides all the necessary dependencies and the bash/batch scripts for compiling it on Windows, Mac and Linux.

You can also check the main **Gunslinger** repository here, where you'll find documentation on how to get started:
[Gunlinger repository](https://github.com/MrFrenik/gunslinger)
 
And you can also find a complete list of examples for you to learn from and test on your machine here: 
[Gunslinger examples](https://github.com/MrFrenik/gs_examples)

## Cloning instructions: 
- Use the following command to clone the repo and init the gunslinger submodule
```bash
git clone --recursive https://github.com/MrFrenik/gs_project_template
```

## Updating GS instructions (updates gunslinger submodule and rebases to main branch): 
```bash
git submodule update --remote --rebase --recursive
```

## Build Instructions:

### Windows
## MSVC:
- From start menu, open `{x86|x64} Native Tools for {VS Version Here}`
- cd to `root dir` where you downloaded project template
- To compile the project, run:
```bash
proc\win\cl.bat
```
- To execute the program, run: 
```bash
bin\App.exe
```
### MINGW:
- From `root dir`, open `git bash`
- To compile, run: 
```bash
bash ./proc/win/mingw.sh
```
- To execute the program, run:
```bash
./bin/App.exe
```

### Linux

## Before Compiling:
- Make sure the following development libraries are installed: 
```bash
sudo apt install git gcc mesa-common-dev libxcursor-dev libxrandr-dev libxinerama-dev libxi-dev
```
- For Mesa and OpenGL, need to export the following: 
```bash
export MESA_GL_VERSION_OVERRIDE=3.3
```
- Credit to https://github.com/Samdal

## GCC:
- Open terminal
- cd to `root dir` where you downloaded project template
- To compile the project, run:
```bash
bash ./proc/linux/gcc.sh
```
- To execute the program, run: 
```bash
./bin/App
```

### OSX
## GCC: 
- Open terminal
- cd to `root dir` where you downloaded project template
- To compile the project, run:
```bash
bash ./proc/osx/gcc.sh
```
- To execute the program, run: 
```bash
./bin/App
```

### HTML5
## Emscripten: 
- Open terminal
- cd to `root dir` where you downloaded project template
- To compile the project, run:
```bash
bash ./proc/osx/emcc.sh
```
- This will generate the appropriate .html, .js, and .wsm files to load in a browser. 

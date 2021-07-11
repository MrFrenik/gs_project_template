# Gunslinger Project Template

This is a minimum and premade configuration that you need in order to get started with gunslinger. It provides all the necessary dependencies and the bash/batch scripts for compiling it on Windows, Mac and Linux.

You can also check the main **Gunslinger** repository here, where you'll find a documentation for you to get started and learn how to use it:
[Gunlinger repository](https://github.com/MrFrenik/gunslinger)
 
And you can also find a complete list of examples for you to learn from and test on your machine here: 
[Gunslinger examples](https://github.com/MrFrenik/gs_examples)

## Cloning instructions: 
- Use the following command to clone the repo and init the gunslinger submodule
```
git clone --recursive https://github.com/MrFrenik/gs_project_template
```

## Updating GS instructions (updates gunslinger submodule and rebases to main branch): 
```
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

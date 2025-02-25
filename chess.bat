@echo off

if "%1"=="run" (
    echo Running ./dist/chess.exe
    pushd dist
    chess.exe
    popd
    goto :EOF
)

if "%1"=="rb" (
    chess.bat build
    chess.bat run
)

if "%1"=="build" (
    echo Building ./src/*.cpp
    if not exist dist (
        mkdir dist
    )
    g++ ./src/*.cpp -o dist/chess.exe 
    goto :EOF
)

echo Invalid argument. Use "run" or "build".

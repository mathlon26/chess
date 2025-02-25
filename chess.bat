@echo off
REM Check the first argument

if "%1"=="run" (
    echo Running chess.exe from .\dist...
    pushd dist
    chess.exe
    popd
    goto :EOF
)

if "%1"=="build-run" (
    echo Building chess.exe from .\src...
    if not exist dist (
        mkdir dist
    )
    REM Compile and link all .cpp files in the src directory
    g++ -o dist/chess.exe src\*.cpp
    echo Running chess.exe from .\dist...
    pushd dist
    chess.exe
    popd
    goto :EOF
)

if "%1"=="build" (
    echo Building chess.exe from .\src...
    if not exist dist (
        mkdir dist
    )
    REM Compile and link all .cpp files in the src directory
    g++ -o dist/chess.exe src\*.cpp
    goto :EOF
)

echo Invalid argument. Use "run" or "build".

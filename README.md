# LeadSorterModul

## Purpose
Build C-program, which converts music file to .wav, looks up a wav-file via ***GNSDK***.
Wrap this for PYTHON (re)tag original files and create hierarchily directory structure.

## Pipeline
    1. convert input to wav (if necessary) - ffmpeg
    2. lookup-request via gnsdk
    3. return result or raise error
        3.1 Perform multiple requests?

## TODO
- update README.md
- wrap it for python (done)
- create directory tree structure 
- implement delete .wav files
- implement is tagged
- implement retag (e.g. eyeD3)
- implement directory structure

## INSTALL (to be updated)
Set in the CMakeLists.txt to your GNSDK home

### Terminal (to be updated)
```
cmake .
make
```
or in CLion

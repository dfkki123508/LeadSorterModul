# LeadSorterModul

## Purpose
Build C-program, which converts music file to .wav, looks up a wav-file via ***GNSDK***.
Wrap this for PYTHON (re)tag original files and create hierarchily directory structure.

## Pipeline
    1. convert input to wav - ffmpeg
    2. lookup-request via gnsdk
    3. return result or raise error
        3.1 Perform multiple requests?
    4. use returned information for retagging
    5. sort track into dir tree (Artist --> Album --> Title)

## TODO
- add INSTALL, TERMINAL, EXAMPLE to README.md
- wrap it for python (done)
- implement is tagged (done)
- implement retag with taglib (done)
- implement directory structure (done)

## INSTALL (to be updated)
Set in the CMakeLists.txt to your GNSDK home

### Terminal (to be updated)
```
cmake .
make
```
or in CLion

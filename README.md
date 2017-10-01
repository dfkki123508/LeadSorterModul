# LeadSorterModul

## Purpose
Build C-program, which converts music file to .wav, looks up a wav-file via ***GNSDK***.
Wrap this for PYTHON (re)tag original files and create hierarchily directory structure.

## Processing Pipeline
    1. Load the mp3-file in python
    2. Call the C function with the mp3-file
        2.1 Decode packets via ffmpeg
        2.2 Lookup raw audio samples via GNSDK
    3. Reset ID3-tags file with result of the lookup
    4. Place file in the right folder

## Dependencies
* FFmpeg libs (avutil,avcodec,avformat,swresample,swscale)
* GNSDK
* unix pkg-config and its python [interface](https://pypi.python.org/pypi/pkgconfig) (use: `pip install pkgconfig` to install)

## Installation
    1. Install the wrapper: 
        1.1 Open file ./wrapper/setup.py and set `gnsdk_dir` variable to your path to the GNSDK home directory
        1.2  


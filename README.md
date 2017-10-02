# LeadSorterModul

Imagine an unsorted music library with unknown or badly named and tagged audio-files. This program should help to bring a whole music-library into the right directory structure and tag each file with the right song information (i.e. artist, album, track-name) set as ID3-tags. The desired directory structure looks as following:
  ```
  ├── <artist>
  │   └── <album>
  │       ├── <track>
  │       └── ...
  ├── <artist>
      ... 
  ```

Therefore we implemented a python command line interface which draws on the [Gracenote Recognition C API](https://developer.gracenote.com/gnsdk) to get track information by its audio sampels and [FFmpeg](https://www.ffmpeg.org/) to decode mp3-files.  

## Processing Pipeline
    1. Load the mp3-file in python
    2. Call the C function with the mp3-file
        2.1 Decode packets via ffmpeg
        2.2 Lookup raw audio samples via GNSDK
    3. Reset ID3-tags file with result of the lookup
    4. Place file in the right folder

## Dependencies
* python (>= 3.5)
* [FFmpeg libs](http://trac.ffmpeg.org/wiki/CompilationGuide/Ubuntu) (avutil,avcodec,avformat,swresample,swscale)
* [GNSDK](https://developer.gracenote.com/gnsdk) libs + Account with license file, client tag and id
* unix pkg-config and its python [interface](https://pypi.python.org/pypi/pkgconfig) (use: `pip install pkgconfig` to install)

## Installation
1. Install the wrapper:     
    1. Open file ./wrapper/setup.py and set `gnsdk_dir` variable to your path to the GNSDK home directory
    2. Type `make`
2. Set client tag, id and license path:
    1. Open ./python/leadSorterCL.py and set the identification (can be retrieved from your gnsdk account)
## Execution
```
python3 leadSorterCL.py [-h] [-m] [-p] [-d DESTINATION] search_path

Sort music files located in SEARCH_PATH. Default copy if not optional MOVE

positional arguments:
  search_path           path to music directory

optional arguments:
  -h, --help            show this help message and exit
  -m, --move            move files: default will copy files
  -p, --print           print info: default won't print extra info
  -d DESTINATION, --destination DESTINATION
                        destination path: path to new sorted directory
```

## Example



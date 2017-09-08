### Purpose
Build a simple C function, which looks up a wav-file via ***GNSDK***, and wrap it for python usage or else.

### Pipeline
    1. convert input to wav (if necessary) - ffmpeg
    2. lookup-request via gnsdk
    3. return result or raise error
        3.1 Perform multiple requests?

### TODO
- wrap it for python
- create directory tree structure

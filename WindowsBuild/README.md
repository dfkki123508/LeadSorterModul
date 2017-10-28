In this directory the compiled c module is included. You can use the setup.py script and type `python setup.py install` to install the module.
In order to enable the runtime linking with the ffmpeg and gnsdk libs, you have to specify the path to the dlls, e.g. 
```set PATH=%PATH%;c:\\LeadSorterModul\\libs\\ffmpeg\\win_x86-64;c:\\LeadSorterModul\\libs\\gnsdk\\win_x86-64;```
in the console you want to execute the python script.
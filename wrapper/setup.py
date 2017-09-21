"""
At first set the gnsdk_dir!!

To install use:
    python3 setup.py install --record files.txt

To remove use:
    rm -rf build
    cat files.txt | xargs rm -f
"""

from distutils.core import setup, Extension
from distutils.command.build_ext import build_ext
import glob
import sysconfig
import pkgconfig

# set to your gnsdk dir
gnsdk_dir = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk'
gnsdk_libs = glob.glob(gnsdk_dir + '/lib/linux_x86-64/*')

extra_compile_args  = []
include_dirs        = []
lib_dirs            = []
libs_static         = []
libs_dynm           = []
linker_flags        = []

include_dirs.append(gnsdk_dir + '/include')
include_dirs.append(gnsdk_dir + '/include/linux_x86-64')
include_dirs.append('/usr/local/include')

lib_dirs.append(gnsdk_dir + '/lib/linux_x86-64')
lib_dirs.append('/usr/local/lib')

libs_dynm += gnsdk_libs

# ffmpeg_libs = ['/usr/local/lib/libavcodec.a','/usr/local/lib/libavformat.a','/usr/local/lib/libavutil.a','/usr/local/lib/libswresample.a','/usr/local/lib/libswscale.a']

# FFmpeg libs
libs_static += ['avutil','avcodec','avformat','swresample','swscale']

# ffmpeg libs flags
linker_flags.append(pkgconfig.libs('libavcodec'))
linker_flags.append(pkgconfig.libs('libavformat'))
linker_flags.append(pkgconfig.libs('libavutil'))
linker_flags.append(pkgconfig.libs('libswresample'))
linker_flags.append(pkgconfig.libs('libswscale'))

# add runtime link directories
for dir in lib_dirs:
    linker_flags.append('-Wl,-rpath,'+dir)


extra_compile_args += sysconfig.get_config_var('CFLAGS').split()
extra_compile_args += ['-fPIC', '-DPIC','-DNDEBUG', '-O3']


print('-- extra compile args:\t', extra_compile_args)
print('-- include dirs:\t', include_dirs)
print('-- lib dirs:\t', lib_dirs)
print('-- static libs :\t', libs_static)
print('-- runtime libs:\t', libs_dynm)
print('-- link flags:\t', linker_flags)


module = Extension('CGnsdkLookup',
                   ['DecodeContainer.c','LookupAudioModule.c', 'LookupAudio.c'],
                   language='c',
                   include_dirs = include_dirs,
                   library_dirs = lib_dirs,
                   libraries = libs_static,
                   # depends = ffmpeg_libs,
                   extra_objects = libs_dynm,
                   runtime_library_dirs = [],
                   extra_compile_args = extra_compile_args,
                   extra_link_args=linker_flags,
                   )
setup(
    name='CGnsdkLookup',
    version='1.0',
    cmdclass={'build_ext': build_ext},
    ext_modules=[module]
)

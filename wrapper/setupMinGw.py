from distutils.core import setup, Extension
from distutils.command.build_ext import build_ext
import glob
import sysconfig
import platform
import os

osys = 'windows'
print("working on {} with compiler {}".format(osys, os.environ["CC"]))
osdir = r'win_x86-64'
statLibExt = 'lib'
dynmLibExt = 'dll'


gnsdk_dir   = os.path.abspath(r"../libs/gnsdk")
gnsdk_libs  = glob.glob(os.path.join(gnsdk_dir, osdir, '*.'+dynmLibExt+'*'))
gnsdk_inc   = os.path.join(gnsdk_dir, 'include')
ffmpeg_dir  = os.path.abspath(r"../libs/ffmpeg")
ffmpeg_libs = glob.glob(os.path.join(ffmpeg_dir, osdir, '*.'+dynmLibExt))
ffmpeg_inc  = os.path.join(ffmpeg_dir, 'include')

extra_compile_args  = []
include_dirs        = []
lib_dirs            = []
# libs_static         = []
# libs_dynm           = []
linker_flags        = []

# HEADER DIRECTORIES
include_dirs.append(gnsdk_inc)
include_dirs.append(os.path.join(gnsdk_inc, osdir))
include_dirs.append(ffmpeg_inc)

# LIB DIRECTORIES
lib_dirs.append(os.path.join(gnsdk_dir,osdir))
lib_dirs.append(os.path.join(ffmpeg_dir,osdir))

# ADD LIBS
if osys.lower() == 'linux' or osys.lower() == 'darwin':
    for dir in lib_dirs:
        # linker_flags.append('-Wl,-rpath,' + dir)
        linker_flags.append('-L' + dir)
# elif osys.lower() == 'windows':
#     from subprocess import call
#     for dir in lib_dirs:
#         linker_flags.append('/LIBPATH:' + dir)
#         call(['set','PATH=%PATH%'+dir])

# EXTRA COMPILATION FLAGS (only gcc)
if osys.lower() == 'linux' or osys.lower() == 'darwin':
    extra_compile_args += sysconfig.get_config_var('CFLAGS').split()
    extra_compile_args += ['-fPIC', '-DPIC','-DNDEBUG', '-O3']


print('-- extra compile args:\t', extra_compile_args)
print('-- include dirs:\t', include_dirs)
print('-- lib dirs:\t', lib_dirs)
print('-- gnsdk libs:\t', gnsdk_libs)
print('-- ffmpeg libs :\t', ffmpeg_libs)
print('-- link flags:\t', linker_flags)


module = Extension('CGnsdkLookup',
                   ['DecodeContainer.c','LookupAudioModule.c', 'LookupAudio.c'],
                   language='c',
                   include_dirs = include_dirs,
                   library_dirs = lib_dirs,
                   libraries = [],
                   # depends = ffmpeg_libs,
                   extra_objects = gnsdk_libs + ffmpeg_libs,
                   runtime_library_dirs = lib_dirs, # only on linux or mac
                   extra_compile_args = extra_compile_args,
                   extra_link_args = linker_flags,
                   )
setup(
    name='CGnsdkLookup',
    version='1.0',
    cmdclass={'build_ext': build_ext},
    ext_modules=[module]
)

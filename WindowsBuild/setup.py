from distutils.core import setup, Extension
from distutils.command.build_ext import build_ext
import glob
import sysconfig
import platform
import os

module = Extension('CGnsdkLookup',
                   [],
                   language='c',
                   )
setup(
    name='CGnsdkLookup',
    version='1.0',
    cmdclass={'build_ext': build_ext},
    ext_modules=[module]
)

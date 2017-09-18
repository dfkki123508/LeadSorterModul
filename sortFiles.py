import sys
import os
import taglib
from shutil import copyfile

#get all files inside dir_path
dir_path = sys.argv[1]
files = [f for f in os.listdir(dir_path) if os.path.isfile(os.path.join(dir_path, f))]

if not os.path.exists(dir_path + 'Unknown'):
    os.makedirs(dir_path+'Unknown')

for file in files:
    song = taglib.File(dir_path+file)

    copy_path = ''

    if 'ARTIST' in song.tags:
        #if song.tags['ARTIST'][0].rfind('feat'):
        #   copy_path = song.tags['ARTIST'][0][:song.tags['ARTIST'][0].rfind('feat')]
        #else:
        copy_path = song.tags['ARTIST'][0]

        if not os.path.exists(dir_path + copy_path):
            os.makedirs(dir_path + copy_path)

        if 'ALBUM' in song.tags:
            copy_path = copy_path + '/' + song.tags['ALBUM'][0]
            if not os.path.exists(dir_path + copy_path):
                os.makedirs(dir_path + copy_path)

        copyfile(dir_path+file, dir_path+copy_path + '/' + file)

    else:
        copyfile(dir_path + file, dir_path + 'Unknown/' + file)

import sys
import os
import taglib
from shutil import copyfile

def findFiles(search_path):
    files = [f for f in os.listdir(search_path) if
            os.path.isfile(os.path.join(search_path, f))]  # get all files inside search_path
    return files

def sortFiles(files, move, dest_path, search_path):
    if not os.path.exists(dest_path + 'Unknown'):
        os.makedirs(dest_path + 'Unknown')  # directory for unsortable files

    for file in files:
        song = taglib.File(search_path + file)

        new_path = ''

        if 'ARTIST' in song.tags:
            # TO-DO: filter featurings
            # if song.tags['ARTIST'][0].rfind('feat'):
            #   new_path = song.tags['ARTIST'][0][:song.tags['ARTIST'][0].rfind('feat')]
            # else:
            new_path = song.tags['ARTIST'][0]

            if not os.path.exists(dest_path + new_path):
                os.makedirs(dest_path + new_path)

            if 'ALBUM' in song.tags:
                new_path = new_path + '/' + song.tags['ALBUM'][0]
                if not os.path.exists(dest_path + new_path):
                    os.makedirs(dest_path + new_path)

            if 'TITLE' in song.tags:
                if os.path.exists(dest_path + new_path + '/' + file):
                    break

            if not move:
                copyfile(search_path + file, dest_path + new_path + '/' + file)
            else:
                os.rename(search_path + file, dest_path + new_path + '/' + file)
        else:
            if not move:
                copyfile(search_path + file, dest_path + 'Unknown/' + file)
            else:
                os.rename(search_path + file, dest_path + 'Unknown/' + file)

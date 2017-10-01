import sys
import os
import taglib
from shutil import copyfile
def isMusicFile(f):
    formats = ('MP3','mp3') # ,'ogg','wma', 'WMA', 'wav','WAV')
    return f.endswith(formats)

def findFiles(search_path):
    #   TODO add subdir path
    allfiles = []
    for path, subdirs, files in os.walk(search_path):
        for name in files:
            full_path = os.path.join(path, name)
            subdir_path = full_path.replace(search_path,'')
            if isMusicFile(subdir_path):
                allfiles.append(subdir_path)

    # files = [f for f in os.listdir(search_path) if os.path.isfile(os.path.join(search_path, f))]  # get all files inside search_path
    # print(files)
    return allfiles


def retagFile(track_info, file, search_path):
        song = taglib.File(search_path + file)

        if 'track' in track_info:
             song.tags['TITLE'] = track_info['track']
        if 'artist' in track_info:
             song.tags['ARTIST'] = track_info['artist']
        if 'album' in track_info:
            song.tags['ALBUM'] = track_info['album']
        song.save()

def sortFile(file, move, doPrint, dest_path, search_path):
    if not os.path.exists(dest_path + 'Unknown'):
        os.makedirs(dest_path + 'Unknown')  # directory for unsortable files

    ext = file.split(".")
    ext = "." + ext[len(ext)-1]
    song = taglib.File(search_path + file)

    #sort
    new_path = ''
    if 'ARTIST' in song.tags:
        # TO-DO: filter featurings

        new_path = song.tags['ARTIST'][0]

        if not os.path.exists(dest_path + new_path):
            os.makedirs(dest_path + new_path)

        if 'ALBUM' in song.tags:
            new_path = new_path + '/' + song.tags['ALBUM'][0]
            if not os.path.exists(dest_path + new_path):
                os.makedirs(dest_path + new_path)

        if 'TITLE' in song.tags and os.path.exists(dest_path + new_path + '/' + song.tags['TITLE'][0] + ext):
            if doPrint:
                print(song.tags['TITLE'][0] + "\talready exists...")
        else:
            if not move:
                copyfile(search_path + file, dest_path + new_path + '/' + song.tags['TITLE'][0].replace("/", "|") + ext)
            else:
                os.rename(search_path + file, dest_path + new_path + '/' + song.tags['TITLE'][0].replace("/", "|") + ext)
    else:
        if not move:
            copyfile(search_path + file, dest_path + 'Unknown/' + file)
        else:
            os.rename(search_path + file, dest_path + 'Unknown/' + file)

import argparse
import sys
import os
import taglib
from shutil import copyfile, move

# region CL Arguments
parser = argparse.ArgumentParser(
    description='Sort music files located in SEARCH_PATH.\n Default copy if not optional MOVE')

parser.add_argument('-m', '--move', action='store_true', default=False, help="move files:\tdefault will copy files")
parser.add_argument('-d', '--destination', help='destination path:\tpath to new sorted directory')
parser.add_argument('search_path', help="path to music directory")

args = parser.parse_args()
# endregion

# region INIT
move = args.move
search_path = args.search_path
dest_path = args.search_path
if args.destination:
    dest_path = args.destination + "/"
    if not os.path.exists(dest_path):
        os.makedirs(dest_path)

files = [f for f in os.listdir(search_path) if
         os.path.isfile(os.path.join(search_path, f))]  # get all files inside search_path

if not os.path.exists(dest_path + 'Unknown'):
    os.makedirs(dest_path + 'Unknown')  # directory for unsortable files
# endregion


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

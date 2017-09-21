import argparse
import os
import CGnsdkLookup

from sortFiles import *
import ast

client_id = '787507086'
client_id_tag = '29C4E1774124666EE2C096CBA3B78E6B'
license_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/lic.txt'

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
# endregion

def retagRenameFile(search_path, file, track_info):
    ext = file.split(".")
    ext = "." + ext[len(ext)-1]
    song = taglib.File(search_path + file)

    if 'track' in track_info:
         song.tags['TITLE'] = track_info['track']
    if 'artist' in track_info:
         song.tags['ARTIST'] = track_info['artist']
    if 'album' in track_info:
        song.tags['ALBUM'] = track_info['album']
    song.save()

files = findFiles(search_path)

for file in files:
    try:
        res = CGnsdkLookup.lookup_audio(client_id, client_id_tag,license_path,search_path+file)
        track_info = ast.literal_eval(res)
        print(track_info)
        retagFile(track_info, file, search_path)
    except Exception as e:
        #retagRenameFile(search_path, file, track_info)
        print("\n")
    sortFile(file, move, dest_path, search_path)

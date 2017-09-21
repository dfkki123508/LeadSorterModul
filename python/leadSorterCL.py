import argparse
import os
from sortFiles import *

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

files = findFiles(search_path)

sortFiles(files, move, dest_path, search_path)

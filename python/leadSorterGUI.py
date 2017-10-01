import os
import CGnsdkLookup

from sortFiles import *
import ast

client_id = 'YOUR_CLIENT_ID'
client_id_tag = 'YOUR_CLIENT_ID_TAG'
license_path = 'YOUR_LICENSE_PATH'

# region INIT
move = getMove()
doPrint = getDoPrint()
search_path = getSearchPath()
dest_path = getDestPath()
# endregion

def getMove():
    pass

def getDoPrint():
    pass

def getSearchPath():
    pass

def getDestPath():
    pass

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

def startProcessing():
    files = findFiles(search_path)

    count = 0
    maximum = len(files)
    for file in files:
        # sys.stdout.write("Progress: %0.2f%%    \r" % (count/maximum*100) )
        # sys.stdout.flush()
        try:
            res = CGnsdkLookup.lookup_audio(client_id, client_id_tag,license_path,search_path+file)
            track_info = ast.literal_eval(res)
            if doPrint:
                # print(track_info)
            retagFile(track_info, file, search_path)
        except Exception as e:
            #retagRenameFile(search_path, file, track_info)
            if doPrint:
                # print(e)
        try:
            sortFile(file, move, doPrint, dest_path, search_path)
        except Exception as e:
            if doPrint:
                # print("not suitable for taglib")
        count = count +1

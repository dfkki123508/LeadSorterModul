
from subprocess import Popen, PIPE
from os import listdir
from os.path import isfile, join

import json
import eyeD3

executable = './LeadSorterModul'

client_id = '787507086'
client_id_tag = '29C4E1774124666EE2C096CBA3B78E6B'
license_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/lic.txt'

wav_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/sample_data/teen_spirit_14s.wav'

tagged = False
overtag = False #will be command line option
track_info = ''
#get all files inside a directory
#mypath = "/home/intruso/Music/Named/"
#onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]

def get_track_info(wav_path):
    p = Popen([executable, client_id, client_id_tag, license_path, wav_path], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    output, err = p.communicate()

    track_info = json.loads(output)
    print "Artist:\t", track_info[0]['artist']
    print "Title:\t", track_info[0]['track']
    print "Album:\t", track_info[0]['album']
    #print track_info[0]

    return track_info

def set_track_info(filepath, track_info):
    #set tags with eyeD3 or other python lib
    pass

def is_file_tagged(filepath):
    #if artist, album, name == true
    #return true
    #else
    return False


mp3_path = wav_path[:wav_path.rfind(".wav")]+".mp3" #.wav gotta be same location as .mp3

if not is_file_tagged(mp3_path) or overtag:
    track_info = get_track_info(wav_path)
    set_track_info(wav_path, track_info)


from subprocess import Popen, PIPE
from os import listdir
from os.path import isfile, join

import json
import eyeD3

executable = './LeadSorterModul'

client_id = '787507086'
client_id_tag = '29C4E1774124666EE2C096CBA3B78E6B'
license_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/lic.txt'

file_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/sample_data/teen_spirit_14s.wav'

tagged = False
overtag = False #will be command line option
track_info = ''

def is_file_tagged(filepath):
    #if artist, album, name == true
    #return true
    #else
    return False

def get_track_info(file_path):
    p = Popen([executable, client_id, client_id_tag, license_path, file_path], stdin=PIPE, stdout=PIPE, stderr=PIPE)
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



if not is_file_tagged(file_path) or overtag:
    track_info = get_track_info(file_path)
    set_track_info(file_path, track_info)

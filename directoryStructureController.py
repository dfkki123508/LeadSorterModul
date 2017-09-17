
from subprocess import Popen, PIPE
from os import listdir
from os.path import isfile, join

import json

executable = './LeadSorterModul'
client_id = '787507086'
client_id_tag = '29C4E1774124666EE2C096CBA3B78E6B'
license_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/lic.txt'
file_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/sample_data/teen_spirit_14s.wav'

#get all files inside a directory
#mypath = "/home/intruso/Music/Named/"
#onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]


# retag(filepath, track_info)


    # print(track_info['artist'] + '\t' + track_info['release'] + '\t' + track_info['title'] + '\t' + track_info['genre'])

def get_track_info():
    p = Popen([executable, client_id, client_id_tag, license_path, file_path], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    output, err = p.communicate()

    track_info = json.loads(output)
    # print "Artist:\t", track_info[0]['artist']
    # print "Title:\t", track_info[0]['track']
    # print "Album:\t", track_info[0]['album']
    print track_info[0]

    return track_info

def is_track_sorted():
    return False

def sort_track():
    pass

track_info = get_track_info()

if not is_track_sorted():
    sort_track()
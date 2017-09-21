
from subprocess import Popen, PIPE
from os import listdir
from os.path import isfile, join

import json
import taglib

executable = './LeadSorterModul'
client_id = '787507086'
client_id_tag = '29C4E1774124666EE2C096CBA3B78E6B'
license_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/lic.txt'

mp3_path = '/media/intruso/HDDLinux/Musik/TestMusik/11. Killing Time.mp3'
wav_path = '/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk/sample_data/05-Hummingbird-sample.wav'

song = taglib.File(mp3_path)
track_info = ''


def is_file_tagged():
    if 'ARTIST' in song.tags and 'TITLE' in song.tags and 'ALBUM' in song.tags:
        return True
    return False


def get_track_info():
    p = Popen([executable, client_id, client_id_tag, license_path, wav_path], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    output, err = p.communicate()

    track_info = json.loads(output)
    print track_info
    return track_info


def set_track_info():
    if 'track' in track_info[0]:
        song.tags['TITLE'] = track_info[0]['track']
    if 'artist' in track_info[0]:
        song.tags['ARTIST'] = track_info[0]['artist']
    if 'album' in track_info[0]:
        song.tags['ALBUM'] = track_info[0]['album']
    song.save()


#if not is_file_tagged(wav_path) or overtag:
#    track_info = get_track_info(wav_path)
#    set_track_info(wav_path, track_info)

track_info = get_track_info()
set_track_info()
print track_info

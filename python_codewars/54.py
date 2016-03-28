# Dubstep

def song_decoder(song):
    new_song = song.replace("WUB", ' ')
    words = new_song.strip().split()
    return ' '.join(words)

assert(song_decoder("AWUBBWUBC")=="A B C")
assert(song_decoder("AWUBWUBWUBBWUBWUBWUBC")=="A B C")
assert(song_decoder("WUBAWUBBWUBCWUB")=="A B C")
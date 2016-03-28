# Bowling score calculator
def bowling_score(rolls):
    "Compute the total score for a player's game of bowling."
    scores = 0
    frame_id = 0
    for num in rolls:
        print(num)
        plus_next = True
        plus_next2 = False
        next_in_frame = False
        if num==10:
            plus_next2 = True
            frame_num += 1
        else:
            next_in_frame = True
            if
    return scores

assert( 0 == bowling_score( [0]*20 ) )
assert( 190 == bowling_score([9,1] * 10 + [9]) )
assert( 300 == bowling_score( [10]*12 ) )
assert( 11 == bowling_score([0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 10,1,0]) )
assert( 12 == bowling_score([0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 10, 1,0]) )

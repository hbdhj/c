# Bowling score calculator

def bowling_score(rolls):
    "Compute the total score for a player's game of bowling."
    scores = 0 #total score
    frame_num = 0 # current frame id
    next_in_frame = False # the next elem is in this frame
    multiple=[1]*len(rolls)
    for id in range(len(rolls)):
        num = rolls[id]
        #print(id, num, scores, next_in_frame, frame_num, multiple)
        scores += num*multiple[id]
        if num==10:
            frame_num += 1
            next_in_frame = False
            if frame_num < 10:
                if id<len(rolls)-1:
                    multiple[id+1]+=1
                if id<len(rolls)-2:
                    multiple[id+2]+=1
        else:
            if next_in_frame == False: # new frame
                next_in_frame = True
            else: # same frame
                frame_num += 1
                next_in_frame = False
                if num+rolls[id-1] == 10 and frame_num<10:
                    if id < len(rolls):
                        multiple[id+1]+=1
    #print(scores)
    return scores

assert( 0 == bowling_score( [0]*20 ) )
assert( 190 == bowling_score([9,1] * 10 + [9]) )
assert( 300 == bowling_score( [10]*12 ) )
assert( 11 == bowling_score([0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 10,1,0]) )
assert( 12 == bowling_score([0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 10, 1,0]) )

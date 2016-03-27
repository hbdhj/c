# Codewar's style ranking system

class User:
    def __init__(self):
        self.rank = -8
        self.progress = 0

    def inc_progress(self, n):
        if n<-8 or n>8 or n==0:
            raise Exception
        else:
            diff = n - self.rank
            if n*self.rank<0:
                diff-=1
            if diff==0:
                self.progress+=3
            elif diff==-1:
                self.progress+=1
            elif diff<-1:
                self.progress+=0
            elif diff>0:
                self.progress+=10*diff*diff
            #print(self.n_progress)
            inc_rank = int(self.progress/100)
            #print(inc_rank)
            self.progress = self.progress%100
            print(self.progress)
            if self.rank<0 and (self.rank+inc_rank)>=0:
                self.rank+=inc_rank+1
            else:
                self.rank+=inc_rank
            if self.rank>8:
                self.progress+=(self.rank-8)*100
                self.rank=8


user = User()
#print(user.rank) # => -8
#print(user.progress) # => 0
#user.inc_progress(-7)
#print(user.progress) # => 10
#user.inc_progress(-5) # will add 90 progress
#print(user.progress) # => 0 # progress is now zero
#print(user.rank) # => -7 # rank was upgraded to -7
user.inc_progress(-1) # will add 90 progress
print(user.progress) # => 0 # progress is now zero
print(user.rank) # => -7 # rank was upgraded to -7
# Finding an appointment

def get_start_time(schedules, duration):
    occu_times=[]
    if len(schedules)>0:
        occu_times = schedules[0]
    if len(schedules)>1:
        for i in range(1, len(schedules)):
            print(schedules[i])
            for meet in schedules[i]:
                for exist_meetings in occu_times:
                    if meet[0] < exist_meetings[0] and meet[1] > exist_meetings[1]:
                        pass
                    elif meet[0] < exist_meetings[0] and meet[1] < exist_meetings[1]:
                        pass
                    elif meet[0] > exist_meetings[0] and meet[1] > exist_meetings[1]:
                        pass
                    elif meet[0] < exist_meetings[0] and meet[1] > exist_meetings[1]:
                        pass
                    else:
                        pass
    pass

schedules = [
  [['09:00', '11:30'], ['13:30', '16:00'], ['16:00', '17:30'], ['17:45', '19:00']],
  [['09:15', '12:00'], ['14:00', '16:30'], ['17:00', '17:30']],
  [['11:30', '12:15'], ['15:00', '16:30'], ['17:45', '19:00']]
]
assert(get_start_time(schedules, 60)=='12:15')
assert(get_start_time(schedules, 90)==None)
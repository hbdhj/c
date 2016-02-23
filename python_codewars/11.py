def processes(start, end, processes):
    processes_dict={};
    for sub_lst in processes:
        processes_dict[sub_lst[1]]=[sub_lst[2], sub_lst[0]];
    if start not in processes_dict.keys():
        return [];
    if start==end:
        return [];
    check=start;
    ret=[];
    found=False
    while check in processes_dict.keys():
        ret.append(processes_dict[check][1]);
        if processes_dict[check][0]==end:
            found=True;
            break;
        else:
            check=processes_dict[check][0];
    if found:
        return ret;
    else:
        return [];        
test_processes = [
    ['gather', 'field', 'wheat'],
    ['bake', 'flour', 'bread'],
    ['mill', 'wheat', 'flour']
]

processes('field', 'bread', test_processes);
#processes('field', 'ferrari', test_processes);
#processes('field', 'field', test_processes);

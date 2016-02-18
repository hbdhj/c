def list_to_array(lst):
    # ???
    ret = [];
    for sub in list:
        ret = ret + sub;
    return ret;

#u = None
#print(list_to_array(u))

u = LinkedList(4, LinkedList(25, LinkedList(30)))
print(list_to_array(u))

u = LinkedList(2, LinkedList(40, LinkedList(43, LinkedList(25, LinkedList(125)))))
print(list_to_array(u))

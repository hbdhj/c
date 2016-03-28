# Linked Lists - Length & Count

class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def length(node):
    len = 0
    while node!=None:
        len+=1
        node = node.next
    return len

def count(node, data):
    cnt = 0
    while node!=None:
        if node.data == data:
            cnt+=1
        node = node.next
    return cnt
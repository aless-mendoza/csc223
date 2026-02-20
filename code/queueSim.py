# Random Queue
# By Alessandra

import random

file_path = input("What's your file path (include .txt): ");

with open(file_path) as file:
    ilist = [line.rstrip() for line in file]

    random.shuffle(ilist)

queue = []

while ilist != []:
    choice = random.randint(0,1)
    if choice == 0:
        # add person to queue
        queue.insert(0, ilist[0])
        del ilist[0]
        print( str(queue[0]) + " entered the queue")
    else :
        # remove person from queue
        if queue != []:
            print( str(queue[-1]) + " left the queue")
            del queue[-1]

while queue != []:
    print( str(queue[-1]) + " left the queue")
    del queue[-1]

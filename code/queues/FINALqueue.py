import sys
import time
import random

def clear_screen():
    """Uses ANSI escape codes to clear the screen and move the cursor to the top."""
    # \033[2J clears the screen, \033[H moves the cursor to home
    sys.stdout.write('\033[2J\033[H')
    sys.stdout.flush()

def render_table(queue):
    """Formats and prints the table to the terminal with queue data."""
    clear_screen()
    
    # Print header
    sys.stdout.write(f'{"Queue":<30}\n')
    sys.stdout.write('-' * 30 + '\n')
    
    # Print each queue item
    for item in queue:
        sys.stdout.write(f'{item:<30}\n')
    
    sys.stdout.flush()

# Main program
file_path = input("What's your file path (include .txt): ")

with open(file_path) as file:
    ilist = [line.rstrip() for line in file]

random.shuffle(ilist)
queue = []
log = ""
# Main loop to process queue and update table live
try:
    while ilist or queue:
        
        if ilist:  # Only make decisions if there are items to process
            choice = random.randint(0, 1)
            if choice == 0:
                # add person to queue
                queue.insert(0, ilist[0])
                del ilist[0]
                log = log + (str(queue[0]) + " entered the queue\n")
            else:
                # remove person from queue
                if queue:
                    log = log + (str(queue[-1]) + " left the queue\n")
                    del queue[-1]
        else:
            # If ilist is empty, just remove remaining queue items
            if queue:
                log = log + (str(queue[-1]) + " left the queue\n")
                del queue[-1]

        render_table(queue) 
        time.sleep(1)  # Update every second

except KeyboardInterrupt:
    print("\nExiting live update.")
    
    
with open("logs.txt", "w") as file:
    file.write(log)

print ("Creating logs.txt... \nDone!\n" + ('-' * 30 + '\n'))
print(log)

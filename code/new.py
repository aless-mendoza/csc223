import sys
import time
import random

def clear_screen():
    """Uses ANSI escape codes to clear the screen and move the cursor to the top."""
    # \033[2J clears the screen, \033[H moves the cursor to home
    sys.stdout.write('\033[2J\033[H')
    sys.stdout.flush()

def render_table(ilist, queue):
    """Formats and prints the table to the terminal with ilist and queue data."""
    clear_screen()
    
    # Print headers
    sys.stdout.write(f'{"Remaining Items":<30} | {"Queue":<30}\n')
    sys.stdout.write('-' * 63 + '\n')
    
    # Get the maximum number of rows needed
    max_rows = max(len(ilist), len(queue))
    
    # Print each row
    for i in range(max_rows):
        left_item = ilist[i] if i < len(ilist) else ""
        right_item = queue[i] if i < len(queue) else ""
        
        sys.stdout.write(f'{left_item:<30} | {right_item:<30}\n')
    
    sys.stdout.flush()

# Main program
file_path = input("What's your file path (include .txt): ")

with open(file_path) as file:
    ilist = [line.rstrip() for line in file]

random.shuffle(ilist)
queue = []

# Main loop to process queue and update table live
try:
    while ilist or queue:
        
        if ilist:  # Only make decisions if there are items to process
            choice = random.randint(0, 1)
            if choice == 0:
                # add person to queue
                queue.insert(0, ilist[0])
                del ilist[0]
            else:
                # remove person from queue
                if queue:
                    del queue[-1]
        else:
            # If ilist is empty, just remove remaining queue items
            if queue:
                del queue[-1]
        render_table(ilist, queue)

        time.sleep(1)  # Update every second
        
except KeyboardInterrupt:
    print("\nExiting live update.")

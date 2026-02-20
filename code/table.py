import sys
import time
import random

def clear_screen():
    """Uses ANSI escape codes to clear the screen and move the cursor to the top."""
    # \033[2J clears the screen, \033[H moves the cursor to home
    sys.stdout.write('\033[2J\033[H')
    sys.stdout.flush()

def generate_table_data():
    """Generates dynamic data for the table."""
    return [
        ['Header 1', 'Header 2'],
        [f'Data A: {random.randint(1, 100)}', f'Data B: {random.randint(1, 100)}'],
        [f'Data C: {random.randint(1, 100)}', f'Data D: {random.randint(1, 100)}']
    ]

def render_table(data):
    """Formats and prints the table to the terminal."""
    clear_screen()
    for row in data:
        sys.stdout.write(f'{row[0]:<20} | {row[1]:<20}\n')
    sys.stdout.flush()

# Main loop to update the table live
try:
    while True:
        table_data = generate_table_data()
        render_table(table_data)
        time.sleep(1) # Update every second
except KeyboardInterrupt:
    # Handle Ctrl+C to exit gracefully
    print("\nExiting live update.")


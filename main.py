import serial
import time
import os
import sys

# port = "/dev/cu.Bluetooth-Incoming-Port"
# port = "/dev/cu.HC-06-DevB"
# port = "/dev/cu.usbmodem14401"
port = "/dev/cu.HC-05-SPPDev"

baud_rate = 9600
# SET_HAND_CONTROL = False
SET_HAND_CONTROL = True


def check_action(action, missed='Q'):
    actions = [('L', 'l'),  # Turn left 90 deg
               ('R', 'r'),  # Turn right 90 deg
               ('F', 'f'),  # Forward
               ('B', 'b'),  # Backward
               ('E', 'e')  # Exit
               ]

    for row in actions:
        if action in row:
            return row[0]
    return missed


def main():

    ser = serial.Serial(port, baud_rate, timeout=5)
    ser.close()
    ser.open()

    time.sleep(3)  # wait for Arduino

    if SET_HAND_CONTROL:
        job_ = True

        while job_:
            ans = input("Do Something? [F|B|L|R|E]:")
            ans = check_action(ans, None)

            if ans in ['E', 'e']:
                job_ = False
            elif ans is not None:
                ans = ans.encode()
                # ser.write(ans)
                ser.write(70)
                time.sleep(1)
            else:
                print ("Invalid input.")

        ser.close()


if __name__ == "__main__":
    main()

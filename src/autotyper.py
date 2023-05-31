import pyautogui
import time
import random

delayBeforeStart = 5


def log(str):
	logObj.write(str)

logObj = open("log.txt", "w")


time.sleep(delayBeforeStart)

print("Writing Started", flush = True)

pyautogui.PAUSE = 0.0001
for line in open("input.txt", "r"):
	
	for ch in line:
		if ch != '\t':
		    pyautogui.write(ch)
    

print("Writing Completed", flush = True)
log("Writing Completed")

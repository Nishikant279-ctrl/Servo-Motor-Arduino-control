import cv2
import mediapipe as mp
import serial
import math

Cam = cv2.VideoCapture(0)
mpHands = mp.solutions.hands
hands = mpHands.Hands()
mpDraw = mp.solutions.drawing_utils
ser = serial.Serial("COM3", 9600)

def calculate_distance(landmark1, landmark2):
  #Extract x and y coordinates
  x1, y1 = landmark1.x, landmark1.y
  x2, y2 = landmark2.x, landmark2.y

  # Use distance formula
  distance = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
  return distance

while True:
    success, img = Cam.read()
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    release = hands.process(imgRGB)
    if release.multi_hand_landmarks:
        for handlms in release.multi_hand_landmarks:
            for id, lm in enumerate(handlms.landmark):
                mpDraw.draw_landmarks(img, handlms, mpHands.HAND_CONNECTIONS)
                if id == 8 and id + 4 == 12:
                    landmark_8 = handlms.landmark[id]
                    landmark_12 = handlms.landmark[id+4]

                    distance = calculate_distance(landmark_8, landmark_12)
                    print(distance)

                    data_to_send = distance
                    ser.write(data_to_send.encode())

    cv2.imshow("Hand Gestures", img)
    if cv2.waitKey(1) == 27:
        Cam.release()
        cv2.destroyAllWindows()
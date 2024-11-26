import cv2
import cvzone.SerialModule  # Assuming cvzone.SerialModule has sendData function
import mediapipe as mp
import serial
import math

Cam = cv2.VideoCapture(0)
mpHands = mp.solutions.hands
hands = mpHands.Hands()
mpDraw = mp.solutions.drawing_utils

# Adjust port name if needed
ser = serial.Serial("COM3", 9600)  # Uncomment for sending data to Arduino

def calculate_distance(landmark1, landmark2):
    # Extract x and y coordinates
    x1, y1 = landmark1.x, landmark1.y
    x2, y2 = landmark2.x, landmark2.y

    # Use distance formula
    distance = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    return distance

while True:
    success, img = Cam.read()
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    results = hands.process(imgRGB)
    if results.multi_hand_landmarks:
        for handlms in results.multi_hand_landmarks:
            for id, lm in enumerate(handlms.landmark):
                mpDraw.draw_landmarks(img, handlms, mpHands.HAND_CONNECTIONS)

                # Distance between index finger (id 4) and middle finger (id 8)
                if id == 4 and id + 4 == 8:
                    landmark_8 = handlms.landmark[id]
                    landmark_12 = handlms.landmark[id + 4]
                    distance = calculate_distance(landmark_8, landmark_12)

                    # Send data to Arduino regardless of distance
                    ser.write(distance)  # Assuming sendData sends data

                # Distance between thumb (id 4) and middle finger (id 8)
                if id == 4 and id + 4 == 8:
                    landmark_4 = handlms.landmark[id]
                    landmark_8 = handlms.landmark[id + 4]
                    distance2 = calculate_distance(landmark_4, landmark_8)

                    print(distance2)  # Print for testing (remove for final implementation)

                    # Implement logic based on distance2 thresholds (uncomment and adjust)
                    # if distance2 < 0.08:
                    #     # Do something
                    # elif distance2 > 0.25:
                    #     # Do something else

    cv2.imshow("Hand Gestures", img)
    if cv2.waitKey(1) == 27:
        Cam.release()
        cv2.destroyAllWindows()
        break

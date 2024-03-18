import os
import cv2
cap=cv2.VideoCapture(0)
directory='Image/'
while True:
    _,frame=cap.read()
    count = {
        '1': len(os.listdir(directory + "/1")),
        '2': len(os.listdir(directory + "/2")),
        '3': len(os.listdir(directory+"/3")),
        '4': len(os.listdir(directory + "/4")),
        '5': len(os.listdir(directory + "/5")),
        '6': len(os.listdir(directory + "/6")),
        '7': len(os.listdir(directory + "/7")),
        '8': len(os.listdir(directory + "/8")),
        '9': len(os.listdir(directory + "/9")),
        '0': len(os.listdir(directory + "/0")),
        'a': len(os.listdir(directory + "/A")),
        'b': len(os.listdir(directory + "/B")),
        'c': len(os.listdir(directory + "/C")),
        'd': len(os.listdir(directory + "/D")),
        'e': len(os.listdir(directory + "/E"))
        }
    row = frame.shape[1]
    col = frame.shape[0]
    cv2.rectangle(frame,(0,40),(300,400),(255,255,255),2)
    cv2.imshow("data",frame)
    cv2.imshow("ROI",frame[40:400,0:300])
    frame=frame[40:400,0:300]
    interrupt = cv2.waitKey(10)
    if interrupt & 0xFF == ord('1'):
        cv2.imwrite(directory+'1/'+str(count['1'])+'.png',frame)
    if interrupt & 0xFF == ord('2'):
        cv2.imwrite(directory+'2/'+str(count['2'])+'.png',frame)
    if interrupt & 0xFF == ord('3'):
        cv2.imwrite(directory+'3/'+str(count['3'])+'.png',frame)
    if interrupt & 0xFF == ord('4'):
        cv2.imwrite(directory+'4/'+str(count['4'])+'.png',frame)
    if interrupt & 0xFF == ord('5'):
        cv2.imwrite(directory+'5/'+str(count['5'])+'.png',frame)
    if interrupt & 0xFF == ord('6'):
        cv2.imwrite(directory+'6/'+str(count['6'])+'.png',frame)
    if interrupt & 0xFF == ord('7'):
        cv2.imwrite(directory+'7/'+str(count['7'])+'.png',frame)
    if interrupt & 0xFF == ord('8'):
        cv2.imwrite(directory+'8/'+str(count['8'])+'.png',frame)
    if interrupt & 0xFF == ord('9'):
        cv2.imwrite(directory+'9/'+str(count['9'])+'.png',frame)
    if interrupt & 0xFF == ord('0'):
        cv2.imwrite(directory+'0/'+str(count['0'])+'.png',frame)
    if interrupt & 0xFF == ord('a'):
        cv2.imwrite(directory+'A/'+str(count['a'])+'.png',frame)
    if interrupt & 0xFF == ord('b'):
        cv2.imwrite(directory+'B/'+str(count['b'])+'.png',frame)
    if interrupt & 0xFF == ord('c'):
        cv2.imwrite(directory+'C/'+str(count['c'])+'.png',frame)
    if interrupt & 0xFF == ord('d'):
        cv2.imwrite(directory+'D/'+str(count['d'])+'.png',frame)
    if interrupt & 0xFF == ord('e'):
        cv2.imwrite(directory+'E/'+str(count['e'])+'.png',frame)


cap.release()
cv2.destroyAllWindows()
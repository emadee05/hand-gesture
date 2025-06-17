import serial
import time
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial('/dev/cu.usbmodem11301', 115200)
time.sleep(2) 

ser.write(b'START\n')
matrix = []

while len(matrix) < 36:
    line = ser.readline().decode().strip()
    print(f"rec: {line}")
    try:
        values = list(map(int, line.split()))
        matrix.extend(values)
        print(matrix)
    except ValueError:
        print(f"cant parse '{line}'")
ser.close()
matrix = np.array(matrix).reshape((6, 6))
print("Matrix:")
print(matrix)



matrix = np.array(matrix).reshape((6, 6))

plt.figure(figsize=(6, 6))
plt.imshow(matrix, cmap='hot', interpolation='nearest')
plt.colorbar(label='Sensor Value')
plt.title("Photodiode Array Heatmap")
plt.xlabel("Column")
plt.ylabel("Row")
plt.tight_layout()
plt.show()

normalized_matrix = (matrix - np.min(matrix)) / (np.max(matrix) - np.min(matrix))
flat_list = normalized_matrix.flatten().tolist()

print(flat_list)
# collecting training data ------------------------------
training = True
label = 't'
if training:
    with open('handgesture.txt', 'a') as f:
        f.write(', '.join(map(str, normalized_matrix.flatten())))
        f.write(f', {label}\n') 

            
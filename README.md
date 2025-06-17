# Hand Gesture Recognizer (Caltech EE 45 Final Project)

This project implements a hardware-software system that recognizes hand gestures using a custom-built 6x6 photodiode sensor array and a convolutional neural network (CNN). The system uses an Arduino Micro for scanning the photodiodes and transmitting intensity data to a Python backend, where the data is processed and classified into hand gestures.

---

## Overview

- **Hardware:** 6x6 photodiode array, NMOS transistors for manual multiplexing, TIA and inverting amplifier stages for signal amplification.
- **Software:** Python + PyTorch CNN for gesture classification; real-time data acquisition via Arduino serial interface.
- **Goal:** Classify 3 distinct gestures: `"c"`, `"2"` (peace sign), and `"t"`.

---

## Repository Contents

- `handgesture_recognizer.ino` – Arduino code for controlling the sensor matrix and sending readings.
- `hand_gesture.py` – Python script for collecting sensor data and visualizing it as a heatmap.
- `handgesture.txt` – Collected dataset for training/testing.
- `hand_ml_model_final.ipynb` – CNN implementation and training pipeline using PyTorch.
- `EE45_Final_Report.pdf` – Full technical documentation of the system architecture, circuit design, simulation, and results.

---

## How to Run

1. **Upload Arduino Code**
   - Open `handgesture_recognizer.ino` in the Arduino IDE.
   - Upload to your Arduino Micro.
   - **Close the Arduino IDE** to free the serial port.

2. **Collect Data**
   - Run `hand_gesture.py` to trigger a gesture scan.
   - A heatmap of the 6x6 sensor reading will be displayed.
   - The data is normalized and flattened for model input.

3. **Train the Model**
   - Use `cnn_model.py` (or the Jupyter notebook) to train a CNN on collected data.
   - You can also use the included dataset (`handgesture.txt`) to test model performance.

4. **Classify a Gesture**
   - Run the final prediction cell or script to classify a real-time gesture.
   - Output will be one of: `"c"`, `"2"`, or `"t"`.

---

## Dependencies

- Arduino IDE
- Python 3.x
- Python packages:
  - `pyserial`
  - `numpy`
  - `matplotlib`
  - `pandas`
  - `scikit-learn`
  - `torch` and `torchvision`

Install them with:
```bash
pip install pyserial numpy matplotlib pandas scikit-learn torch torchvision

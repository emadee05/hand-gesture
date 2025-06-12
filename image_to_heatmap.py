import os
from PIL import Image
import numpy as np
import random


letter = "h"
folder_path = letter

output_file = "output_" + letter+ ".txt"
indx = 0
with open(output_file, "w") as f:
    for filename in os.listdir(folder_path):
        if filename.endswith(".jpeg"):
            img_path = os.path.join(folder_path, filename)
            # converts to grayscale
            img = Image.open(img_path).convert("L")
            # randomly rotates each image
            if (indx + 1) % 4 ==0:
                angle = random.uniform(-5, 5)
                img = img.rotate(angle, fillcolor=255)
            # upscaling/downscaling to 6x6, using lanczos
            img_resized = img.resize((6,6), Image.Resampling.LANCZOS)
            grayscale = np.array(img_resized)
            inverted = 255 - grayscale

            if (indx+1)%4 == 0:
                mask = np.random.rand(*inverted.shape) < 0.07
                inverted[mask] = 255

            flat = inverted.flatten()

            flat_str = ",".join(map(str, flat))

            f.write(f"{flat_str},{letter}\n")
        indx+=1
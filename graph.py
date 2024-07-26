// Intial graph
import matplotlib.pyplot as plt
import numpy as np

# Generate some data
np.random.seed(0)
time = np.linspace(0, 10, 100)
value = np.sin(time) + np.random.normal(0, 0.1, time.shape)

# Define the threshold
threshold = 0.5

# Identify when the value crosses the threshold
crossings = value > threshold

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(time, value, label='Value')
plt.axhline(threshold, color='r', linestyle='--', label='Threshold')
plt.scatter(time[crossings], value[crossings], color='g', label='Crossings')
plt.title('Value Crossing Threshold')
plt.xlabel('Time')
plt.ylabel('Value')
plt.legend()

# Display the plot
plt.show()

// Final graph
import matplotlib.pyplot as plt
import numpy as np

# Generate some data
np.random.seed(0)
time = np.linspace(0, 10, 100)
value = np.sin(time) + np.random.normal(0, 0.1, time.shape)

# Define the threshold
threshold = 0.5

# Clip the values to prevent them from going too low
clipped_value = np.clip(value, threshold - 1, None)

# Identify when the value crosses the threshold
crossings = np.where((value[:-1] < threshold) & (value[1:] > threshold))[0] + 1

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(time, clipped_value, label='Value')
plt.axhline(threshold, color='r', linestyle='--', label='Threshold')

# Annotate the crossings
for t in crossings:
    plt.axvline(time[t], color='g', linestyle='--')
    plt.annotate('Message Delivered', xy=(time[t], clipped_value[t]), xytext=(time[t], clipped_value[t]+0.5),
                 arrowprops=dict(facecolor='black', shrink=0.05))

plt.title('Value Crossing Threshold')
plt.xlabel('Time')
plt.ylabel('Value')
plt.legend()

# Display the plot
plt.show()


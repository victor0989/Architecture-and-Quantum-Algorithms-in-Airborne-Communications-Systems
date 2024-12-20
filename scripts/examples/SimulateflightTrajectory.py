import numpy as np
import matplotlib.pyplot as plt

# Parámetros de vuelo
time = np.linspace(0, 100, 500)  # 100 segundos
altitude = 0.5 * 9.8 * (time ** 2)  # Altura en caída libre

# Gráfica de trayectoria
plt.plot(time, altitude)
plt.title("Trayectoria de vuelo")
plt.xlabel("Tiempo (s)")
plt.ylabel("Altitud (m)")
plt.grid()
plt.show()

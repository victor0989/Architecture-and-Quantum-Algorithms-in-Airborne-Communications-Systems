from qiskit import QuantumCircuit, Aer, execute
from qiskit.circuit.library import QFT

# Parámetros FIR simulados
coeffs = [0.1, 0.2, 0.3, 0.4]
signal = [1.0, 0.5, 0.3, 0.1]

# Creación del circuito cuántico
qc = QuantumCircuit(len(signal))

# Simulación de la suma ponderada (circuito conceptual)
for i in range(len(signal)):
    qc.ry(coeffs[i] * signal[i], i)  # Rotación proporcional a la entrada

# Transformada de Fourier para procesamiento (ejemplo simplificado)
qft = QFT(len(signal))
qc.append(qft.to_instruction(), range(len(signal)))

qc.measure_all()

# Simulación
simulator = Aer.get_backend('qasm_simulator')
result = execute(qc, simulator, shots=1024).result()
print(result.get_counts())

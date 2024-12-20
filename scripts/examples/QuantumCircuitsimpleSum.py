from qiskit import QuantumCircuit

def quantum_full_adder():
    qc = QuantumCircuit(5, 2)  # 3 qubits for input, 2 ancillas

    # Qubits: a, b, c_in, sum, c_out
    qc.cx(0, 3)  # XOR for sum
    qc.cx(1, 3)
    qc.ccx(0, 1, 4)  # AND for carry
    qc.ccx(3, 2, 4)  # Combine c_in and sum for carry_out

    qc.measure([3, 4], [0, 1])  # Measure sum and carry_out
    return qc

circuit = quantum_full_adder()
print(circuit)

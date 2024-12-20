# Architecture-and-Quantum-Algorithms-in-Airborne-Communications-Systems

## Implementation of Photodetection, Quantum Processors, and Data Structures in Air Navigation

### Overview
This project focuses on implementing photodetection systems, quantum processors, and optimized data structures to enhance airborne communication systems.

---

## Components

### Power Supply
The power supply generates the current supplied to the laser. Key characteristics include:
- **Continuous Operation**: Offers great stability in current levels.
- **Pulse Sources**: Supplies short pulses with fast turn-on times and low duty cycles.

### Temperature Stabilizer
Essential for minimizing errors due to ambient temperature variations, ensuring reproducibility of experimental results.

### Beam Guidance and Selection
Collects emitted light to introduce it into the measurement device. This stage enables:
- Filtering of emission spectra.
- Elimination of unwanted emission modes.

### Spectrum Detection
Final stage where ASE spectra are obtained using an Optical Spectrum Analyzer.

---

## Characteristics of Electronic Components and VHF Signal Carriers in Light Aviation

### Traceability Matrix for Software Requirements (DO-178C)
| Requirement ID | Description                             | Test ID       | Expected Outcome | Test Outcome | Traceability to Code |
|----------------|-----------------------------------------|---------------|------------------|--------------|-----------------------|
| REQ-SW-001     | Implement FIR filter to process 5 sample signals. | TEST-FIR-001 | Output = 2.4     | Passed       | `fir_filter()` in file `fir_filter.c` |
| REQ-SW-002     | FIR filter must produce an 8-bit output.          | TEST-FIR-002 | Output = 8 bits  | Passed       | `fir_filter()` - Output format verification |
| REQ-SW-003     | FIR filter must minimize noise in a known test signal. | TEST-FIR-003 | Noise reduction = 10 dB | Passed | `fir_filter()` - Noise reduction validation |

### Traceability Matrix for Hardware Requirements (DO-254)
| Requirement ID | Description                             | Test ID       | Expected Outcome | Test Outcome | Traceability to Code |
|----------------|-----------------------------------------|---------------|------------------|--------------|-----------------------|
| REQ-HW-001     | FIR filter must be implemented in hardware to process signals. | TEST-FIR-SIM-001 | Output = 2.4 | Passed | VHDL code in `fir_filter.vhdl` |
| REQ-HW-002     | FIR filter must operate in real-time with no significant latency. | TEST-FIR-SIM-002 | Latency < 1 ms | Passed | Latency verification in Vivado simulation |

---

## Testing Methodology

### Integration Testing (DO-178C)
- **Test ID**: TEST-INTEGRATION-001
- **Description**: Verify that the FIR filter integrates correctly with other system modules.
- **Test Method**: Perform integration testing in STM32CubeIDE by connecting various modules (FIR filter, I2C communication, etc.) and verifying the correct interaction between them.
- **Expected Outcome**: The entire system should function without communication or processing errors between modules.

### Validation Testing (DO-178C)
- **Test ID**: TEST-VALIDATION-001
- **Description**: Validate the complete system in a realistic test environment.
- **Test Method**: Run the full system on a test bench and measure the precision and stability of the FIR filter output under various conditions.
- **Expected Outcome**: The system must meet performance and stability requirements under operational conditions.

### Hardware Verification and Validation (DO-254)

#### FPGA Testing in Vivado
1. **Verification of Implementation**: Ensure that the FIR filter implemented in FPGA functions as expected for different inputs.
2. **Timing Verification**: Ensure that the FIR filter handles signals in real-time without introducing significant latency.

#### STM32 Microcontroller Testing
1. Configure the I2C interface to transmit data between the microcontroller and other devices.
2. Use timing functions in the microcontroller to ensure the FIR filter executes within the specified time limits.
3. Measure the output of the FIR filter and compare it to the expected result using an oscilloscope or analysis tool.

---

## Tools and Technologies
- **STM32CubeIDE**: Microcontroller testing and integration.
- **Vivado**: FPGA simulations and timing verification.
- **Optical Spectrum Analyzer**: For ASE spectrum detection.

---

## Conclusion
To meet certification standards such as DO-178C for software and DO-254 for hardware:
- Ensure thorough testing, validation, and documentation of all components.
- Maintain meticulous traceability of requirements, design, and testing activities.
- Leverage tools like STM32CubeIDE and Vivado to achieve compliance with safety, reliability, and performance standards.

The documentation of requirements, testing, and verification provides a robust foundation for certification while ensuring system reliability in aviation contexts.


Feel free to contribute or raise issues to improve the system further.
## Contact
For any queries or collaborations, please contact [Víctor Alonso García](mailto:victoralonsogarcia8@gmail.com).

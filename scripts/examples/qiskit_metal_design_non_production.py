//You can change this code with the Qiskit metal documentation, recomendable
from qiskit_metal import designs, MetalGUI
from qiskit_metal.qlibrary.qubits.transmon_pocket import TransmonPocket

# Crear diseño
design = designs.DesignPlanar()
gui = MetalGUI(design)

# Agregar un qubit como elemento del circuito FIR
qbit = TransmonPocket(design, 'QubitFIR', options=dict(
    pad_width='500um', 
    pad_height='300um', 
    connection_pads=dict(
        input=dict(loc_W=+1, pad_height='40um', pad_width='20um'),
        output=dict(loc_W=-1, pad_height='40um', pad_width='20um')
    )
))

gui.rebuild()
gui.autoscale()

# Exportar el diseño a un archivo GDS para su fabricación
design.save_design("FIR_Qubit_Design.gds")
gui.show()

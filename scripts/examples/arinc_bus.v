module arinc_bus (
    input wire clk,
    input wire [31:0] data_in,
    output reg [31:0] data_out
);
    always @(posedge clk) begin
        data_out <= data_in; // Transmisión de datos
    end
endmodule

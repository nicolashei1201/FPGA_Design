`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/02/2018 07:53:55 PM
// Design Name: 
// Module Name: RGB_Dec
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module RGB_Dec (
  input  [1:0] sw,
  output reg [7:0] R_time_out,
  output reg [7:0] G_time_out,
  output reg [7:0] B_time_out
);

  always @ ( * ) begin
    case (sw)
      2'b00: begin
        R_time_out = 8'd100;
        G_time_out = 8'd0;
        B_time_out = 8'd0;
      end
      2'b01: begin
        R_time_out = 8'd100;
        G_time_out = 8'd100;
        B_time_out = 8'd0;
      end
      2'b10: begin
        R_time_out = 8'd100;
        G_time_out = 8'd10;
        B_time_out = 8'd255;
      end
      2'b11: begin
        R_time_out = 8'd255;
        G_time_out = 8'd255;
        B_time_out = 8'd255;
      end
      default: begin
        R_time_out = 8'd0;
        G_time_out = 8'd0;
        B_time_out = 8'd0;
      end
    endcase
  end

endmodule

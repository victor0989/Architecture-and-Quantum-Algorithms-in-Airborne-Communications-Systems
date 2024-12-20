with Ada.Text_IO;
use Ada.Text_IO;

procedure Sensor_Check is
   type Sensor_Status is (OK, Warning, Critical);
   Sensor_1_Status : Sensor_Status := OK;

begin
   -- Simulación de chequeo de sensor
   if Sensor_1_Status = OK then
      Put_Line("Sensor 1: OK");
   elsif Sensor_1_Status = Warning then
      Put_Line("Sensor 1: Warning");
   else
      Put_Line("Sensor 1: Critical");
   end if;
end Sensor_Check;

with Interfaces.C.Extensions;
use Interfaces.C.Extensions;

package body calculate_mppt_QGenC is

procedure Ada_Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage(pBuffer : Interfaces.C.char_array) is
    procedure C_Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage(pBuffer : Interfaces.C.char_array);
    pragma Import(C, C_Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage, "Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage");
begin
    C_Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage(pBuffer);
end Ada_Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage;

procedure Ada_Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current(pBuffer : Interfaces.C.char_array) is
    procedure C_Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current(pBuffer : Interfaces.C.char_array);
    pragma Import(C, C_Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current, "Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current");
begin
    C_Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current(pBuffer);
end Ada_Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current;

procedure Ada_Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm(pBuffer : in Interfaces.C.char_array; bytesWritten : out Integer) is
    function C_Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm(pBuffer : Interfaces.C.char_array) return Integer;
    pragma Import(C, C_Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm, "Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm");
begin
    bytesWritten := C_Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm(pBuffer);
end Ada_Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm;

procedure Ada_Execute_calculate_mppt_QGenC is
    procedure C_Execute_calculate_mppt_QGenC;
    pragma Import(C, C_Execute_calculate_mppt_QGenC, "Execute_calculate_mppt_QGenC");
begin
    C_Execute_calculate_mppt_QGenC;
end Ada_Execute_calculate_mppt_QGenC;


end calculate_mppt_QGenC;

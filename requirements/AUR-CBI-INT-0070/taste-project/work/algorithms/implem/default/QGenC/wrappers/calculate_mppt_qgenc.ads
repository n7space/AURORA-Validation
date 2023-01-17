with Interfaces.C.Extensions;
use Interfaces.C.Extensions;

package calculate_mppt_QGenC is

procedure Ada_Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage(pBuffer : Interfaces.C.char_array);
procedure Ada_Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current(pBuffer : Interfaces.C.char_array);
procedure Ada_Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm(pBuffer : in Interfaces.C.char_array; bytesWritten : out Integer);
procedure Ada_Execute_calculate_mppt_QGenC;

end calculate_mppt_QGenC;

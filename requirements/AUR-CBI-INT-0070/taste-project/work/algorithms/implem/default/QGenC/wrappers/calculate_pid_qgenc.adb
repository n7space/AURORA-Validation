with Interfaces.C.Extensions;
use Interfaces.C.Extensions;

package body calculate_pid_QGenC is

procedure Ada_Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value(pBuffer : in Interfaces.C.char_array; bytesWritten : out Integer) is
    function C_Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value(pBuffer : Interfaces.C.char_array) return Integer;
    pragma Import(C, C_Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value, "Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value");
begin
    bytesWritten := C_Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value(pBuffer);
end Ada_Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value;

procedure Ada_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p(pBuffer : Interfaces.C.char_array) is
    procedure C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p(pBuffer : Interfaces.C.char_array);
    pragma Import(C, C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p, "Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p");
begin
    C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p(pBuffer);
end Ada_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p;

procedure Ada_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i(pBuffer : Interfaces.C.char_array) is
    procedure C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i(pBuffer : Interfaces.C.char_array);
    pragma Import(C, C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i, "Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i");
begin
    C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i(pBuffer);
end Ada_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i;

procedure Ada_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d(pBuffer : Interfaces.C.char_array) is
    procedure C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d(pBuffer : Interfaces.C.char_array);
    pragma Import(C, C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d, "Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d");
begin
    C_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d(pBuffer);
end Ada_Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d;

procedure Ada_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value(pBuffer : Interfaces.C.char_array) is
    procedure C_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value(pBuffer : Interfaces.C.char_array);
    pragma Import(C, C_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value, "Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value");
begin
    C_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value(pBuffer);
end Ada_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value;

procedure Ada_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value(pBuffer : Interfaces.C.char_array) is
    procedure C_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value(pBuffer : Interfaces.C.char_array);
    pragma Import(C, C_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value, "Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value");
begin
    C_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value(pBuffer);
end Ada_Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value;

procedure Ada_Execute_calculate_pid_QGenC is
    procedure C_Execute_calculate_pid_QGenC;
    pragma Import(C, C_Execute_calculate_pid_QGenC, "Execute_calculate_pid_QGenC");
begin
    C_Execute_calculate_pid_QGenC;
end Ada_Execute_calculate_pid_QGenC;


end calculate_pid_QGenC;
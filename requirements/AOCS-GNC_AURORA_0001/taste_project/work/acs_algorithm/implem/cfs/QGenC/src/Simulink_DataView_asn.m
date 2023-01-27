T_Float = Simulink.AliasType;
T_Float.BaseType = 'double';
T_Float.Description = 'range is (-3.4e+38, 3.4e+38)';
T_Float.HeaderFile = 'simulink_definition_of_types.h';

T_B_b_T_member_data=Simulink.BusElement;
T_B_b_T_member_data.Name='arr';
T_B_b_T_member_data.DataType='double';
T_B_b_T_member_data.Dimensions=15;

T_B_b_T=Simulink.Bus;
T_B_b_T.HeaderFile = 'simulink_definition_of_types.h';
T_B_b_T.Elements = [T_B_b_T_member_data ];

T_Omega_member_data=Simulink.BusElement;
T_Omega_member_data.Name='arr';
T_Omega_member_data.DataType='double';
T_Omega_member_data.Dimensions=3;

T_Omega=Simulink.Bus;
T_Omega.HeaderFile = 'simulink_definition_of_types.h';
T_Omega.Elements = [T_Omega_member_data ];

T_MT_Working_member_data=Simulink.BusElement;
T_MT_Working_member_data.Name='arr';
T_MT_Working_member_data.DataType='double';
T_MT_Working_member_data.Dimensions=3;

T_MT_Working=Simulink.Bus;
T_MT_Working.HeaderFile = 'simulink_definition_of_types.h';
T_MT_Working.Elements = [T_MT_Working_member_data ];

T_Control_member_data=Simulink.BusElement;
T_Control_member_data.Name='arr';
T_Control_member_data.DataType='double';
T_Control_member_data.Dimensions=3;

T_Control=Simulink.Bus;
T_Control.HeaderFile = 'simulink_definition_of_types.h';
T_Control.Elements = [T_Control_member_data ];

T_UInteger32 = Simulink.AliasType;
T_UInteger32.BaseType = 'uint32';
T_UInteger32.Description = 'range is (0, 4294967295)';
T_UInteger32.HeaderFile = 'simulink_definition_of_types.h';

T_Telemetry_elem01=Simulink.BusElement;
T_Telemetry_elem01.Name='m_sensors';
T_Telemetry_elem01.DataType='T_B_b_T';
T_Telemetry_elem01.Dimensions=1;

T_Telemetry_elem02=Simulink.BusElement;
T_Telemetry_elem02.Name='m_control';
T_Telemetry_elem02.DataType='T_Control';
T_Telemetry_elem02.Dimensions=1;

T_Telemetry_elem03=Simulink.BusElement;
T_Telemetry_elem03.Name='m_step';
T_Telemetry_elem03.DataType='uint32';
T_Telemetry_elem03.Dimensions=1;

T_Telemetry = Simulink.Bus;
T_Telemetry.HeaderFile = 'simulink_definition_of_types.h';
T_Telemetry.Elements = [T_Telemetry_elem01 T_Telemetry_elem02 T_Telemetry_elem03 ];

T_Telecommand_elem01=Simulink.BusElement;
T_Telecommand_elem01.Name='choiceIdx';
T_Telecommand_elem01.DataType='uint8';
T_Telecommand_elem01.Dimensions=1;

T_Telecommand_elem02=Simulink.BusElement;
T_Telecommand_elem02.Name='m_start';
T_Telecommand_elem02.DataType='T_Telecommand_m_start';
T_Telecommand_elem02.Dimensions=1;

T_Telecommand_elem03=Simulink.BusElement;
T_Telecommand_elem03.Name='m_pause';
T_Telecommand_elem03.DataType='T_Telecommand_m_pause';
T_Telecommand_elem03.Dimensions=1;

T_Telecommand_elem04=Simulink.BusElement;
T_Telecommand_elem04.Name='m_stop';
T_Telecommand_elem04.DataType='T_Telecommand_m_stop';
T_Telecommand_elem04.Dimensions=1;

T_Telecommand_elem05=Simulink.BusElement;
T_Telecommand_elem05.Name='m_restart';
T_Telecommand_elem05.DataType='T_Telecommand_m_restart';
T_Telecommand_elem05.Dimensions=1;

T_Telecommand = Simulink.Bus;
T_Telecommand.HeaderFile = 'simulink_definition_of_types.h';
T_Telecommand.Elements = [T_Telecommand_elem01 T_Telecommand_elem02 T_Telecommand_elem03 T_Telecommand_elem04 T_Telecommand_elem05 ];

T_Int32 = Simulink.AliasType;
T_Int32.BaseType = 'int32';
T_Int32.Description = 'range is (-2147483648, 2147483647)';
T_Int32.HeaderFile = 'simulink_definition_of_types.h';

T_UInt32 = Simulink.AliasType;
T_UInt32.BaseType = 'uint32';
T_UInt32.Description = 'range is (0, 4294967295)';
T_UInt32.HeaderFile = 'simulink_definition_of_types.h';

T_Int8 = Simulink.AliasType;
T_Int8.BaseType = 'int8';
T_Int8.Description = 'range is (-128, 127)';
T_Int8.HeaderFile = 'simulink_definition_of_types.h';

T_UInt8 = Simulink.AliasType;
T_UInt8.BaseType = 'uint8';
T_UInt8.Description = 'range is (0, 255)';
T_UInt8.HeaderFile = 'simulink_definition_of_types.h';

T_Boolean = Simulink.AliasType;
T_Boolean.BaseType = 'boolean';
T_Boolean.Description = 'A simple BOOLEAN';
T_Boolean.HeaderFile = 'simulink_definition_of_types.h';

PID_Range = Simulink.AliasType;
PID_Range.BaseType = 'uint8';
PID_Range.Description = 'range is (0, 4)';
PID_Range.HeaderFile = 'simulink_definition_of_types.h';

% Values for PID:
PID_value_acs_algorithm = 0;
PID_value_mmi = 1;
PID_value_measurer_and_actuator = 2;
PID_value_simulated_acs_hw = 3;
PID_value_env = 4;
PID = Simulink.AliasType;
PID.BaseType = 'int32';
PID.Description = 'values of ENUMERATED PID';
PID.HeaderFile = 'simulink_definition_of_types.h';



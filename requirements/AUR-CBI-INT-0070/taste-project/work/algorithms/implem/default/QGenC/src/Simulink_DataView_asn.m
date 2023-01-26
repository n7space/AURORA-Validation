AuroraInt = Simulink.AliasType;
AuroraInt.BaseType = 'int32';
AuroraInt.Description = 'range is (-1000000, 1000000)';

AuroraUInt = Simulink.AliasType;
AuroraUInt.BaseType = 'uint32';
AuroraUInt.Description = 'range is (0, 1000000)';

AuroraReal = Simulink.AliasType;
AuroraReal.BaseType = 'double';
AuroraReal.Description = 'range is (-1000000.0, 1000000.0)';

AuroraVoltage = Simulink.AliasType;
AuroraVoltage.BaseType = 'double';
AuroraVoltage.Description = 'range is (-1000000.0, 1000000.0)';

AuroraCurrent = Simulink.AliasType;
AuroraCurrent.BaseType = 'double';
AuroraCurrent.Description = 'range is (-1000000.0, 1000000.0)';

AuroraPWM = Simulink.AliasType;
AuroraPWM.BaseType = 'double';
AuroraPWM.Description = 'range is (-1000000.0, 1000000.0)';

AuroraPIDValue = Simulink.AliasType;
AuroraPIDValue.BaseType = 'double';
AuroraPIDValue.Description = 'range is (-1000000.0, 1000000.0)';

AuroraTemperature = Simulink.AliasType;
AuroraTemperature.BaseType = 'double';
AuroraTemperature.Description = 'range is (-1000000.0, 1000000.0)';

AuroraFlowRate = Simulink.AliasType;
AuroraFlowRate.BaseType = 'double';
AuroraFlowRate.Description = 'range is (-1000000.0, 1000000.0)';

AuroraBatteryCapacity = Simulink.AliasType;
AuroraBatteryCapacity.BaseType = 'double';
AuroraBatteryCapacity.Description = 'range is (-1000000.0, 1000000.0)';

AuroraControllerStatus_elem01=Simulink.BusElement;
AuroraControllerStatus_elem01.Name='payload_temperature';
AuroraControllerStatus_elem01.DataType='double';
AuroraControllerStatus_elem01.Dimensions=1;

AuroraControllerStatus_elem02=Simulink.BusElement;
AuroraControllerStatus_elem02.Name='payload_flow_rate';
AuroraControllerStatus_elem02.DataType='double';
AuroraControllerStatus_elem02.Dimensions=1;

AuroraControllerStatus_elem03=Simulink.BusElement;
AuroraControllerStatus_elem03.Name='battery_capacity';
AuroraControllerStatus_elem03.DataType='double';
AuroraControllerStatus_elem03.Dimensions=1;

AuroraControllerStatus_elem04=Simulink.BusElement;
AuroraControllerStatus_elem04.Name='solar_panel_voltage';
AuroraControllerStatus_elem04.DataType='double';
AuroraControllerStatus_elem04.Dimensions=1;

AuroraControllerStatus_elem05=Simulink.BusElement;
AuroraControllerStatus_elem05.Name='solar_panel_current';
AuroraControllerStatus_elem05.DataType='double';
AuroraControllerStatus_elem05.Dimensions=1;

AuroraControllerStatus = Simulink.Bus;
AuroraControllerStatus.Elements = [AuroraControllerStatus_elem01 AuroraControllerStatus_elem02 AuroraControllerStatus_elem03 AuroraControllerStatus_elem04 AuroraControllerStatus_elem05 ];

T_Int32 = Simulink.AliasType;
T_Int32.BaseType = 'int32';
T_Int32.Description = 'range is (-2147483648, 2147483647)';

T_UInt32 = Simulink.AliasType;
T_UInt32.BaseType = 'uint32';
T_UInt32.Description = 'range is (0, 4294967295)';

T_Int8 = Simulink.AliasType;
T_Int8.BaseType = 'int8';
T_Int8.Description = 'range is (-128, 127)';

T_UInt8 = Simulink.AliasType;
T_UInt8.BaseType = 'uint8';
T_UInt8.Description = 'range is (0, 255)';

T_Boolean = Simulink.AliasType;
T_Boolean.BaseType = 'boolean';
T_Boolean.Description = 'A simple BOOLEAN';

PID_Range = Simulink.AliasType;
PID_Range.BaseType = 'uint8';
PID_Range.Description = 'range is (0, 6)';

% Values for PID:
PID_value_algorithms = 0;
PID_value_controller = 1;
PID_value_electrics_power_supply = 2;
PID_value_master_clock = 3;
PID_value_mmi = 4;
PID_value_payload = 5;
PID_value_env = 6;
PID = Simulink.AliasType;
PID.BaseType = 'int32';
PID.Description = 'values of ENUMERATED PID';



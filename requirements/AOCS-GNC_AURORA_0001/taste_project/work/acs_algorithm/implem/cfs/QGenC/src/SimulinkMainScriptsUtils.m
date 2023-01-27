classdef SimulinkMainScriptsUtils
    methods (Static, Access = public)
        function dataview_c_directory_path = find_dataview_c_directory_path()
            work_directory_path         = regexp(pwd, 'work\\.+\\QGenC\\src', 'match');
            src_directory_nesting_level = length(strfind(work_directory_path{1}, '\'));

            dataview_c_directory_path   = '';

            for i = 1:src_directory_nesting_level
                dataview_c_directory_path = strcat('..\', dataview_c_directory_path);
            end

            dataview_c_directory_path = strcat(dataview_c_directory_path, 'dataview\C');
        end

        function c_stub_file_name = prepare_c_stub_file(iv_block_name)
            stub_file_name   = strcat(iv_block_name, '_invoke_ri.c.stub');
            c_stub_file_name = strrep(stub_file_name, '.c.stub', '.c');

            copyfile(stub_file_name, c_stub_file_name)
        end

        function [] = remove_prepared_c_stub_file(c_stub_file_name)
            delete(c_stub_file_name);
        end

        function function_to_call = generate_function_to_call(iv_block_name, required_interface_name, interface_datatypes, interface_directions)
            input_argument_index  = 1;
            output_argument_index = 1;

            function_to_call      = strcat("void ", iv_block_name, '_RI_', required_interface_name, '(');

            for i = 1:length(interface_datatypes)
                datatype  = interface_datatypes{i};
                direction = interface_directions{i};

                if strcmp(direction, 'IN')
                    input_argument_name   = strcat(datatype, ' u', string(input_argument_index), '[1]');
                    function_to_call      = strcat(function_to_call, input_argument_name, ", ");
                    input_argument_index  = input_argument_index + 1;
                else
                    output_argument_name  = strcat(datatype, ' y', string(output_argument_index), '[1]');
                    function_to_call      = strcat(function_to_call, output_argument_name, ", ");
                    output_argument_index = output_argument_index + 1;
                end
            end

            function_to_call        = convertStringsToChars(function_to_call);
            function_to_call(end-1) = '';
            function_to_call(end)   = ')';
        end

        function def = compile_s_function(s_function_block_name, function_to_call, iv_block_name, dataview_c_directory_path)
            def                     = legacy_code('initialize');

            def.SFunctionName       = s_function_block_name;
            def.OutputFcnSpec       = function_to_call;
            def.HeaderFiles         = { strcat(iv_block_name, '_invoke_ri.h') };
            def.SourceFiles         = { strcat(iv_block_name, '_invoke_ri.c') };
            def.IncPaths            = { dataview_c_directory_path };
            def.SrcPaths            = {};
            def.SampleTime          = [1, 0]; % -> A discrete sample time.

            legacy_code('sfcn_cmex_generate', def);
            legacy_code('compile', def);
        end

        function [] = set_inputs_bus_creator(in_type, in_bus_creator)
            if isa(in_type, 'Simulink.Bus')
                s = '';

                if length(in_type.Elements) == 1
                    set_param(in_bus_creator, 'Inputs', '1');
                else
                    for i = 1:length(in_type.Elements)
                        s = strcat(s, in_type.Elements(i).Name);

                        if i < length(in_type.Elements)
                        s = strcat(s, ',');
                        end
                    end

                    set_param(in_bus_creator, 'Inputs', s);
                end
            end
        end

        function [] = set_outputs_bus_selector(in_type, in_bus_selector)
            if isa(in_type, 'Simulink.Bus')
                s = '';

                for i = 1:length(in_type.Elements)
                    s = strcat(s,in_type.Elements(i).Name);

                    if i < length(in_type.Elements)
                        s = strcat(s, ',');
                    end
                end

                set_param(in_bus_selector, 'OutputSignals', s);
            end
        end

        function index = get_s_function_index_by_function_to_call(s_functions, function_to_call)
            for i = 1:length(s_functions)
                if strcmp(s_functions{i}.function_to_call, function_to_call)
                    index = i;
                    return;
                end
            end

            index = -1;
        end

        function index = get_s_function_index_by_function_to_call_name(s_functions, function_to_call_name)
            for i = 1:length(s_functions)
                s_function_function_to_call_name = extractBefore(s_functions{i}.function_to_call, '(');

                if strcmp(s_function_function_to_call_name, function_to_call_name)
                    index = i;
                    return;
                end
            end

            index = -1;
        end

        function [] = set_system_parameters(system_name)
            set_param(system_name, 'SaveOutput',         'off');
            set_param(system_name, 'SignalLogging',      'off');
            set_param(system_name, 'SaveTime',           'off')
            set_param(system_name, 'Solver',             'FixedStepDiscrete');
            set_param(system_name, 'SystemTargetFile',   'ert.tlc');
            set_param(system_name, 'TemplateMakefile',   'ert_default_tmf');
            set_param(system_name, 'PostCodeGenCommand', 'packNGo(buildInfo);');
            set_param(system_name, 'StrictBusMsg',       'ErrorLevel1');
        end
    end
end

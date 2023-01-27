run Simulink_DataView_asn;


% ----------------------------------------------------------------------------------------------------------------------------------------------------
% ----------------------------------------------------------------------------------------------------------------------------------------------------
% 'Step' protected interface

n_inports              = 1 + 1 + 1 + 1 + 1 + 1;
inport_index           = 0;
all_inports_created    = false;
inports_positions      = zeros(1, 4);
bus_selector_positions = zeros(1, 4);

n_outports             = 1;
outport_index          = 0;
all_outports_created   = false;
outports_positions     = zeros(1, 4);
bus_creator_positions  = zeros(1, 4);

if exist('generated_s_functions', 'var') == 1
   current_s_functions = generated_s_functions;
end

if exist('Step', 'file') == 4
   load_system('Step');

   inport_handles       = find_system('Step', 'FindAll', 'on', 'SearchDepth', 1, 'BlockType', 'Inport');
   outport_handles      = find_system('Step', 'FindAll', 'on', 'SearchDepth', 1, 'BlockType', 'Outport');
   s_function_handles   = find_system('Step', 'FindAll', 'on', 'SearchDepth', 1, 'BlockType', 'S-Function');

   all_inports_created  = (length(inport_handles)  == n_inports);
   all_outports_created = (length(outport_handles) == n_outports);

   % ---------------------------------------------------------------------------------
   % start by removing the Bus Selectors / then lines / finally ports
   % ---------------------------------------------------------------------------------

   % get the handles of all the lines connected to inports
   for i=1:length(inport_handles)
      inports_positions(i,:) = get_param(inport_handles(i), 'Position');         % remember Inport's position
      line_structsIn(i)      = get_param(inport_handles(i), 'LineHandles');      % get the structures
      inLinesHan(i)          = line_structsIn(i).Outport;                        % get the line connected to the block's Outport

      if inLinesHan(i) ~= -1                                                     % if exists
         dstBlock = get_param(inLinesHan(i), 'DstBlockHandle');                  % get the destination block's handle

         if strcmp(get_param(dstBlock, 'BlockType'), 'BusSelector')
            bus_selector_positions(i,:) = get_param(dstBlock, 'Position');       % remember Bus Selector's position
            blockLineStructs            = get_param(dstBlock, 'LineHandles');    % get the line connected structures
            blockLineHandles            = blockLineStructs.Outport;              % get the line handlers connected to the bus's outports

            for j=1:length(blockLineHandles)
               if blockLineHandles(j) ~= -1
                  delete(blockLineHandles(j));
               end
            end

            delete_block(dstBlock);                                              % delete it if it is a Bus Selector Block
         end

         delete(inLinesHan(i));                                                  % delete the respective line
      end

      delete_block(inport_handles(i));                                           % delete the outdated inport block
   end

   % now remove the outports
   for i=1:length(outport_handles)
      outports_positions(i,:) = get_param(outport_handles(i), 'Position');       % remember Outport's position
      line_structsOut(i)      = get_param(outport_handles(i), 'LineHandles');    % get the structures
      outLinesHan(i)          = line_structsOut(i).Inport;                       % get the line connected to the block's Inport

      if outLinesHan(i) ~= -1                                                    % if exists
         srcBlock = get_param(outLinesHan(i), 'SrcBlockHandle');                 % get the source block's handle

         if strcmp(get_param(srcBlock,'BlockType'), 'BusCreator')
            bus_creator_positions(i,:) = get_param(srcBlock, 'Position');        % remember Bus Creator's position
            blockLineStructs           = get_param(srcBlock, 'LineHandles');     % get the line connected structures
            blockLineHandles           = blockLineStructs.Inport;                % get the line handlers connected to the bus's outports

            for j=1:length(blockLineHandles)
               if blockLineHandles(j) ~= -1
                  delete(blockLineHandles(j));
               end
            end

            delete_block(srcBlock);                                              % delete it if it is a Bus Creator Block
         end

         delete(outLinesHan(i));                                                 % delete the respective line
      end

      delete_block(outport_handles(i));                                          % delete the outdated outport block
   end

   % s-functions
   if exist('generated_s_functions', 'var') == 1
      for i=1:length(s_function_handles)
         s_function_mask             = Simulink.Mask.get(s_function_handles(i));
         s_function_function_to_call = s_function_mask.Parameters(1, 1).Value;
         s_function_index            = SimulinkMainScriptsUtils.get_s_function_index_by_function_to_call(current_s_functions, s_function_function_to_call);

         if s_function_index ~= -1
            current_s_functions(s_function_index) = [];
            continue;
         else
            s_function_function_to_call_name = extractBefore(s_function_function_to_call, '(');
            s_function_index                 = SimulinkMainScriptsUtils.get_s_function_index_by_function_to_call_name(current_s_functions, s_function_function_to_call_name);

            if s_function_index ~= -1
               current_s_functions{s_function_index}.position = get_param(s_function_handles(i), 'Position');
            end
         end

         s_function_line_handles = get_param(s_function_handles(i), 'LineHandles');

         for s_function_inport = s_function_line_handles.Inport
            if s_function_inport ~= -1
               delete(s_function_inport);
            end
         end

         for s_function_outport = s_function_line_handles.Outport
            if s_function_outport ~= -1
               delete(s_function_outport);
            end
         end

         delete_block(s_function_handles(i));
      end
   end
else
   new_system('Step');
   load_system('Step');
end

% --------------------------------------------------------------------------
% inport name:      BBT
% inport direction: PARAM_IN

inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'Step/BBT');
if all_inports_created
   set_param('Step/BBT', 'Position', inports_positions(inport_index, :));
else
   set_param('Step/BBT', 'Position', [25, (inport_index * 100), 55, ((inport_index * 100) + 14)]);
end
set_param('Step/BBT', 'BusOutputAsStruct', 'on');
set_param('Step/BBT', 'UseBusObject', 'on');
set_param('Step/BBT', 'BusObject', 'T_B_b_T');
add_block('simulink/Commonly Used Blocks/Bus Selector', 'Step/BBT_T_B_b_T_BusSel');
add_line('Step','BBT/1', 'BBT_T_B_b_T_BusSel/1');
SimulinkMainScriptsUtils.set_outputs_bus_selector(T_B_b_T, 'Step/BBT_T_B_b_T_BusSel');
if all_inports_created
   set_param('Step/BBT_T_B_b_T_BusSel', 'Position', bus_selector_positions(inport_index, :));
else
   set_param('Step/BBT_T_B_b_T_BusSel', 'Position', [95, ((inport_index * 100) - 19), 100, ((inport_index * 100) + 19)]);
end

% --------------------------------------------------------------------------
% inport name:      Omega
% inport direction: PARAM_IN

inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'Step/Omega');
if all_inports_created
   set_param('Step/Omega', 'Position', inports_positions(inport_index, :));
else
   set_param('Step/Omega', 'Position', [25, (inport_index * 100), 55, ((inport_index * 100) + 14)]);
end
set_param('Step/Omega', 'BusOutputAsStruct', 'on');
set_param('Step/Omega', 'UseBusObject', 'on');
set_param('Step/Omega', 'BusObject', 'T_Omega');
add_block('simulink/Commonly Used Blocks/Bus Selector', 'Step/Omega_T_Omega_BusSel');
add_line('Step','Omega/1', 'Omega_T_Omega_BusSel/1');
SimulinkMainScriptsUtils.set_outputs_bus_selector(T_Omega, 'Step/Omega_T_Omega_BusSel');
if all_inports_created
   set_param('Step/Omega_T_Omega_BusSel', 'Position', bus_selector_positions(inport_index, :));
else
   set_param('Step/Omega_T_Omega_BusSel', 'Position', [95, ((inport_index * 100) - 19), 100, ((inport_index * 100) + 19)]);
end

% --------------------------------------------------------------------------
% inport name:      K_PB
% inport direction: PARAM_IN

inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'Step/K_PB');
if all_inports_created
   set_param('Step/K_PB', 'Position', inports_positions(inport_index, :));
else
   set_param('Step/K_PB', 'Position', [25, (inport_index * 100), 55, ((inport_index * 100) + 14)]);
end
set_param('Step/K_PB', 'BusOutputAsStruct', 'on');
set_param('Step/K_PB', 'OutDataTypeStr', 'T_Float');

% --------------------------------------------------------------------------
% inport name:      K_PE
% inport direction: PARAM_IN

inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'Step/K_PE');
if all_inports_created
   set_param('Step/K_PE', 'Position', inports_positions(inport_index, :));
else
   set_param('Step/K_PE', 'Position', [25, (inport_index * 100), 55, ((inport_index * 100) + 14)]);
end
set_param('Step/K_PE', 'BusOutputAsStruct', 'on');
set_param('Step/K_PE', 'OutDataTypeStr', 'T_Float');

% --------------------------------------------------------------------------
% inport name:      M_M
% inport direction: PARAM_IN

inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'Step/M_M');
if all_inports_created
   set_param('Step/M_M', 'Position', inports_positions(inport_index, :));
else
   set_param('Step/M_M', 'Position', [25, (inport_index * 100), 55, ((inport_index * 100) + 14)]);
end
set_param('Step/M_M', 'BusOutputAsStruct', 'on');
set_param('Step/M_M', 'OutDataTypeStr', 'T_Float');

% --------------------------------------------------------------------------
% inport name:      MT_Working
% inport direction: PARAM_IN

inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'Step/MT_Working');
if all_inports_created
   set_param('Step/MT_Working', 'Position', inports_positions(inport_index, :));
else
   set_param('Step/MT_Working', 'Position', [25, (inport_index * 100), 55, ((inport_index * 100) + 14)]);
end
set_param('Step/MT_Working', 'BusOutputAsStruct', 'on');
set_param('Step/MT_Working', 'UseBusObject', 'on');
set_param('Step/MT_Working', 'BusObject', 'T_MT_Working');
add_block('simulink/Commonly Used Blocks/Bus Selector', 'Step/MT_Working_T_MT_Working_BusSel');
add_line('Step','MT_Working/1', 'MT_Working_T_MT_Working_BusSel/1');
SimulinkMainScriptsUtils.set_outputs_bus_selector(T_MT_Working, 'Step/MT_Working_T_MT_Working_BusSel');
if all_inports_created
   set_param('Step/MT_Working_T_MT_Working_BusSel', 'Position', bus_selector_positions(inport_index, :));
else
   set_param('Step/MT_Working_T_MT_Working_BusSel', 'Position', [95, ((inport_index * 100) - 19), 100, ((inport_index * 100) + 19)]);
end








% --------------------------------------------------------------------------
% outport name:      Control
% outport direction: PARAM_OUT

outport_index = outport_index + 1;
add_block('simulink/Sinks/Out1', 'Step/Control');
if all_outports_created
   set_param('Step/Control', 'Position', outports_positions(outport_index, :));
else
   set_param('Step/Control', 'Position', [430, (outport_index * 100), 460, ((outport_index * 100) + 14)]);
end
set_param('Step/Control', 'UseBusObject','on');
set_param('Step/Control', 'BusObject','T_Control');
add_block('simulink/Commonly Used Blocks/Bus Creator', 'Step/Control_T_Control_BusCre');
add_line('Step', 'Control_T_Control_BusCre/1', 'Control/1');
SimulinkMainScriptsUtils.set_inputs_bus_creator(T_Control, 'Step/Control_T_Control_BusCre');
set_param('Step/Control', 'UseBusObject', 'on');
set_param('Step/Control', 'BusOutputAsStruct', 'on');
set_param('Step/Control_T_Control_BusCre', 'BusObject', 'T_Control');
if all_outports_created
   set_param('Step/Control_T_Control_BusCre', 'Position', bus_creator_positions(outport_index, :));
else
   set_param('Step/Control_T_Control_BusCre', 'Position', [360, ((outport_index * 100) - 19), 365, ((outport_index * 100) + 19)]);
end
set_param('Step/Control_T_Control_BusCre', 'UseBusObject', 'on');
set_param('Step/Control_T_Control_BusCre', 'NonVirtualBus', 'on');


if exist('generated_s_functions', 'var') == 1
   s_function_block_pos_under_last_inport = [];

   if all_inports_created
      s_function_block_pos_under_last_inport    = inports_positions(inport_index,:);
      s_function_block_pos_under_last_inport    = s_function_block_pos_under_last_inport(1:2);
      s_function_block_pos_under_last_inport(2) = s_function_block_pos_under_last_inport(2) + 75;
   else
      s_function_block_pos_under_last_inport = [25, inport_index * 100 + 75];
   end

   for i = 1:length(current_s_functions)
      s_function               = current_s_functions{i};
      s_function_block_old_pos = s_function.position;
      s_function_block_path    = strcat('Step', '/', s_function.block_name);

      legacy_code('slblock_generate', s_function.def, 'Step');

      s_function_mask = Simulink.Mask.get(s_function_block_path);
      s_function_mask.Parameters(1, 2).Tunable = 'off';

      % if you want to display full function declaration in sfunction block - just uncomment the line
      % s_function_mask.Parameters(1, 2).Value = 'on';

      s_function_block_current_pos = get_param(s_function_block_path, 'Position');
      s_function_block_new_pos     = [];

      if isempty(s_function_block_old_pos)
         s_function_block_new_pos = [s_function_block_pos_under_last_inport(1), ...
                                     s_function_block_pos_under_last_inport(2), ...
                                     s_function_block_pos_under_last_inport(1) + s_function_block_current_pos(3), ...
                                     s_function_block_pos_under_last_inport(2) + s_function_block_current_pos(4)];

         s_function_block_pos_under_last_inport = [s_function_block_pos_under_last_inport(1), ...
                                                   s_function_block_pos_under_last_inport(2) + 75];
      else
         s_function_block_new_pos = [s_function_block_old_pos(1), ...
                                     s_function_block_old_pos(2), ...
                                     s_function_block_old_pos(1) + s_function_block_current_pos(3), ...
                                     s_function_block_old_pos(2) + s_function_block_current_pos(4)];
      end

      set_param(s_function_block_path, 'Position', s_function_block_new_pos + 10);
   end
end

SimulinkMainScriptsUtils.set_system_parameters('Step');

save_system('Step');
close_system('Step');

% end of 'Step' protected interface
% ----------------------------------------------------------------------------------------------------------------------------------------------------
% ----------------------------------------------------------------------------------------------------------------------------------------------------

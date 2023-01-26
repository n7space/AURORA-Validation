run Simulink_DataView_asn;

inports_positions  = zeros(1, 4);
bussel_positions   = zeros(1, 4);
outports_positions = zeros(1, 4);
buscre_positions   = zeros(1, 4);

n_inports  = 1 + 1;
n_outports = 1;

all_inports_created  = false;
all_outports_created = false;

if (exist('calculate_mppt', 'file') == 4)
   load_system('calculate_mppt');
   inportHan = find_system('calculate_mppt','FindAll','on', 'SearchDepth', 1, 'BlockType','Inport');
   outportHan = find_system('calculate_mppt','FindAll','on', 'SearchDepth', 1, 'BlockType','Outport');
   all_inports_created  = (length(inportHan) == n_inports);
   all_outports_created = (length(outportHan) == n_outports);
   % ---------------------------------------------------------------------------------
   % start by removing the Bus Selectors / then lines / finally ports
   % ---------------------------------------------------------------------------------
   % get the handles of all the lines connected to inports
   for i=1:length(inportHan)
      inports_positions(i,:) = get_param(inportHan(i),'Position'); % remember Inport's position
      line_structsIn(i)=get_param(inportHan(i),'LineHandles'); % get the structures
      inLinesHan(i)=line_structsIn(i).Outport;        % get the line connected to the block's Outport
      if (inLinesHan(i) ~= -1) % if exists
         dstBlock = get_param(inLinesHan(i),'DstBlockHandle'); % get the destination block's handle
         if (strcmp(get_param(dstBlock,'BlockType'),'BusSelector'))
            bussel_positions(i,:) = get_param(dstBlock,'Position'); % remember Bus Selector's position
            blockLineStructs = get_param(dstBlock,'LineHandles'); % get the line connected structures
            blockLineHandles = blockLineStructs.Outport; % get the line handlers connected to the bus's outports
            for j=1:length(blockLineHandles)
               if (blockLineHandles(j) ~= -1)
                  delete(blockLineHandles(j));
               end
            end
            delete_block(dstBlock); % delete it if it is a Bus Selector Block
         end
         delete(inLinesHan(i)); % delete the respective line
      end
      delete_block(inportHan(i)); % delete the outdated inport block
   end
   % now remove the outports
   for i=1:length(outportHan)
      outports_positions(i,:) = get_param(outportHan(i),'Position'); % remember Outport's position
      line_structsOut(i)=get_param(outportHan(i),'LineHandles'); % get the structures
      outLinesHan(i)=line_structsOut(i).Inport;       % get the line connected to the block's Inport
      if (outLinesHan(i) ~= -1) % if exists
         srcBlock = get_param(outLinesHan(i),'SrcBlockHandle'); % get the source block's handle
         if (strcmp(get_param(srcBlock,'BlockType'),'BusCreator'))
            buscre_positions(i,:) = get_param(srcBlock,'Position'); % remember Bus Creator's position
            blockLineStructs = get_param(srcBlock,'LineHandles'); % get the line connected structures
            blockLineHandles = blockLineStructs.Inport; % get the line handlers connected to the bus's outports
            for j=1:length(blockLineHandles)
                    if (blockLineHandles(j) ~= -1)
                            delete(blockLineHandles(j));
                    end
            end
            delete_block(srcBlock); % delete it if it is a Bus Creator Block
         end
         delete(outLinesHan(i)); % delete the respective line
      end
      delete_block(outportHan(i)); % delete the outdated outport block
   end
else
   new_system('calculate_mppt');
   load_system('calculate_mppt');
end

% These are the parameters for this Simulink function:
   % Name: voltage
   % Direction: PARAM_IN
   % Name: current
   % Direction: PARAM_IN
   % Name: pwm
   % Direction: PARAM_OUT

inport_index = 0;
inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'calculate_mppt/voltage');
if all_inports_created
   set_param('calculate_mppt/voltage','Position', inports_positions(inport_index,:));
else
   set_param('calculate_mppt/voltage','Position',[25 (inport_index * 100) 55 ((inport_index * 100) + 14)]);
end
set_param('calculate_mppt/voltage','BusOutputAsStruct','on');
set_param('calculate_mppt/voltage','OutDataTypeStr','AuroraVoltage');
inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'calculate_mppt/current');
if all_inports_created
   set_param('calculate_mppt/current','Position', inports_positions(inport_index,:));
else
   set_param('calculate_mppt/current','Position',[25 (inport_index * 100) 55 ((inport_index * 100) + 14)]);
end
set_param('calculate_mppt/current','BusOutputAsStruct','on');
set_param('calculate_mppt/current','OutDataTypeStr','AuroraCurrent');

outport_index = 0;
outport_index = outport_index + 1;
add_block('simulink/Sinks/Out1','calculate_mppt/pwm');
if all_outports_created
   set_param('calculate_mppt/pwm','Position', outports_positions(outport_index,:));
else
   set_param('calculate_mppt/pwm','Position',[430 (outport_index * 100) 460 ((outport_index * 100) + 14)]);
end
set_param('calculate_mppt/pwm','OutDataTypeStr','AuroraPWM');

set_param('calculate_mppt','SaveOutput','off');
set_param('calculate_mppt','SignalLogging','off');
set_param('calculate_mppt','SaveTime','off')
set_param('calculate_mppt','Solver','FixedStepDiscrete');
set_param('calculate_mppt','SystemTargetFile','ert.tlc');
set_param('calculate_mppt','TemplateMakefile','ert_default_tmf');
set_param('calculate_mppt', 'PostCodeGenCommand', 'packNGo(buildInfo);');
set_param('calculate_mppt','StrictBusMsg','ErrorLevel1')
save_system('calculate_mppt');
close_system('calculate_mppt');

n_inports  = 1 + 1 + 1 + 1 + 1;
n_outports = 1;

all_inports_created  = false;
all_outports_created = false;

if (exist('calculate_pid', 'file') == 4)
   load_system('calculate_pid');
   inportHan = find_system('calculate_pid','FindAll','on', 'SearchDepth', 1, 'BlockType','Inport');
   outportHan = find_system('calculate_pid','FindAll','on', 'SearchDepth', 1, 'BlockType','Outport');
   all_inports_created  = (length(inportHan) == n_inports);
   all_outports_created = (length(outportHan) == n_outports);
   % ---------------------------------------------------------------------------------
   % start by removing the Bus Selectors / then lines / finally ports
   % ---------------------------------------------------------------------------------
   % get the handles of all the lines connected to inports
   for i=1:length(inportHan)
      inports_positions(i,:) = get_param(inportHan(i),'Position'); % remember Inport's position
      line_structsIn(i)=get_param(inportHan(i),'LineHandles'); % get the structures
      inLinesHan(i)=line_structsIn(i).Outport;        % get the line connected to the block's Outport
      if (inLinesHan(i) ~= -1) % if exists
         dstBlock = get_param(inLinesHan(i),'DstBlockHandle'); % get the destination block's handle
         if (strcmp(get_param(dstBlock,'BlockType'),'BusSelector'))
            bussel_positions(i,:) = get_param(dstBlock,'Position'); % remember Bus Selector's position
            blockLineStructs = get_param(dstBlock,'LineHandles'); % get the line connected structures
            blockLineHandles = blockLineStructs.Outport; % get the line handlers connected to the bus's outports
            for j=1:length(blockLineHandles)
               if (blockLineHandles(j) ~= -1)
                  delete(blockLineHandles(j));
               end
            end
            delete_block(dstBlock); % delete it if it is a Bus Selector Block
         end
         delete(inLinesHan(i)); % delete the respective line
      end
      delete_block(inportHan(i)); % delete the outdated inport block
   end
   % now remove the outports
   for i=1:length(outportHan)
      outports_positions(i,:) = get_param(outportHan(i),'Position'); % remember Outport's position
      line_structsOut(i)=get_param(outportHan(i),'LineHandles'); % get the structures
      outLinesHan(i)=line_structsOut(i).Inport;       % get the line connected to the block's Inport
      if (outLinesHan(i) ~= -1) % if exists
         srcBlock = get_param(outLinesHan(i),'SrcBlockHandle'); % get the source block's handle
         if (strcmp(get_param(srcBlock,'BlockType'),'BusCreator'))
            buscre_positions(i,:) = get_param(srcBlock,'Position'); % remember Bus Creator's position
            blockLineStructs = get_param(srcBlock,'LineHandles'); % get the line connected structures
            blockLineHandles = blockLineStructs.Inport; % get the line handlers connected to the bus's outports
            for j=1:length(blockLineHandles)
                    if (blockLineHandles(j) ~= -1)
                            delete(blockLineHandles(j));
                    end
            end
            delete_block(srcBlock); % delete it if it is a Bus Creator Block
         end
         delete(outLinesHan(i)); % delete the respective line
      end
      delete_block(outportHan(i)); % delete the outdated outport block
   end
else
   new_system('calculate_pid');
   load_system('calculate_pid');
end

% These are the parameters for this Simulink function:
   % Name: output_value
   % Direction: PARAM_OUT
   % Name: k_p
   % Direction: PARAM_IN
   % Name: k_i
   % Direction: PARAM_IN
   % Name: k_d
   % Direction: PARAM_IN
   % Name: input_value
   % Direction: PARAM_IN
   % Name: target_value
   % Direction: PARAM_IN

inport_index = 0;
inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'calculate_pid/k_p');
if all_inports_created
   set_param('calculate_pid/k_p','Position', inports_positions(inport_index,:));
else
   set_param('calculate_pid/k_p','Position',[25 (inport_index * 100) 55 ((inport_index * 100) + 14)]);
end
set_param('calculate_pid/k_p','BusOutputAsStruct','on');
set_param('calculate_pid/k_p','OutDataTypeStr','AuroraPIDValue');
inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'calculate_pid/k_i');
if all_inports_created
   set_param('calculate_pid/k_i','Position', inports_positions(inport_index,:));
else
   set_param('calculate_pid/k_i','Position',[25 (inport_index * 100) 55 ((inport_index * 100) + 14)]);
end
set_param('calculate_pid/k_i','BusOutputAsStruct','on');
set_param('calculate_pid/k_i','OutDataTypeStr','AuroraPIDValue');
inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'calculate_pid/k_d');
if all_inports_created
   set_param('calculate_pid/k_d','Position', inports_positions(inport_index,:));
else
   set_param('calculate_pid/k_d','Position',[25 (inport_index * 100) 55 ((inport_index * 100) + 14)]);
end
set_param('calculate_pid/k_d','BusOutputAsStruct','on');
set_param('calculate_pid/k_d','OutDataTypeStr','AuroraPIDValue');
inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'calculate_pid/input_value');
if all_inports_created
   set_param('calculate_pid/input_value','Position', inports_positions(inport_index,:));
else
   set_param('calculate_pid/input_value','Position',[25 (inport_index * 100) 55 ((inport_index * 100) + 14)]);
end
set_param('calculate_pid/input_value','BusOutputAsStruct','on');
set_param('calculate_pid/input_value','OutDataTypeStr','AuroraReal');
inport_index = inport_index + 1;
add_block('simulink/Sources/In1', 'calculate_pid/target_value');
if all_inports_created
   set_param('calculate_pid/target_value','Position', inports_positions(inport_index,:));
else
   set_param('calculate_pid/target_value','Position',[25 (inport_index * 100) 55 ((inport_index * 100) + 14)]);
end
set_param('calculate_pid/target_value','BusOutputAsStruct','on');
set_param('calculate_pid/target_value','OutDataTypeStr','AuroraReal');

outport_index = 0;
outport_index = outport_index + 1;
add_block('simulink/Sinks/Out1','calculate_pid/output_value');
if all_outports_created
   set_param('calculate_pid/output_value','Position', outports_positions(outport_index,:));
else
   set_param('calculate_pid/output_value','Position',[430 (outport_index * 100) 460 ((outport_index * 100) + 14)]);
end
set_param('calculate_pid/output_value','OutDataTypeStr','AuroraPWM');

set_param('calculate_pid','SaveOutput','off');
set_param('calculate_pid','SignalLogging','off');
set_param('calculate_pid','SaveTime','off')
set_param('calculate_pid','Solver','FixedStepDiscrete');
set_param('calculate_pid','SystemTargetFile','ert.tlc');
set_param('calculate_pid','TemplateMakefile','ert_default_tmf');
set_param('calculate_pid', 'PostCodeGenCommand', 'packNGo(buildInfo);');
set_param('calculate_pid','StrictBusMsg','ErrorLevel1')
save_system('calculate_pid');
close_system('calculate_pid');

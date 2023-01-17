all: compile-linux

clean:
	rm -rf obj ./xmi

edit:
	matlab -desktop -sd src

generate-code: ./xmi/calculate_mppt_built ./xmi/calculate_pid_built

./xmi/calculate_mppt_built: ./src/calculate_mppt.slx
	$(warning ---------------------------------------------------------------------)
	$(warning NOTE: The following is a patch to generate source code automatically.)
	$(warning ---------------------------------------------------------------------)
	matlab -batch \
	    "cd src; \
	     run ./Simulink_DataView_asn.m; \
	     qgen_export_xmi ('calculate_mppt.slx', '-o', '../xmi'); \
	     exit;"
	qgenc ./xmi/calculate_mppt.xmi --gen-entrypoint --wrap-io --pre-process-xmi --incremental \
	    --no-misra --language c --output src
	touch $@

./xmi/calculate_pid_built: ./src/calculate_pid.slx
	$(warning ---------------------------------------------------------------------)
	$(warning NOTE: The following is a patch to generate source code automatically.)
	$(warning ---------------------------------------------------------------------)
	matlab -batch \
	    "cd src; \
	     run ./Simulink_DataView_asn.m; \
	     qgen_export_xmi ('calculate_pid.slx', '-o', '../xmi'); \
	     exit;"
	qgenc ./xmi/calculate_pid.xmi --gen-entrypoint --wrap-io --pre-process-xmi --incremental \
	    --no-misra --language c --output src
	touch $@

./src/calculate_mppt%slx ./src/calculate_pid%slx : ./src/.algorithms_script.m.md5
	$(warning Edit the Simulink model(s) before the system build.)
	matlab -batch \
	    "cd src; \
	     run algorithms_script.m; \
	     exit;"

./src/.algorithms_script.m.md5: ./src/algorithms_script.m
	test -f $@ || md5sum $< > $@
	md5sum -c $@ &> /dev/null || md5sum $< > $@


compile-linux: generate-code
	mkdir -p obj && cd obj && gcc -c ../src/*.c ../code/*.c ../wrappers/*.c

.PHONY: all clean edit generate-code compile-linux

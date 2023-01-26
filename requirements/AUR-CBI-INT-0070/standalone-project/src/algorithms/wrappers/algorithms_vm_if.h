/* Header file for function algorithms
 * Generated by TASTE (kazoo/templates/glue/language_wrappers/vm_if-header/function.tmplt)
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

/* The purpose of this file is to provide a wrapper around the user code,
 * with a single interface that is independent of the implementation language
 * of the function. The parameters of each PI are blackboxes encoded
 * in the form specified in the interface view (Native, uPER, or ACN)
*/

#pragma once
#if defined(__unix__) || defined (__MSP430__)
   #include <stdlib.h>
   #include <stdio.h>
#else
   typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif


// Function initialization - calls user startup code of all dependent functions
void init_algorithms(void);


/* Provided interfaces */
void algorithms_calculate_mppt
      (const char *IN_voltage, size_t IN_voltage_len,
       const char *IN_current, size_t IN_current_len,
       char *OUT_pwm, size_t *OUT_pwm_len);



void algorithms_calculate_pid
      (char *OUT_output_value, size_t *OUT_output_value_len,
       const char *IN_k_p, size_t IN_k_p_len,
       const char *IN_k_i, size_t IN_k_i_len,
       const char *IN_k_d, size_t IN_k_d_len,
       const char *IN_input_value, size_t IN_input_value_len,
       const char *IN_target_value, size_t IN_target_value_len);


#ifdef __cplusplus
}
#endif


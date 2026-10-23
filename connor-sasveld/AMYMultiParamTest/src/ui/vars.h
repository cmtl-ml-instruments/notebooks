#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_CUTOFF_VALUE = 0,
    FLOW_GLOBAL_VARIABLE_CUTOFF_LABEL_VALUE = 1,
    FLOW_GLOBAL_VARIABLE_RESONANCE_VALUE = 2,
    FLOW_GLOBAL_VARIABLE_RESONANCE_LABEL_VALUE = 3
};

// Native global variables

extern int32_t get_var_cutoff_value();
extern void set_var_cutoff_value(int32_t value);
extern const char *get_var_cutoff_label_value();
extern void set_var_cutoff_label_value(const char *value);
extern int32_t get_var_resonance_value();
extern void set_var_resonance_value(int32_t value);
extern const char *get_var_resonance_label_value();
extern void set_var_resonance_label_value(const char *value);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/
#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_cutoff_slider(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var_cutoff_value(value);
        }
    }
}

static void event_handler_cb_main_resonance_slider(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var_resonance_value(value);
        }
    }
}

//
// Screens
//

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // cutoff_slider
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.cutoff_slider = obj;
            lv_obj_set_pos(obj, 25, 48);
            lv_obj_set_size(obj, 9, 148);
            lv_slider_set_range(obj, 20, 6000);
            lv_obj_add_event_cb(obj, event_handler_cb_main_cutoff_slider, LV_EVENT_ALL, 0);
        }
        {
            // cutoff_label_name
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.cutoff_label_name = obj;
            lv_obj_set_pos(obj, 7, 16);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Filter\nCutoff");
        }
        {
            // cutoff_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.cutoff_label = obj;
            lv_obj_set_pos(obj, 12, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
        {
            // resonance_slider
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.resonance_slider = obj;
            lv_obj_set_pos(obj, 99, 48);
            lv_obj_set_size(obj, 9, 148);
            lv_slider_set_range(obj, 7, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_main_resonance_slider, LV_EVENT_ALL, 0);
        }
        {
            // resonance_label_name
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.resonance_label_name = obj;
            lv_obj_set_pos(obj, 64, 24);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Resonance");
        }
        {
            // resonance_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.resonance_label = obj;
            lv_obj_set_pos(obj, 95, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    {
        int32_t new_val = get_var_cutoff_value();
        int32_t cur_val = lv_slider_get_value(objects.cutoff_slider);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.cutoff_slider;
            lv_slider_set_value(objects.cutoff_slider, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_cutoff_label_value();
        const char *cur_val = lv_label_get_text(objects.cutoff_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.cutoff_label;
            lv_label_set_text(objects.cutoff_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_resonance_value();
        int32_t cur_val = lv_slider_get_value(objects.resonance_slider);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.resonance_slider;
            lv_slider_set_value(objects.resonance_slider, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_resonance_label_value();
        const char *cur_val = lv_label_get_text(objects.resonance_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.resonance_label;
            lv_label_set_text(objects.resonance_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 1) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_main();
}
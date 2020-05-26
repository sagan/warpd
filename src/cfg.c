//GENERATED BY gen_assets.py

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "cfg.h"

static int kvp(char *line, char **key, char **val) {
  *key = NULL;
  *val = NULL;
  
  for(;*line != '\0';line++) {
    if(*line != ' ' && !*key)
      *key = line;
    
    if(*line == ':' && !*val) {
      *line++ = '\0';
      for(;isspace(*line);line++);
      *val = line;
    }
  }
  
  if(*(line - 1) == '\n')
    *(line - 1) = '\0';
  
  if(!(*val && *key))
    return -1;
  
  return 0;
}

struct cfg* parse_cfg(const char *fname) {
    char *line = NULL;
    size_t n = 0, ln = 0;
    struct cfg *cfg = malloc(sizeof(struct cfg));

    cfg->grid_nr = 2;
    cfg->grid_nc = 2;
    cfg->movement_increment = 20;
    cfg->grid_up = "w";
    cfg->grid_left = "a";
    cfg->grid_down = "s";
    cfg->grid_right = "d";
    cfg->grid_keys = "u,i,j,k";
    cfg->hint_activation_key = "M-z";
    cfg->grid_activation_key = "M-x";
    cfg->discrete_activation_key = "M-c";
    cfg->close_key = "Escape";
    cfg->buttons = "m,comma,period";
    cfg->trigger_mods = "M-C";
    cfg->hint_nc = 20;
    cfg->hint_nr = 20;
    cfg->hint_up = "k";
    cfg->hint_left = "h";
    cfg->hint_down = "j";
    cfg->hint_right = "l";
    cfg->hint_bgcol = "#00ff00";
    cfg->hint_fgcol = "#000000";
    cfg->hint_characters = "asdfghjkl;'zxcvbm,./";
    cfg->grid_col = "#ff0000";
    cfg->grid_mouse_col = "#00ff00";
    cfg->grid_pointer_size = 20;
    cfg->grid_line_width = 5;
    cfg->grid_activation_timeout = 300;
    cfg->discrete_left = "h";
    cfg->discrete_down = "j";
    cfg->discrete_up = "k";
    cfg->discrete_right = "l";

    FILE *fp = fopen(fname, "r");
    if(!fp) return cfg; //Return defaults if no config file xists..
    while(getline(&line, &n, fp) != -1) {
        ln++;
        char *key, *val;
        if(kvp(line, &key, &val)) {
            fprintf(stderr, "Invalid entry in %s at line %lu.\n", fname, ln);
            exit(1);
        }

        if(!strcmp(key, "grid_nr"))
            cfg->grid_nr = atoi(val);
        else if(!strcmp(key, "grid_nc"))
            cfg->grid_nc = atoi(val);
        else if(!strcmp(key, "movement_increment"))
            cfg->movement_increment = atoi(val);
        else if(!strcmp(key, "grid_up"))
            cfg->grid_up = strdup(val);
        else if(!strcmp(key, "grid_left"))
            cfg->grid_left = strdup(val);
        else if(!strcmp(key, "grid_down"))
            cfg->grid_down = strdup(val);
        else if(!strcmp(key, "grid_right"))
            cfg->grid_right = strdup(val);
        else if(!strcmp(key, "grid_keys"))
            cfg->grid_keys = strdup(val);
        else if(!strcmp(key, "hint_activation_key"))
            cfg->hint_activation_key = strdup(val);
        else if(!strcmp(key, "grid_activation_key"))
            cfg->grid_activation_key = strdup(val);
        else if(!strcmp(key, "discrete_activation_key"))
            cfg->discrete_activation_key = strdup(val);
        else if(!strcmp(key, "close_key"))
            cfg->close_key = strdup(val);
        else if(!strcmp(key, "buttons"))
            cfg->buttons = strdup(val);
        else if(!strcmp(key, "trigger_mods"))
            cfg->trigger_mods = strdup(val);
        else if(!strcmp(key, "hint_nc"))
            cfg->hint_nc = atoi(val);
        else if(!strcmp(key, "hint_nr"))
            cfg->hint_nr = atoi(val);
        else if(!strcmp(key, "hint_up"))
            cfg->hint_up = strdup(val);
        else if(!strcmp(key, "hint_left"))
            cfg->hint_left = strdup(val);
        else if(!strcmp(key, "hint_down"))
            cfg->hint_down = strdup(val);
        else if(!strcmp(key, "hint_right"))
            cfg->hint_right = strdup(val);
        else if(!strcmp(key, "hint_bgcol"))
            cfg->hint_bgcol = strdup(val);
        else if(!strcmp(key, "hint_fgcol"))
            cfg->hint_fgcol = strdup(val);
        else if(!strcmp(key, "hint_characters"))
            cfg->hint_characters = strdup(val);
        else if(!strcmp(key, "grid_col"))
            cfg->grid_col = strdup(val);
        else if(!strcmp(key, "grid_mouse_col"))
            cfg->grid_mouse_col = strdup(val);
        else if(!strcmp(key, "grid_pointer_size"))
            cfg->grid_pointer_size = atoi(val);
        else if(!strcmp(key, "grid_line_width"))
            cfg->grid_line_width = atoi(val);
        else if(!strcmp(key, "grid_activation_timeout"))
            cfg->grid_activation_timeout = atoi(val);
        else if(!strcmp(key, "discrete_left"))
            cfg->discrete_left = strdup(val);
        else if(!strcmp(key, "discrete_down"))
            cfg->discrete_down = strdup(val);
        else if(!strcmp(key, "discrete_up"))
            cfg->discrete_up = strdup(val);
        else if(!strcmp(key, "discrete_right"))
            cfg->discrete_right = strdup(val);

        free(line);
        line = NULL;
        n = 0;
    }

    return cfg;
}
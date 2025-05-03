/*
 * b21_config_gen
 * Copyright (c) 2025 nosuke <sasugaanija@gmail.com>
 *
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
extern char *optarg;
extern int optind, opterr, optopt;
#include <getopt.h>

#ifdef __MINGW32__
#include <windows.h>
#endif


#define COPY "2025 nosuke <sasugaanija@gmail.com>"
#define VERSION "1.0"

#define CONFIG_FILE "config.txt"
//#define DEBUG
#ifdef DEBUG
# define CONFIG_FILE_ALL "config_all.txt" // for DEBUG
#endif

#define MAME_CODE "cps1_v.cpp"


enum {
    CPS_B_01 = 0,
    CPS_B_02,
    CPS_B_03,
    CPS_B_04,
    CPS_B_05,
    CPS_B_11,
    CPS_B_12,
    CPS_B_13,
    CPS_B_14,
    CPS_B_15,
    CPS_B_16,
    CPS_B_17,
    CPS_B_18,
    CPS_B_21_DEF,
    CPS_B_21_BT1,
    CPS_B_21_BT2,
    CPS_B_21_BT3,
    CPS_B_21_BT4,
    CPS_B_21_BT5,
    CPS_B_21_BT6,
    CPS_B_21_BT7,
    CPS_B_21_QS1,
    CPS_B_21_QS2,
    CPS_B_21_QS3,
    CPS_B_21_QS4,
    CPS_B_21_QS5
};



typedef struct battery_cfg_title {
    int id;
    char title_en[128];
    char title_jp[128];
} t_battery_cfg_title;


t_battery_cfg_title title_utf8[] = {
#include "title_utf8.txt"
};

t_battery_cfg_title title_sjis[] = {
#include "title_sjis.txt"
};



enum {
    ID_OFS = 0,
    ID_VAL,
    MULT_FACTOR1,
    MULT_FACTOR2,
    MULT_RESULT_LOW,
    MULT_RESULT_HIGH,
    MULT_TC,
    CHECK1,
    CHECK2,
    LAYER_CONTROL,
    PRIORITY0,
    PRIORITY1,
    PRIORITY2,
    PRIORITY3,
    PALETTE_CONTROL,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    HW_CFG_NUM
};


enum {
    OFS_ID = 0,
    OFS_MULT_FACTOR1,
    OFS_MULT_FACTOR2,
    OFS_MULT_RESULT_LOW,
    OFS_MULT_RESULT_HIGH,
    OFS_MULT_TC,
    OFS_CHECK1,
    OFS_CHECK2,
    OFS_LAYER_CONTROL,
    OFS_PRIORITY0,
    OFS_PRIORITY1,
    OFS_PRIORITY2,
    OFS_PRIORITY3,
    OFS_PALETTE_CONTROL,
    OFFSET_NUM
};

enum values {
    VAL_CPS_ID = 0,
    VAL_CHECK1,
    VAL_CHECK2,
    VALUE_NUM
};

#define LAYER_NUM 5

#define CONFIG_LEN 18

typedef struct cps_cfg_info {
    char cfg_name[64];
    char bchip_name[64];
    int b21;
    int battery;
    int immitate;
    int id;
    uint8_t offset_conf[OFFSET_NUM];
    uint8_t layer_mask_conf[LAYER_NUM];
    uint16_t value_conf[VALUE_NUM];

    uint8_t config[CONFIG_LEN];

    int valid;

} t_cps_cfg_info;

#define BT1_CHECK1 0x1B3D
#define BT1_CHECK2 0x0E6B
#define BT2_CHECK1 0x1D6B
#define BT2_CHECK2 0x21C2
#define BT3_CHECK1 0x0A47
#define BT3_CHECK2 0x205C
#define BT4_CHECK1 0x1DD0
#define BT4_CHECK2 0x267E
#define BT5_CHECK1 0x3039
#define BT5_CHECK2 0xB26E
#define QS2_CHECK1 0x49DF
#define QS2_CHECK2 0xBC52
#define QS4_CHECK1 0x69F4
#define QS4_CHECK2 0xC803

#define CFG_NAME_BASE "CPS_B_"

t_cps_cfg_info cps_cfg[] = {
//   CFG NAME,        BCHIP NAME, B21, BAT, IMM,  ID,           OFS, MASK,VAL, CONF,VALID
    {"CPS_B_01",      "CPS_B_01", 0,   0,   1,    CPS_B_01,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_02",      "CPS_B_02", 0,   0,   1,    CPS_B_02,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_03",      "CPS_B_03", 0,   0,   1,    CPS_B_03,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_04",      "CPS_B_04", 0,   0,   1,    CPS_B_04,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_05",      "CPS_B_05", 0,   0,   1,    CPS_B_05,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_11",      "CPS_B_11", 0,   0,   1,    CPS_B_11,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_12",      "CPS_B_12", 0,   0,   1,    CPS_B_12,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_13",      "CPS_B_13", 0,   0,   1,    CPS_B_13,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_14",      "CPS_B_14", 0,   0,   1,    CPS_B_14,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_15",      "CPS_B_15", 0,   0,   1,    CPS_B_15,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_16",      "CPS_B_16", 0,   0,   1,    CPS_B_16,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_17",      "CPS_B_17", 0,   0,   1,    CPS_B_17,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_18",      "CPS_B_18", 0,   0,   1,    CPS_B_18,     {0}, {0}, {0}, {0}, 0},
    {"CPS_B_21_DEF",  "CPS_B_21", 1,   1,   1,    CPS_B_21_DEF, {0}, {0}, {0}, {0}, 0},
    {"CPS_B_21_BT1",  "CPS_B_21", 1,   1,   0,    CPS_B_21_BT1, {0}, {0}, {0, BT1_CHECK1, BT1_CHECK2}, {0}, 0},
    {"CPS_B_21_BT2",  "CPS_B_21", 1,   1,   0,    CPS_B_21_BT2, {0}, {0}, {0, BT2_CHECK1, BT2_CHECK2}, {0}, 0},
    {"CPS_B_21_BT3",  "CPS_B_21", 1,   1,   0,    CPS_B_21_BT3, {0}, {0}, {0, BT3_CHECK1, BT3_CHECK2}, {0}, 0},
    {"CPS_B_21_BT4",  "CPS_B_21", 1,   1,   0,    CPS_B_21_BT4, {0}, {0}, {0, BT4_CHECK1, BT4_CHECK2}, {0}, 0},
    {"CPS_B_21_BT5",  "CPS_B_21", 1,   1,   0,    CPS_B_21_BT5, {0}, {0}, {0, BT5_CHECK1, BT5_CHECK2}, {0}, 0},
    {"CPS_B_21_BT6",  "CPS_B_21", 1,   1,   0,    CPS_B_21_BT6, {0}, {0}, {0}, {0}, 0},
    {"CPS_B_21_BT7",  "CPS_B_21", 1,   1,   0,    CPS_B_21_BT7, {0}, {0}, {0}, {0}, 0},
    {"CPS_B_21_QS1",  "CPS_B_21", 1,   1,   0,    CPS_B_21_QS1, {0}, {0}, {0}, {0}, 0},
    {"CPS_B_21_QS2",  "CPS_B_21", 1,   1,   0,    CPS_B_21_QS2, {0}, {0}, {0, QS2_CHECK1, QS2_CHECK2}, {0}, 0},
    {"CPS_B_21_QS3",  "CPS_B_21", 1,   1,   0,    CPS_B_21_QS3, {0}, {0}, {0}, {0}, 0},
    {"CPS_B_21_QS4",  "CPS_B_21", 1,   1,   0,    CPS_B_21_QS4, {0}, {0}, {0, QS4_CHECK1, QS4_CHECK2}, {0}, 0},
    {"CPS_B_21_QS5",  "CPS_B_21", 1,   1,   0,    CPS_B_21_QS5, {0}, {0}, {0}, {0}, 0}
};

int cfg_num = sizeof(cps_cfg) / sizeof(cps_cfg[0]);

// Display titles in Japanese
int g_title_jp = 1;


void
update_config(t_cps_cfg_info *b)
{
    b->config[0] = (b->value_conf[VAL_CPS_ID] >> 10) | ((b->layer_mask_conf[0] & 0x03) << 6);
    b->config[1] = (b->layer_mask_conf[0] >> 2) | 0xfe;
    b->config[2] = 0x07 | (b->offset_conf[OFS_LAYER_CONTROL] << 3);
    b->config[3] = 0x1f | (b->layer_mask_conf[3] << 5);
    b->config[4] = b->offset_conf[OFS_CHECK2] | ((b->value_conf[VAL_CHECK2] & 0x7) << 5);
    b->config[5] = (b->value_conf[VAL_CHECK2] >> 3) & 0xff;
    b->config[6] = (b->value_conf[VAL_CHECK2] >> 11) | ((b->offset_conf[OFS_PRIORITY0] & 0x7) << 5);
    b->config[7] = (b->offset_conf[OFS_PRIORITY0] >> 3) | (b->offset_conf[OFS_CHECK1] << 2)
                   | ((b->layer_mask_conf[4] & 0x1) << 7);
    b->config[8] = (b->layer_mask_conf[4] >> 1) | ((b->value_conf[VAL_CHECK1] & 0x3f) << 2);
    b->config[9] = (b->value_conf[VAL_CHECK1] >> 6) & 0xff;
    b->config[10] = ((b->value_conf[VAL_CHECK1] >> 14) & 0x3) | (b->offset_conf[OFS_PRIORITY1] << 2)
                    | ((b->offset_conf[OFS_MULT_TC] & 0x1) << 7);
    b->config[11] = ((b->offset_conf[OFS_MULT_TC] >> 1) & 0xf)
                    | ((b->offset_conf[OFS_PRIORITY2] & 0x0f) << 4);
    b->config[12] = (b->offset_conf[OFS_PRIORITY2] >> 4) | (b->offset_conf[OFS_MULT_RESULT_HIGH] << 1)
                    | ((b->layer_mask_conf[2] & 0x3) << 6);
    b->config[13] = (b->layer_mask_conf[2] >> 2) | (b->offset_conf[OFS_PRIORITY3] << 1)
                    | ((b->offset_conf[OFS_MULT_RESULT_LOW] & 0x3) << 6);
    b->config[14] = (b->offset_conf[OFS_MULT_RESULT_LOW] >> 2)
                    | (b->offset_conf[OFS_PALETTE_CONTROL] << 3);
    b->config[15] = b->offset_conf[OFS_MULT_FACTOR2] | ((b->offset_conf[OFS_ID] & 0x7) << 5);
    b->config[16] = (b->offset_conf[OFS_ID] >> 3) | (b->layer_mask_conf[1] << 2)
                    | ((b->offset_conf[OFS_MULT_FACTOR1] & 0x7) << 5);
    b->config[17] = (b->offset_conf[OFS_MULT_FACTOR1] >> 3)
                    | ((b->value_conf[VAL_CPS_ID] & 0x3F) << 2);
}


void
update_cps_cfg(int target_cfg, long *hw_cfg)
{
    unsigned char layer_mask;

    // convert HW spec to B21 configuration
    cps_cfg[target_cfg].value_conf[VAL_CPS_ID] = (hw_cfg[ID_VAL] < 0) ? 0 : (hw_cfg[ID_VAL] & 0xffff);

#define GEN_CFG_OFS(x) ((x) < 0 ? 0x3e : ((x) & 0x3e))
    cps_cfg[target_cfg].offset_conf[OFS_ID] = GEN_CFG_OFS(hw_cfg[ID_OFS]);
    cps_cfg[target_cfg].offset_conf[OFS_MULT_FACTOR1] = GEN_CFG_OFS(hw_cfg[MULT_FACTOR1]);
    cps_cfg[target_cfg].offset_conf[OFS_MULT_FACTOR2] = GEN_CFG_OFS(hw_cfg[MULT_FACTOR2]);
    cps_cfg[target_cfg].offset_conf[OFS_MULT_RESULT_LOW] = GEN_CFG_OFS(hw_cfg[MULT_RESULT_LOW]);
    cps_cfg[target_cfg].offset_conf[OFS_MULT_RESULT_HIGH] = GEN_CFG_OFS(hw_cfg[MULT_RESULT_HIGH]);
    cps_cfg[target_cfg].offset_conf[OFS_MULT_TC] = GEN_CFG_OFS(hw_cfg[MULT_TC]);
    cps_cfg[target_cfg].offset_conf[OFS_CHECK1] = GEN_CFG_OFS(hw_cfg[CHECK1]);
    cps_cfg[target_cfg].offset_conf[OFS_CHECK2] = GEN_CFG_OFS(hw_cfg[CHECK2]);
    cps_cfg[target_cfg].offset_conf[OFS_LAYER_CONTROL] = GEN_CFG_OFS(hw_cfg[LAYER_CONTROL]);
    cps_cfg[target_cfg].offset_conf[OFS_PRIORITY0] = GEN_CFG_OFS(hw_cfg[PRIORITY0]);
    cps_cfg[target_cfg].offset_conf[OFS_PRIORITY1] = GEN_CFG_OFS(hw_cfg[PRIORITY1]);
    cps_cfg[target_cfg].offset_conf[OFS_PRIORITY2] = GEN_CFG_OFS(hw_cfg[PRIORITY2]);
    cps_cfg[target_cfg].offset_conf[OFS_PRIORITY3] = GEN_CFG_OFS(hw_cfg[PRIORITY3]);
    cps_cfg[target_cfg].offset_conf[OFS_PALETTE_CONTROL] = GEN_CFG_OFS(hw_cfg[PALETTE_CONTROL]);

    // lower 1bit of offset is omitted from configuration
    for (int i = 0; i < OFFSET_NUM; i++) {
        cps_cfg[target_cfg].offset_conf[i] >>= 1;
    }

    // for undefined layer
    layer_mask = 0x3e;

    for (int i = LAYER1; i <= LAYER5; i++) {
        uint8_t layer = hw_cfg[i] & 0xff;
        for (int j = 5; j >= 1; j--) {
            if (((layer & layer_mask) >> j) & 0x1) {
                cps_cfg[target_cfg].layer_mask_conf[i - LAYER1] = j;
                layer_mask ^= (1 << j);
                break;
            }
        }
    }

    // assign undefined layers to unused bits
    for (int i = 0; i < LAYER_NUM; i++) {
        if (cps_cfg[target_cfg].layer_mask_conf[i] == 0) {
            for (int j = 5; j >= 1; j--) {
                if ((layer_mask >> j) & 0x1) {
                    cps_cfg[target_cfg].layer_mask_conf[i] = j;
                    layer_mask ^= (1 << j);
                    break;
                }
            }
        }
    }

    cps_cfg[target_cfg].valid = 1;    
}


int
get_val(long *val, char **p1, char d)
{
    char *endptr;

    *val = strtol(*p1, &endptr, 0);
    if (*val == 0 && *p1 == endptr) {
        // invalid format
        printf("not number\n");
        return -1;
    }
    *p1 = endptr;

    return 0;
}

void
skip_space(char **p)
{
    while (isspace(*p[0]))
        (*p)++;
}


// get HW configuration from MAME soruce code (cps1_v.cpp)
int
parse_line(char *line)
{
    char *p1, *p2;
    long hw_cfg[HW_CFG_NUM] = {0};
    int len;
    char define_str[] = "#define";
    char not_applicable[] = "__not_applicable__";
    int target_cfg = -1;
    int rc;
    //unsigned char layer_mask;

    // check if line is a macro that defines B-chip spec (#define CPS_B_...)
    p1 = line;
    if (strncmp(p1, define_str, strlen(define_str)) != 0) {
        // line does not start from "#define"
        return -1;
    }
    
    p1 += strlen(define_str);

    if (!isspace(*p1)) {
        // no space after "#define"
        return -1;
    }

    // skip white3 spaces
    skip_space(&p1);

    // search end of macro name
    p2 = p1;
    len = 0;
    while (isalnum(*p2) || *p2 == '_') {
        p2++;
        len++;
    }

    if (len == 0) {
        // no macro name after define
        return -1;
    }

    if (!isspace(*p2)) {
        // no space character after macro name
        return -1;
    }

    // check if macro name starts from "CPS_B_"
    if (strncmp(p1, CFG_NAME_BASE, strlen(CFG_NAME_BASE)) != 0) {
        // not CFG define
        return -1;
    }

    // get target configuration
    for (int i = 0; i < cfg_num; i++) {
        if (strlen(cps_cfg[i].cfg_name) == len && strncmp(p1, cps_cfg[i].cfg_name, len) == 0) { 
            target_cfg = i;
            break;
        }
    }

    if (target_cfg < 0) {
        // unexpected macro
        return -1;
    }


    if (cps_cfg[target_cfg].valid == 1) {
        // multiple definition
        printf("Warning: %s is already defined\n", cps_cfg[target_cfg].cfg_name);
    }

    p1 += strlen(cps_cfg[target_cfg].cfg_name);

    skip_space(&p1);

    // parse definition

    for (int i = ID_OFS; i <= ID_VAL; i++) {
        rc = get_val(&hw_cfg[i], &p1, ',');
        if (rc < 0) {
            printf("no digit (#%d): %s\n", i, line);
            return -1;
        }

        skip_space(&p1); // for "0x32  ," case
        if (*p1 != ',') {
            printf("no separator (#%d): %s\n", i, p1);
            return -1;
        }
        p1++;
    }

    if (cps_cfg[target_cfg].b21 == 0) {
        // skip "__not_applicable__," in definition
        skip_space(&p1);
        if (strncmp(p1, not_applicable, strlen(not_applicable)) != 0) {
            printf("Old b-chip definition has mult/check related values: %s\n", p1);
            return -1;
        }
        p1 += strlen(not_applicable);

        skip_space(&p1);
        if (*p1 != ',') {
            printf("invalid format after \"%s\": %s\n", not_applicable, p1);
            return -1;
        }
        p1++;

        for (int i = MULT_FACTOR1; i <= CHECK2; i++) {
            hw_cfg[i] = -1;
        }

    } else {
        // parse B21 specific parameters (from mult_factor1 to check2)
        for (int i = MULT_FACTOR1; i <= CHECK2; i++) {
            rc = get_val(&hw_cfg[i], &p1, ',');
            if (rc < 0) {
                printf("no digit (#%d): %s\n", i, line);
                return -1;
            }

            skip_space(&p1); // for "0x32  ," case
            if (*p1 != ',') { // check ","
                printf("no separator (#%d): %s\n", i, line);
                return -1;
            }
            p1++;
        }
    }

    // layer_control
    rc = get_val(&hw_cfg[LAYER_CONTROL], &p1, ',');
    if (rc < 0) {
        printf("no digit (#%d): %s\n", LAYER_CONTROL, line);
        return -1;
    }

    skip_space(&p1); // for "0x32  ," case
    if (*p1 != ',') { // check ","
        printf("no separator (#%d): %s\n", LAYER_CONTROL, line);
        return -1;
    }
    p1++;


    skip_space(&p1);

    // check "{"
    if (*p1 != '{') {
        printf("no '{': %s\n", p1);
        return -1;
    }
    p1++;


    // from priority0 to priority3
    for (int i = PRIORITY0; i <= PRIORITY3; i++) {
        rc = get_val(&hw_cfg[i], &p1, ',');
        if (rc < 0) {
            printf("no digit (#%d): %s\n", i, line);
            return -1;
        }

        skip_space(&p1); // for "0x32  ," case
        if (i < PRIORITY3) {
            if (*p1 != ',') { // check ","
                printf("no separator (#%d): %s\n", i, line);
                return -1;
            }
            p1++;
        }
    }

    // check "}"
    if (*p1 != '}') {
        printf("no '}': %s\n", line);
        return -1;
    }
    p1++;

    // check ","
    skip_space(&p1);
    if (*p1 != ',') {
        printf("no separator ',' (1) : %s\n", p1);
        return -1;
    }
    p1++;

    // palette_control
    rc = get_val(&hw_cfg[PALETTE_CONTROL], &p1, ',');
    if (rc < 0) {
        printf("no digit (#%d): %s\n", PALETTE_CONTROL, line);
        return -1;
    }

    skip_space(&p1);
    if (*p1 != ',') { // check ","
        printf("no separator ',' (2) : %s\n", p1);
        return -1;
    }
    p1++;

    skip_space(&p1);

    // check "{"
    if (*p1 != '{') { 
        printf("no '{': %s\n", line);
        return -1;
    }
    p1++;

    // from layer1 to layer5
    for (int i = LAYER1; i <= LAYER5; i++) {
        rc = get_val(&hw_cfg[i], &p1, ',');
        if (rc < 0) {
            printf("no digit (#%d): %s\n", i, line);
            return -1;
        }

        skip_space(&p1); // for "0x32  ," case
        if (i < LAYER5) {
            if (*p1 != ',') { // check ","
                printf("no separator (#%d): %s\n", i, line);
                return -1;
            }
            p1++;
        }
    }

    // check "}"
    if (*p1 != '}') {
        printf("no '}': %s\n", line);
        return -1;
    }
    p1++;

    // update configuration
    update_cps_cfg(target_cfg, hw_cfg);

    return 0;
}


char *
get_title(int id, int *width)
{
    for (int i = 0; title_utf8[i].id >= 0; i++) {
        if (title_utf8[i].id == id) {
            if (width != NULL)
                *width = strlen(g_title_jp ? title_sjis[i].title_jp : title_sjis[i].title_en);
            return g_title_jp ? title_utf8[i].title_jp : title_utf8[i].title_en;
        }
    }
    if (width != NULL)
        *width = 0;
    return NULL;
}


int
title_selection(char **name, char**title)
{
    int in;
    char buf[256], *p;
    int *sel2id;
    int idx_col1 = 0, idx_col2 = 0;
    int line = 0;
    int num_normal = 0, num_immitation = 0, num_total;
    int rc = -1;
    char *label;


#define MENU_WIDTH 72
#define COL_WIDTH (MENU_WIDTH / 2)
#define NUM_WIDTH 5 // "[10] "

    printf("%-*s%s", COL_WIDTH, "== Normal Mode ==", "== Immitation Mode ==\n");

    // count battery configuration number
    for (int i = 0; i < cfg_num; i++) {
        if (cps_cfg[i].battery)
            num_normal++;
        if (cps_cfg[i].immitate)
            num_immitation++;
    }

    num_total = num_immitation + num_normal;

    sel2id = malloc(sizeof(int) * num_total);
    
    for (int i = 0; i < num_total; i++) {
        sel2id[i] = -1;
    }

    while (1) {
        int col1 = 0, col2 = 0;

        // search next cfg
        while (idx_col1 < cfg_num) {
            if (cps_cfg[idx_col1].battery) {
                col1 = 1;
                break;
            } else {
                idx_col1++;
            }
        }

        while (idx_col2 < cfg_num) {
            if (cps_cfg[idx_col2].immitate) {
                col2 = 1;
                break;
            } else {
                idx_col2++;
            }
        }
        
        if (!col1 && !col2)
            break;

        if (col1) {
            int label_width;
            label = get_title(cps_cfg[idx_col1].id, &label_width);
            if (cps_cfg[idx_col1].valid == 1) {
                printf("[%2d]", line);
                sel2id[line] = cps_cfg[idx_col1].id;
            } else {
                printf("[**]");
            }
            idx_col1++;
            printf(" %s%*s", label, COL_WIDTH - NUM_WIDTH - label_width, "");
        } else {
            label = NULL;
            printf("%*s", COL_WIDTH, "");
        }


        if (col2) {
            if (cps_cfg[idx_col2].valid == 1) {
                printf("[%2d]", line + num_normal);
                sel2id[line + num_normal] = cps_cfg[idx_col2].id;
            } else {
                printf("[**]");
            }
            printf(" %s\n", cps_cfg[idx_col2].bchip_name);
            idx_col2++;
        } else {
            printf("                 \n");
        }

        line++;
    }


    for (int i = 0; i < MENU_WIDTH; i++)
        putchar('-');
    putchar('\n');
    printf("Select configuration: ");
    fflush(stdout);

    p = buf;
    fgets(buf, sizeof(buf), stdin);
    in = strtol(buf, &p, 10);
    if (p == buf || !isspace(*p)) {
        in = -1;
    }


    if (in >= 0 && in < num_total && sel2id[in] >= 0) {
        rc = sel2id[in];
        if (in <= num_normal) {
            *name = cps_cfg[rc].cfg_name;
            *title = get_title(cps_cfg[rc].id, NULL);
        } else {
            *name = cps_cfg[rc].bchip_name;
            *title = NULL;
        }
    }

    free(sel2id);

    return rc;
}




void
version()
{
    printf("CPS1 configuration generator (ver %s)\n", VERSION);
    printf("Copyright (c) %s\n", COPY);
}


void
usage(char **argv)
{
    fprintf(stderr, "Usage: %s [OPTION]\n", argv[0]);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -o FILE    change output file name from %s\n", CONFIG_FILE);
    fprintf(stderr, "  -e         show game titles in English %s\n", CONFIG_FILE);
    fprintf(stderr, "  -v         show tool version\n");   
    fprintf(stderr, "  -h         show this message\n");   
}


#ifdef __MINGW32__
int cp_org_valid = 0;
UINT cp_org;

BOOL WINAPI CtrlHandler(DWORD dwCtrlType)
{
    switch(dwCtrlType) {
    case CTRL_C_EVENT:
    case CTRL_BREAK_EVENT:
        if (cp_org_valid) {
            SetConsoleOutputCP(cp_org);
        }
        return FALSE;
        break;
    default:
        break;
    }
    return TRUE;
}
#endif


int
main(int argc, char *argv[])
{
    FILE *fp;
    char *configfile = CONFIG_FILE;
    int ret = -1;
    char line[1024];
    int opt;

#ifdef __MINGW32__
    cp_org = GetConsoleOutputCP();
    cp_org_valid = 1;
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE);
    SetConsoleOutputCP(65001);
#endif

    while ((opt = getopt(argc, argv, "o:evh")) != -1) {
        switch (opt) {
        case 'o':
            configfile = optarg;
            break;
        case 'e':
            g_title_jp = 0;
            break;
        case 'v':
            ret = 0;
            version();
            goto FIN;
        case 'h':
            usage(argv);
            goto FIN;
        default:
            fprintf(stderr, "Invalid options\n");
            usage(argv);
            goto FIN;
        }
    }


    fp = fopen(MAME_CODE, "rb");
    if (fp == NULL) {
        perror("fopen");
        fprintf(stderr, MAME_CODE " open failed\n");
//        goto FIN;
    }

    if (fp) {
        while (fgets(line, sizeof(line) - 1, fp) > 0) {
            parse_line(line);
        }
        fclose(fp);
    }



    for (int i = 0; i < cfg_num; i++) {
        if (cps_cfg[i].valid == 1) {
#if 0
            printf("%16s : 0x%02x 0x%04x  0x%02x,0x%02x,0x%02x,0x%02x,  0x%02x,0x%02x,0x%02x,  0x%02x,{0x%02x,0x%02x,0x%02x,0x%02x},0x%02x, {0x%02x,0x%02x,0x%02x,0x%02x,0x%02x}, %04x, %04x\n",
                   cps_cfg[i].name, cps_cfg[i].offset_conf[OFS_ID] << 1, cps_cfg[i].value_conf[VAL_CPS_ID],
                   cps_cfg[i].offset_conf[OFS_MULT_FACTOR1] << 1, cps_cfg[i].offset_conf[OFS_MULT_FACTOR2] << 1, cps_cfg[i].offset_conf[OFS_MULT_RESULT_LOW] << 1, cps_cfg[i].offset_conf[OFS_MULT_RESULT_HIGH] << 1,
                   cps_cfg[i].offset_conf[OFS_MULT_TC] << 1, cps_cfg[i].offset_conf[OFS_CHECK1] << 1, cps_cfg[i].offset_conf[OFS_CHECK2] << 1,
                   cps_cfg[i].offset_conf[OFS_LAYER_CONTROL] << 1,
                   cps_cfg[i].offset_conf[OFS_PRIORITY0] << 1, cps_cfg[i].offset_conf[OFS_PRIORITY1] << 1, cps_cfg[i].offset_conf[OFS_PRIORITY2] << 1, cps_cfg[i].offset_conf[OFS_PRIORITY3] << 1,
                   cps_cfg[i].offset_conf[OFS_PALETTE_CONTROL] << 1,
                   1 << cps_cfg[i].layer_mask_conf[0], 1 << cps_cfg[i].layer_mask_conf[1], 1 << cps_cfg[i].layer_mask_conf[2], 1 << cps_cfg[i].layer_mask_conf[3], 1 << cps_cfg[i].layer_mask_conf[4],
                   cps_cfg[i].value_conf[VAL_CHECK1], cps_cfg[i].value_conf[VAL_CHECK2]);
#endif
            update_config(&cps_cfg[i]);
        }
    }


#ifdef DEBUG
    fp = fopen(CONFIG_FILE_ALL, "wb");
    if (fp == NULL) {
        perror("fopen");
        fprintf(stderr, "Output file \"%s\" open failed\n", CONFIG_FILE_ALL);
        goto FIN;
    }

    for (int i = 0; i < cfg_num; i++) {
        if (cps_cfg[i].valid == 1) {
            fprintf(fp, "%16s : {", cps_cfg[i].cfg_name);
            for (int j = CONFIG_LEN - 1; j >= 0; j--) {
                fprintf(fp, "0x%02X%c", cps_cfg[i].config[j], j != 0 ? ',' : '}');
            }
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
#endif

    char *name;
    char *title;

    ret = title_selection(&name, &title);

    if (ret >= 0) {
        printf("Generated config file \"%s\" for \"%s", configfile, name);

        if (title != NULL) {
            printf(" (%s)", title);
        }

        printf("\"\n");

        fp = fopen(configfile, "wb");
        if (fp == NULL) {
            perror("fopen");
            fprintf(stderr, "Config file \"%s\" open failed\n", configfile);
            ret = -1;
            goto FIN;
        }

        for (int i = CONFIG_LEN - 1; i >= 0; i--) {
            fprintf(fp, "0x%02X%c", cps_cfg[ret].config[i], i != 0 ? ',' : ' ');
        }

        fprintf(fp, "# %s", name);

        if (title != NULL)
            fprintf(fp, " (%s)", title);


        fprintf(fp, "\n");

        fclose(fp);
    } else {
        printf("Invalid number\n");
    }

 FIN:

    fflush(stderr);

    printf("Press enter to exit.");
    fflush(stdout);
    getchar();

#ifdef __MINGW32__
    SetConsoleOutputCP(cp_org);
#endif


    return ret;
}

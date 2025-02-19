// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_PLUGINSD_PARSER_H
#define NETDATA_PLUGINSD_PARSER_H

#include "parser/parser.h"

typedef struct parser_user_object {
    PARSER  *parser;
    RRDSET *st;
    RRDHOST *host;
    void    *opaque;
    struct plugind *cd;
    int trust_durations;
    DICTIONARY *new_host_labels;
    DICTIONARY *chart_rrdlabels_linked_temporarily;
    size_t data_collections_count;
    int enabled;

    struct parser_user_object_replay {
        time_t start_time;
        time_t end_time;

        usec_t start_time_ut;
        usec_t end_time_ut;

        time_t wall_clock_time;

        bool rset_enabled;
    } replay;

    struct parser_user_object_v2 {
        bool locked_data_collection;
        RRDSET_STREAM_BUFFER stream_buffer;
        time_t update_every;
        time_t end_time;
        time_t wall_clock_time;
        bool ml_locked;
    } v2;
} PARSER_USER_OBJECT;

PARSER_RC pluginsd_function(char **words, size_t num_words, void *user);
PARSER_RC pluginsd_function_result_begin(char **words, size_t num_words, void *user);
void inflight_functions_init(PARSER *parser);
#endif //NETDATA_PLUGINSD_PARSER_H

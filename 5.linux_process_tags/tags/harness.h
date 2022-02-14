#ifndef COP6400_HARNESS_H
#define COP6400_HARNESS_H

#include <stdlib.h>
#include <tags.h>

// Array has format:
// { call_number, num_params [, param1] [, param2] }

// Definitions are static inline to avoid linker error during tests;
// with no modifier - can yield "multiple definition",
// with inline - can yield "undefined reference"

static inline int *retrieve_get_tag_params(int pid) {
  int *get_params = malloc( sizeof(int) * 3);

  get_params[0] = SYS_get_tag;
  get_params[1] = 1;
  get_params[2] = pid;

  return get_params;
}

static inline int *retrieve_set_tag_params(int pid, int new_tag) {
  int *set_params = malloc( sizeof(int) * 4);

  set_params[0] = SYS_set_tag;
  set_params[1] = 2;
  set_params[2] = pid;
  set_params[3] = new_tag;

  return set_params;
}

static inline int interpret_get_tag_result(int ret_value) {
  if (ret_value < 0)
    return -1;

  return ret_value;
}

static inline int interpret_set_tag_result(int ret_value) {
  if (ret_value < 0)
    return -1;

  return ret_value;
}

#endif /* COP6400_HARNESS_H */

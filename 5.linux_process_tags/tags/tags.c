#include <unistd.h>
#include <tags.h>

int get_tag(int pid) {
  int tag = syscall(SYS_get_tag, pid); 

  if (tag < 0)
    return -1; // error

  return tag; 
}


int set_tag(int pid, int new_tag) {
  int err = syscall(SYS_set_tag, pid, new_tag);

  if (err < 0)
    return -1; // error

  return new_tag;
}

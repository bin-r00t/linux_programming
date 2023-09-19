#include <fcntl.h>
/**
 * typically you have no need to import below two files in POSIX supported system
 * BUT some unix may not support POSIX...
 */
#include <sys/types.h>
#include <sys/stat.h>

/**
 * there are two variations of open():
 *
 * int open(const char *path,  int oflags);
 * int open(const char *path,  int oflags,  mode_t mode);
 *
 * returns int (file descriptor) postive value
 *
 * manual: man 2 open
 *
 * POSIX has a 'creat()' system call, basically equals to open() with
 * O_CREAT | O_WRONLY | O_TRUNC
 *
 * limits.h >> OPEN_MAX >> usually be 256
 */

int main()
{
  /** create a file */
  /** if setting OFLAGS to 'O_CREAT', you must use three paramaters version */
  open("./testing_file", O_CREAT, S_IRUSR | S_IRGRP);
  /** mode_t mode is defined in sys/stat.h */
  /** mode_t normally has a pattern:   S_IRxxx(read) S_IWxxx(write) S_IXxxx(execute) */
  /**
   * S_IRxxx, and 'xxx' can be one of 'USR'(user), 'GRP'(group), 'OTH'(other)
   * so, you can get:
   * S_IRUSR,S_IRGRP,S_IROTH
   * S_IWUSR,S_IWGRP,...
   */

  /**
   * [result]
   * $ ls -al
   * -r--r----- 1 liubin liubin    0 Sep 19 21:44 testing_file
   */

  /**
   * more complicated conecpt: umask
   * basically, your <mode_t mode> are doing some sort of requests to system,
   * acutal behavior is to do AND operate with the inverted <umask> value,
   * that means, if <umask> has been set to 001 and pass S_IXOTH
   * ot open() or creat(), then S_IXOTH will be combined with 11111110 something
   * like that, 就会造成其他用户对所创建的文件永远不会有执行权限（刚好和目的相反）
   */

  /** read something about umask */
  return 0;
}

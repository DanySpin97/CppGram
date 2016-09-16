#ifdef __unix__
#include<unistd.h>
#include<stdlib.h>
#endif

#include "cppgram/utils.h"

int cppgram::osutil::backgroundProcess()
{
#ifdef __gnu_linux__
    pid_t procid;

    procid=fork();
	 switch(procid) {
		 case -1:
			 return OSUTIL_NEWPROC_FAILED;
		 case 0:
			 break;
		 default:
			 exit(0);
	 }

    if(setsid() < 0) return OSUTIL_NEWPROC_FAILED;

    /*close file descriptors*/
    close(0);
    close(1);
    close(2);

    return OSUTIL_NEWPROC_SUCCESS;
#else
    return OSUTIL_NEWPROC_NOTSUPPORTED;
#endif
}
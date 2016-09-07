#ifdef Header_H
#define Header_H

#include <iostream>
#include <assert.h>
#include <sys/time.h>
#include <sys/types.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <pwd.h>
#include <sys/wait.h>

using namespace std;

//MacroDef
#define TRUE        1
#define FALSE       0

#define SUCCESS     0x00

typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned int        UINT;
typedef bool                BOOL;
typedef unsigned long       DWORD;
typedef unsigned long       timeout_t;

#endif

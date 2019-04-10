//
//  ErrorHandle.h
//  DSaAA
//
//  Created by zeek on 2019/4/5.
//  Copyright © 2019 Musca. All rights reserved.
//

#ifndef ErrorHandle_h
#define ErrorHandle_h

#include <stdio.h>
#include <stdlib.h>

void Error(const char *msg) {
    perror(msg);
}

void FatalError(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
#endif /* ErrorHandle_h */

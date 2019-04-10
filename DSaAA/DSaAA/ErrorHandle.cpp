//
//  ErrorHandle.c
//  DSaAA
//
//  Created by zeek on 2019/4/5.
//  Copyright © 2019 Musca. All rights reserved.
//

#include "ErrorHandle.hpp"

void Error(const char *msg) {
    perror(msg);
}

void FatalError(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

//
//  main.c
//  DSaAA
//
//  Created by Milo on 2019/4/3.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <stdio.h>

void myprint(const char* format, ...) {
    va_list list;
    va_start(list);
    
    va_end(list);
    printf(format, list);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    myprint("Hello, World! Zhao:%d\n", 3);
    
    return 0;
}

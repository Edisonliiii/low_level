#include <stdlib.h>
#include <stdio.h>

char code[] = "\x31\xc0\x31\xdb\xb8\x01\x00\x00\x00\xbb\x00\x00\x00\x00\xcd\x80";

int main(int argc, char const *argv[])
{
    int (*func)();
    func = (int(*)()) code;
    (int)(*func)();
    return 0;
}

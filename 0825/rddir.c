#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, const char *argv[])
{
    DIR *dir;
    struct dirent *dir_name;
    dir = opendir("../Tony_mid_C");
    if(dir == NULL)
    {
        perror("opendir fail");
        exit(1);
    }
    while((dir_name = readdir(dir)) != NULL)
    {
         printf("   %s",dir_name->d_name);
    }
    return 0;
}


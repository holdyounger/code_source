typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
 
int get_cpu_info(uint16_t *user, uint16_t *nice, uint16_t *idle)
{
    FILE *fd;
    char buff[256];
            char name[32];
uint32_t system;
 
    fd = fopen("/proc/stat", "r");
    fgets(buff, sizeof(buff), fd);
 
    sscanf(buff, "%s %u %u %u %u", name, user,
           nice, &system, idle);
    fclose(fd);
 
return 0;
}
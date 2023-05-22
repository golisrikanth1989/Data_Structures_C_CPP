#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int main() {
    // Open serial port
    int fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        exit(1);
    }
    
    // Configure serial port
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;
    tcsetattr(fd, TCSANOW, &options);
    
    // Read AT commands from file
    FILE *fp = fopen("at_commands.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char cmd[256];
    while (fgets(cmd, sizeof(cmd), fp)) {
        // Send AT command
        strcat(cmd, "\r");
        write(fd, cmd, strlen(cmd));
        
        // Read response
        char buffer[256];
        memset(buffer, 0, sizeof(buffer));
        read(fd, buffer, sizeof(buffer));
        printf("Response: %s\n", buffer);
    }
    
    // Close serial port and file
    close(fd);
    fclose(fp);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Open syslog with LOG_USER facility
    openlog(NULL, 0, LOG_USER);

    // Validate number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: expected 2, got %d", argc - 1);
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return 1;
    }

    char *writefile = argv[1];
    char *writestr = argv[2];

    // Try opening the file for writing
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Failed to open file: %s", writefile);
        perror("fopen");
        closelog();
        return 1;
    }

    // Write the string into the file
    if (fprintf(fp, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Failed to write to file: %s", writefile);
        perror("fprintf");
        fclose(fp);
        closelog();
        return 1;
    }

    // Log successful write
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Clean up
    fclose(fp);
    closelog();

    return 0;
}


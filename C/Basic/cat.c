#include <stdio.h>
#include <stdlib.h>


void cat_file(char* file_name);

int main(int argc, char **argv) {
    if(argc < 0) {
        printf("Usage: cat <file1> <file2> ... <fileN>\n");
        return 1;
    }
    for (int i = 1 ; i < argc; i++) {
        cat_file(argv[i]);
    }

    return 0;
}

void cat_file(char* file_name) {
    const int BUFFER_SIZE = 1024 * 64;
    unsigned char buffer[BUFFER_SIZE];
    FILE *f = fopen(file_name,"rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (!f) {
        printf("cat: %s: No such file or directory\n", file_name);
        return;
    }

    int byte_count = 0;
    int bytes_to_read = BUFFER_SIZE < fsize ? BUFFER_SIZE : fsize;

    fread(buffer,bytes_to_read,1,f);
    fwrite(buffer,bytes_to_read,1,stdout);

    byte_count += bytes_to_read;

    if (bytes_to_read == fsize) {
        exit(0);
    }

    while (1) {
        bytes_to_read = BUFFER_SIZE <= fsize - byte_count ? BUFFER_SIZE : fsize - byte_count;
        if (bytes_to_read == 0) {
            break;
        }

        fread(buffer,bytes_to_read,1,f);
        fwrite(buffer,bytes_to_read,1,stdout);

        byte_count += bytes_to_read;
    }

}

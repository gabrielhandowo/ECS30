#ifndef main_2_h
#define main_2_h
    void print_lines(char** lines, int num_lines);
    void free_lines(char** lines, int num_lines);
    FILE* validate_input(int argc, char* argv[]);
    void read_lines(FILE* fp, char*** lines, int* num_lines);

#endif

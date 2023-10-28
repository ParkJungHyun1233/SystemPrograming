#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
int main()
{
        void *handle;
        int (*add)(int, ...), (*subtract)(int,...),(*multiply)(int,...),(*divide)(int,...);
        char *error;
        handle = dlopen("./lib/lib_fp_operation.so", RTLD_LAZY);
        if(!handle) {
                fputs(dlerror(),stderr);
                exit(1);
        }

        add = dlsym(handle, "sum");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error);
                exit(1);
        }

        subtract = dlsym(handle, "sub");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error);
                exit(1);
        }

        multiply = dlsym(handle, "mul");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error); 
                exit(1);
        }

        divide = dlsym(handle, "div");
        if((error = dlerror()) != NULL) {
                fprintf(stderr,"%s", error);
                exit(1);
        }


        printf("SUM: %d \n",(*add)(3,1,5,2));
        printf("SUB: %d \n",(*subtract)(3,1,5,2));
        printf("MUL: %d \n",(*multiply)(3,1,5,2));
        printf("DIV :%d \n", (*divide)(3,1,5,2));
}

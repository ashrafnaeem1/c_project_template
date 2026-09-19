#include <stdio.h>

int main(void)
{
#if defined(__STDC_VERSION__)
    printf("C Standard Version Macro: %ld\n", __STDC_VERSION__);

#if __STDC_VERSION__ >= 202311L
    printf("Mode: C23 (or /std:clatest)\n");
#elif __STDC_VERSION__ >= 201710L
    printf("Mode: C17 (/std:c17)\n");
#elif __STDC_VERSION__ >= 201112L
    printf("Mode: C11 (/std:c11)\n");
#else
    printf("Mode: Pre-C11 Standard\n");
#endif
#else
    // Default MSVC C mode (ANSI C89 with Microsoft Extensions)
    printf("Mode: MSVC Default (ANSI C89 / MS Extensions)\n");
#endif

    return 0;
}

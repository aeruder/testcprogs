#include <pcre.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    pcre *re;
    const char *sampleData = "\rNet:   dm9000\n\rHit any key to stop autoboot: disabled\n\r2 seconds remain until autoboot, $bootdelaykey{,2} to cancel\n\rDefault values: spac, ctrl-c";
    const char *regex = "(Hit any key to stop autoboot)|([\\n\\r]+\\$ $)";
    const char *errorMsg;
    int errorOffset;
    int rc;
    re = pcre_compile(
        regex,
        PCRE_DOLLAR_ENDONLY |
        PCRE_DOTALL |
        PCRE_UTF8 |
        PCRE_NEWLINE_LF,
        &errorMsg,
        &errorOffset,
        0);
    if (re == 0) {
        printf("Regex failed @ %d offset: %s\n", errorOffset, errorMsg);
        return 1;
    }
    rc = pcre_exec(
        re,
        NULL,
        sampleData,
        strlen(sampleData),
        0,
        PCRE_NEWLINE_LF,
        NULL,
        0);
    if (rc == 0) {
        printf("Matched\n");
    } else {
        printf("No matched\n");
    }

    return 0;
}

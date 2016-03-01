#include <time.h>
#include "date.h"

long * get_date_1_svc(void *argp, struct svc_req *rqstp)
{
    static long result;

    result = time((long *)0);

    return &result;
}
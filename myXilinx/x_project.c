#include "x_basic_types.h"

void project_clear()
{
    UInt16 i;
    for(i=0;i<sizeof(T_project);i++)
        *(((UInt16*)(&project)) + i) = 0x0000;
}

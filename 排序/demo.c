#include "stdio.h"
#include "string.h"
#include "procession.h"

int main(void)
{
    Element_Type array[] = {16,28,4,78,54,2,36,0,74,1,9,Int_End};

    //Maopao_Process(&array[0]);
    //Insert_Process(array);
    //Shell_Sort(array);
    //Quick_Sort(array,0,Get_Len(array)-1);
    //Sample_Sort(array);
    ARRAY_SHOW(array);

    return 0;
}
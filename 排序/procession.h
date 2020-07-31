#ifndef __PROCESSION_H
#define __PROCESSION_H

/* data type */
#define Element_Type int
#define Int_End  65536 
/* procession function */
int Get_Len(Element_Type *array);
void Maopao_Process(Element_Type *array);
void ARRAY_SHOW(Element_Type *array);
void Insert_Process(Element_Type *array);
void Shell_Sort(Element_Type *array);
void Quick_Sort(Element_Type *array,int low ,int high);
void Sample_Sort(Element_Type *array);
#endif
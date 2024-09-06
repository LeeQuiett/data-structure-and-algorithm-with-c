#include <stdio.h>

void BubbleSort(int DataSet[], int length)
{
    int temp = 0;
    int flag;

    for (int i = 0; i < length - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < length - (i + 1); j++)
        {
            if (DataSet[j] > DataSet[j + 1])
            {
                temp = DataSet[j];
                DataSet[j] = DataSet[j + 1];
                DataSet[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main(void)
{
    int DataSet[] = { 6,4,2,3,1,5 };
    int length = sizeof(DataSet) / sizeof(DataSet[0]); 

    BubbleSort(DataSet, length); 

    for (int i = 0; i < length; i++)
    {
        printf("%d ", DataSet[i]);
    }
    printf("\n");

    return 0;
}

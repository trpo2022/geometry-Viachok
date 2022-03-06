#include <stdio.h>
#include <string.h>

int GetFormat(char string[],int *arr)
{
    int cords[3];
    int *adres = arr;
    if(!strcmp(string,"circle")){
        if(scanf("%d %d %d",&cords[0],&cords[1],&cords[2]) == 3)
        {
            *adres = cords[0];
            adres++;
            *adres = cords[1];
            adres++;
            *adres = cords[2];
            return 1;
        }
    }
    return 0;
}

int main()
{
    char format[30];
    int cords[3];
    printf("Type !exit to stop the programm.\n");
    while(1){
            scanf("%s",format);
        if(!strcmp(format,"!exit"))
            break;
        if(GetFormat(format,cords))
        {
            printf("Object: Circle\nX: %d\nY: %d\nRadius: %d\n",cords[0],cords[1],cords[2]);
        }
        else
        {
            printf("Incorrect Format\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int CheckFormat(char string[])
{
    int succes = 0;
    char figure[20];
    strncpy(figure,string,strrchr(string,' '));
    if(!figure)
	strncpy(figure,string,strrchr(string,'('));
    if(strcmp(figure,"circle"))
	succes = CheckCircle(string);
    return succes;
}

int CheckCircle(char string[])
{
    int marker1=0;
    int marker2=0;
    char center[20];
    if(strrchr(string,'(') && strrchr(string,')'))
    {
	marker1 = strrchr(string,'(');
	marker2 = strrchr(string,')');
	marker2--;
    }
    else
	return 0;
    strncat(center,string,marker2);
    strnset(center,marker1,(char)0);
    if(sizeof(CheckCoordinates(center))>3)
    {
	printf("Too much arguments.");
	return 0;
    }
    else
	int coordinates[3] = CheckCoordinates(center);
    printf("Circle center x:%d \n Circle center y:%d \n Circle radius %d \n",coordinates[0],
    coordinates[1],coordinates[2]);
    return 1;
}

int* CheckCoordinate(char string[])
{
    return NULL;
}

int main()
{
    char data[100];
    printf("Type !exit to stop the programm.");
    while(1){
	scanf("%s",data);
	strlwr(data);
	if(data == "!exit")
	    break;
	if(!CheckFormat(data))
	{
	    printf("Given data is incorrect! Use WKT format.");
	}
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <geometry/geometry.h>

int main()
{
    char format[30];
    int *cords;
    printf("Type !exit to stop the programm.\n");
    while (1) {
        scanf("%s", format);
        if (!strcmp(format, "!exit"))
            break;
    	geometry object = *geometry_new(format);
        if (geometry_get_type(&object)) {
    	    cords = geometry_get_coordinates(&object);
    	    if(!strcmp(format, "circle")){
            printf("Object: %s\nX: %d\nY: %d\nRadius: %d\n Perimeter %f\n",
                   geometry_get_type(&object),
                   cords[0],
                   cords[1],
                   cords[2],
                   geometry_get_perimeter(&object));
    	    }
    	    if(!strcmp(format,"triangle")){
            printf("Object: %s\nX1: %d\nY1: %d\nX2: %d\nY2: %d\nX3: %d\nY3: %d\n Perimeter %f\n",
                   geometry_get_type(&object),
                   cords[0],
                   cords[1],
                   cords[2],
                   cords[3],
                   cords[4],
                   cords[5],
                   geometry_get_perimeter(&object));
	    }
        } else {
            printf("Incorrect Format\n");
        }
    }
    return 0;
}
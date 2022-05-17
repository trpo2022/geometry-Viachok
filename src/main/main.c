#include <geometry/geometry.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  char format[30];
  int *cords;
  int *cords2;
  geometry object;
  geometry object2;
  printf("Type !exit to stop the programm.\n");
  while (1) {
    scanf("%s", format);
    if (!strcmp(format, "!exit"))
      break;
    if (!strcmp(format, "circle")) {
        object = *geometry_new(format);
        cords = geometry_get_coordinates(&object);
        printf("Object: %s\nX: %d\nY: %d\nRadius: %d\n Perimeter %f\n",
               geometry_get_type(&object), cords[0], cords[1], cords[2],
               geometry_get_perimeter(&object));
    }
    else if (!strcmp(format, "triangle")) {
        object = *geometry_new(format);
        cords = geometry_get_coordinates(&object);
        printf("Object: %s\nX1: %d\nY1: %d\nX2: %d\nY2: %d\nX3: "
               "%d\nY3: %d\n Perimeter %f\n",
               geometry_get_type(&object), cords[0], cords[1], cords[2],
               cords[3], cords[4], cords[5], geometry_get_perimeter(&object));
    }
    else if (!strcmp(format, "intersect")) {
	object = *geometry_new("circle");
        object2 = *geometry_new("circle");
        int check = geometry_is_intersecting(&object,&object2);
        printf("test\n");
        cords = geometry_get_coordinates(&object);
        cords2 = geometry_get_coordinates(&object2);
        printf("test2\n");
        printf("Object: %s\nX: %d\nY: %d\nRadius:  "
    		"%d\n Perimeter %f\n And \nObject: %s\nX: %d\nY: %d\nRadius: "
		"%d\n Perimeter %f\n is",
    		geometry_get_type(&object), cords[0], cords[1], cords[2],
    		geometry_get_perimeter(&object),geometry_get_type(&object2), cords2[0], cords2[1], cords2[2],
    		geometry_get_perimeter(&object2));
    	if(check)
    	    printf(" intersecting\n");
    	else
    	printf(" not intersecting\n");
    }else{
      printf("Incorrect Format\n");
    }
  }
  return 0;
}
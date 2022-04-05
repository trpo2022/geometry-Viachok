#include <stdio.h>
#include <string.h>
#include <math.h>
#include "geometry.h"

geometry *geometry_new(char string[])
{
    int cords[10];
    int cords_amount = 0;
    geometry* object = malloc(sizeof(geometry));
    if(!object)
	return NULL;
    if (!strcmp(string, "circle")) {
	object->type = "circle";
        if (scanf("%d %d %d", &cords[0], &cords[1], &cords[2]) == 3) {
            cords_amount = 3;
        }
    }
    if (!strcmp(string, "triangle")) {
	object->type = "triangle";
        if (scanf("%d %d %d %d %d %d", &cords[0], &cords[1], &cords[2], &cords[3], &cords[4], &cords[5]) == 6) {
            cords_amount = 6;
        }
    }
    if(cords_amount > 0)
    {
	object->coordinates = malloc(sizeof(int) * cords_amount);
	if(!object->coordinates)
	    return NULL;
	for(int i=0;i<cords_amount;i++)
	    object->coordinates[i] = cords[i];
	return 1;
    }
    return 0;
}

void geometry_clear_object(geometry *object)
{
    free(object->coordinates);
    free(object->type);
    free(object);
}

int geeometry_set_type(geometry *object, char* string)
{
    int cords[10];
    int cords_amount = 0;
    if (!strcmp(string, "circle")) {
	object->type = "circle";
        if (scanf("%d %d %d", &cords[0], &cords[1], &cords[2]) == 3) {
            cords_amount = 3;
        }
    }
    if (!strcmp(string, "triangle")) {
	object->type = "triangle";
        if (scanf("%d %d %d %d %d %d", &cords[0], &cords[1], &cords[2], &cords[3], &cords[4], &cords[5]) == 6) {
            cords_amount = 6;
        }
    }
    if(cords_amount > 0)
    {
	object->coordinates = realloc(sizeof(int) * cords_amount);
	if(!object->coordinates)
	    return -1;
	for(int i=0;i<cords_amount;i++)
	    object->coordinates[i] = cords[i];
	return 0;
    }
    return -1;
}

int geeometry_set_coordinates(geometry *object, int* coordinates)
{
    if(sizeof(coordinates) != sizeof(object->coordinates))
	return -1;
    if (!strcmp(object->type, "circle")) {
	for(in i = 0; i < 3;i++)
	    object->coordinates[i] = coordinates[i];
    }
    if (!strcmp(string, "triangle")) {
        for(in i = 0; i < 6;i++)
	    object->coordinates[i] = coordinates[i];
    }
}

char *geometry_get_type(geometry *object)
{
    return object->type;
}

int *geometry_get_coordinates(geometry *object)
{
    return object->coordinates;
}

float geometry_get_perimeter(geometry *object)
{
    if (!strcmp(object->type, "circle")) {
	return 3.142857 * object->coordinates[2] * 2;
    }
    if (!strcmp(string, "triangle")) {
        int perimeter = 0;
        perimeter += sqrt(pow(fabs(fabs(object->coordinates[0])-fabs(object->coordinates[2])),2) + pow(fabs(fabs(object->coordinates[1])-fabs(object->coordinates[3])),2));
        perimeter += sqrt(pow(fabs(fabs(object->coordinates[2])-fabs(object->coordinates[4])),2) + pow(fabs(fabs(object->coordinates[4])-fabs(object->coordinates[5])),2));
        perimeter += sqrt(pow(fabs(fabs(object->coordinates[0])-fabs(object->coordinates[4])),2) + pow(fabs(fabs(object->coordinates[1])-fabs(object->coordinates[5])),2));
        return perimeter;
    }
}
#pragma once
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct geometry {
  int *coordinates;
  char *type;
} geometry;

geometry *geometry_new(char string[]);

int geometry_set_type(geometry *object, char *type);

int geometry_set_coordinates(geometry *object, int *coordinates);

int *geometry_get_coordinates(geometry *object);

char *geometry_get_type(geometry *object);

float geometry_get_perimeter(geometry *object);

void geometry_clear_object(geometry* object);
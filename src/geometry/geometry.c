#include "geometry.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

geometry *geometry_new(char string[]) {
  int cords[10];
  int cords_amount = 0;
  geometry *object = malloc(sizeof(geometry));
  if (!object)
    return NULL;
  if (!strcmp(string, "circle")) {
    object->type = "circle";
    if (scanf("%d %d %d", &cords[0], &cords[1], &cords[2]) == 3) {
      cords_amount = 3;
    }
  }
  if (!strcmp(string, "triangle")) {
    object->type = "triangle";
    if (scanf("%d %d %d %d %d %d", &cords[0], &cords[1], &cords[2], &cords[3],
              &cords[4], &cords[5]) == 6) {
      cords_amount = 6;
    }
  }
  if (cords_amount > 0) {
    object->coordinates = malloc(sizeof(int) * cords_amount);
    if (!object->coordinates)
      return NULL;
    for (int i = 0; i < cords_amount; i++)
      object->coordinates[i] = cords[i];
    return object;
  }
  return NULL;
}

void geometry_clear_object(geometry *object) {
  free(object->coordinates);
  free(object->type);
  free(object);
}

int geometry_set_type(geometry *object, char *string) {
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
    if (scanf("%d %d %d %d %d %d", &cords[0], &cords[1], &cords[2], &cords[3],
              &cords[4], &cords[5]) == 6) {
      cords_amount = 6;
    }
  }
  if (cords_amount > 0) {
    int *buffer = realloc(object->coordinates, sizeof(int) * cords_amount);
    if (!buffer)
      return -1;
    object->coordinates = buffer;
    for (int i = 0; i < cords_amount; i++)
      object->coordinates[i] = cords[i];
    return 0;
  }
  return -1;
}

int geometry_set_coordinates(geometry *object, int *coordinates) {
  if (sizeof(coordinates) != sizeof(object->coordinates))
    return -1;
  if (!strcmp(object->type, "circle")) {
    for (int i = 0; i < 3; i++)
      object->coordinates[i] = coordinates[i];
  }
  if (!strcmp(object->type, "triangle")) {
    for (int i = 0; i < 6; i++)
      object->coordinates[i] = coordinates[i];
  }
  return 1;
}

char *geometry_get_type(geometry *object) { return object->type; }

int *geometry_get_coordinates(geometry *object) { return object->coordinates; }

float geometry_get_perimeter(geometry *object) {
  if (!strcmp(object->type, "circle")) {
    return 3.142857 * object->coordinates[2] * 2;
  }
  if (!strcmp(object->type, "triangle")) {
    float perimeter = 0;
    perimeter += sqrt(pow(fabs(fabs((float)object->coordinates[0]) -
                               fabs((float)object->coordinates[2])),
                          2) +
                      pow(fabs(fabs((float)object->coordinates[1]) -
                               fabs((float)object->coordinates[3])),
                          2));
    perimeter += sqrt(pow(fabs(fabs((float)object->coordinates[0]) -
                               fabs((float)object->coordinates[4])),
                          2) +
                      pow(fabs(fabs((float)object->coordinates[1]) -
                               fabs((float)object->coordinates[5])),
                          2));
    perimeter += sqrt(pow(fabs(fabs((float)object->coordinates[2]) -
                               fabs((float)object->coordinates[4])),
                          2) +
                      pow(fabs(fabs((float)object->coordinates[3]) -
                               fabs((float)object->coordinates[5])),
                          2));
    return perimeter;
  }
  return -1;
}

int geometry_is_intersecting(geometry *first, geometry *second) {
  int intersection = 0;
  printf("test");
  if (!strcmp(first->type, "circle") && !strcmp(second->type, "circle")) {
    intersection = sqrt(pow(fabs(fabs((float)first->coordinates[0]) -
                                 fabs((float)second->coordinates[0])),
                            2) +
                        pow(fabs(fabs((float)first->coordinates[1]) -
                                 fabs((float)second->coordinates[1])),
                            2));
    if (intersection > second->coordinates[3] + first->coordinates[3])
      return 1;
    else
      return 0;
  } else {
    return -1;
  }
}
#include <ctest.h>
#include <geometry/geometry.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SQR(x) (x) * (x)

CTEST(arithmetic_suite, geometry_triangle_perimeter) {
  // Given
  geometry objectA;
  objectA.type = "triangle";
  objectA.coordinates = malloc(sizeof(int) * 3);
  objectA.coordinates[0] = 0;
  objectA.coordinates[1] = 0;
  objectA.coordinates[2] = 1;
  objectA.coordinates[3] = 1;
  objectA.coordinates[4] = 0;
  objectA.coordinates[5] = 2;

  // When
  double exp = 0;
  exp = exp + sqrt(SQR(objectA.coordinates[0] - objectA.coordinates[2]) +
                   SQR(objectA.coordinates[1] - objectA.coordinates[3]));
  exp = exp + sqrt(SQR(objectA.coordinates[0] - objectA.coordinates[4]) +
                   SQR(objectA.coordinates[1] - objectA.coordinates[5]));
  exp = exp + sqrt(SQR(objectA.coordinates[2] - objectA.coordinates[4]) +
                   SQR(objectA.coordinates[3] - objectA.coordinates[5]));
  const double result = geometry_get_perimeter(&objectA);

  // Then
  const double expected = exp;
  ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, geometry_circle_perimeter) {
  // Given
  geometry objectA;
  objectA.type = "circle";
  objectA.coordinates = malloc(sizeof(int) * 3);
  objectA.coordinates[0] = 1;
  objectA.coordinates[1] = 2;
  objectA.coordinates[2] = 3;

  // When
  const double result = geometry_get_perimeter(&objectA);

  // Then
  const double expected = objectA.coordinates[2] * 2 * M_PI;
  ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, geometry_coordinates_change) {
  // Given
  geometry objectA;
  objectA.type = "circle";
  objectA.coordinates = malloc(sizeof(int) * 3);
  objectA.coordinates[0] = 1;
  objectA.coordinates[1] = 2;
  objectA.coordinates[2] = 3;
  int new_coordinates[3] = {2, 4, 6};

  // When
  const int result = geometry_set_coordinates(&objectA, new_coordinates);

  // Then
  const int expected = 1;
  ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, circle_intersection) {
  // Given
  geometry objectA;
  objectA.type = "circle";
  objectA.coordinates = malloc(sizeof(int) * 3);
  objectA.coordinates[0] = 1;
  objectA.coordinates[1] = 2;
  objectA.coordinates[2] = 3;
  geometry objectB;
  objectB.type = "circle";
  objectB.coordinates = malloc(sizeof(int) * 3);
  objectB.coordinates[0] = 2;
  objectB.coordinates[1] = 2;
  objectB.coordinates[2] = 3;

  // When
  const int result = geometry_is_intersecting(&objectA, &objectB);

  // Then
  const int expected = 1;
  ASSERT_EQUAL(expected, result);
}

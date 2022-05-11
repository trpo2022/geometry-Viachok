#define CTEST_MAIN

#include <ctest.h>
#include <geometry/geometry.h>

CTEST(arithmetic_suite, geometry_triangle_perimeter)
{
    // Given
    const geometry objectA = *geometry_new("circle");
	objectA->coordinates = malloc(sizeof(int)*3);
	objectA->coordinates[0] = 0;
	objectA->coordinates[1] = 0;
	objectA->coordinates[2] = 1;
	objectA->coordinates[3] = 1;
	objectA->coordinates[4] = 0;
	objectA->coordinates[5] = 2;
	
    // When
    const int result = (geometry_get_perimeter(objectA) == 4.828427)?1:0;
	
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, geometry_circle_perimeter)
{
    // Given
    const geometry objectA = *geometry_new("circle");
	objectA->coordinates = malloc(sizeof(int)*3);
	objectA->coordinates[0] = 1;
	objectA->coordinates[1] = 2;
	objectA->coordinates[2] = 3;
	
    // When
    const int result = (geometry_get_perimeter(objectA) == 18.857142)?1:0;
	
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, geometry_coordinates_change)
{
    // Given
    const geometry objectA = *geometry_new("circle");
	objectA->coordinates = malloc(sizeof(int)*3);
	objectA->coordinates[0] = 1;
	objectA->coordinates[1] = 2;
	objectA->coordinates[2] = 3;
	const int new_coordinates[3] = {2,4,6};
	
    // When
    const int result = geometry_set_coordinates(objectA,new_coordinates);
	
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, geometry_initializtaion)
{
    // Given
    const geometry objectA = *geometry_new("circle");
	objectA->coordinates = malloc(sizeof(int)*3);
	objectA->coordinates[0] = 1;
	objectA->coordinates[1] = 2;
	objectA->coordinates[2] = 3;
	
    // When
    const int result = (!objectA)?0:1;
	
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, circle_intersection)
{
    // Given
    const geometry objectA = *geometry_new("circle");
	objectA->coordinates = malloc(sizeof(int)*3);
	objectA->coordinates[0] = 1;
	objectA->coordinates[1] = 2;
	objectA->coordinates[2] = 3;
    const geometry objectB = *geometry_new("circle");
	objectB->coordinates = malloc(sizeof(int)*3);
	objectB->coordinates[0] = 2;
	objectB->coordinates[1] = 2;
	objectB->coordinates[2] = 3;
	
    // When
    const int result = geometry_is_intersecting(objectA,objectB);
	
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
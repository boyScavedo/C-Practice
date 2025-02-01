#include <conio.h>
#include <stdio.h>

unsigned int minimum_distance(unsigned int, unsigned int, unsigned int[]);
unsigned int maximum(unsigned int[], unsigned int);

int main() {
  unsigned int perimeter, houses, distances[200000];

  printf("Enter the perimeter of the pond: ");
  scanf("%u", &perimeter);
  printf("Enter the number of houses: ");
  scanf("%u", &houses);

  printf("\n");

  for (int i = 0; i < houses; i++) {
    printf("Enter the distance of the house no. %u from the pond: ", i + 1);
    scanf("%u", &distances[i]);
  }

  printf("\nThe minimum distance between the houses is %u meters.",
         minimum_distance(perimeter, houses, distances));

  getch();
  return 0;
}

unsigned int minimum_distance(unsigned int perimeter, unsigned int houses,
                              unsigned int distances[200000]) {
  int difference = 0, maximum_difference = 0;
  int total_difference = 0;
  int wrap;
  int length = houses;

  for (int i = 1; i < length; i++) {
    difference = distances[i] - distances[i - 1];
    total_difference += difference;

    if (difference > maximum_difference) {
      maximum_difference = difference;
    }
  }

  wrap = perimeter - total_difference;
  if (wrap > maximum_difference) {
    maximum_difference = wrap;
  }

  return perimeter - maximum_difference;
}

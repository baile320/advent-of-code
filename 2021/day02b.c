#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Direction {
  FORWARD = 0,
  UP = 1,
  DOWN = 2,
};

typedef struct {
  int vertical_distance;
  int horizontal_distance;
  int aim;
} Position;

void update_position(char line[], Position *position) {
  enum Direction direction = 0;
  int distance = 0;
  int aim = 0;
  if (strncmp(line, "up", 2) == 0) {
    direction = 1;
    distance = atoi(&line[3]);
  } else if (strncmp(line, "down", 4) == 0) {
    direction = 2;
    distance = atoi(&line[5]);
  } else {
    direction = 0;
    distance = atoi(&line[8]);
  }

  if (direction == 0) {
    position->horizontal_distance += distance;
    position->vertical_distance += distance * position->aim;
  } else if (direction == 1) {
    position->aim -= distance;
  } else {
    position->aim += distance;
  }
}

// borrowed from:
// https://stackoverflow.com/questions/9069205/how-do-i-free-memory-in-c
char *readFile(char *filename) {
  FILE *f = fopen(filename, "rt");
  assert(f);
  fseek(f, 0, SEEK_END);
  long length = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *buffer = (char *)malloc(length + 1);
  buffer[length] = '\0';
  fread(buffer, 1, length, f);
  fclose(f);
  return buffer;
}

int main() {
  char *test_directions = readFile("day2_test.txt");

  int test_horizontal_position = 0;
  int test_vertical_position = 0;

  char *test_current_line;

  test_current_line = strtok(test_directions, "\n");
  Position test_position = {0, 0, 0};

  while (test_current_line != NULL) {
    update_position(test_current_line, &test_position);
    test_current_line = strtok(NULL, "\n");
  }

  printf("vertical position: %d, horizontal position: %d. product: %d\n",
         test_position.vertical_distance, test_position.horizontal_distance,
         test_position.vertical_distance * test_position.horizontal_distance);

  char *real_directions = readFile("day2_input.txt");

  int real_horizontal_position = 0;
  int real_vertical_position = 0;

  char *real_current_line;

  real_current_line = strtok(real_directions, "\n");
  Position real_position = {0, 0, 0};

  while (real_current_line != NULL) {
    update_position(real_current_line, &real_position);
    real_current_line = strtok(NULL, "\n");
  }

  printf("vertical position: %d, horizontal position: %d. product: %d\n",
         real_position.vertical_distance, real_position.horizontal_distance,
         real_position.vertical_distance * real_position.horizontal_distance);

  free(test_directions);
  free(real_directions);
  return 0;
}

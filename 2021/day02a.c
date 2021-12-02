#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Direction {
  FORWARD = 0,
  UP = 1,
  DOWN = 2,
};

typedef struct {
  enum Direction direction;
  int distance;
} Instruction;

Instruction parse_instruction(char line[]) {
  Instruction instruction;
  enum Direction direction = 0;
  int distance = 0;

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

  instruction.direction = direction;
  instruction.distance = distance;

  return instruction;
}

int main() {
  char test_directions[] =
      "forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2\n";

  int test_horizontal_position = 0;
  int test_vertical_position = 0;

  char *test_current_line;

  test_current_line = strtok(test_directions, "\n");
  while (test_current_line != NULL) {
    Instruction instruction = parse_instruction(test_current_line);
    if (instruction.direction == 0) {
      test_horizontal_position += instruction.distance;
    } else if (instruction.direction == 1) {
      test_vertical_position -= instruction.distance;
    } else {
      test_vertical_position += instruction.distance;
    }
    test_current_line = strtok(NULL, "\n");
  }

  printf("vertical position: %d, horizontal position: %d. product: %d\n",
         test_vertical_position, test_horizontal_position,
         test_vertical_position * test_horizontal_position);

  char real_directions[] =
      "forward 2\ndown 7\ndown 8\nforward 9\ndown 8\nforward 9\nforward "
      "8\ndown 3\nforward 8\nforward 5\nup 2\ndown 9\ndown 4\nforward "
      "4\nforward 3\ndown 8\ndown 9\nforward 5\ndown 1\nup 1\nforward 4\nup "
      "5\nforward 2\ndown 6\nforward 9\nforward 3\nforward 7\ndown 6\ndown "
      "1\nforward 8\ndown 3\nforward 1\nup 6\ndown 1\ndown 2\nforward 9\ndown "
      "7\ndown 1\ndown 7\ndown 7\nup 5\ndown 8\nforward 6\nup 8\nup 2\nforward "
      "6\nup 1\ndown 9\nforward 8\nforward 4\nup 3\nforward 7\ndown 2\ndown "
      "8\nforward 5\ndown 9\nup 4\nforward 7\nforward 5\ndown 5\ndown "
      "5\nforward 3\nforward 2\ndown 2\nup 4\nup 7\ndown 8\nup 8\nforward "
      "1\nup 4\nforward 4\ndown 2\nforward 5\nforward 7\ndown 4\nforward "
      "8\ndown 2\nforward 5\nforward 9\nforward 6\nforward 5\ndown 5\nforward "
      "4\nforward 3\ndown 7\ndown 8\nforward 9\nforward 7\ndown 3\ndown "
      "6\nforward 4\ndown 7\nup 9\ndown 8\nup 7\nup 3\nforward 6\nforward "
      "9\ndown 2\ndown 3\ndown 1\ndown 3\nforward 8\nforward 3\nforward "
      "9\ndown 5\nup 1\nup 2\ndown 9\nup 9\ndown 5\ndown 9\nforward 1\ndown "
      "3\ndown 5\ndown 1\nforward 7\ndown 6\nforward 7\nforward 4\nup 2\nup "
      "1\nforward 9\ndown 2\ndown 6\ndown 5\ndown 6\nforward 8\ndown "
      "5\nforward 1\nforward 2\ndown 7\ndown 5\ndown 7\nup 9\ndown 9\nup "
      "4\ndown 7\nup 8\ndown 9\nforward 3\ndown 6\ndown 2\nforward 9\ndown "
      "4\nup 7\nforward 3\ndown 5\nforward 8\nforward 9\ndown 2\nup 5\nforward "
      "2\nforward 9\nup 5\ndown 2\nforward 8\nforward 6\ndown 7\ndown "
      "3\nforward 4\nforward 3\nforward 9\nup 4\nup 4\nforward 7\nup "
      "3\nforward 6\ndown 7\nup 8\nforward 2\nup 1\ndown 6\nforward 4\nup "
      "6\nup 6\nup 3\nforward 4\nforward 2\nforward 5\nforward 8\ndown 9\ndown "
      "4\ndown 3\ndown 1\ndown 6\ndown 4\ndown 5\ndown 7\ndown 5\nup "
      "4\nforward 3\ndown 4\ndown 7\ndown 7\ndown 2\nforward 2\nforward 9\nup "
      "6\ndown 3\nup 9\nforward 8\ndown 9\nup 2\nup 2\nup 2\nup 1\ndown "
      "6\nforward 9\nforward 2\nforward 2\nforward 2\nforward 5\nup 3\ndown "
      "7\ndown 6\ndown 8\nup 3\nup 9\ndown 3\nforward 1\nforward 7\ndown "
      "7\ndown 1\nforward 3\ndown 7\ndown 9\ndown 7\ndown 3\nup 2\ndown 6\nup "
      "6\ndown 1\nup 2\nforward 7\nup 2\ndown 7\nup 2\ndown 9\ndown 3\nforward "
      "6\ndown 5\ndown 1\nforward 5\ndown 2\ndown 6\ndown 1\ndown 3\ndown "
      "3\ndown 5\nforward 2\nforward 4\nforward 8\nforward 6\nforward "
      "4\nforward 9\nup 8\ndown 5\nforward 1\ndown 1\nforward 1\nforward 6\nup "
      "1\ndown 6\ndown 3\nforward 9\nforward 5\nforward 4\nup 3\nup 7\ndown "
      "2\nup 4\nup 2\ndown 1\nforward 6\nforward 9\nforward 4\nforward 2\ndown "
      "8\nforward 4\nforward 3\nup 5\ndown 4\nforward 3\ndown 8\ndown 5\ndown "
      "5\nforward 1\nforward 6\nforward 4\nforward 5\nforward 9\nforward "
      "5\ndown 4\nforward 3\nforward 8\ndown 8\ndown 1\nup 4\ndown 4\nup "
      "7\nforward 2\nforward 6\ndown 3\ndown 5\ndown 5\ndown 8\nup 3\ndown "
      "2\nforward 4\nforward 2\nforward 4\nforward 9\nup 2\ndown 7\nup 7\ndown "
      "2\nforward 4\nup 7\nforward 4\ndown 2\nforward 7\nup 2\ndown 3\nforward "
      "5\ndown 7\ndown 2\nup 2\nup 1\nup 7\nup 9\ndown 3\nforward 1\nforward "
      "3\ndown 2\ndown 3\nforward 6\ndown 7\nforward 9\ndown 9\nforward "
      "3\nforward 2\ndown 1\nup 9\ndown 4\nforward 4\nup 4\nforward 7\nup "
      "3\ndown 4\ndown 9\ndown 3\nforward 7\ndown 6\ndown 7\ndown 6\nup "
      "5\nforward 3\nforward 9\nup 2\nup 4\nup 9\ndown 2\nforward 5\nup "
      "1\ndown 7\ndown 5\nup 2\nforward 8\ndown 8\nup 3\nforward 4\ndown "
      "9\nforward 6\ndown 9\ndown 5\nforward 6\ndown 8\nup 6\ndown 3\nforward "
      "6\nforward 3\ndown 3\ndown 5\ndown 7\ndown 1\ndown 5\ndown 7\ndown "
      "5\nforward 3\ndown 2\nforward 4\nup 4\nup 1\nup 7\nforward 1\nforward "
      "5\ndown 4\ndown 8\ndown 3\nforward 4\ndown 3\nup 7\ndown 6\nforward "
      "9\nup 8\nforward 2\nforward 5\ndown 6\nup 4\nforward 8\nforward 5\ndown "
      "6\nforward 2\ndown 7\nforward 3\nforward 1\nforward 6\ndown 9\nup "
      "6\ndown 4\ndown 2\nup 8\nforward 4\ndown 8\nforward 8\nup 9\nforward "
      "7\ndown 6\nup 9\ndown 4\nup 6\ndown 4\ndown 3\nup 7\nup 4\nforward "
      "5\nup 9\ndown 9\nup 6\ndown 3\nforward 8\ndown 9\nforward 7\nup 3\nup "
      "9\nforward 8\ndown 3\nforward 3\nforward 5\ndown 6\nforward 3\ndown "
      "4\nup 6\nforward 3\nforward 7\ndown 1\ndown 6\ndown 4\nforward 6\nup "
      "6\ndown 5\ndown 6\ndown 4\nup 2\ndown 7\ndown 9\ndown 2\ndown "
      "6\nforward 3\nforward 4\ndown 5\nup 5\ndown 5\nforward 3\nforward "
      "6\ndown 4\ndown 7\nup 2\nforward 7\ndown 7\nup 6\nup 3\nforward "
      "9\nforward 8\nup 6\nforward 2\ndown 2\nforward 8\nforward 4\nup "
      "6\nforward 6\ndown 8\nup 3\nup 5\nforward 6\nup 8\ndown 1\ndown 4\nup "
      "9\nforward 6\nup 5\ndown 6\ndown 8\ndown 9\nforward 5\nup 3\ndown "
      "7\nforward 3\nforward 6\ndown 3\ndown 1\ndown 9\nup 9\ndown 4\ndown "
      "7\nforward 2\nforward 4\ndown 7\nforward 7\nup 5\ndown 9\nup 7\ndown "
      "4\nforward 6\ndown 5\nforward 4\nup 8\ndown 4\ndown 7\nforward 3\ndown "
      "6\ndown 1\nforward 3\ndown 4\nup 6\nup 5\nup 7\nforward 5\ndown "
      "4\nforward 7\nup 1\ndown 4\nforward 4\ndown 2\ndown 6\nforward 1\nup "
      "3\nup 8\nforward 6\nforward 6\ndown 5\nforward 7\ndown 6\ndown "
      "8\nforward 6\ndown 6\nforward 3\nforward 5\ndown 9\ndown 5\nup 4\ndown "
      "5\ndown 1\nforward 1\nforward 5\ndown 2\nforward 5\nforward 2\nforward "
      "5\nup 3\nforward 5\nup 8\nforward 9\nforward 3\ndown 2\nup 2\nforward "
      "7\ndown 5\nup 1\ndown 3\ndown 7\nup 2\nforward 8\nforward 6\nforward "
      "1\nforward 6\nforward 6\ndown 5\nforward 4\ndown 5\nforward 9\nforward "
      "7\ndown 7\ndown 7\ndown 9\nforward 4\ndown 4\nforward 3\ndown "
      "6\nforward 5\ndown 9\nforward 6\nup 7\ndown 3\nup 4\nup 4\ndown 1\ndown "
      "2\nup 5\nforward 6\nforward 2\ndown 7\nup 6\nup 3\ndown 8\nforward "
      "1\ndown 3\nup 9\ndown 2\nforward 6\nforward 1\nforward 4\nup 1\ndown "
      "8\ndown 2\ndown 9\ndown 5\nforward 3\ndown 1\ndown 6\ndown 5\ndown "
      "3\nforward 1\nforward 9\nup 2\ndown 3\ndown 3\ndown 9\ndown 7\nforward "
      "6\nforward 8\nforward 4\nup 7\ndown 2\nforward 3\nforward 1\nup "
      "4\nforward 8\nup 9\nforward 8\nforward 2\ndown 5\nforward 2\ndown "
      "6\ndown 6\ndown 4\nforward 8\ndown 6\nforward 2\nforward 8\ndown "
      "7\ndown 6\nforward 2\ndown 1\ndown 8\nforward 2\nforward 9\nup "
      "6\nforward 6\ndown 3\ndown 2\nup 5\nup 6\ndown 6\nup 7\nforward "
      "5\nforward 7\ndown 1\nforward 7\nforward 9\ndown 3\nforward 4\nforward "
      "5\ndown 1\nup 3\nforward 2\nup 5\nforward 2\nforward 1\ndown 5\ndown "
      "4\ndown 8\nup 8\nforward 3\ndown 3\nforward 4\ndown 6\nup 8\ndown 5\nup "
      "2\ndown 1\nup 3\nforward 8\nup 6\nforward 9\nup 9\ndown 5\nforward "
      "2\nforward 9\nup 6\nforward 1\ndown 2\nforward 4\nforward 4\nforward "
      "1\nforward 5\nforward 1\nforward 4\ndown 5\ndown 1\ndown 2\ndown "
      "2\nforward 7\ndown 7\ndown 7\ndown 4\ndown 7\ndown 4\ndown 3\nup 7\nup "
      "1\nforward 2\nforward 3\ndown 4\ndown 5\nforward 9\nup 7\nforward "
      "6\ndown 1\nforward 6\nforward 6\nforward 8\ndown 3\nforward 2\ndown "
      "6\nforward 9\nup 6\nup 6\nforward 7\ndown 5\ndown 6\nup 3\ndown 5\nup "
      "4\nforward 3\ndown 7\nforward 9\nup 1\ndown 1\nup 6\ndown 3\nup 2\ndown "
      "5\nforward 3\nforward 6\ndown 9\ndown 4\nforward 7\ndown 1\nup "
      "1\nforward 3\nforward 5\nup 7\ndown 3\nup 9\nup 9\ndown 4\nup "
      "4\nforward 8\nup 9\ndown 8\nforward 6\nforward 4\nforward 9\nforward "
      "8\ndown 2\nforward 3\nforward 2\ndown 3\nup 1\nforward 6\ndown 3\ndown "
      "7\ndown 3\ndown 5\ndown 9\nup 9\nforward 8\nforward 6\ndown 8\nforward "
      "3\ndown 4\ndown 2\ndown 9\nforward 4\nforward 2\nup 4\nforward 1\nup "
      "8\nup 1\ndown 4\nup 2\ndown 1\nup 7\ndown 2\ndown 4\nup 4\nforward "
      "2\ndown 3\nforward 2\nforward 3\ndown 5\nforward 9\nforward 7\ndown "
      "1\nup 3\ndown 3\nforward 3\ndown 6\nforward 5\nup 3\nup 3\nup "
      "1\nforward 7\nforward 1\nforward 2\nforward 2\ndown 4\nup 7\nforward "
      "1\nforward 1\nforward 6\ndown 8\nup 8\ndown 8\ndown 4\ndown 6\nforward "
      "8\nforward 4\nforward 5\ndown 2\ndown 3\nforward 7\ndown 6\nforward "
      "4\nforward 1\nup 7\nup 5\nup 2\nforward 1\nforward 8\nforward 2\nup "
      "9\nforward 4\nforward 5\ndown 2\nforward 5\nforward 7\ndown 3\nforward "
      "1\ndown 3\nup 5\nup 2\nup 2\nup 2\nforward 4\nforward 4\nforward "
      "8\nforward 2\ndown 3\nup 7\ndown 4\ndown 2\ndown 7\nforward 2\ndown "
      "2\nforward 7\nup 9\nup 7\nforward 7\nforward 7\ndown 3\ndown 4\nup "
      "4\ndown 2\ndown 8\nforward 4\ndown 1\nup 6\nforward 4\ndown 2\nup "
      "8\ndown 1\ndown 8\ndown 6\nup 9\nforward 4\nup 1\ndown 2\ndown 9\ndown "
      "7\ndown 4\ndown 8\ndown 8\nup 1\ndown 5\nup 5\ndown 7\nup 7\nforward "
      "5\ndown 3\nforward 7\nup 5\ndown 3\nforward 9\nup 5\ndown 7\nforward "
      "8\nforward 8\ndown 2\nforward 7\nforward 8\ndown 4\nup 7\ndown 2\nup "
      "7\nforward 5\ndown 1\ndown 3\nforward 9\nup 4\nforward 6\nforward "
      "4\ndown 5\ndown 7\nforward 2\nforward 4\ndown 2\nforward 1\ndown 5\nup "
      "2\ndown 8\ndown 1\ndown 4\ndown 8\ndown 6\nforward 9\nforward "
      "2\nforward 6\nforward 4\ndown 1\nforward 8\nup 4\nforward 6\ndown "
      "4\nforward 4\nforward 3\nforward 6\nforward 9\nforward 8\ndown "
      "1\nforward 5\ndown 8\nforward 7\nup 1\ndown 3\nup 6\nforward 5\nforward "
      "8\nforward 8\nforward 5\nforward 5\nforward 1\nup 9\nforward 7\nup "
      "3\ndown 2\ndown 4\nforward 6\nup 2\nforward 5\nup 8\nforward 8\nforward "
      "2\nforward 6\nforward 3\nup 4\nforward 3\nforward 6\n";

  int real_horizontal_position = 0;
  int real_vertical_position = 0;

  char *real_current_line;

  real_current_line = strtok(real_directions, "\n");
  while (real_current_line != NULL) {
    Instruction instruction = parse_instruction(real_current_line);
    if (instruction.direction == 0) {
      real_horizontal_position += instruction.distance;
    } else if (instruction.direction == 1) {
      real_vertical_position -= instruction.distance;
    } else {
      real_vertical_position += instruction.distance;
    }
    real_current_line = strtok(NULL, "\n");
  }

  printf("vertical position: %d, horizontal position: %d. product: %d\n",
         real_vertical_position, real_horizontal_position,
         real_vertical_position * real_horizontal_position);
  return 0;
}

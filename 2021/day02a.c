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

  char *real_directions = readFile("day2_input.txt");

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

  free(test_directions);
  free(real_directions);
  return 0;
}

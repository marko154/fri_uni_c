#include <stdio.h>

typedef enum {
  ERROR,
  INIT,
  FINAL_1,
  FINAL_2,
  FINAL_ZERO,
  HEX_BEGIN,
  FINAL_HEX,
  BIN_BEGIN,
  FINAL_BIN
} State;

State next_state_init(char c) {
  if (c == '0') return FINAL_2;
  if ('1' <= c && c <= '9') return FINAL_1;
  return ERROR;
}

State next_state_final_1(char c) {
  if ('0' <= c && c <= '9') return FINAL_1;
  return ERROR;
}

State next_state_final_2(char c) {
  if ('0' <= c && c <= '7') return FINAL_ZERO;
  if (c == 'x') return HEX_BEGIN;
  if (c == 'b') return BIN_BEGIN;
  return ERROR;
}

State next_state_final_zero(char c) {
  if ('0' <= c && c <= '7') return FINAL_ZERO;
  return ERROR;
}

State next_state_hex_begin(char c) {
  if ('0' <= c && c <= '9') return FINAL_HEX;
  if ('A' <= c && c <= 'F') return FINAL_HEX;
  return ERROR;
}

State next_state_bin_begin(char c) {
  if (c == '1' || c == '0') return FINAL_BIN;
  return ERROR;
}

State next_state_final_bin(char c) {
  if (c == '1' || c == '0') return FINAL_BIN;
  return ERROR;
}

State next_state_final_hex(char c) {
  if ('0' <= c && c <= '9') return FINAL_HEX;
  if ('A' <= c && c <= 'F') return FINAL_HEX;
  return ERROR;
}

State get_next_state(State current_state, char c) {
  if (c == ' ') return INIT;

  switch (current_state) {
    case INIT:
      return next_state_init(c);
    case ERROR:
      return ERROR;
    case FINAL_1:
      return next_state_final_1(c);
    case FINAL_2:
      return next_state_final_2(c);
    case FINAL_ZERO:
      return next_state_final_zero(c);
    case HEX_BEGIN:
      return next_state_hex_begin(c);
    case BIN_BEGIN:
      return next_state_bin_begin(c);
    case FINAL_HEX:
      return next_state_final_hex(c);
    case FINAL_BIN:
      return next_state_final_bin(c);

    default:
      return -1;
  }
}

void print_result(State state) {
  switch (state) {
    case FINAL_1:
    case FINAL_2:
    case FINAL_BIN:
    case FINAL_HEX:
    case FINAL_ZERO:
      putchar('1');
      break;
    default:
      putchar('0');
  }
}

int main() {
  char c;
  State state = INIT;

  do {
    c = getchar();
    if (c == ' ' || c == '\n') {
      print_result(state);
    }
    state = get_next_state(state, c);

  } while (c != '\n');
  return 0;
}
#include <stdio.h>

enum State { ERROR, INIT, AFTER_SIGN, FINAL_ZERO, FINAL_NONZERO };

enum State next_state_init(char c) {
  if (c == '0') return FINAL_ZERO;
  if ('1' <= c && c <= '9') return FINAL_NONZERO;
  if (c == '+' || c == '-') return AFTER_SIGN;
  return ERROR;
}

enum State next_state_after_sign(char c) {
  if (c == '0') return FINAL_ZERO;
  if ('1' <= c && c <= '9') return FINAL_NONZERO;
  return ERROR;
}

enum State next_state_final_zero(char c) { return ERROR; }

enum State next_state_final_nonzero(char c) {
  if ('0' <= c && c <= '9') return FINAL_NONZERO;
  return ERROR;
}

enum State get_next_state(enum State current_state, char c) {
  if (c == ' ') return INIT;

  switch (current_state) {
    case INIT:
      return next_state_init(c);
    case ERROR:
      return ERROR;
    case AFTER_SIGN:
      return next_state_after_sign(c);
    case FINAL_ZERO:
      return next_state_final_zero(c);
    case FINAL_NONZERO:
      return next_state_final_nonzero(c);
    default:
      return -1;
  }
}

void print_result(enum State state) {
  if (state == FINAL_NONZERO || state == FINAL_ZERO) {
    putchar('1');
  } else {
    putchar('0');
  }
}

int main() {
  char c;
  enum State state = INIT;

  do {
    c = getchar();
    if (c == ' ' || c == '\n') {
      print_result(state);
    }
    state = get_next_state(state, c);

  } while (c != '\n');

  return 0;
}
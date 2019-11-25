#include <DerivativesDefines.h>
case 1:
{
  CUR_TYPE = NUMBER_TYPE;
  CUR_VALUE = 1;
  RET;
}
case 2:
{
  LEFT = DIF(LEFT);
  RIGHT = DIF(RIGHT);
  RET;
}
case 3:
{
  LEFT = DIF(LEFT);
  RIGHT = DIF(RIGHT);
  RET;
}
case 4:
{
  LET copy_left  = COPY(LEFT);
  LET copy_right = COPY(RIGHT);
  LEFT = MUL(DIF(LEFT), RIGHT);
  RIGHT = MUL(copy_left, DIF(copy_right));
  CUR_TYPE = TYPE("+");
  RET;
}
case 5:
{
  LET copy_left = COPY(LEFT);
  LET copy_right = COPY(RIGHT);
  LET denominator_multiplier1 = COPY(RIGHT);
  LET denominator_multiplier2 = COPY(RIGHT);
  LET left_child_left_subtree = MUL(DIF(LEFT), RIGHT);
  LET left_child_right_subtree = MUL(copy_left, DIF(copy_right));
  LET left_child = NEW(TYPE("+"), 0, left_child_left_subtree, left_child_right_subtree);
  LEFT = MOV(left_child);
  RIGHT = NEW(TYPE("*"), 0, denominator_multiplier1, denominator_multiplier2);
  RET;
}
#include <DerivativesUndefs.h>

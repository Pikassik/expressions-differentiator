VARIABLE x
{
  CUR_TYPE = NUMBER_TYPE;
  CUR_VALUE = 1;
  RET;
}
OPERATION +
{
  LEFT = DIF(LEFT);
  RIGHT = DIF(RIGHT);
  RET;
}
OPERATION -
{
  LEFT = DIF(LEFT);
  RIGHT = DIF(RIGHT);
  RET;
}
OPERATION *
{
  LET copy_left  = COPY(LEFT);
  LET copy_right = COPY(RIGHT);
  LEFT = MUL(DIF(LEFT), RIGHT);
  RIGHT = MUL(copy_left, DIF(copy_right));
  CUR_TYPE = TYPE("+");
  RET;
}
OPERATION /
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
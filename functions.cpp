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
  RET
}
OPERATION /
{
  LET copy_left = COPY(LEFT);
  LET copy_right = COPY(RIGHT);
  LET denominator_multiplier = COPY(RIGHT);
  LET left_child_left_subtree = MUL(DIF(LEFT), RIGHT);
  LET left_child_right_subtree = MUL(LEFT, DIF(RIGHT));
  LET left_child = NEW(TYPE("+"), 0, MOV(left_child_left_subtree), MOV(left_child_right_subtree));
  LEFT = MOV(left_child);
  RIGHT = NEW(TYPE("*"), 0, MOV(RIGHT), MOV(denominator_multiplier));
  RET
}
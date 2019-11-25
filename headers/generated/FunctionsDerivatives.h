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
  LEFT = OPERATION("*", DIF(LEFT), RIGHT);
  RIGHT = OPERATION("*", copy_left, DIF(copy_right));
  CUR_TYPE = TYPE("+");
  RET;
}
case 5:
{
  LET copy_left = COPY(LEFT);
  LET copy_right = COPY(RIGHT);
  LET denominator_multiplier1 = COPY(RIGHT);
  LET denominator_multiplier2 = COPY(RIGHT);
  LET left_child_left_subtree = OPERATION("*", DIF(LEFT), RIGHT);
  LET left_child_right_subtree = OPERATION("*", copy_left, DIF(copy_right));
  LET left_child =
    NEW("+", 0, left_child_left_subtree, left_child_right_subtree);
  LEFT = MOV(left_child);
  RIGHT = NEW("*", 0, denominator_multiplier1, denominator_multiplier2);
  RET;
}
case 6:
{
  CUR_TYPE = TYPE("*");
  LET copy_left = MOV(LEFT);
  LET copy_right = MOV(RIGHT);
  RIGHT = OPERATION("+",
                        OPERATION("*",
                                      DIF(COPY(copy_right)),
                                      FUNC("ln", COPY(copy_left))
                                  ),
                        OPERATION("*",
                                      OPERATION("/",
                                                    COPY(copy_right),
                                                    COPY(copy_left)
                                                ),
                                      DIF(COPY(copy_left))
                                  )
                    );
  LEFT = OPERATION("pow", MOV(copy_left), MOV(copy_right));
  RET;
}
case 7:
{
  CUR_TYPE = TYPE("/");
  LET copy_left = COPY(LEFT);
  LEFT = DIF(LEFT);
  RIGHT = MOV(copy_left);
  RET;
}
case 8:
{
  CUR_TYPE = TYPE("*");
  LET copy_left = COPY(LEFT);
  LEFT = FUNC("cos", COPY(LEFT));
  RIGHT = DIF(copy_left);
  RET;
}
case 9:
{
  CUR_TYPE = TYPE("*");
  LET copy_left = MOV(LEFT);
  LEFT = VALUE(-1);
  RIGHT = OPERATION("*",
                        FUNC("sin", COPY(copy_left)),
                        DIF(COPY(copy_left))
                    );
  RET;
}
case 10:
{
  CUR_TYPE = TYPE("*");
  LET copy_left = MOV(LEFT);
  LEFT = OPERATION("/",
                       VALUE(1),
                       OPERATION("*",
                                     FUNC("cos", COPY(copy_left)),
                                     FUNC("cos", COPY(copy_left))
                                 )
                   );
  RIGHT = DIF(copy_left);
  RET;
}
case 11:
{
  CUR_TYPE = TYPE("*");
  LET copy_left = MOV(LEFT);
  LEFT = OPERATION("/",
                       VALUE(-1),
                       OPERATION("*",
                                     FUNC("sin", COPY(copy_left)),
                                     FUNC("sin", COPY(copy_left))
                                 )
                   );
  RIGHT = DIF(copy_left);
  RET;
}
case 12:
{
  CUR_TYPE = TYPE("/");
  RIGHT = OPERATION("pow",
                          OPERATION("-",
                                        VALUE(1),
                                        OPERATION("*",
                                                  COPY(LEFT),
                                                  COPY(LEFT)
                                                  )
                                    ),
                          OPERATION("/",
                                    VALUE(1),
                                    VALUE(2)
                                    )
                   );
  LEFT = DIF(LEFT);
  RET;
}
case 13:
{
  CUR_TYPE = TYPE("/");
  RIGHT = OPERATION("pow",
                          OPERATION("-",
                                        VALUE(1),
                                        OPERATION("*",
                                                  COPY(LEFT),
                                                  COPY(LEFT)
                                                  )
                                    ),
                          OPERATION("/",
                                    VALUE(1),
                                    VALUE(2)
                                    )
                   );
  LEFT = OPERATION("*",
                       VALUE(-1),
                       DIF(LEFT));
  RET;
}
case 14:
{
  RIGHT = OPERATION("+",
                        VALUE(1),
                        OPERATION("*",
                                      COPY(LEFT),
                                      COPY(LEFT)
                                  )
                    );
  LEFT = DIF(LEFT);
  RET;
}
case 15:
{
  RIGHT = OPERATION("+",
                        VALUE(1),
                        OPERATION("*",
                                      COPY(LEFT),
                                      COPY(LEFT)
                                  )
                    );
  LEFT = OPERATION("*",
                       VALUE(-1),
                       DIF(LEFT)
                   );
  RET;
}
#include <DerivativesUndefs.h>

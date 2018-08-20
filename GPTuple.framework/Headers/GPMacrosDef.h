//
//  GPMacrosDef.h
//  GPTuple
//
//  Created by Liyanwei on 2018/8/15.
//  Copyright © 2018年 Liyanwei. All rights reserved.
//

#ifndef GP_MARCROS_DEF_H_
#define GP_MARCROS_DEF_H_
#import "GPTupleBase.h"

// Origin data

#define GP_ORDINAL_NUMBERS              \
first, second, third, fourth,           \
fifth, sixth, seventh, eighth,          \
ninth, tenth, eleventh, twelfth,        \
thirteenth, fourteenth, fifteenth,      \
sixteenth, seventeenth, eighteenth,     \
nineteenth, twentieth

#define GP_ORDINAL_CAP_NUMBERS          \
First, Second, Third, Fourth, Fifth,    \
Sixth, Seventh, Eighth, Ninth, Tenth,   \
Eleventh, Twelfth, Thirteenth,          \
Fourteenth, Fifteenth, Sixteenth,       \
Seventeenth, Eighteenth, Nineteenth,    \
Twentieth

#define GP_CHARS                        \
A, B, C, D, E, F, G, H, I, J, K, L, M,  \
N, O, P, Q, R, S, T, U, V, W, X, Y, Z

// Meta macro method

#define GP_STRINGIFY(VALUE)                                  GP_STRINGIFY_(VALUE)
#define GP_STRINGIFY_(VALUE)                                 # VALUE

#define GP_CONCAT(A, B)                                      GP_CONCAT_(A, B)
#define GP_CONCAT_(A, B)                                     A ## B

#define GP_ARG_HEAD(FIRST, ...)                              FIRST
#define GP_ARG_TAIL(FIRST, ...)                              __VA_ARGS__

#define GP_ARG_AT(N, ...)                                    GP_ARG_AT_(N, __VA_ARGS__)
#define GP_ARG_AT_(N, ...)                                   GP_CONCAT(GP_ARG_AT, N)(__VA_ARGS__)
#define GP_ARG_AT0(...)                                      GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT1(_0, ...)                                  GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT2(_0, _1, ...)                              GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT3(_0, _1, _2, ...)                          GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT4(_0, _1, _2, _3, ...)                      GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT5(_0, _1, _2, _3, _4, ...)                  GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT6(_0, _1, _2, _3, _4, _5, ...)              GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT7(_0, _1, _2, _3, _4, _5, _6, ...)          GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT8(_0, _1, _2, _3, _4, _5, _6, _7, ...)      GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT9(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...)  GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...)                                                                \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...)                                                           \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...)                                                      \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...)                                                 \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...)                                            \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...)                                       \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...)                                  \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...)                             \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...)                        \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...)                   \
GP_ARG_HEAD(__VA_ARGS__)
#define GP_ARG_AT20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...)              \
GP_ARG_HEAD(__VA_ARGS__)

#define GP_DEC(VAL)     \
GP_ARG_AT(VAL, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19)

#define GP_INC(VAL)     \
GP_ARG_AT(VAL, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)

#define GP_ARG_COUNT(...)   _GP_ARG_COUNT(__VA_ARGS__)

#define _GP_ARG_COUNT(...)  \
GP_ARG_AT(20, ##__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define GP_TAKE(N, ...)                                      GP_CONCAT(GP_TAKE, N)(__VA_ARGS__)
#define GP_TAKE0(...)
#define GP_TAKE1(...)                                        GP_ARG_HEAD(__VA_ARGS__)
#define GP_TAKE2(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE1(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE3(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE2(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE4(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE3(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE5(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE4(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE6(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE5(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE7(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE6(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE8(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE7(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE9(...)                                        GP_ARG_HEAD(__VA_ARGS__), GP_TAKE8(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE10(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE9(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE11(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE10(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE12(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE11(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE13(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE12(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE14(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE13(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE15(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE14(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE16(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE15(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE17(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE16(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE18(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE17(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE19(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE18(GP_ARG_TAIL(__VA_ARGS__))
#define GP_TAKE20(...)                                       GP_ARG_HEAD(__VA_ARGS__), GP_TAKE19(GP_ARG_TAIL(__VA_ARGS__))

#define GP_DROP(N, ...)                                      GP_CONCAT(GP_DROP, N)(__VA_ARGS__)
#define GP_DROP0(...)                                        __VA_ARGS__
#define GP_DROP1(...)                                        GP_ARG_TAIL(__VA_ARGS__)
#define GP_DROP2(...)                                        GP_DROP1(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP3(...)                                        GP_DROP2(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP4(...)                                        GP_DROP3(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP5(...)                                        GP_DROP4(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP6(...)                                        GP_DROP5(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP7(...)                                        GP_DROP6(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP8(...)                                        GP_DROP7(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP9(...)                                        GP_DROP8(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP10(...)                                       GP_DROP9(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP11(...)                                       GP_DROP10(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP12(...)                                       GP_DROP11(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP13(...)                                       GP_DROP12(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP14(...)                                       GP_DROP13(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP15(...)                                       GP_DROP14(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP16(...)                                       GP_DROP15(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP17(...)                                       GP_DROP16(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP18(...)                                       GP_DROP17(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP19(...)                                       GP_DROP18(GP_ARG_TAIL(__VA_ARGS__))
#define GP_DROP20(...)                                       GP_DROP19(GP_ARG_TAIL(__VA_ARGS__))

#define GP_INIT(...)                                         GP_TAKE(GP_DEC(GP_ARG_COUNT(__VA_ARGS__)), __VA_ARGS__)
#define GP_LAST(...)                                         GP_DROP(GP_DEC(GP_ARG_COUNT(__VA_ARGS__)), __VA_ARGS__)

#define GP_FOR(COUNT, MARCO, SEP)                            GP_CONCAT(GP_FOR, COUNT)(MARCO, SEP)
#define GP_FOR0(MARCO, SEP)
#define GP_FOR1(MARCO, SEP)                                  MARCO(0)
#define GP_FOR2(MARCO, SEP)                                  GP_FOR1(MARCO, SEP) SEP MARCO(1)
#define GP_FOR3(MARCO, SEP)                                  GP_FOR2(MARCO, SEP) SEP MARCO(2)
#define GP_FOR4(MARCO, SEP)                                  GP_FOR3(MARCO, SEP) SEP MARCO(3)
#define GP_FOR5(MARCO, SEP)                                  GP_FOR4(MARCO, SEP) SEP MARCO(4)
#define GP_FOR6(MARCO, SEP)                                  GP_FOR5(MARCO, SEP) SEP MARCO(5)
#define GP_FOR7(MARCO, SEP)                                  GP_FOR6(MARCO, SEP) SEP MARCO(6)
#define GP_FOR8(MARCO, SEP)                                  GP_FOR7(MARCO, SEP) SEP MARCO(7)
#define GP_FOR9(MARCO, SEP)                                  GP_FOR8(MARCO, SEP) SEP MARCO(8)
#define GP_FOR10(MARCO, SEP)                                 GP_FOR9(MARCO, SEP) SEP MARCO(9)
#define GP_FOR11(MARCO, SEP)                                 GP_FOR10(MARCO, SEP) SEP MARCO(10)
#define GP_FOR12(MARCO, SEP)                                 GP_FOR11(MARCO, SEP) SEP MARCO(11)
#define GP_FOR13(MARCO, SEP)                                 GP_FOR12(MARCO, SEP) SEP MARCO(12)
#define GP_FOR14(MARCO, SEP)                                 GP_FOR13(MARCO, SEP) SEP MARCO(13)
#define GP_FOR15(MARCO, SEP)                                 GP_FOR14(MARCO, SEP) SEP MARCO(14)
#define GP_FOR16(MARCO, SEP)                                 GP_FOR15(MARCO, SEP) SEP MARCO(15)
#define GP_FOR17(MARCO, SEP)                                 GP_FOR16(MARCO, SEP) SEP MARCO(16)
#define GP_FOR18(MARCO, SEP)                                 GP_FOR17(MARCO, SEP) SEP MARCO(17)
#define GP_FOR19(MARCO, SEP)                                 GP_FOR18(MARCO, SEP) SEP MARCO(18)
#define GP_FOR20(MARCO, SEP)                                 GP_FOR19(MARCO, SEP) SEP MARCO(19)
#define GP_FOR21(MARCO, SEP)                                 GP_FOR20(MARCO, SEP) SEP MARCO(20)

#define GP_FOR_SPACE(COUNT, MARCO)                           GP_CONCAT(GP_FOR_SPACE, COUNT)(MARCO)
#define GP_FOR_SPACE0(MARCO)
#define GP_FOR_SPACE1(MARCO)                                 MARCO(0)
#define GP_FOR_SPACE2(MARCO)                                 GP_FOR_SPACE1(MARCO) MARCO(1)
#define GP_FOR_SPACE3(MARCO)                                 GP_FOR_SPACE2(MARCO) MARCO(2)
#define GP_FOR_SPACE4(MARCO)                                 GP_FOR_SPACE3(MARCO) MARCO(3)
#define GP_FOR_SPACE5(MARCO)                                 GP_FOR_SPACE4(MARCO) MARCO(4)
#define GP_FOR_SPACE6(MARCO)                                 GP_FOR_SPACE5(MARCO) MARCO(5)
#define GP_FOR_SPACE7(MARCO)                                 GP_FOR_SPACE6(MARCO) MARCO(6)
#define GP_FOR_SPACE8(MARCO)                                 GP_FOR_SPACE7(MARCO) MARCO(7)
#define GP_FOR_SPACE9(MARCO)                                 GP_FOR_SPACE8(MARCO) MARCO(8)
#define GP_FOR_SPACE10(MARCO)                                GP_FOR_SPACE9(MARCO) MARCO(9)
#define GP_FOR_SPACE11(MARCO)                                GP_FOR_SPACE10(MARCO) MARCO(10)
#define GP_FOR_SPACE12(MARCO)                                GP_FOR_SPACE11(MARCO) MARCO(11)
#define GP_FOR_SPACE13(MARCO)                                GP_FOR_SPACE12(MARCO) MARCO(12)
#define GP_FOR_SPACE14(MARCO)                                GP_FOR_SPACE13(MARCO) MARCO(13)
#define GP_FOR_SPACE15(MARCO)                                GP_FOR_SPACE14(MARCO) MARCO(14)
#define GP_FOR_SPACE16(MARCO)                                GP_FOR_SPACE15(MARCO) MARCO(15)
#define GP_FOR_SPACE17(MARCO)                                GP_FOR_SPACE16(MARCO) MARCO(16)
#define GP_FOR_SPACE18(MARCO)                                GP_FOR_SPACE17(MARCO) MARCO(17)
#define GP_FOR_SPACE19(MARCO)                                GP_FOR_SPACE18(MARCO) MARCO(18)
#define GP_FOR_SPACE20(MARCO)                                GP_FOR_SPACE19(MARCO) MARCO(19)
#define GP_FOR_SPACE21(MARCO)                                GP_FOR_SPACE20(MARCO) MARCO(20)

#define GP_FOR_RECURSIVE(COUNT, MARCO, SEP)                  GP_CONCAT(GP_FOR_RECURSIVE, COUNT)(MARCO, SEP)
#define GP_FOR_RECURSIVE0(MARCO, SEP)
#define GP_FOR_RECURSIVE1(MARCO, SEP)                        MARCO(0)
#define GP_FOR_RECURSIVE2(MARCO, SEP)                        GP_FOR_RECURSIVE1(MARCO, SEP) SEP MARCO(1)
#define GP_FOR_RECURSIVE3(MARCO, SEP)                        GP_FOR_RECURSIVE2(MARCO, SEP) SEP MARCO(2)
#define GP_FOR_RECURSIVE4(MARCO, SEP)                        GP_FOR_RECURSIVE3(MARCO, SEP) SEP MARCO(3)
#define GP_FOR_RECURSIVE5(MARCO, SEP)                        GP_FOR_RECURSIVE4(MARCO, SEP) SEP MARCO(4)
#define GP_FOR_RECURSIVE6(MARCO, SEP)                        GP_FOR_RECURSIVE5(MARCO, SEP) SEP MARCO(5)
#define GP_FOR_RECURSIVE7(MARCO, SEP)                        GP_FOR_RECURSIVE6(MARCO, SEP) SEP MARCO(6)
#define GP_FOR_RECURSIVE8(MARCO, SEP)                        GP_FOR_RECURSIVE7(MARCO, SEP) SEP MARCO(7)
#define GP_FOR_RECURSIVE9(MARCO, SEP)                        GP_FOR_RECURSIVE8(MARCO, SEP) SEP MARCO(8)
#define GP_FOR_RECURSIVE10(MARCO, SEP)                       GP_FOR_RECURSIVE9(MARCO, SEP) SEP MARCO(9)
#define GP_FOR_RECURSIVE11(MARCO, SEP)                       GP_FOR_RECURSIVE10(MARCO, SEP) SEP MARCO(10)
#define GP_FOR_RECURSIVE12(MARCO, SEP)                       GP_FOR_RECURSIVE11(MARCO, SEP) SEP MARCO(11)
#define GP_FOR_RECURSIVE13(MARCO, SEP)                       GP_FOR_RECURSIVE12(MARCO, SEP) SEP MARCO(12)
#define GP_FOR_RECURSIVE14(MARCO, SEP)                       GP_FOR_RECURSIVE13(MARCO, SEP) SEP MARCO(13)
#define GP_FOR_RECURSIVE15(MARCO, SEP)                       GP_FOR_RECURSIVE14(MARCO, SEP) SEP MARCO(14)
#define GP_FOR_RECURSIVE16(MARCO, SEP)                       GP_FOR_RECURSIVE15(MARCO, SEP) SEP MARCO(15)
#define GP_FOR_RECURSIVE17(MARCO, SEP)                       GP_FOR_RECURSIVE16(MARCO, SEP) SEP MARCO(16)
#define GP_FOR_RECURSIVE18(MARCO, SEP)                       GP_FOR_RECURSIVE17(MARCO, SEP) SEP MARCO(17)
#define GP_FOR_RECURSIVE19(MARCO, SEP)                       GP_FOR_RECURSIVE18(MARCO, SEP) SEP MARCO(18)
#define GP_FOR_RECURSIVE20(MARCO, SEP)                       GP_FOR_RECURSIVE19(MARCO, SEP) SEP MARCO(19)
#define GP_FOR_RECURSIVE21(MARCO, SEP)                       GP_FOR_RECURSIVE20(MARCO, SEP) SEP MARCO(20)

#define GP_FOR_COMMA(COUNT, MARCO)                           GP_CONCAT(GP_FOR_COMMA, COUNT)(MARCO)
#define GP_FOR_COMMA0(MARCO)
#define GP_FOR_COMMA1(MARCO)                                 MARCO(0)
#define GP_FOR_COMMA2(MARCO)                                 GP_FOR_COMMA1(MARCO), MARCO(1)
#define GP_FOR_COMMA3(MARCO)                                 GP_FOR_COMMA2(MARCO), MARCO(2)
#define GP_FOR_COMMA4(MARCO)                                 GP_FOR_COMMA3(MARCO), MARCO(3)
#define GP_FOR_COMMA5(MARCO)                                 GP_FOR_COMMA4(MARCO), MARCO(4)
#define GP_FOR_COMMA6(MARCO)                                 GP_FOR_COMMA5(MARCO), MARCO(5)
#define GP_FOR_COMMA7(MARCO)                                 GP_FOR_COMMA6(MARCO), MARCO(6)
#define GP_FOR_COMMA8(MARCO)                                 GP_FOR_COMMA7(MARCO), MARCO(7)
#define GP_FOR_COMMA9(MARCO)                                 GP_FOR_COMMA8(MARCO), MARCO(8)
#define GP_FOR_COMMA10(MARCO)                                GP_FOR_COMMA9(MARCO), MARCO(9)
#define GP_FOR_COMMA11(MARCO)                                GP_FOR_COMMA10(MARCO), MARCO(10)
#define GP_FOR_COMMA12(MARCO)                                GP_FOR_COMMA11(MARCO), MARCO(11)
#define GP_FOR_COMMA13(MARCO)                                GP_FOR_COMMA12(MARCO), MARCO(12)
#define GP_FOR_COMMA14(MARCO)                                GP_FOR_COMMA13(MARCO), MARCO(13)
#define GP_FOR_COMMA15(MARCO)                                GP_FOR_COMMA14(MARCO), MARCO(14)
#define GP_FOR_COMMA16(MARCO)                                GP_FOR_COMMA15(MARCO), MARCO(15)
#define GP_FOR_COMMA17(MARCO)                                GP_FOR_COMMA16(MARCO), MARCO(16)
#define GP_FOR_COMMA18(MARCO)                                GP_FOR_COMMA17(MARCO), MARCO(17)
#define GP_FOR_COMMA19(MARCO)                                GP_FOR_COMMA18(MARCO), MARCO(18)
#define GP_FOR_COMMA20(MARCO)                                GP_FOR_COMMA19(MARCO), MARCO(19)
#define GP_FOR_COMMA21(MARCO)                                GP_FOR_COMMA20(MARCO), MARCO(20)

#define GP_FOR_EACH(...)                                     _GP_FOR_EACH(__VA_ARGS__)
#define _GP_FOR_EACH(MACRO, SEP, ...)                        GP_FOR_EACH_CTX(GP_FOR_EACH_ITER_, SEP, MACRO, ##__VA_ARGS__)
#define GP_FOR_EACH_ITER_(INDEX, PARAM, MACRO)               MACRO(INDEX, PARAM)

#define GP_FOR_EACH_CTX(MACRO, SEP, CTX, ...)                GP_CONCAT(GP_FOR_EACH_CTX, GP_ARG_COUNT(__VA_ARGS__))(MACRO, SEP, CTX, ##__VA_ARGS__)
#define GP_FOR_EACH_CTX0(MACRO, SEP, CTX)
#define GP_FOR_EACH_CTX1(MACRO, SEP, CTX, _0) MACRO(0, _0, CTX)
#define GP_FOR_EACH_CTX2(MACRO, SEP, CTX, _0, _1) \
GP_FOR_EACH_CTX1(MACRO, SEP, CTX, _0) SEP MACRO(1, _1, CTX)
#define GP_FOR_EACH_CTX3(MACRO, SEP, CTX, _0, _1, _2) \
GP_FOR_EACH_CTX2(MACRO, SEP, CTX, _0, _1) SEP MACRO(2, _2, CTX)
#define GP_FOR_EACH_CTX4(MACRO, SEP, CTX, _0, _1, _2, _3) \
GP_FOR_EACH_CTX3(MACRO, SEP, CTX, _0, _1, _2) SEP MACRO(3, _3, CTX)
#define GP_FOR_EACH_CTX5(MACRO, SEP, CTX, _0, _1, _2, _3, _4) \
GP_FOR_EACH_CTX4(MACRO, SEP, CTX, _0, _1, _2, _3) SEP MACRO(4, _4, CTX)
#define GP_FOR_EACH_CTX6(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5) \
GP_FOR_EACH_CTX5(MACRO, SEP, CTX, _0, _1, _2, _3, _4) SEP MACRO(5, _5, CTX)
#define GP_FOR_EACH_CTX7(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6) \
GP_FOR_EACH_CTX6(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5) SEP MACRO(6, _6, CTX)
#define GP_FOR_EACH_CTX8(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7) \
GP_FOR_EACH_CTX7(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6) SEP MACRO(7, _7, CTX)
#define GP_FOR_EACH_CTX9(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
GP_FOR_EACH_CTX8(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7) SEP MACRO(8, _8, CTX)
#define GP_FOR_EACH_CTX10(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
GP_FOR_EACH_CTX9(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8) SEP MACRO(9, _9, CTX)
#define GP_FOR_EACH_CTX11(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
GP_FOR_EACH_CTX10(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) SEP MACRO(10, _10, CTX)
#define GP_FOR_EACH_CTX12(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
GP_FOR_EACH_CTX11(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) SEP MACRO(11, _11, CTX)
#define GP_FOR_EACH_CTX13(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
GP_FOR_EACH_CTX12(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) SEP MACRO(12, _12, CTX)
#define GP_FOR_EACH_CTX14(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
GP_FOR_EACH_CTX13(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) SEP MACRO(13, _13, CTX)
#define GP_FOR_EACH_CTX15(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
GP_FOR_EACH_CTX14(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) SEP MACRO(14, _14, CTX)
#define GP_FOR_EACH_CTX16(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
GP_FOR_EACH_CTX15(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) SEP MACRO(15, _15, CTX)
#define GP_FOR_EACH_CTX17(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
GP_FOR_EACH_CTX16(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) SEP MACRO(16, _16, CTX)
#define GP_FOR_EACH_CTX18(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
GP_FOR_EACH_CTX17(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) SEP MACRO(17, _17, CTX)
#define GP_FOR_EACH_CTX19(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
GP_FOR_EACH_CTX18(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) SEP MACRO(18, _18, CTX)
#define GP_FOR_EACH_CTX20(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
GP_FOR_EACH_CTX19(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) SEP MACRO(19, _19, CTX)

#define GP_IF_EQ(A, B)                                       GP_CONCAT(GP_IF_EQ, A)(B)

#define GP_CONSUME_(...)
#define GP_EXPAND_(...)                                      __VA_ARGS__

#define GP_IF_EQ0(VALUE)                                     GP_CONCAT(GP_IF_EQ0_, VALUE)
#define GP_IF_EQ0_0(...)                                     __VA_ARGS__ GP_CONSUME_
#define GP_IF_EQ0_1(...)                                     GP_EXPAND_
#define GP_IF_EQ0_2(...)                                     GP_EXPAND_
#define GP_IF_EQ0_3(...)                                     GP_EXPAND_
#define GP_IF_EQ0_4(...)                                     GP_EXPAND_
#define GP_IF_EQ0_5(...)                                     GP_EXPAND_
#define GP_IF_EQ0_6(...)                                     GP_EXPAND_
#define GP_IF_EQ0_7(...)                                     GP_EXPAND_
#define GP_IF_EQ0_8(...)                                     GP_EXPAND_
#define GP_IF_EQ0_9(...)                                     GP_EXPAND_
#define GP_IF_EQ0_10(...)                                    GP_EXPAND_
#define GP_IF_EQ0_11(...)                                    GP_EXPAND_
#define GP_IF_EQ0_12(...)                                    GP_EXPAND_
#define GP_IF_EQ0_13(...)                                    GP_EXPAND_
#define GP_IF_EQ0_14(...)                                    GP_EXPAND_
#define GP_IF_EQ0_15(...)                                    GP_EXPAND_
#define GP_IF_EQ0_16(...)                                    GP_EXPAND_
#define GP_IF_EQ0_17(...)                                    GP_EXPAND_
#define GP_IF_EQ0_18(...)                                    GP_EXPAND_
#define GP_IF_EQ0_19(...)                                    GP_EXPAND_
#define GP_IF_EQ0_20(...)                                    GP_EXPAND_

#define GP_IF_EQ1(VALUE)                                     GP_IF_EQ0(GP_DEC(VALUE))
#define GP_IF_EQ2(VALUE)                                     GP_IF_EQ1(GP_DEC(VALUE))
#define GP_IF_EQ3(VALUE)                                     GP_IF_EQ2(GP_DEC(VALUE))
#define GP_IF_EQ4(VALUE)                                     GP_IF_EQ3(GP_DEC(VALUE))
#define GP_IF_EQ5(VALUE)                                     GP_IF_EQ4(GP_DEC(VALUE))
#define GP_IF_EQ6(VALUE)                                     GP_IF_EQ5(GP_DEC(VALUE))
#define GP_IF_EQ7(VALUE)                                     GP_IF_EQ6(GP_DEC(VALUE))
#define GP_IF_EQ8(VALUE)                                     GP_IF_EQ7(GP_DEC(VALUE))
#define GP_IF_EQ9(VALUE)                                     GP_IF_EQ8(GP_DEC(VALUE))
#define GP_IF_EQ10(VALUE)                                    GP_IF_EQ9(GP_DEC(VALUE))
#define GP_IF_EQ11(VALUE)                                    GP_IF_EQ10(GP_DEC(VALUE))
#define GP_IF_EQ12(VALUE)                                    GP_IF_EQ11(GP_DEC(VALUE))
#define GP_IF_EQ13(VALUE)                                    GP_IF_EQ12(GP_DEC(VALUE))
#define GP_IF_EQ14(VALUE)                                    GP_IF_EQ13(GP_DEC(VALUE))
#define GP_IF_EQ15(VALUE)                                    GP_IF_EQ14(GP_DEC(VALUE))
#define GP_IF_EQ16(VALUE)                                    GP_IF_EQ15(GP_DEC(VALUE))
#define GP_IF_EQ17(VALUE)                                    GP_IF_EQ16(GP_DEC(VALUE))
#define GP_IF_EQ18(VALUE)                                    GP_IF_EQ17(GP_DEC(VALUE))
#define GP_IF_EQ19(VALUE)                                    GP_IF_EQ18(GP_DEC(VALUE))
#define GP_IF_EQ20(VALUE)                                    GP_IF_EQ19(GP_DEC(VALUE))

// Functions

#define GP_ORDINAL_AT(N)                                     GP_ARG_AT(N, GP_ORDINAL_NUMBERS)
#define GP_ORDINAL_CAP_AT(N)                                 GP_ARG_AT(N, GP_ORDINAL_CAP_NUMBERS)
#define GP_CHARS_AT(N)                                       GP_ARG_AT(N, GP_CHARS)

#define GP_GENERIC_TYPE(index)                               __covariant GP_CHARS_AT(index): id
#define GP_PROPERTY_DEF(index)                               @property (nonatomic, strong) GP_CHARS_AT(index) GP_ORDINAL_AT(index)
#define _GP_INIT_PARAM_FIRST(index)                          GP_ORDINAL_CAP_AT(index):(GP_CHARS_AT(index))GP_ORDINAL_AT(index)
#define _GP_INIT_PARAM(index)                                GP_ORDINAL_AT(index):(GP_CHARS_AT(index))GP_ORDINAL_AT(index)
#define GP_INIT_PARAM(index)                                 GP_IF_EQ(0, index)(_GP_INIT_PARAM_FIRST(index))(_GP_INIT_PARAM(index))

#define GP_TUPLE_DEF(i)                                                                                                         \
@interface GP_CONCAT(GPTuple, i)<GP_FOR_COMMA(i, GP_GENERIC_TYPE)> :GPTupleBase                                                     \
\
GP_FOR_RECURSIVE(i, GP_PROPERTY_DEF, ;);                                                                                         \
\
@property (nonatomic, strong) GP_CHARS_AT(GP_DEC(i)) last;                                                                       \
\
- (instancetype)GP_CONCAT(initWith, GP_FOR_SPACE(i, GP_INIT_PARAM));                                                              \
\
@end

#define GP_TUPLE_DEF_FOREACH(index)                          GP_TUPLE_DEF(GP_INC(index))

#define GP_TUPLE_CLASSES_DEF                                 GP_FOR(20, GP_TUPLE_DEF_FOREACH, ;)

#define _GP_INIT_PARAM_CALL_FIRST(index, param)              GP_ORDINAL_CAP_AT(index):param
#define _GP_INIT_PARAM_CALL(index, param)                    GP_ORDINAL_AT(index):param
#define GP_INIT_PARAM_CALL(index, param)                     GP_IF_EQ(0, index)(_GP_INIT_PARAM_CALL_FIRST(index, param))(_GP_INIT_PARAM_CALL(index, param))

#define GPTupleAs(_Class_, ...)                              [[_Class_ alloc] GP_CONCAT(initWith, GP_FOR_EACH(GP_INIT_PARAM_CALL, ,__VA_ARGS__))]

#define GPTuple(...)                                         GPTupleAs(GP_CONCAT(GPTuple, GP_ARG_COUNT(__VA_ARGS__)), __VA_ARGS__)

#define GPT_FromVar(tuple)                                    (tuple)

#define GPT_UNPACK(index, param, tuple)                       param = [tuple GP_ORDINAL_AT(index)]

#define GPTupleUnpack(...)                                   GP_FOR_EACH_CTX_(GPT_UNPACK, ;, GP_LAST(__VA_ARGS__), GP_INIT(__VA_ARGS__))
#define GP_FOR_EACH_CTX_(...)                                GP_FOR_EACH_CTX(__VA_ARGS__)

#define GPTupleExtend(tuple, ...)                            [tuple join:GPTuple(__VA_ARGS__)]

#define GPT_PrivateSetterDef(_index_)  \
- (void)GP_CONCAT(_set, GP_ORDINAL_CAP_AT(_index_)):(id)value excludeNotifiyKey:(NSString *)key

@interface GPTupleBase (Private)
GP_FOR(20, GPT_PrivateSetterDef, ;);
@end

#endif /* GP_MARCROS_DEF_H_ */

/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2022 Harrison Chan (Xelus)
 * Copyright 2022 Pablo Ramirez <jp.ramangulo@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "optical_ansi.h"

#define XX NO_LED

led_config_t g_led_config = { {
  {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, XX,  13, 14, 15,  16, 17, 18, 19},
  { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,  34, 35, 36,  37, 38, 39, 40},
  { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,  55, 56, 57,  58, 59, 60, 61},
  { 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, XX, 74,  XX, XX, XX,  75, 76, 77, XX},
  { 78, XX, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, XX, 89,  XX, 90, XX,  91, 92, 93, 94},
  { 95, 96, 97, XX, XX, XX, 98, XX, XX, XX, 99,100,101,102, 103,104,105, 106, XX,107, XX}
}, {
    {5  ,  5},            {25 ,  5}, {35 ,  5}, {45 ,  5}, {55 ,  5}, {70 ,  5}, {80 ,  5}, {90 ,  5}, {100,  5}, {115,  5}, {125,  5}, {135,  5}, {145,  5}, {157,  5}, {167,  5}, {177,  5},// {190,  8}, {199,  8}, {207,  8}, {215,  8},
    {5  , 17}, {15 , 17}, {25 , 17}, {35 , 17}, {45 , 17}, {55 , 17}, {65 , 17}, {75 , 17}, {85 , 17}, {95 , 17}, {105, 17}, {115, 17}, {125, 17}, {140, 17}, {157, 17}, {167, 17}, {177, 17}, {188, 17}, {198, 17}, {208, 17}, {218, 17},
    {7  , 27}, {20 , 27}, {30 , 27}, {40 , 27}, {50 , 27}, {60 , 27}, {70 , 27}, {80 , 27}, {90 , 27}, {100, 27}, {110, 27}, {120, 27}, {130, 27}, {143, 27}, {157, 27}, {167, 27}, {177, 27}, {188, 27}, {198, 27}, {208, 27}, {218, 27},
    {9  , 37}, {23 , 37}, {33 , 37}, {43 , 37}, {53 , 37}, {63 , 37}, {73 , 37}, {83 , 37}, {93 , 37}, {103, 37}, {113, 37}, {123, 37},            {139, 37},                                  {188, 37}, {198, 37}, {208, 37},
    {11 , 48},            {28 , 48}, {38 , 48}, {48 , 48}, {58 , 48}, {68 , 48}, {78 , 48}, {88 , 48}, {98 , 48}, {108, 48}, {118, 48},            {137, 48},            {167, 48},            {188, 48}, {198, 48}, {208, 48}, {218, 48},
    {6  , 58}, {19 , 58}, {31 , 58},                                  {69 , 58},                                  {106, 58}, {119, 58}, {132, 58}, {144, 58}, {157, 58}, {167, 58}, {177, 58}, {193, 58},            {208, 58}
}, {
   4,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8, 8, 8,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,          4, 4, 4,
   4,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,    4,    4, 4, 4, 4,
   4, 4, 4,          4,          4, 4, 4, 4, 4, 4, 4, 4,    4
} };

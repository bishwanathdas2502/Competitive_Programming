/*

sum = 5 + 7 + 9
sum = 21

other way to write it

      3rd bit    2nd bit    1stbit    0th bit
      0           1          0          1      = 5 
      0           1          1          1      = 7
      1           0          0          1      = 9
---------------------------------------------------
set=  1            2          1          3
bit
cnt

      cnt*weight
sum = 1*(2^3) + 2*(2^2) + 1*(2^1) + 3*(2^0)
    = 8 +  8 + 2 + 3
    = 21


whenever pair sum of xor think in this way
*/





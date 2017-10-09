c, h, o = map(int, raw_input().strip().split())
H2O_c = -4 * c + 1 * h + 2 * o
CO2_c = -1 * h + 2 * o
C6H12O6_c = 4 * c + 1 * h - 2 * o
if H2O_c < 0 or CO2_c < 0 or C6H12O6_c < 0 or \
    H2O_c % 4 != 0 or CO2_c % 4 != 0 or C6H12O6_c % 24 != 0:
    print "Error"
else:
    H2O_c /= 4
    CO2_c /= 4
    C6H12O6_c /= 24
    print "{} {} {}".format(H2O_c, CO2_c, C6H12O6_c)
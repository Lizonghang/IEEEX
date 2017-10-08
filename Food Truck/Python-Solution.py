from __future__ import print_function
from math import *
from datetime import datetime


def degree2radian(degree):
    return degree / 180.0 * 3.1415926


class Custom:

    def __init__(self, date, latitude, longitude):
        self.date = date
        self.latitude = latitude
        self.longitude = longitude

    def in_range(self, radius, myLatitude, myLongitude):
        distance = 2 * 6378.137 * asin(sqrt(
            sin((self.latitude - myLatitude) / 2.0) ** 2 +
            cos(self.latitude) * cos(myLatitude) * sin((self.longitude - myLongitude) / 2.0) ** 2
        ))
        return distance < radius


def process_subscriber(string):
    date = datetime.strptime(string[0], '%m/%d/%Y %H:%M')
    latitude = degree2radian(float(string[1]))
    longitude = degree2radian(float(string[2]))
    phone = int(string[3])
    return date, latitude, longitude, phone

if __name__ == '__main__':
    customs = {}

    myLatitude, myLongitude = map(lambda s: degree2radian(float(s)), raw_input().strip().split(','))
    radius = input()
    _ = raw_input()

    while True:
        try:
            item = raw_input()
            if not item:  break
        except EOFError:
            break
        date, latitude, longitude, phone = process_subscriber(item.strip().split(','))
        c = Custom(date, latitude, longitude)
        if customs.has_key(phone):
            if customs[phone].date < c.date:
                customs[phone] = c
        else:
            customs[phone] = c

    first = True
    for phone in sorted(customs.keys()):
        c = customs[phone]
        if c.in_range(radius, myLatitude, myLongitude):
            if not first:  print(',', end='')
            print(phone, end='')
            first = False

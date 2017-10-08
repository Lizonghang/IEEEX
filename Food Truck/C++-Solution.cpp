#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//Reference to meelo's solution
//Page: http://www.cnblogs.com/meelo/p/6102959.html

double degree2radian(double degree){
    return degree / 180 * 3.1415926;
}

struct Custom {
    int year, month, day, hour, minute;
    double latitude, longitude;
    
    int timeNumber() const {
        return minute*60 + hour*3600 + day*86400 + month*2678400 + (year-1970)*980294400;
    }
    
    bool earlyThan(const Custom & that){
        return timeNumber() < that.timeNumber();
    }
    
    bool inRange(double radius, double myLatitude, double myLongitude) const {
        double distance = 2 * 6378.137 * asin(sqrt(pow(sin((latitude - myLatitude)/2),2) + cos(latitude)*cos(myLatitude)*pow(sin((longitude-myLongitude)/2),2)));
        return distance < radius;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double myLatitude, myLongitude, radius;
    map<long long, Custom> customs;
    
    scanf("%lf,%lf", &myLatitude, &myLongitude);
    myLatitude = degree2radian(myLatitude);
    myLongitude = degree2radian(myLongitude);
    scanf("%lf", &radius);
    string headers;
    cin >> headers;
    
    Custom c;
    long long phone;
    while (scanf("%d/%d/%d %d:%d, %lf, %lf, %lld", &c.day, &c.month, &c.year, &c.hour, &c.minute, &c.latitude, &c.longitude, &phone) != EOF) {
        c.latitude = degree2radian(c.latitude);
        c.longitude = degree2radian(c.longitude);
        if(customs.find(phone) == customs.end()){
            customs[phone] = c;
        }
        else{
            if (customs[phone].earlyThan(c)) {
                customs[phone] = c;
            }
        }
    }
    
    bool first = true;
    for(const auto kv: customs){
        if (kv.second.inRange(radius, myLatitude, myLongitude)) {
            if(!first) cout << ',';
            first = false;
            cout << kv.first;
        }
    }
    
    return 0;
}

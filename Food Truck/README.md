# Xtreme10.0 - Food Truck

Madhu has a food-truck called "The Yummy Goods" that goes to a different business hotspot every day at lunch! Madhu wants to perform location-based advertising to folks in the offices near her halt. To do this she uses the GPS location as a longitude and a latitude at the stop and decides on a radius (r) value. She wants to broadcast advertisement SMSes, to customers within this radius, advertising her food-truck.

She needs your help to generate the list of phone numbers of such folks. She has access to a big file of telecom data, which among other details, contains the phone number, longitude and latitude of active cell-phone users in the city at that moment.

In order to calculate the distance between her stops and her subscribers, she wants you to use the most recent location available for each subscriber. To calculate the distance, you should use the Haversine formula:

<code>d=2r×arcsin(sqrt(sin((latitude1-latitude2)/2)^2+cos(latitude1)×cos(latitude2)×sin((longitude1-longitude2)/2))^2)</code>
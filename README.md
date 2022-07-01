# Biometric-Glove
IoT project - Smart Biometric Glove to monitor health vitals using Arduino

Smart Biometric Gloves is a technology that can be termed as one of the most basic
form of IoT applications and have various use cases. Smart gloves have been employed in
various sectors and industries. This technology has a variety of use cases, for example a study
in Harvard University on TinyML and IoT produced a smart glove that is able to strum
guitar chords using motion sensors which detect the movement of the fingers and generate a
matching tune (click here for link). Another intriguing use case of the same can be found in
the assistance of the mute that assists the target audience in producing the required text with
hand gestures alone (click here for link). These have also proves their use in sports industry
where one needs to track specific movements. Smart gloves have been around for a while and
the spectrum of their uses has been boomed in the recent years.

![alt text](https://foglets.com/content/images/2019/05/sensors-18-02403-g001.png)

Biometric glove is yet another application and works on the principles of Wireless Body
Area Network, abbreviated as WBAN, the guidelines of which have been highlighted in the
IEEE 802.15 guidelines. WBAN is a technology that aims at deploying sensors at different
parts of the body that are used to sense the vitals of a particular individual (for example:
heart rate, SpO2 levels, diabetic sensors etc.) and essentially creating various nodes over the
entire body that interact with each other constantly and viewing the body as a network of
nodes. Such data can be sent to a device/target machine connected over the internet that can
process the data collected. In healthcare domain, Wireless Body Area Network (WBAN) has
transpired as a prominent technology which has been capable of providing better methods of
real time patient health monitoring at medicare centres and other places of tracing such as
home/workplace.

Due to the sudden increase in sedentary lifestyle in the recent times, it has become
crucial to track health vitals on a regular basis. In this project, the idea is to create a smart
biometric glove that is able to sense heart rate, temperature and oxygen saturation levels in
the blood stream and project them over a device that tracks and analyses the vitals and is able
to make predictions by classifies the data into specific clusters by means of employing ML
algorithms on the tracked data such as K Means Clustering, Hierarchical clustering into
categories of Normal, At Risk and Danger Zone.

### BIG STRUCTURE
This project operates on the principles of Wireless Body Area Network(WBAN) outlined
in IEEE 802.15.6 and is used specifically for healthcare purpose.WBAN aims to create a
network of nodes over the human body to track various details. WBAN in health care sector
is working their way to completely eliminate the need for blood checkups with constantly
tracking vitals with chips and sensors embedded inside and on human body as per the
demands for deployment. IoT application in this project can be highlighted in the use of
sensors such as temperature sensor, heart rate sensor and oxygen saturation level sensor which
interact with each other and are connected over the internet to user’s device using WiFi
module. The context sensors make up for things in the definition of IoT.

### EXACT PROBLEM STATEMENT
In this project, the aim is to create a smart biometric glove that is able to sense multiple
context of the human body and provide the data over to the device of the user. Upon the
arrival of the data on the device, an AI/ML algorithm can be employed to the collected data
to make predictions based on the provided dataset to add to the learning process and make
predictions based on that. The algorithms employed will be able to detect whether the person
in question has normal vitals, at risk or in danger category at any given time. It may also
change the normal range depending on different individuals and provide a relative analysis as
to the changes inflicted in the health are positive or negative in nature. In case of any sudden
anomalous activity in the data, the user along with a third party medical facility will be
immediately notified of the situation.

<img width="655" alt="Screenshot 2022-07-01 at 9 51 11 AM" src="https://user-images.githubusercontent.com/69413205/176822827-c90679ea-4559-49ce-b335-10125dcda510.png">

The wire connections for the Arduino can be seen in the picture above.
A WiFi module is being used for communication
1 Temperature sensor
1 Heart Rate sensor
1 SpO2 sensor
Currently, the connections have been made on a breadboard.
Soldering is yet to be done so as to provide a steady build for submission
Necessary alterations to glove have been made to accommodate the sensors.

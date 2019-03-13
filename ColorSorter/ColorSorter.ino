    /*Color Sorter Arduino
     *CPSC 581 - Human Computer Interaction: II
     */
    
    #include <Servo.h>
    #define S0 3
    #define S1 4
    #define S2 5
    #define S3 6
    #define sensorOut 7
    Servo topServo;
    Servo bottomServo;
    int frequency = 0;
    int color=0;
    void setup() {
      pinMode(S0, OUTPUT);
      pinMode(S1, OUTPUT);
      pinMode(S2, OUTPUT);
      pinMode(S3, OUTPUT);
      pinMode(sensorOut, INPUT);
      // Setting frequency-scaling to 20%
      digitalWrite(S0, HIGH);
      digitalWrite(S1, LOW);
      topServo.attach(8);
      bottomServo.attach(9);
      Serial.begin(9600);
    }
    void loop() {

      topServo.write(12);
      delay(1000);

      topServo.write(70);
      delay(2000);
      
      color = readColor();
      delay(10);  
      switch (color) {
        case 1:
        bottomServo.write(25);
        break;
        case 2:
        bottomServo.write(55);
        break;
        case 3:
        bottomServo.write(85);
        break;
        case 4:
        bottomServo.write(115);
        break;
        case 5:
        bottomServo.write(145);
        break;
    
        case 0:
        break;
      }

      topServo.write(92);
      delay(1000);
    }
    // Custom Function - readColor()
    int readColor() {
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      int R = frequency;
      // Printing the value on the serial monitor
      Serial.print("R= ");//printing name
      Serial.print(frequency);//printing RED color frequency
      Serial.print("  ");
      delay(50);
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      int G = frequency;
      // Printing the value on the serial monitor
      Serial.print("G= ");//printing name
      Serial.print(frequency);//printing RED color frequency
      Serial.print("  ");
      delay(50);
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      int B = frequency;
      // Printing the value on the serial monitor
      Serial.print("B= ");//printing name
      Serial.print(frequency);//printing RED color frequency
      Serial.println("  ");
      delay(50);
      
      /*
       * Add values here, need to calibrate.
       */
      if(R<45 & R>32 & G<65 & G>55){
        color = 1; // Red
      }
      if(G<55 & G>43 & B<47 &B>35){
        color = 2; // Orange
      }
      if(R<53 & R>40 & G<53 & G>40){
        color = 3; // Green
      }
      if(R<38 & R>24 & G<44 & G>30){
        color = 4; // Yellow
      }
      if(R<56 & R>46 & G<65 & G>55){
        color = 5; // Brown
      }
      return color;  
    }

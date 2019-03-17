    /*Color Sorter Arduino
     *CPSC 581 - Human Computer Interaction: II
     *This program is used to control two servo motors and a color sensor
     *in order to sort Skittle flavors in respective cups.
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

      topServo.write(68);
      delay(1000);
      
      color = readColor();
      delay(50);  
      switch (color) {
        case 1:
        bottomServo.write(28);
        break;
        case 2:
        bottomServo.write(65);
        break;
        case 3:
        bottomServo.write(115);
        break;
        /*
        case 4:
        bottomServo.write(115);
        break;
        */
        case 4:
        bottomServo.write(140);
        break;
    
        case 0:
        break;
      }
      delay(1000);
      topServo.write(92);
      delay(1000);
    }
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
      if(R>=68 && R<=82 && G>=98 && G<=112 && B>=68 && B<=82){
        color = 1; // Purple
      }
      /*
      else if(R>=46 && R<=58 && G>=80 && G<=92 && B>=68 && B<=82){
        color = 2; // Orange
      }
      */
      else if(R>=56 && R<=76 && G>=70 && G<=96 && B>=64 & B<=88){
        color = 2; // Green
      }
      else if(R>=54 && R<=72 && G>=90 && G<=120 && B>=68 & B<=89){
        color = 3; // Red
      }
      else if(R>=44 && R<=58 && G>=65 && G<=80 && B>=62 & B<=78){
        color = 4; // Yellow
      }
    
      return color;  
    }

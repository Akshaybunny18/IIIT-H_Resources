#include <Servo.h> 
#define enA 10     
#define in1 9       
#define in2 8       
#define in3 7       
#define in4 6       
#define enB 5      
#define trigger 11  
#define echo 12     
#define servoPin 2  
#define L_S 3      
#define R_S 4     
#define hi 13 
const int SAFE_DISTANCE = 25; 
Servo myServo;

void setup() {
    Serial.begin(9600);

   
    pinMode(R_S, INPUT);
    pinMode(L_S, INPUT);
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);

    
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    
    pinMode(hi, INPUT);
    
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 255);
    analogWrite(enB, 255);

    
    myServo.attach(servoPin);
    myServo.write(90);
}

void loop() {
    long distanceF ;
    if (digitalRead(hi) == HIGH) {
         distanceF = measureDistance(); // Measure forward distance
       
        Serial.println("Obstacle Avoidance Mode");
        if (distanceF > SAFE_DISTANCE || distanceF == 0) {
            forword();
        } else {
            Check_side();
        }
    } else {
        Serial.println("Line Following Mode");
        if (distanceF < SAFE_DISTANCE && distanceF!=0 && 0) {
            escapeObstacle();
        } else {
            // Line-following logic
            if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) {
                forword();
            } if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)) {
                forword();
            } else if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) {
                turnRight();
            } else if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) {
                turnLeft();
            }
        }
    }
}

int measureDistance() {
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    long duration = pulseIn(echo, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}

void escapeObstacle() {
    int leftDistance, rightDistance;
    myServo.write(180);
    delay(500);
    leftDistance = measureDistance(); 
    myServo.write(90);

    if (leftDistance > SAFE_DISTANCE) {
       
        turnLeft();
        delay(300);
        forword();  
        delay(600);
        turnRight();
        delay(300);
//        forword();  // Move forward again
//        delay(600);
//        turnRight(); // Turn right again for adjustment
//        delay(400);
    } else {
        // If left side is not clear, check the right side
        myServo.write(0); // Turn servo to the right
        delay(500);
        rightDistance = measureDistance(); // Measure distance on the right
        myServo.write(90);

        if (rightDistance > SAFE_DISTANCE) {
            // If right side is clear
            turnRight();
            delay(300);
            forword();  
            delay(600);
            turnLeft();  
            delay(300);
//            forword();  
//            delay(600);
//            turnLeft(); 
//            delay(400);
        } 
        else {
            backword(); 
            delay(800);
        }
    }
}

void forword() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    //analogWrite(enA, 255);
    //analogWrite(enB, 255);
}
void backword() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    //analogWrite(enA, 255);
    //analogWrite(enB, 255);
}

void turnRight() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
   // analogWrite(enA, 255);
   // analogWrite(enB, 255);
}

void turnLeft() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
   // analogWrite(enA, 255);
   // analogWrite(enB, 255);
}

void Stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    //analogWrite(enA, 0);
    //analogWrite(enB, 0);
}

void reverseTurn(bool turnRight) {
    if (turnRight) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    } else {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    delay(800);
    Stop();
}
void Check_side() {
    Stop();
    delay(500);

    // Check left using servo.write
    myServo.write(180); // Servo turns left
    delay(500);
    long distance_L = measureDistance();
    myServo.write(90);
    delay(500);
    Serial.print("D L = "); Serial.println(distance_L);

    if (distance_L > SAFE_DISTANCE) {
        turnLeft();
        delay(500);
        return; // Left is clear
    }

    // Check right using servo.write
    myServo.write(0); // Servo turns right
    delay(500);
    long distance_R = measureDistance();
    myServo.write(90);
    delay(500);
    Serial.print("D R = "); Serial.println(distance_R);

    if (distance_R > SAFE_DISTANCE) {
        turnRight();
        delay(500);
        return; // Right is clear
    }

    // If both are blocked, reverse and pick the side with greater distance
    backword();
    delay(800);

    if (distance_L > distance_R) {
        reverseTurn(false); // Turn left
    } else {
        reverseTurn(true);  // Turn right
    }
}

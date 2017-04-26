//constants

const int rPin = 5;
const int gPin = 6;
const int bPin = 3;

const float margin = 1 / 4;
const int lowerBound = margin * 255;
const int upperBound = (1 - margin) * 255;

const int variation = 5;
const float boundWeight = 3 / 4;

//initialize variables
int rValue;
int rValue;
int rValue;

int average;

void setup() {
  //set pinout
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  //set lights to random values
  int rValue = random(0, 255);
  int rValue = random(0, 255);
  int rValue = random(0, 255);

}

void loop() {
  average = (rValue + gValue + bValue) / 3;

  //randomly change pin values
  if (average < lowerBound) {
    int lowerVariation = (1 - boundWeight) * variation;
    int upperVariation = boundWeight * variation;
    rValue = random(rValue - lowerVariation, rValue + upperVariation);
    gValue = random(gValue - lowerVariation, gValue + upperVariation);
    bValue = random(bValue - lowerVariation, bValue + upperVariation);
  }
  else if (average > upperBound) {
    int lowerVariation = boundWeight * variation;
    int upperVariation = (1 - boundWeight) * variation;
    rValue = random(rValue - lowerVariation, rValue + upperVariation);
    gValue = random(gValue - lowerVariation, gValue + upperVariation);
    bValue = random(bValue - lowerVariation, bValue + upperVariation);
  }
  else {
    rValue = random(rValue - variation, rValue + variation);
    gValue = random(gValue - variation, gValue + variation);
    bValue = random(bValue - variation, bValue + variation);
  }

  //write values to pins
  analogWrite(rPin, 255);
  analogWrite(gPin, 255);
  analogWrite(bPin, 255);
}

//constants

const int rPin = 5;
const int gPin = 6;
const int bPin = 3;

const float margin = 1 / 4;
const int lowerBound = margin * 255;
const int upperBound = (1 - margin) * 255;

const int variation = 20;
const float boundWeight = 3 / 4;

//initialize variables
int rVal;
int gVal;
int bVal;

int average;

void setup() {
  //set pinout
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  //set lights to random Vals
  int rVal = random(0, 255);
  int gVal = random(0, 255);
  int bVal = random(0, 255);

}

void loop() {
  average = (rVal + gVal + bVal) / 3;

  //randomly change pin values
  if (average < lowerBound) {
    int lowerVariation = (1 - boundWeight) * variation;
    int upperVariation = boundWeight * variation;
    rVal = random(rVal - lowerVariation, rVal + upperVariation);
    gVal = random(gVal - lowerVariation, gVal + upperVariation);
    bVal = random(bVal - lowerVariation, bVal + upperVariation);
  }
  else if (average > upperBound) {
    int lowerVariation = boundWeight * variation;
    int upperVariation = (1 - boundWeight) * variation;
    rVal = random(rVal - lowerVariation, rVal + upperVariation);
    gVal = random(gVal - lowerVariation, gVal + upperVariation);
    bVal = random(bVal - lowerVariation, bVal + upperVariation);
  }
  else {
    rVal = random(rVal - variation, rVal + variation);
    gVal = random(gVal - variation, gVal + variation);
    bVal = random(bVal - variation, bVal + variation);
  }

  //write values to pins
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
}

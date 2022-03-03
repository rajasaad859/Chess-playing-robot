#include <Servo.h>

Servo baseServo;
Servo arm1Servo;
Servo arm2Servo;
Servo rotationServo;
Servo gripServo;

int servoAngle = 0;
int reqAngle = 0;

int data[9];

bool pass = true;

void setup()
{
  baseServo.attach(10);
  arm1Servo.attach(12);
  arm2Servo.attach(9);
  rotationServo.attach(2);
  gripServo.attach(5);

  Serial.begin(9600);

  setToDefault();
}

void loop()
{

  while (Serial.available() >= 9)
  {

    for (int i = 0; i < 9; i++)
    {
      data[i] = Serial.read();
    }

    if (data[0] == 0)
    {
      noCapture(data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
    }
    else
    {
      yesCapture(data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
    }
  }
}

// void loop()
// {

//   while (pass)
//   {

//     noCapture(46, 60, 50, 43, 57, 85, 73, 33);

//       // yesCapture(43, 60, 50, 43, 57, 85, 73, 30);

//     pass = false;
//   }

// }


void setToDefault()
{
  servoAngle = baseServo.read();
  reqAngle = 170;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      baseServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      baseServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm1Servo.read();
  reqAngle = 40;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm2Servo.read();
  reqAngle = 50;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = rotationServo.read();
  reqAngle = 90;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      rotationServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      rotationServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = gripServo.read();
  reqAngle = 107;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      gripServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      gripServo.write(i);
      delay(20);
    }
  }
}

void setToDefault2()
{
  servoAngle = arm1Servo.read();
  reqAngle = 50;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm2Servo.read();
  reqAngle = 90;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = baseServo.read();
  reqAngle = 90;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      baseServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      baseServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = rotationServo.read();
  reqAngle = 20;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      rotationServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      rotationServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = gripServo.read();
  reqAngle = 90;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      gripServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      gripServo.write(i);
      delay(20);
    }
  }
}

void setToDefault3()
{
  servoAngle = baseServo.read();
  reqAngle = 170;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      baseServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      baseServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm1Servo.read();
  reqAngle = 50;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm2Servo.read();
  reqAngle = 48;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = rotationServo.read();
  reqAngle = 20;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      rotationServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      rotationServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = gripServo.read();
  reqAngle = 110;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      gripServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      gripServo.write(i);
      delay(20);
    }
  }
}

void noCapture(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6, int angle7, int angle8)
{
  setToDefault();

  delay(1000);

  MoveToSquareCapture(angle1, angle2, angle3, angle4);

  delay(1000);

  capture();

  delay(1000);

  setToDefault2();

  delay(1000);

  MoveToSquareRelease(angle5, angle6, angle7, angle8);

  delay(1000);

  release();

  delay(1000);

  setToDefault2();

  delay(1000);

  setToDefault();
}

void yesCapture(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6, int angle7, int angle8)
{
  setToDefault();

  delay(1000);

  MoveToSquareCapture(angle5, angle6, angle7, angle8);

  delay(1000);

  capture();

  delay(1000);

  setToDefault2();

  delay(1000);

  setToDefault3();

  delay(1000);

  release();

  delay(1000);

  setToDefault2();

  delay(1000);

  MoveToSquareCapture(angle1, angle2, angle3, angle4);

  delay(1000);

  capture();

  delay(1000);

  setToDefault2();

  delay(1000);

  MoveToSquareRelease(angle5, angle6, angle7, angle8);

  delay(1000);

  release();

  delay(1000);

  setToDefault2();

  delay(1000);

  setToDefault();
}

void MoveToSquareCapture(int base, int arm1, int arm2, int rotation)
{
  // MoveToSquare(baseServo,  gripServo,  arm2Servo,  rotationServo,  arm1Servo);

  // MoveToSquare(baseServo,  arm1Servo,  arm2Servo,  rotationServo,  gripServo);

  servoAngle = baseServo.read();
  reqAngle = base;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      baseServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      baseServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  openGripper();
  // servoAngle = gripServo.read();
  // reqAngle = 107;

  // if (servoAngle < reqAngle)
  // {
  //   for (int i = servoAngle; i <= reqAngle; i++)
  //   {
  //     gripServo.write(i);
  //     delay(20);
  //   }
  // }
  // else if (servoAngle > reqAngle)
  // {
  //   for (int i = servoAngle; i >= reqAngle; i--)
  //   {
  //     gripServo.write(i);
  //     delay(20);
  //   }
  // }

  delay(1000);

  servoAngle = arm2Servo.read();
  reqAngle = arm2;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }

  servoAngle = rotationServo.read();
  reqAngle = rotation;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      rotationServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      rotationServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm1Servo.read();
  reqAngle = arm1;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }
}

void MoveToSquareRelease(int base, int arm1, int arm2, int rotation)
{
  // MoveToSquare(baseServo,  gripServo,  arm2Servo,  rotationServo,  arm1Servo);

  // MoveToSquare(baseServo,  arm1Servo,  arm2Servo,  rotationServo,  gripServo);

  servoAngle = baseServo.read();
  reqAngle = base;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      baseServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      baseServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm2Servo.read();
  reqAngle = arm2;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm2Servo.write(i);
      delay(20);
    }
  }

  servoAngle = rotationServo.read();
  reqAngle = rotation;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      rotationServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      rotationServo.write(i);
      delay(20);
    }
  }

  delay(1000);

  servoAngle = arm1Servo.read();
  reqAngle = arm1;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      arm1Servo.write(i);
      delay(20);
    }
  }
}

void capture()
{
  servoAngle = gripServo.read();
  reqAngle = 90;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      gripServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      gripServo.write(i);
      delay(20);
    }
  }
}

void release()
{
  servoAngle = gripServo.read();
  reqAngle = 110;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      gripServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      gripServo.write(i);
      delay(20);
    }
  }
}

void openGripper()
{
  servoAngle = gripServo.read();
  reqAngle = 108;

  if (servoAngle < reqAngle)
  {
    for (int i = servoAngle; i <= reqAngle; i++)
    {
      gripServo.write(i);
      delay(20);
    }
  }
  else if (servoAngle > reqAngle)
  {
    for (int i = servoAngle; i >= reqAngle; i--)
    {
      gripServo.write(i);
      delay(20);
    }
  }
}

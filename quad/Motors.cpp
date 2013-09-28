/*
  Motors.cpp - Library for controlling a set of Quadcopter motors (aka motors)
  Created by Myles Grant <myles@mylesgrant.com>
  See also: https://github.com/grantmd/QuadCopter
  
  This program is free software: you can redistribute it and/or modify 
  it under the terms of the GNU General Public License as published by 
  the Free Software Foundation, either version 3 of the License, or 
  (at your option) any later version. 

  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  GNU General Public License for more details. 

  You should have received a copy of the GNU General Public License 
  along with this program. If not, see <http://www.gnu.org/licenses/>. 
*/


#include "Motors.h"




Motors::Motors(){  
  // Setup motors
  motors[0] = MOTOR_1_PIN;
  motors[1] = MOTOR_2_PIN;
  motors[2] = MOTOR_3_PIN;
  motors[3] = MOTOR_4_PIN;
  motorsOn = false;
}

void Motors::init(){
   setAllSpeed(0);
}

void Motors::allStop(){
  setAllSpeed(0);
}

void Motors::setMotorsOn(bool b){
	motorsOn = b;
}



void Motors::setMotorSpeed(byte motor, float speed){
  int speed_int;

  speed = map_f(speed, MIN_MOTOR_SPEED_CONTROL, MAX_MOTOR_SPEED_CONTROL, MIN_MOTOR_SPEED_PWM, MAX_MOTOR_SPEED_PWM);
  speed = constrain(speed, MIN_MOTOR_SPEED_PWM, MAX_MOTOR_SPEED_PWM);
  speed_int = (int) (speed) ;
  analogWrite(motors[motor-1], speed_int*motorsOn);

Serial.print(speed_int);
Serial.print("   ");

//Serial.println(speed_int );
  motor_speeds[motor-1] = speed_int;
}


int Motors::getMotorSpeed(byte motor){
  return motor_speeds[motor-1];
}

void Motors::setAllSpeed(float speed){
  for (byte motor = 1; motor <= MOTOR_COUNT; motor++){
    setMotorSpeed(motor, speed);
  }
}






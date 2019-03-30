#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int x1=15;
int y1=0;
int x2=1;
int y2=1;
int score=0;

byte dracon[8] = {
 0b01110, 
 0b11011, 
 0b11111, 
 0b11100, 
 0b11111, 
 0b01100, 
 0b10010, 
 0b11011
};

byte enemy[8] = {
 0b01110, 
 0b11011, 
 0b11111, 
 0b11100, 
 0b11111, 
 0b01100, 
 0b10010, 
 0b11011
};
void setup(){
  pinMode(2,INPUT);
  lcd.begin (20, 4);
  lcd.setBacklight(HIGH);
  lcd.createChar(0, dracon);
  lcd.createChar(1, enemy);
}

void loop(){
  x1=x1-1;
  //player
  lcd.setCursor(x2,y2);
  lcd.print(char(0)); 
  //enemy
  lcd.setCursor(x1,y1);
  lcd.print(char(1));
  //other
  delay(1000);
  
  if(digitalRead(2)){
    if(y2==1){
    y2=0;
    delay(400
    );  
  }}

   if(digitalRead(2)){
    if(y2==0){
    y2=1;
    delay(400);  
  }}

   if (x1==x2){
    if (y1==y2){
       lcd.clear();
       lcd.setCursor(2,0);
       lcd.print("GAME OVER!");
       lcd.setCursor(2,1);
       lcd.print(score);
       delay(2000);
    }}
    
  if(x1<=0){
    x1=15;
    y1=random(1);
    score=score+1;
    delay(300);
  }
  lcd.clear();
}


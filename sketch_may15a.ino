#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial mySerial(2,3);
byte c=0;

Servo servo_Big1;//mftoo7 90 we m2fool 0
Servo servo_Big2;//m2fool 3nd 180 we byft7 3nd 70
Servo servo_Small1;//close at 90 open at 0
Servo servo_Small2;//close at 0 open 90

//const byte servoPin_Arm=12;
//const byte servoPin_Stir=9;
  
Servo servo_Arm;
Servo servo_Stir;

const byte relayPin_Pump=6;

const byte relayPin_Stove=2;

const byte relayPin_Cutting=7;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
mySerial.begin(9600);

servo_Big1.attach(12);
servo_Big1.write(0);
servo_Big2.attach(10);
servo_Big2.write(180);


servo_Small1.attach(11);
servo_Small1.write(90);
servo_Small2.attach(9);
servo_Small2.write(0);

servo_Arm.attach(7);
servo_Arm.write(90);

pinMode(relayPin_Pump, OUTPUT);
digitalWrite(relayPin_Pump, HIGH);

pinMode(relayPin_Stove, OUTPUT);
digitalWrite(relayPin_Stove, HIGH);

 pinMode(relayPin_Cutting, OUTPUT);
digitalWrite(relayPin_Cutting, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(millis()==0)
{
if(mySerial.available())
{
  c=mySerial.read();
}
}
if(millis()==60000)
{
//Besela variable on
if(c==0)
{
  digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 millis()() ys5n
  if(millis()==65000)
  {
    servo_Big2.write(90); //open big 1 zebda +basl
  }
  
  if(millis()==72000)
  {
    //code elarm for stiring the basal
    servo_Arm.write(0);
  }

if(millis()==80000){ //added by martina 22/5
//    //hnbtl stiring close arm
        servo_Arm.write(90);
}
if(millis()==84000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==104000)
{
   digitalWrite(relayPin_Pump, HIGH); //close pump
}
if(millis()==107000)
{
   servo_Big1.write(90);//hnft7 big 2 3shan nnzl besela + powder tamatem
}

if(millis()==111000)
{
  servo_Big1.write(0);//hn2fl big 2
}
if(millis()==117000){
   servo_Small1.write(0);
}
if(millis()==120000){
   servo_Small1.write(90);//s=110: n2fl small 1
}

if(millis()==121000){
   servo_Small2.write(0);
}

if(millis()==124000){
   servo_Small1.write(90);
}

if(millis()==125000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==129000)
{
   digitalWrite(relayPin_Pump, HIGH); //close pump
}

if(millis()==131000){
//s=113: nbd2 stiring code elarm
    servo_Arm.write(0);


}
  if(millis()==154000){
  //s=140: n2fl stiring;
      servo_Arm.write(90);

  }
  if( millis()==1404000 ){
  //s=1340: n2fl oven
  digitalWrite(relayPin_Stove,HIGH);
  }
}

//Besela variable off
else if(c==1)
{
  digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 millis()() ys5n
  if(millis()==65000)
  {
    servo_Big2.write(90); //open big 1 zebda +basl
  }
  
  if(millis()==72000)
  {
    //code elarm for stiring the basal
    servo_Arm.write(0);
  }

if(millis()==80000){ //added by martina 22/5
//    //hnbtl stiring close arm
        servo_Arm.write(90);
}
if(millis()==84000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==104000)
{
   digitalWrite(relayPin_Pump, HIGH); //close pump
}
if(millis()==107000)
{
   servo_Big1.write(90);//hnft7 big 2 3shan nnzl besela + powder tamatem
}

if(millis()==111000)
{
  servo_Big1.write(0);//hn2fl big 2
}
if(millis()==117000){
   servo_Small1.write(0);
}
if(millis()==120000){
   servo_Small1.write(90);//s=110: n2fl small 1
}
if(millis()==121000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==125000)
{
   digitalWrite(relayPin_Pump, HIGH); //close pump
}

if(millis()==127000){
//s=113: nbd2 stiring code elarm
    servo_Arm.write(0);


}
  if(millis()==150000){
  //s=140: n2fl stiring;
      servo_Arm.write(90);

  }
  if( millis()==1400000 ){
  //s=1340: n2fl oven
  digitalWrite(relayPin_Stove,HIGH);
  }
}

//Saute variable on
else if(c==2)
digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 secs ys5n

if(millis()==65000)
{
   servo_Big1.write(90); //open big1 fasolya+besela+gazar
}
if(millis()==70000)
{
    servo_Small2.write(90); //open small2 lltawabl 
}
if(millis()==71000)
{
    servo_Small1.write(90); 
}
if(millis()==72000)
{  
    digitalWrite(relayPin_Pump, LOW);
}
if(millis()==81000)
{
    digitalWrite(relayPin_Pump,HIGH);
}
if(millis()==82000)
{
  //start stiring
    servo_Arm.write(0);
}

if(millis()==92000)
{
   //stop stirring
   servo_Arm.write(90);
}
if(millis()==93000)
{
   servo_Big2.write(70); //open Big2 for kosa+flfl
}

if(millis()==95000)
{
   servo_Big2.write(180); //open Big2 for kosa+flfl
}

if(millis()==97000)
{  
    digitalWrite(relayPin_Pump, LOW);
}
if(millis()==104000)
{
    digitalWrite(relayPin_Pump,HIGH);
}

if(millis()==105000)
{
  //start stiring
    servo_Arm.write(0);
}
if(millis()==111000){
   //stop stirring
   servo_Arm.write(90);
}
if(millis()==411000)
{
  digitalWrite(relayPin_Stove,HIGH); //hn2felh el stove 
}
}

//Saute variable off
else if(c==3)
{
  digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 secs ys5n

if(millis()==65000)
{
   servo_Big1.write(90); //open big1 fasolya+besela+gazar
}
if(millis()==70000)
{
    servo_Small2.write(90); //open small2 lltawabl 
}
if(millis()==71000)
{  
    digitalWrite(relayPin_Pump, LOW);
}
if(millis()==80000)
{
    digitalWrite(relayPin_Pump,HIGH);
}
if(millis()==81000)
{
  //start stiring
    servo_Arm.write(0);
}

if(millis()==91000)
{
   //stop stirring
   servo_Arm.write(90);
}
if(millis()==92000)
{
   servo_Big2.write(70); //open Big2 for kosa+flfl
}

if(millis()==94000)
{
   servo_Big2.write(180); //open Big2 for kosa+flfl
}

if(millis()==96000)
{  
    digitalWrite(relayPin_Pump, LOW);
}
if(millis()==103000)
{
    digitalWrite(relayPin_Pump,HIGH);
}

if(millis()==104000)
{
  //start stiring
    servo_Arm.write(0);
}
if(millis()==110000){
   //stop stirring
   servo_Arm.write(90);
}
if(millis()==410000)
{
  digitalWrite(relayPin_Stove,HIGH); //hn2felh el stove 
}
}

else if(c==4)
{
  
}
else if(c==5)
{
  
}
else if(c==6)
{
digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 thwany ys5n

if(millis()==65000)
{
   servo_Big1.write(90); //open big 1 sokar w vanillia w laban
}
if(millis()==67000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==71000)
{
    servo_Big1.write(0); //hn2fl big 1
}
if(millis()==71000)// nt2kd mn yasmine
{
   digitalWrite(relayPin_Pump, HIGH); //close pump
}

if(millis()==72000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}

if(millis()==130000)//60 sec milk stir ydoob
{
    servo_Arm.write(90);
}
if(millis()==132000)
{
   servo_Big2.write(90);//hnft7 big 2 3shan nnzl roz 
}

if(millis()==134000)
{
  servo_Big2.write(180);//hn2fl big 2
}

if(millis()==135000)
{
   servo_Small1.write(0);
}

if(millis()==136000)
{
  servo_Small1.write(90);
}

if(millis()==137000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==142000)// nt2kd mn yasmine
{
   digitalWrite(relayPin_Pump, HIGH); //pump kol el mya 
}



if(millis()==147000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==197000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}

if(millis()==317000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==377000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}

if(millis()==497000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==557000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}


if(millis()==677000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==737000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}

if(millis()==857000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==917000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}






/*if(millis()==1214000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}*/
if(millis()==1881000){
   digitalWrite(relayPin_Stove,HIGH);
}
}
else if(c==7)
{
  digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 thwany ys5n

if(millis()==65000)
{
   servo_Big1.write(90); //open big 1 sokar w vanillia w laban
}
if(millis()==67000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==71000)
{
    servo_Big1.write(0); //hn2fl big 1
}
if(millis()==71000)// nt2kd mn yasmine
{
   digitalWrite(relayPin_Pump, HIGH); //close pump
}

if(millis()==72000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}

if(millis()==130000)//60 sec milk stir ydoob
{
    servo_Arm.write(90);
}
if(millis()==132000)
{
   servo_Big2.write(90);//hnft7 big 2 3shan nnzl roz 
}

if(millis()==134000)
{
  servo_Big2.write(180);//hn2fl big 2
}

if(millis()==136000)
{
  digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
}

if(millis()==141000)// nt2kd mn yasmine
{
   digitalWrite(relayPin_Pump, HIGH); //pump kol el mya 
}



if(millis()==146000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==196000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}

if(millis()==316000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==376000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}

if(millis()==496000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==556000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}


if(millis()==676000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==736000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}

if(millis()==856000)
{
    //code elarm for stiring the milk
    servo_Arm.write(0);
}
if(millis()==916000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}






/*if(millis()==1214000)//telt sa3a ba2laeb ? check elservo hy3ml eh
{   
    servo_Arm.write(90);
}*/
if(millis()==1880000){
   digitalWrite(relayPin_Stove,HIGH);
}
}
else if(c==8)
{
digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 millis()() ys5n
  if(millis()==62000) //shay
  {
    servo_Big1.write(90); 
  }
    
  if(millis()==64000)
  {
    servo_Big1.write(0); 
  }
   if(millis()==66000)//sokar
  {
    servo_Small1.write(0); 
  }
    
  if(millis()==68000)
  {
    servo_Small1.write(90); 
  }
    if(millis()==70000)
  {
    digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
  }

  if(millis()==90000)
  {
   digitalWrite(relayPin_Pump, HIGH); //close pump
  }
 if( millis()==960000 ){
  //n2fl oven
  digitalWrite(relayPin_Stove,HIGH);
  }
if(millis()==962000){
// nbd2 stiring code elarm
    servo_Arm.write(0);


}
  if(millis()==972000){
  //n2fl stiring;
      servo_Arm.write(90);

  }
}

else if(c==9)
{
digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 millis()() ys5n
  if(millis()==62000) 
  {
    servo_Big2.write(90); 
  }
    
  if(millis()==64000)
  {
    servo_Big2.write(0); 
  }
   if(millis()==66000)//sokar
  {
    servo_Small1.write(0); 
  }
    
  if(millis()==68000)
  {
    servo_Small1.write(90); 
  }
    if(millis()==70000)
  {
    digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
  }

  if(millis()==90000)
  {
   digitalWrite(relayPin_Pump, HIGH); //close pump
  }
 if( millis()==960000 ){
  //n2fl oven
  digitalWrite(relayPin_Stove,HIGH);
  }
if(millis()==962000){
// nbd2 stiring code elarm
    servo_Arm.write(0);


}
  if(millis()==972000){
  //n2fl stiring;
      servo_Arm.write(90);

  }
}

else if(c==10)
{
digitalWrite(relayPin_Stove,LOW); //hnfth el stove fy 0 w nsebo 5 millis()() ys5n
  if(millis()==62000) //shay
  {
    servo_Small2.write(90); 
  }
    
  if(millis()==64000)
  {
    servo_Small2.write(0); 
  }
   if(millis()==66000)//sokar
  {
    servo_Small1.write(0); 
  }
    
  if(millis()==68000)
  {
    servo_Small1.write(90); 
  }
    if(millis()==70000)
  {
    digitalWrite(relayPin_Pump, LOW); //pump kol el mya 
  }

  if(millis()==90000)
  {
   digitalWrite(relayPin_Pump, HIGH); //close pump
  }
 if( millis()==960000 ){
  //n2fl oven
  digitalWrite(relayPin_Stove,HIGH);
  }
if(millis()==962000){
// nbd2 stiring code elarm
    servo_Arm.write(0);


}
  if(millis()==972000){
  //n2fl stiring;
      servo_Arm.write(90);

  }
}

}

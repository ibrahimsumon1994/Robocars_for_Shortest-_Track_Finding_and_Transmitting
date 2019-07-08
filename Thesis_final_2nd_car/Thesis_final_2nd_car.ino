#define w 0 //color white
#define b 1 //color black

int x = 160; //motor speed for moving car
int y = 130; //motor speed for moving car
int c=0; // path count
bool r1, r2, r3, r4; //right sensor
bool l1, l2, l3, l4; //left sensor

int a; // for saving bluetooth information
int k=1; //for counting bluetooth

void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT); //L
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);  //R
  pinMode(9,OUTPUT);
  
  //Right Array
  pinMode(12,INPUT); //r1
  pinMode(2,INPUT);  //r2
  pinMode(3,INPUT);  //r3
  pinMode(4,INPUT);  //r4

  //Left Array
  pinMode(13,INPUT); //l1
  pinMode(6,INPUT);  //l2
  pinMode(7,INPUT);  //l3
  pinMode(8,INPUT);  //l4 

  Serial.println();   
  Serial.println("...........Serial Communication Opened.............");
}

void loop() {
irRead();
if(Serial.available() && (k==1))
{ 

  a= Serial.read();
  delay(10);
  
  if(a<10 && a>0)
    {
     Serial.println();
     Serial.println("==================Bluetooth is receiving the shortest path=====================");
     Serial.println();
     Serial.print("The shortest path number is ");
     Serial.println(a);
     Serial.println();
     Serial.println("Now Robocar starts to follow the shortest path");
     Serial.println();
     k++;
    }
} 
  if(k==2){
  pathcheck();
  }
}

void pathcheck()
{
  if(a==1)
  {
    irCondition1();
    
  }

  else if(a==2)
  {
    irCondition2();
   
  }

  else if(a==3)
  {
    irCondition3();
   
  }

  else if(a==4)
  {
    irCondition4();
   
  }

  else if(a==5)
  {
    irCondition5();
   
  }

  else if(a==6)
  {
    irCondition6();
 
  }

  else if(a==7)
  {
    irCondition7();
 
  }
}

void irCondition1()   //  Turn: right-left-left-right-right-left-right-forward-Left
{
  if(l1==w && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w)
  {
    forward();
  }


  
  if((l1==b && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l2==b && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l3==b && l4==w && r1==w && r2==w && r3==w && r4==w) || ( l4==b && r1==w && r2==w && r3==w && r4==w))
  {
    left();
  }
  
  if((l1==w && l2==w && l3==w && l4==w && r1==b && r2==w && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r2==b && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r3==b && r4==w) || ( l1==w && l2==w && l3==w && l4==w && r4==w))
  {
    right();
  }
  
  if((l1==b&&l4==b)||(r1==b&&r4==b))
  {
    if(c==0)
      {
       Right();  
       c++;
      }    
    
    else if(c==1)
      {
       Left();  
       c++;
      }

    else if(c==2)
      {
       Left();  
       c++;
      }
      
    else if(c==3)
      {
       Right();  
       c++;
      }

    else if(c==4)
      {
       Right();  
       c++;
      }

    else if(c==5)
      {
       Left();  
       c++;
      }

    else if(c==6)
      {
       Right();  
       c++;
      }

    else if(c==7)
      {
       Forward();  
       c++;
      }

    else if(c==8)
      {
       forward();
       delay(700);
       Stop();
       delay(500);
       Left();
       forward();
       delay(450);
       Stop();
       c=0;
       Serial.println("****************************************************************************");
       Serial.println("***********2nd Robocar reached the destination successfully!!***************");
       Serial.println("****************************************************************************");
       delay(500000);
      } 
   }  
}


void irCondition2() // Turn: forward-forward-forward-forward-right-forward-forward-Right 
{
  if(l1==w && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w)
  {
    forward();
  }


  
  if((l1==b && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l2==b && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l3==b && l4==w && r1==w && r2==w && r3==w && r4==w) || ( l4==b && r1==w && r2==w && r3==w && r4==w))
  {
    left();
  }
  
  if((l1==w && l2==w && l3==w && l4==w && r1==b && r2==w && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r2==b && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r3==b && r4==w) || ( l1==w && l2==w && l3==w && l4==w && r4==w))
  {
    right();
  }
  
  if(r1==b&&r4==b)
  {
    
     if(c==0)
      {
       Forward();  
       c++;
      }
    
   else if(c==1)
      {
       Forward();  
       c++;
      }

    else if(c==2)
      {
       Forward();  
       c++;
      }
      
    else if(c==3)
      {
       Forward();  
       c++;
      }

      else if(c==4)
      {
       Right();  
       c++;
      }

    else if(c==5)
      {
       Forward();  
       c++;
      }

     else if(c==6)
      {
       Forward();  
       c++;
      }

    else if(c==7)
      {
       forward();
       delay(700);
       Stop();
       delay(500);
       Right();
       forward();
       delay(450);
       Stop();
       c=0;
       Serial.println("****************************************************************************");
       Serial.println("***********2nd Robocar reached the destination successfully!!***************");
       Serial.println("****************************************************************************");
       delay(500000);       
      }  
   }  
}
void irCondition3()    // Turn: right-forward-forward-forward-left-forward-forward-Left
{
  if(l1==w && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w)
  {
    forward();
  }

  if((l1==b && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l2==b && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l3==b && l4==w && r1==w && r2==w && r3==w && r4==w) || ( l4==b && r1==w && r2==w && r3==w && r4==w))
  {
    left();
  }
  
  if((l1==w && l2==w && l3==w && l4==w && r1==b && r2==w && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r2==b && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r3==b && r4==w) || ( l1==w && l2==w && l3==w && l4==w && r4==w))
  {
    right();
  }
  
  if((l1==b&&l4==b)||(r1==b&&r4==b))
  {
    
     if(c==0)
      {
       Right();  
       c++;
      }
    
    else if(c==1)
      {
       Forward();  
       c++;
      }

    else if(c==2)
      {
       Forward();  
       c++;
      }
    else if(c==3)
      {
       Forward();  
       c++;
      }

     else if(c==4)
      {
       Left();  
       c++;
      }  

    else if(c==5)
      {
       Forward();  
       c++;
      }

    else if(c==6)
      {
       Forward();  
       c++;
      }
      

    else if(c==7)
      {
       forward();
       delay(700);
       Stop();
       delay(500);
       Left();
       forward();
       delay(450);
       Stop();
       c=0;
       Serial.println("****************************************************************************");
       Serial.println("***********2nd Robocar reached the destination successfully!!***************");
       Serial.println("****************************************************************************");
       delay(500000);
       
      } 
   }  
}

void irCondition4()    //right-left-right-left-right-left-Right
{
  if(l1==w && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w)
  {
    forward();
  }


  
  if((l1==b && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l2==b && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l3==b && l4==w && r1==w && r2==w && r3==w && r4==w) || ( l4==b && r1==w && r2==w && r3==w && r4==w))
  {
    left();
  }
  
  if((l1==w && l2==w && l3==w && l4==w && r1==b && r2==w && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r2==b && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r3==b && r4==w) || ( l1==w && l2==w && l3==w && l4==w && r4==w))
  {
    right();
  }
  
  if((l1==b&&l4==b)||(r1==b&&r4==b))
  {
    
     if(c==0)
      {
       Right();  
       c++;
      }
    
    else if(c==1)
      {
       Left();  
       c++;
      }

    else if(c==2)
      {
       Right();  
       c++;
      }
    else if(c==3)
      {
       Left();  
       c++;
      }

     else if(c==4)
      {
       Right();  
       c++;
      }  

    else if(c==5)
      {
       Left(); 
       c++;
      }

    else if(c==6)
      {
       forward();
       delay(700);
       Stop();
       delay(500);
       Right();
       forward();
       delay(450);
       Stop();
       c=0;
       Serial.println("****************************************************************************");
       Serial.println("***********2nd Robocar reached the destination successfully!!***************");
       Serial.println("****************************************************************************");
       delay(500000);
       
      } 
   }  
}

void irCondition5()    //forward-right-left-forward-right-forward-Left
{
  if(l1==w && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w)
  {
    forward();
  }


  
  if((l1==b && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l2==b && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l3==b && l4==w && r1==w && r2==w && r3==w && r4==w) || ( l4==b && r1==w && r2==w && r3==w && r4==w))
  {
    left();
  }
  
  if((l1==w && l2==w && l3==w && l4==w && r1==b && r2==w && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r2==b && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r3==b && r4==w) || ( l1==w && l2==w && l3==w && l4==w && r4==w))
  {
    right();
  }
  
  if(r1==b&&r4==b)
  {
    
     if(c==0)
      {
       Forward();  
       c++;
      }
    
    else if(c==1)
      {
       Right();  
       c++;
      }

    else if(c==2)
      {
       Left();  
       c++;
      }
    else if(c==3)
      {
       Forward();  
       c++;
      }

     else if(c==4)
      {
       Right();  
       c++;
      }  

    else if(c==5)
      {
       Forward();  
       c++;
      }

    else if(c==6)
      {
       forward();
       delay(700);
       Stop();
       delay(500);
       Left();
       forward();
       delay(450);
       Stop();
       c=0;
       Serial.println("****************************************************************************");
       Serial.println("***********2nd Robocar reached the destination successfully!!***************");
       Serial.println("****************************************************************************");
       delay(500000);
       
      } 
   }  
}

void irCondition6()    //forward-forward-forward-right-forward-right-forward-left-left-forward-Right
{
  if(l1==w && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w)
  {
    forward();
  }


  
  if((l1==b && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l2==b && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l3==b && l4==w && r1==w && r2==w && r3==w && r4==w) || ( l4==b && r1==w && r2==w && r3==w && r4==w))
  {
    left();
  }
  
  if((l1==w && l2==w && l3==w && l4==w && r1==b && r2==w && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r2==b && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r3==b && r4==w) || ( l1==w && l2==w && l3==w && l4==w && r4==w))
  {
    right();
  }
  
  if(r1==b&&r4==b)
  {
    
     if(c==0)
      {
       Forward();  
       c++;
      }
    
    else if(c==1)
      {
       Forward();  
       c++;
      }

    else if(c==2)
      {
       Forward();  
       c++;
      }
    else if(c==3)
      {
       Right();  
       c++;
      }

     else if(c==4)
      {
       Forward();  
       c++;
      }  

    else if(c==5)
      {
       Right();  
       c++;
      }

    else if(c==6)
      {
       Forward();  
       c++;
      }

    else if(c==7)
      {
       Left();  
       c++;
      }

    else if(c==8)
      {
       Left();  
       c++;
      }

    else if(c==9)
      {
       Forward();  
       c++;
      }
      
    else if(c==10)
      { 
       forward();
       delay(700);
       Stop();
       delay(500);
       Right();
       forward();
       delay(450);
       Stop();
       c=0;
       Serial.println("****************************************************************************");
       Serial.println("***********2nd Robocar reached the destination successfully!!***************");
       Serial.println("****************************************************************************");
       delay(500000);
       
      }
   }  
}

void irCondition7()    //right-forward-forward-left-left-right-forward-right-Left
{
  if(l1==w && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w)
  {
    forward();
  }


  
  if((l1==b && l2==w && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l2==b && l3==w && l4==w && r1==w && r2==w && r3==w && r4==w) || (l3==b && l4==w && r1==w && r2==w && r3==w && r4==w) || ( l4==b && r1==w && r2==w && r3==w && r4==w))
  {
    left();
  }
  
  if((l1==w && l2==w && l3==w && l4==w && r1==b && r2==w && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r2==b && r3==w && r4==w) || (l1==w && l2==w && l3==w && l4==w && r3==b && r4==w) || ( l1==w && l2==w && l3==w && l4==w && r4==w))
  {
    right();
  }
  
  if((l1==b&&l4==b)||(r1==b&&r4==b))
  {
    
     if(c==0)
      {
       Right();  
       c++;
      }
    
    else if(c==1)
      {
       Forward(); 
       c++;
      }

    else if(c==2)
      {
       Forward();  
       c++;
      }
    else if(c==3)
      {
       Left();  
       c++;
      }

     else if(c==4)
      {
       Left();  
       c++;
      }  

    else if(c==5)
      {
       Right();  
       c++;
      }

    else if(c==6)
      {
       Forward(); 
       c++;
      }

    else if(c==7)
      {
       Right(); 
       c++;
      }

    else if(c==8)
      { 
       forward();
       delay(700);
       Stop();
       delay(500);
       Left();
       forward();
       delay(450);
       Stop();
       c=0;
       Serial.println("****************************************************************************");
       Serial.println("***********2nd Robocar reached the destination successfully!!***************");
       Serial.println("****************************************************************************");
       delay(500000);
      } 
   }  
}

void irRead()
{
 digitalWrite(12, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, HIGH);

 digitalWrite(13, HIGH);
 digitalWrite(6, HIGH);
 digitalWrite(7, HIGH);
 digitalWrite(8, HIGH);
 
 //Right Array
 r1 = digitalRead(12);
 r2 = digitalRead(2);
 r3 = digitalRead(3);
 r4 = digitalRead(4);
 
 //Left Array
 l1 = digitalRead(13);
 l2 = digitalRead(6);
 l3 = digitalRead(7);
 l4 = digitalRead(8);

}

void irPrint()
{
  Serial.print("R1 = ");
    Serial.println(r1);
  Serial.print("R2 = ");
    Serial.println(r2);
  Serial.print("R3 = ");
    Serial.println(r3);
  Serial.print("R4 = ");
    Serial.println(r4);

  Serial.print("L1 = ");
    Serial.println(l1);
  Serial.print("L2 = ");
    Serial.println(l2);
  Serial.print("L3 = ");
    Serial.println(l3);
  Serial.print("L4 = ");
    Serial.println(l4);
}

// car wheel

void forward()
{
analogWrite(10,y); 
analogWrite(11,0); 
analogWrite(5,x); 
analogWrite(9,0);
}

//---------------
void Forward()
{
    Stop();
    delay(500);
    forward();
    delay(400);
    Stop();
    delay(500);  
}


void right()
{
analogWrite(10,0); 
analogWrite(11,0); 
analogWrite(5,x); 
analogWrite(9,0);
}
//--------------

void Right()
{
    Stop();
    delay(200);
    right();
    delay(750);
    Stop();
    delay(200);  
}



void left()
{
analogWrite(10,y); 
analogWrite(11,0); 
analogWrite(5,0); 
analogWrite(9,0);
}

//---------------
void Left()
{
    Stop();
    delay(200);
    left();
    delay(785);
    Stop();
    delay(200);  
}


void backward()
{
analogWrite(10,0); 
analogWrite(11,x); 
analogWrite(5,0); 
analogWrite(9,x);
}

void Stop()
{
analogWrite(10,0); 
analogWrite(11,0); 
analogWrite(5,0); 
analogWrite(9,0);  
}


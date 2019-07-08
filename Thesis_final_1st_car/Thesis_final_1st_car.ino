#define w 0 //sensor read color white
#define b 1 //sensor read color black

int x = 150; //motor speed for moving car
int c=0; // path count
bool r1, r2, r3, r4; //right sensor
bool l1, l2, l3, l4; //left sensor
int i=0; // turn count. if right or left turn occur then i will increase.
int v=4; // delay variable for maximum number of path choosen.
int k=1; // path no.
int turn[15]; // array for saving turn number.
int p=1; // turn array variable. exmple: turn[p].

int m; // sorting varible
int t; // for looping in sorting
int d=0; // holding the value of t when the turn value is minimum. exmple: d=t.

//random
 int j; // for loop
 int n=7; // maximum number for looping bcz total number of path is 7.
 int arr[10]; // array for saving the generating random number.
 int r; // random variable for saving a random number. r = random(1,g).
 //int g=8; //maximum number for random number generate. exmple: random(1,g).
 int s=0; //how many times random function work in main loop

 int q=0; //for passing information using bluetooth

 int g=500; //for delay in light

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

  //Light
  pinMode(A1,OUTPUT);  //RED LIGHT
  pinMode(A2,OUTPUT);  //Blue LIGHT 
  Serial.println();   
  Serial.println("...........Serial Communication Opened.............");
  Serial.println();
  Serial.println("=================Process start=================");
  Serial.println();
  Serial.println("Generating Random Path");
  
  
  //Random number generate
  randomSeed(analogRead(0));
  delay(5000);
}

void loop() {

  if(s==0)
  {
    randm();
    Serial.println();
    Serial.println("===================================================");
    Serial.println("IR Sensors are taking the reading");
    Serial.println();
    Serial.println("===================================================");
    Serial.println("Robocar start to explore the generated path");
    s=1;
  }

  irRead();
  pathChoose();
  
}

void sorting(){
  Serial.println();
  Serial.println("=====================Shortest Path is Generating=======================");
  m = turn[1];
  for(t=1;t<v;t++)
  {
   if(turn[t]<=m)
    {
     m=turn[t];
     d=t ;
     //Serial.print("Minimum value: ");
     //Serial.println(m);
     //Serial.print("Turn array position: ");
     //Serial.println(d);
    }
  // delay(2000);
  }
  light(d);
  delay(300);
  share(d,m);
}

void share(int d, int m){
  if(d == 1)
  {
   Serial.println();
   Serial.print("Shortest Path is ");
   Serial.println(arr[1]);
   Serial.println();
   Serial.print("Cost is ");
   Serial.println(m);
   Serial.println("==============Sending the Shortest Path to other Robocars================");
   Serial.println();
   Serial.print("Bluetooth is sending path number ");
   Serial.println(arr[1]);
   Serial.write(arr[1]);
   Serial.println();
   Serial.println("=========================================================================");
   Serial.println("Now the Master Robocar stops");
   Serial.println();
   Serial.println("2nd Robocar will start within 1000 mili sec");
   //delay(10);
  }

  else if(d == 2)
  {
   Serial.println();
   Serial.print("Shortest Path is ");
   Serial.println(arr[2]);
   Serial.println();
   Serial.print("Cost is ");
   Serial.println(m);
   Serial.println("==============Sending the Shortest Path to other Robocars================");
   Serial.println();
   Serial.print("Bluetooth is sending path number ");
   Serial.println(arr[2]);
   Serial.write(arr[2]);
   Serial.println();
   Serial.println("=========================================================================");
   Serial.println("Now the Master Robocar stops");
   Serial.println();
   Serial.println("2nd Robocar will start within 1000 mili sec");
   //delay(10);
  }

  else if(d==3)
  {
   Serial.println();
   Serial.print("Shortest Path is ");
   Serial.println(arr[3]);
   Serial.println();
   Serial.print("Cost is ");
   Serial.println(m);
   Serial.println("==============Sending the Shortest Path to other Robocars================");
   Serial.println();
   Serial.print("Bluetooth is sending path number ");
   Serial.println(arr[3]);
   Serial.write(arr[3]);
   Serial.println();
   Serial.println("=========================================================================");
   Serial.println("Now the Master Robocar stops");
   Serial.println();
   Serial.println("2nd Robocar will start within 1000 mili sec");
   //delay(10);
  }

  else if(d == 4)
  {
   Serial.println();
   Serial.print("Shortest Path is ");
   Serial.println(arr[4]);
   Serial.println();
   Serial.print("Cost is ");
   Serial.println(m);
   Serial.println("==============Sending the Shortest Path to other Robocars================");
   Serial.println();
   Serial.print("Bluetooth is sending path number ");
   Serial.println(arr[4]);
   Serial.write(arr[4]);
   Serial.println();
   Serial.println("=========================================================================");
   Serial.println("Now the Master Robocar stops");
   Serial.println();
   Serial.println("2nd Robocar will start within 1000 mili sec");
   //delay(10);
  }

  else if(d == 5)
  {
   Serial.println();
   Serial.print("Shortest Path is ");
   Serial.println(arr[5]);
   Serial.println();
   Serial.print("Cost is ");
   Serial.println(m);
   Serial.println("==============Sending the Shortest Path to other Robocars================");
   Serial.println();
   Serial.print("Bluetooth is sending path number ");
   Serial.println(arr[5]);
   Serial.write(arr[5]);
   Serial.println();
   Serial.println("=========================================================================");
   Serial.println("Now the Master Robocar stops");
   Serial.println();
   Serial.println("2nd Robocar will start within 1000 mili sec");
   //delay(10);
  }

  else if(d == 6)
  {
   Serial.println();
   Serial.print("Shortest Path is ");
   Serial.println(arr[6]);
   Serial.println();
   Serial.print("Cost is ");
   Serial.println(m);
   Serial.println("==============Sending the Shortest Path to other Robocars================");
   Serial.println();
   Serial.print("Bluetooth is sending path number ");
   Serial.println(arr[6]);
   Serial.write(arr[6]);
   Serial.println();
   Serial.println("=========================================================================");
   Serial.println("Now the Master Robocar stops");
   Serial.println();
   Serial.println("2nd Robocar will start within 1000 mili sec");
   //delay(10);
  }

  else if(d == 7)
  {
   Serial.println();
   Serial.print("Shortest Path is ");
   Serial.println(arr[7]);
   Serial.println();
   Serial.print("Cost is ");
   Serial.println(m);
   Serial.println("==============Sending the Shortest Path to other Robocars================");
   Serial.println();
   Serial.print("Bluetooth is sending path number ");
   Serial.println(arr[7]);
   Serial.write(arr[7]);
   Serial.println();
   Serial.println("=========================================================================");
   Serial.println("Now the Master Robocar stops");
   Serial.println();
   Serial.println("2nd Robocar will start within 1000 mili sec");
   //delay(10);
  }
}

void randm(){
   
   for(j = 1 ; j <= n ; j++) 
   {
    r = random(1,8);
    arr[j] = r;
   }

  for(j = 1 ; j < n ; j++) 
   {
    arr[j] = arr[j+1] ;
    Serial.print("Auto Generated Path : "); 
    Serial.println(arr[j]);
   }
   arr[7]=5;  
   Serial.print("Auto Generated Path : "); 
   Serial.println(arr[7]);
   
   for(j = 1 ; j <v ; j++)
   {
    light(j);
   }
}

void light( int j){
  
  if(arr[j]==1)
    {
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A2,HIGH);
      delay(g);
      digitalWrite(A2,LOW);
      delay(g);
    }
    else if(arr[j]==2)
    {
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A2,HIGH);
      delay(g);
      digitalWrite(A2,LOW);
      delay(g);
    }
    else if(arr[j]==3)
    {
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A2,HIGH);
      delay(g);
      digitalWrite(A2,LOW);
      delay(g);
    }
    else if(arr[j]==4)
    {
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A2,HIGH);
      delay(g);
      digitalWrite(A2,LOW);
      delay(g);
    }
    else if(arr[j]==5)
    {
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A2,HIGH);
      delay(g);
      digitalWrite(A2,LOW);
      delay(g);
    }
    else if(arr[j]==6)
    {
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A2,HIGH);
      delay(g);
      digitalWrite(A2,LOW);
      delay(g);
    }
    else if(arr[j]==7)
    {
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A1,HIGH);
      delay(g);
      digitalWrite(A1,LOW);
      delay(g);
      digitalWrite(A2,HIGH);
      delay(g);
      digitalWrite(A2,LOW);
      delay(g);
    }
}

void pathChoose(){
  if(arr[k]==1)
  {
    irCondition1();
    
  }

  else if(arr[k]==2)
  {
    irCondition2();
   
  }

  else if(arr[k]==3)
  {
    irCondition3();
   
  }

  else if(arr[k]==4)
  {
    irCondition4();
   
  }

  else if(arr[k]==5)
  {
    irCondition5();
   
  }

  else if(arr[k]==6)
  {
    irCondition6();
 
  }

  else if(arr[k]==7)
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
       i++;
      }    
    
    else if(c==1)
      {
       Left();  
       c++;
       i++;
      }

    else if(c==2)
      {
       Left();  
       c++;
       i++;
      }
      
    else if(c==3)
      {
       Right();  
       c++;
       i++;
      }

    else if(c==4)
      {
       Right();  
       c++;
       i++;
      }

    else if(c==5)
      {
       Left();  
       c++;
       i++;
      }

    else if(c==6)
      {
       Right();  
       c++;
       i++;
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
       delay(300);

       k++;
       c=0;
       i++;
       turn[p]= i;
       p++ ;
       i=0;
       Serial.println();
       Serial.println("Auto Generated Path 1 visited");
       if(k==v)
       {
        sorting();
        //share();
        delay(300000);
       }
       delay(10000);
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
       i++;
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
       delay(300);

       k++;
       c=0;
       i++;
       turn[p]= i;
       p++;
       i=0;
       Serial.println();
       Serial.println("Auto Generated Path 2 visited");
       if(k==v)
       {
        sorting();
        //share();
        delay(300000);
       }
       delay(10000);       
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
       i++;
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
       i++;
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
       delay(300);

       k++;
       c=0;
       i++;
       turn[p]= i;
       p++;
       i=0;
       Serial.println();
       Serial.println("Auto Generated Path 3 visited");
       if(k==v)
       {
        sorting();
        //share();
        delay(300000);
       }
       delay(10000);
       
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
       i++;
      }
    
    else if(c==1)
      {
       Left();  
       c++;
       i++;
      }

    else if(c==2)
      {
       Right();  
       c++;
       i++;
      }
    else if(c==3)
      {
       Left();  
       c++;
       i++;
      }

     else if(c==4)
      {
       Right();  
       c++;
       i++;
      }  

    else if(c==5)
      {
       Left(); 
       c++;
       i++;
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
       delay(300);

       k++;
       c=0;
       i++;
       turn[p]= i;
       p++;
       i=0;
       Serial.println();
       Serial.println("Auto Generated Path 4 visited");
       if(k==v)
       {
        sorting();
        //share();
        delay(300000);
       }
       delay(10000);
       
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
       i++;
      }

    else if(c==2)
      {
       Left();  
       c++;
       i++;
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
       i++;
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
       delay(300);

       k++;
       c=0;
       i++;
       turn[p]= i;
       p++;
       i=0;
       Serial.println();
       Serial.println("Auto Generated Path 5 visited");
       if(k==v)
       {
        sorting();
        //share();
        delay(300000);
       }
       delay(10000);
       
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
       i++;
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
       i++;
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
       i++;
      }

    else if(c==8)
      {
       Left();  
       c++;
       i++;
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
       delay(300);

       k++;
       c=0;
       i++;
       turn[p]= i;
       p++;
       i=0;
       Serial.println();
       Serial.println("Auto Generated Path 6 visited");
       if(k==v)
       {
        sorting();
        //share();
        delay(300000);
       }
       delay(10000);
       
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
       i++;
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
       i++;
      }

     else if(c==4)
      {
       Left();  
       c++;
       i++;
      }  

    else if(c==5)
      {
       Right();  
       c++;
       i++;
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
       i++;
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
       delay(300);

       k++;
       c=0;
       i++;
       turn[p]= i;
       p++;
       i=0;
       Serial.println();
       Serial.println("Auto Generated Path 7 visited");
       if(k==v)
       {
        sorting();
        //share();
        delay(300000);
       }
       delay(10000);
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
analogWrite(10,x); 
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
analogWrite(10,x); 
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

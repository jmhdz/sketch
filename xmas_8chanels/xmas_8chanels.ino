
int tree1 = 6;
int tree2 = 7;
int tree3 = 8;
int tree4 = 9;
int tree5 = 2;
int tree6 = 3;
int tree7 = 4;
int tree8 = 5;
int s = 150;
int ds = 225;
int e = 300;
int de = 450;
int q = 600;
int dq = 900;
int h = 1200;
int dh = 1800;
int start;
int end;
int time;

void setup()
{
  pinMode(tree1, OUTPUT);
  pinMode(tree2, OUTPUT);
  pinMode(tree3, OUTPUT);
  pinMode(tree4, OUTPUT);
  pinMode(tree5, OUTPUT);
  pinMode(tree6, OUTPUT);
  pinMode(tree7, OUTPUT);
  pinMode(tree8, OUTPUT);
  digitalWrite(tree1,HIGH);
  delay(1000);
  digitalWrite(tree2,HIGH);
  delay(1000);
  digitalWrite(tree3,HIGH);
  delay(1000);
  digitalWrite(tree4,HIGH);
  delay(1000);
  digitalWrite(tree5,HIGH);
  delay(1000);
  digitalWrite(tree6,HIGH);
  delay(1000);
  digitalWrite(tree7,HIGH);
  delay(1000);
  digitalWrite(tree8,HIGH);
  delay(1000);
  digitalWrite(tree1,LOW);
  digitalWrite(tree2,LOW);
  digitalWrite(tree3,LOW);
  digitalWrite(tree4,LOW);
  digitalWrite(tree5,LOW);
  digitalWrite(tree6,LOW);
  digitalWrite(tree7,LOW);
  digitalWrite(tree8,LOW);
  Serial.begin(9600);
}

void loop()
{
  start = millis();
  digitalWrite(tree1, HIGH);
  digitalWrite(tree8, HIGH);
  delay(q);
  digitalWrite(tree1, LOW);
  digitalWrite(tree8, LOW);

  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(de);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);

  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(s);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);

  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  delay(1050);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);

  digitalWrite(tree1, HIGH);
  digitalWrite(tree8, HIGH);
  delay(s);
  digitalWrite(tree1, LOW);
  digitalWrite(tree8, LOW);

  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(q);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);

  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(q);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);

  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  delay(dq);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);

  digitalWrite(tree1, HIGH);
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
  digitalWrite(tree8, LOW);

  digitalWrite(tree2, HIGH);
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  digitalWrite(tree7, HIGH);
  delay(dq);
  digitalWrite(tree2, LOW);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
  digitalWrite(tree7, LOW);

  digitalWrite(tree1, HIGH);
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
  digitalWrite(tree8, LOW);

  digitalWrite(tree3, HIGH);
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  digitalWrite(tree6, HIGH);
  delay(dq);
  digitalWrite(tree3, LOW);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
  digitalWrite(tree6, LOW);

  digitalWrite(tree1, HIGH);
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
  digitalWrite(tree8, LOW);

  digitalWrite(tree1, HIGH);
  digitalWrite(tree2, HIGH);
  digitalWrite(tree3, HIGH);
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  digitalWrite(tree6, HIGH);
  digitalWrite(tree7, HIGH);
  digitalWrite(tree8, HIGH);
  delay(dq);
  digitalWrite(tree1, LOW);
  digitalWrite(tree2, LOW);
  digitalWrite(tree3, LOW);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
  digitalWrite(tree6, LOW);
  digitalWrite(tree7, LOW);
  digitalWrite(tree8, LOW);

  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree8, LOW);

  digitalWrite(tree1, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);

  digitalWrite(tree7, HIGH);
  delay(e);
  digitalWrite(tree7, LOW);  

  digitalWrite(tree2, HIGH);
  delay(e);
  digitalWrite(tree2, LOW);

  digitalWrite(tree6, HIGH);
  delay(e);
  digitalWrite(tree6, LOW);

  digitalWrite(tree3, HIGH);
  delay(de);
  digitalWrite(tree3, LOW);

  digitalWrite(tree5, HIGH);
  delay(s);
  digitalWrite(tree5, LOW);
 
  digitalWrite(tree4, HIGH);
  delay(e);
  digitalWrite(tree4, LOW);
 
  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree8, LOW);

  digitalWrite(tree1, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);

  digitalWrite(tree7, HIGH);
  delay(e);
  digitalWrite(tree7, LOW);  

  digitalWrite(tree2, HIGH);
  delay(e);
  digitalWrite(tree2, LOW);

  digitalWrite(tree6, HIGH);
  delay(e);
  digitalWrite(tree6, LOW);

  digitalWrite(tree3, HIGH);
  delay(de);
  digitalWrite(tree3, LOW);

  digitalWrite(tree5, HIGH);
  delay(s);
  digitalWrite(tree5, LOW);
 
  digitalWrite(tree4, HIGH);
  delay(e);
  digitalWrite(tree4, LOW);
 
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(e);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);
  digitalWrite(tree8, LOW);
 
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(e);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);
  digitalWrite(tree8, LOW);
 
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(75);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
 
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(75);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
 
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  delay(dq);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
 
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  delay(75);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
 
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(75);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
 
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  delay(e);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
 
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(e);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
 
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  delay(e);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
 
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(75);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
 
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(75);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree8, HIGH);
  delay(dq);
  digitalWrite(tree1, LOW);
  digitalWrite(tree8, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  digitalWrite(tree8, HIGH);
  delay(75);
  digitalWrite(tree1, LOW);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
  digitalWrite(tree8, LOW);
 
  digitalWrite(tree2, HIGH);
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  digitalWrite(tree7, HIGH);
  delay(75);
  digitalWrite(tree2, LOW);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
  digitalWrite(tree7, LOW);
 
  digitalWrite(tree3, HIGH);
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  digitalWrite(tree6, HIGH);
  delay(e);
  digitalWrite(tree3, LOW);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
  digitalWrite(tree6, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree2, HIGH);
  digitalWrite(tree3, HIGH);
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  digitalWrite(tree6, HIGH);
  digitalWrite(tree7, HIGH);
  digitalWrite(tree8, HIGH);
  delay(q);
  digitalWrite(tree1, LOW);
  digitalWrite(tree2, LOW);
  digitalWrite(tree3, LOW);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
  digitalWrite(tree6, LOW);
  digitalWrite(tree7, LOW);
  digitalWrite(tree8, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree8, HIGH);
  delay(e);
  digitalWrite(tree1, LOW);
  digitalWrite(tree8, LOW);
 
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(de);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
 
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(s);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
 
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  delay(e);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
 
  digitalWrite(tree3, HIGH);
  digitalWrite(tree6, HIGH);
  delay(e);
  digitalWrite(tree3, LOW);
  digitalWrite(tree6, LOW);
 
  digitalWrite(tree2, HIGH);
  digitalWrite(tree7, HIGH);
  delay(q);
  digitalWrite(tree2, LOW);
  digitalWrite(tree7, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree8, HIGH);
  delay(q);
  digitalWrite(tree1, LOW);
  digitalWrite(tree8, LOW);
 
  digitalWrite(tree1, HIGH);
  digitalWrite(tree2, HIGH);
  digitalWrite(tree3, HIGH);
  digitalWrite(tree4, HIGH);
  digitalWrite(tree5, HIGH);
  digitalWrite(tree6, HIGH);
  digitalWrite(tree7, HIGH);
  digitalWrite(tree8, HIGH);
  delay(h);
  digitalWrite(tree1, LOW);
  digitalWrite(tree2, LOW);
  digitalWrite(tree3, LOW);
  digitalWrite(tree4, LOW);
  digitalWrite(tree5, LOW);
  digitalWrite(tree6, LOW);
  digitalWrite(tree7, LOW);
  digitalWrite(tree8, LOW);
  delay(20000);
 
  end = millis();
  time = end - start;
  Serial.println(time);
}


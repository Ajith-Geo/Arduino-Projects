int time = 0;
int buzzer = 7;
long sum = 0;
int alrm = 530;
int count = 0;

long hr_to_sec(int alrm)
{
  int hr = alrm / 100;
  int min = alrm % 100;
  
  long total_sec = hr*60*60 + min*60;
  return total_sec;
}

long alarm = hr_to_sec(alrm);

void setup() 
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  Serial.println(alarm);
  digitalWrite(buzzer, HIGH);
  delay(2000);
  digitalWrite(buzzer, LOW);
}

void loop() 
{

  if (time >= alarm)
  {
    count++;
    if(count>10)
    {
      for (int i = 0; i < 4; i++)
      {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
      }
      delay(1000);
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
        delay(300);
      }
      delay(1000);
    }
  }

  else
  {
    delay(1000);
    time++;
    // Serial.println(time);
  }
}

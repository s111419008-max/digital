// 七段顯示器數字設定
byte seven_seg_digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

// 按鈕腳位
const int buttonPin = 12;

// 變數
int buttonState = 0;
int lastButtonState = HIGH;
int num = 0;

void setup() {

  // 七段顯示器腳位設定
  pinMode(2, OUTPUT); // a
  pinMode(3, OUTPUT); // b
  pinMode(4, OUTPUT); // c
  pinMode(5, OUTPUT); // d
  pinMode(6, OUTPUT); // e
  pinMode(7, OUTPUT); // f
  pinMode(8, OUTPUT); // g
  pinMode(9, OUTPUT); // dp

  // 關閉小數點
  digitalWrite(9, LOW);

  // 按鈕使用內建上拉電阻
  pinMode(buttonPin, INPUT_PULLUP);

  // 一開始顯示 0
  sevenSegWrite(num);
}

// 顯示數字函式
void sevenSegWrite(byte digit) {

  for (byte seg = 0; seg < 7; seg++) {
    digitalWrite(seg + 2, seven_seg_digits[digit][seg]);
  }
}

void loop() {

  // 讀取按鈕狀態
  buttonState = digitalRead(buttonPin);

  // 偵測按鈕按下（HIGH → LOW）
  if (lastButtonState == HIGH && buttonState == LOW) {

    num++;

    // 超過9回到0
    if (num > 9) {
      num = 0;
    }

    // 顯示數字
    sevenSegWrite(num);

    // 防止按鈕彈跳
    delay(200);
  }

  // 更新按鈕狀態
  lastButtonState = buttonState;
}
void Anim1() {
  //AnimationBordersForShowing
  if (ChosenAnimation == 0) {
    if (Y < 200 && Y != 0 && waitflag == 0) {
      oled.clear();
      ChosenAnimation = 1;
      //SaveInEEPROMmemory(ill write it later)
      waitflag = 1;
    }
  }

  //AnimationCode
  if (millis() > mil) {
    mil = mil + FrameDelay;
    NextFrame = 1;
  }
  if (NextFrame == 1) {
    //                                                  ---HeartX---
    if (HeartX > 110) {
      HeartGravityX = 1;
    }
    if (HeartX == 0) {
      HeartGravityX = 0;
    }
    //                                                  ---4HeartDirections---
    if (HeartGravityX == 0 && HeartGravityY == 0) {
      oled.drawBitmap(HeartX, HeartY, Heart_17x16, 17, 16);
      oled.update();
      HeartX++;
      HeartY++;
      NextFrame = 0;
    }
    if (HeartGravityX == 1 && HeartGravityY == 1) {
      oled.drawBitmap(HeartX, HeartY, Heart_17x16, 17, 16);
      oled.update();
      HeartX--;
      HeartY--;
      NextFrame = 0;
    }
    if (HeartGravityX == 0 && HeartGravityY == 1) {
      oled.drawBitmap(HeartX, HeartY, Heart_17x16, 17, 16);
      oled.update();
      HeartX++;
      HeartY--;
      NextFrame = 0;
    }
    if (HeartGravityX == 1 && HeartGravityY == 0) {
      oled.drawBitmap(HeartX, HeartY, Heart_17x16, 17, 16);
      oled.update();
      HeartX--;
      HeartY++;
      NextFrame = 0;
    }
    //                                                  ---HeartY---
    if (HeartY > HeartYmax /*49forChoosingMenu(CreatingBorders)*/) {
      HeartGravityY = 1;
    }
    if (HeartY < HeartYmin) /*17forChoosingMenu(CreatingBorders)*/ {
      HeartGravityY = 0;
    }
  }
}
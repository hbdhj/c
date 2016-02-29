//mathUI.js

/**************************************************************
 * this is write by zhangjiuan
 *************************************************************/

 var mathUI = {
  //ui line color
  color: '#000',
 
  /**
   * set color
   **/
  setColor: function(color)
  {
   this.color = color;
  },

  /**
   * draw line dot
   * but we may not need draw line dot and dot,
   * becourse if x = 0, and y …, so we can draw it as
   **/
  printDot: function(startX, startY, endX, endY)
  {
   document.write(('<span style="position: absolute; left:' + startX + ';top:' + startY + ';width:' + (endX - startX) + ';height:' +
   (endY - startY) + ';font-size: 1px; background-color: ' + this.color + ';”></span>'));
  },

  /**
   * drawLine
   **/
  drawLine: function(startX, startY, endX, endY)
  {
   if (startX > endX) {
    var temp = endX;
    endX = startX;
    startX = temp;

    temp = endY;
    endY = startY;
    startY = temp;
   }

   if (startX == endX) {
    this.printDot(startX, startY, (endX + 1), endY);
   }
   else if (startY == endY) {
    this.printDot(startX, startY, endX, (endY + 1));
   }
   else {
    var e = (endY - startY) / (endX - startX);
    var tempX = startX;
    var widthY;
    while (startX < endX) {
     tempX++;
     widthY = Math.round((tempX - startX) * e);
     if (widthY == 0) {
      continue;
     }
     this.printDot(startX, startY, tempX, startY + widthY);
     startX = tempX;
     startY = startY + widthY;
    }
   }
  }
 }

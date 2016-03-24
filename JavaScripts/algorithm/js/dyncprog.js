
function showDemo() {
    //func();
    var str1 = document.getElementById("str1").value
    var str2 = document.getElementById("str2").value
    console.log("str1 = ",str1," str2 = ",str2);

    var c = document.getElementById("mycanvas");
    var row = str1.length+2
    var col = str2.length+2
    var space = 50
    c.width = space*(row+2);
    c.height = space*(col+2);
    var ctx = c.getContext("2d");
    ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
    //console.log("space = ",space," context.width = ", ctx.canvas.width, "context.height = ", ctx.canvas.height)
    // line for row
    for (var i = 0; i < row+1; i++) {
        //console.log("now draw ",i+1, " row line");
        //console.log("start at x: ",space*(i+1), " y: ", space);
        ctx.moveTo(space*(i+1), space);
        //console.log("end at x: ",space*(i+1), " y: ", space*(col+1));
        ctx.lineTo(space*(i+1), space*(col+1));
        //console.log("stop this line");
        ctx.stroke();
    }
    // line for col
    for (var i = 0; i < col+1; i++) {
        //console.log("now draw ",i+1, " col line");
        //console.log("start at x: ",space, " y: ", space*(i+1));
        ctx.moveTo(space, space*(i+1));
        //console.log("end at x: ",space*(i+1), " y: ", space*(col+1));
        ctx.lineTo(space*(row+1), space*(i+1));
        //console.log("stop this line");
        ctx.stroke();
    }
    // fill str1 to row 1
    var chars1 = str1.split("")
    for (var i = 0; i < chars1.length; i++)
    {
        ctx.font = 'bold 30pt Calibri';
        ctx.fillText(chars1[i], space*(i+2.2), space*1.8);
    }
    // fill str2 to col 1
    var chars2 = str2.split("")
    for (var i = 0; i < chars2.length; i++)
    {
        ctx.font = 'bold 30pt Calibri';
        ctx.fillText(chars2[i], space*1.2, space*(i+2.8));
    }
}

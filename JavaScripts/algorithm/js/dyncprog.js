
function showDemo() {
    // get input strings
    var str1 = document.getElementById("str1").value
    var str2 = document.getElementById("str2").value
    if (str1.length<1 || str2.length<1)
        return
    // create canvas
    var c = document.getElementById("mycanvas");
    var row = str1.length+2
    var col = str2.length+2
    var space = 50
    c.width = space*(row+2);
    c.height = space*(col+2);
    var ctx = c.getContext("2d");
    ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
    // line for row
    for (var i = 0; i < row+1; i++) {
        ctx.moveTo(space*(i+1), space);
        ctx.lineTo(space*(i+1), space*(col+1));
        ctx.stroke();
    }
    // line for col
    for (var i = 0; i < col+1; i++) {
        ctx.moveTo(space, space*(i+1));
        ctx.lineTo(space*(row+1), space*(i+1));
        ctx.stroke();
    }
    // fill str1 to row 1
    var chars1 = str1.split("")
    for (var i = 0; i < chars1.length; i++)
    {
        ctx.font = 'bold 30pt Calibri';
        ctx.fillText(chars1[i], space*(i+3.2), space*1.8);
    }
    // fill str2 to col 1
    var chars2 = str2.split("")
    for (var i = 0; i < chars2.length; i++)
    {
        ctx.font = 'bold 30pt Calibri';
        ctx.fillText(chars2[i], space*1.2, space*(i+3.8));
    }
    //
    num = []
    for (i = 0; i<= chars1.length; i++)
    {
        row = []
        for (j = 0; j<= chars2.length; j++)
        {
            row.push(0)
        }
        //console.log(num.toString())
        num.push(row)
    }
    for (i = 0; i<= chars1.length; i++)
        num[i][0]=i
    for (j = 0; j<= chars2.length; j++)
        num[0][j]=j
    for (i = 1; i<= chars1.length; i++)
        for (j = 1; j<= chars2.length; j++)
            if(str1[i-1]==str1[j-1])
                num[i][j] = num[i-1][j-1]
            else
                num[i][j]= Math.min(num[i][j-1], num[i-1][j], num[i-1][j-1])+1
    for (i = 0; i<= chars1.length; i++)
        console.log(i.toString()+' = '+num[i].toString())
    for (i = 0; i<= chars1.length; i++)
    {
        for (j = 0; j<= chars2.length; j++)
        {
            ctx.font = 'bold 30pt Calibri';
            ctx.fillText(num[i][j].toString(), space*(i+2.2), space*(j+2.8));
        }
    }
}


var str1;
var str2;
var num = [];
var drawFirstRowId;
var drawFirstColId;
var refreshMatrixId;
var space = 50;
var row = 0;
var col = 0;
var type = 0

function canvas_arrow(ctx, fromx, fromy, tox, toy){
    var headlen = 10;   // length of head in pixels
    var angle = Math.atan2(toy-fromy,tox-fromx);
    ctx.moveTo(fromx, fromy);
    ctx.lineTo(tox, toy);
    ctx.stroke();
    ctx.lineTo(tox-headlen*Math.cos(angle-Math.PI/6),toy-headlen*Math.sin(angle-Math.PI/6));
    ctx.stroke();
    ctx.moveTo(tox, toy);
    ctx.lineTo(tox-headlen*Math.cos(angle+Math.PI/6),toy-headlen*Math.sin(angle+Math.PI/6));
    ctx.stroke();
}

function drawFirstRow(ctx) {
    //console.log(row, str1.length, num.length)
    ctx.fillText(num[row][0].toString(), space*(row+2.2), space*2.8);
    row++
    if( row>str1.length )
    {
        clearInterval(drawFirstRowId);
        col = 1;
        drawFirstColId = setInterval(function() {
            drawFirstCol(ctx);
        }, 200);
    }
}

function drawFirstCol(ctx) {
    //console.log(col, str2.length, num[0].length)
    ctx.fillText(num[0][col].toString(), space*2.2, space*(col+2.8));
    col++
    if( col>str2.length )
    {
        clearInterval(drawFirstColId);
        row = 1;
        col = 1;
        refreshMatrixId = setInterval(function() {
            drawMatrix(ctx);
        }, 200);
    }
}

function drawMatrix(ctx) {
    //console.log(row, str1.length, col, str2.length)
    if ((row <= str1.length)&&(col <= str2.length))
    {
        /*if (num[row][col]==num[row-1][col-1])
        {
            canvas_arrow(ctx, space*(row+1.8), space*(col+1.8), space*(row+2.2), space*(col+2.2));
        }
        if (num[row][col]==num[row-1][col-1]+1)
        {
            canvas_arrow(ctx, space*(row+1.2), space*(col+1.8), space*(row+2.2), space*(col+2.8));
        }
        if (num[row][col]==num[row-1][col]+1)
        {
            canvas_arrow(ctx, space*(row+2.2), space*(col+1.8), space*(row+2.2), space*(col+2.8));
        }
        if (num[row][col]==num[row][col-1]+1)
        {
            canvas_arrow(ctx, space*(row+1.2), space*(col+2.8), space*(row+2.2), space*(col+2.8));
        }*/
        if(str1[row-1]==str2[col-1])
            canvas_arrow(ctx, space*(row+1.8), space*(col+1.8), space*(row+2.2), space*(col+2.2));
        else
        {
            if ((num[row-1][col-1]<=num[row-1][col])&&(num[row-1][col-1]<= num[row][col-1]))
            {
                canvas_arrow(ctx, space*(row+1.8), space*(col+1.8), space*(row+2.2), space*(col+2.2));
            }
            else if ((num[row][col-1]<=num[row-1][col])&&(num[row][col-1]<= num[row-1][col-1]))
            {
                canvas_arrow(ctx, space*(row+2.5), space*(col+1.8), space*(row+2.5), space*(col+2.2));
            }
            else if ((num[row-1][col]<=num[row][col-1])&&(num[row-1][col]<= num[row-1][col-1]))
            {
                canvas_arrow(ctx, space*(row+1.8), space*(col+2.5), space*(row+2.2), space*(col+2.5));
            }

        }
        ctx.fillText(num[row][col].toString(), space*(row+2.2), space*(col+2.8));
        col++;
        if (col>str2.length)
        {
            col = 1;
            row ++;
        }
    }
    else {
        clearInterval(refreshMatrixId);
    }

}

function showDemo() {
    // get input strings
    str1 = document.getElementById("str1").value
    str2 = document.getElementById("str2").value
    if (str1.length<1 || str2.length<1)
        return
    // create canvas
    var c = document.getElementById("mycanvas");
    var row = str1.length+2
    var col = str2.length+2

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
    for (var i = 0; i < str1.length; i++)
    {
        ctx.font = 'bold 30pt Calibri';
        ctx.fillText(chars1[i], space*(i+3.2), space*1.8);
    }
    // fill str2 to col 1
    var chars2 = str2.split("")
    for (var i = 0; i < str2.length; i++)
    {
        ctx.font = 'bold 30pt Calibri';
        ctx.fillText(chars2[i], space*1.2, space*(i+3.8));
    }
    // init the empty matrix
    for (i = 0; i<= str1.length; i++)
    {
        row = []
        for (j = 0; j<= str2.length; j++)
        {
            row.push(0)
        }
        //console.log(num.toString())
        num.push(row)
    }
    for (i = 0; i<= str1.length; i++)
        num[i][0]=i
    for (j = 0; j<= str2.length; j++)
        num[0][j]=j
    for (i = 1; i<= str1.length; i++)
        for (j = 1; j<= str2.length; j++)
            if(str1[i-1]==str2[j-1])
                num[i][j] = num[i-1][j-1];
            else
                num[i][j]= Math.min(num[i][j-1], num[i-1][j], num[i-1][j-1])+1;
    ctx.font = 'bold 30pt Calibri';
    col = 0;
    row = 0;
    drawFirstRowId = setInterval(function() {
        drawFirstRow(ctx);
    }, 200);
}

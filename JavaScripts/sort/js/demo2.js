var digitsToSort;
var Coordinate_y = 40;
var Rect = new Array();
var track_insert = new Array();
var cons = 0;
var cnt;
var sort_type;
var sort_type_str;
var textStartPix = 40;
function func() {
    //获取字符串，存入数组
    digitsToSort = document.getElementsByName("string")[0].value.split("");
    var sort_type_select = document.getElementById("sort_type");
    var sort_type_index=sort_type_select.selectedIndex ;
    sort_type = sort_type_select.options[sort_type_index].value;
    sort_type_str = sort_type_select.options[sort_type_index].text;
    textStartPix = digitsToSort.length*15-sort_type_str.length*5;
    if(textStartPix < 0)
    {
        textStartPix = 0
    }
    // console.log(textStartPix);
    // 依据数组元素，完成对象数组
    Rect = [];
    track_insert = [];
    cons = 0;
    for (var i = 0; i < digitsToSort.length; i++)
    {
        var rect = {
            x: 30 * i + 15,
            y: Coordinate_y,
            target_x: 30 * i + 15,
            target_y: Coordinate_y,
            text: digitsToSort[i]
        }
        Rect.push(rect);
    }
    insertSort(digitsToSort);
}

function insertSort(arr) {
    var i = 1, j, key, temp;
    for (; i < arr.length; i++)
    {
        j = i;
        key = arr[i];
        while (--j >= 0)
        {
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                arr[j] = key;
                // 当数据有交换时，记录下标
                track_insert.push(j);
            } else {
                break;
            }
        }
    }
}
//坐标更新
function update() {
    if (cons > track_insert.length) {
        return;
    }
    if (cons == 0) {
        cnt = track_insert[cons];
        // console.log(cnt);
        Rect[cnt].target_x = Rect[cnt + 1].x;
        Rect[cnt + 1].target_x = Rect[cnt].x;
        cons += 1;
    }
    if (Rect[cnt].x == Rect[cnt].target_x) {
        if (cons == track_insert.length) {
            cons += 1;
            return;
        }
        var tem = Rect[cnt];
        Rect[cnt] = Rect[cnt + 1];
        Rect[cnt + 1] = tem;
        cnt = track_insert[cons];
        Rect[cnt].target_x = Rect[cnt + 1].x;
        Rect[cnt + 1].target_x = Rect[cnt].x;
        cons += 1;
        console.log(cnt);
    } else {
        Rect[cnt].x += 1;
        Rect[cnt + 1].x -= 1;
    }
}
//绘制图像
function draw(context) {
    context.clearRect(0, 0, context.canvas.width, context.canvas.height);
    for (var i = 0; i < Rect.length; i++) {
        if ((Rect[i].x - Rect[i].target_x) >= 2 || (Rect[i].x - Rect[i].target_x) < -2) {
            context.fillStyle = "yellow";
            context.fillRect(Rect[i].x, Rect[i].y, 25, 25);
            context.fillStyle = "blue";
            context.fillText(Rect[i].text, Rect[i].x + 5, Rect[i].y + 20);
        } else {
            context.strokeStyle = "blue";
            context.strokeRect(Rect[i].x, Rect[i].y, 25, 25);
            context.fillStyle = "blue";
            context.fillText(Rect[i].text, Rect[i].x + 5, Rect[i].y + 20);
        }
    }
    // context.fillText("插入排序", 40, 80);
    context.font="20px Verdana";
    context.fillText(sort_type_str, textStartPix, 100);
}

function showDemo() {
    func();
    var c = document.getElementById("mycanvas");
    c.width = digitsToSort.length*30+30;
    c.height = 200;
    var context = c.getContext("2d");
    // 40ms调用一次函数
    setInterval(function() {
        draw(context);
        update();
    }, 40);
}

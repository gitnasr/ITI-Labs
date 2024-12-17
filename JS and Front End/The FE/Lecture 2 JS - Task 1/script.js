// var html = ""

// for (var i = 0; i < 10; i++) {
// if (i%2 == 0) {
//     html += "<h2>Even number: " + i + "</h2>";

// }else{
//     html += "<div class='black'></div>";
// }

// }

// document.getElementById("demo").innerHTML = html;

// var s = "";
// for (var i = 0; i < 20; i++) {
// 	if (i % 2 == 0) {
// 		s += "<div class='black'>iti</div>";
// 	} else {
// 		s += "<h1>hi</h1>";
// 	}
// }
// document.getElementById("demo").innerHTML = s;


// var x = 20;
// function test() { 
//     console.log("x inside function: ", x) 
//     x = 6;
//     console.log("x inside function after reassign: ", x)
// }

// console.log("x before function call: ", x)
// test()
// console.log("x after function call: ", x)


// var y = 10;

// (function() {
//     console.log("y inside function: ", y)
//    y = 5;
//     console.log("y inside function after reassign: ", y)
// })()

// console.log("y after function call: ", y)


// function test() {
//     var x = 10;
//     console.log("x inside function: ", x)

//     function inner() {
//         console.log("x inside inner function: ", x)
//        var x = 5;
//         console.log("x inside inner function after reassign: ", x)
//     }
//     inner()

//     console.log("x inside function after inner function call: ", x)

// }

// test()


console.log(foo())
var foo = function()
{
    return bar();
    function bar() { return 3;} 
    var bar = function() { return 8;}
}





console.log(foo())
var foo = function()
{
    return bar();
    function bar() { return 3;} 
    var bar = function() { return 8;}
}
// alert("I love pizza");

// console.log("I really enjoy talking");
// let var1="Sonia";
// // console.log(var1);

// ACCEPTING INPUT

//type1: window prompt 
// var1= window.prompt("Whats ur name");   : 
// console.log("My name is",var1);

/*TYPE2: by taking input in page
document.getElementById("someButton").onclick=function(){
    var myName=document.getElementById("myText").value;
    console.log("Hello",myName);
} 
*/

//variables  Number, String, Boolean

// var age= window.prompt("Enter your age");
// // age+=1;     //age is string
// console.log(age);
// //if age is 19 19+1 will be logged as 191
// age=Number(age);
// age+=1;
// console.log(typeof age);
// console.log(age);

//FUNCTIONS  end with;    call without having datatype of arg

/* function sayHello(myName, myAge){
    console.log("Hello",myName);
    console.log("My age is",myAge);
};
//sayHello("Sonia",19);

function toCelcius(f){
    return (f-32)*(5/9);
};

let cel=toCelcius(180);

console.log("My temp in celcius:",cel);
*/

//OBJECTS : like classes separated by "," ends with; after {}

// var human = {
//     name: "Rick",
//     age: "29",

//     eat: function(){
//         console.log("Rick is eating");
//     },
//     drink:function(){
//         console.log("Rick is drinking ");
//     },
//     sleep: function(){
//         console.log("Rick is sleeping");
//     }

// };

// //accessing
// human.name  //dot not
// human['name'] //bracket notation

// console.log(human.age);
// human.sleep();

// ARRAYS any type   in [] 
/*
var cars = ["Skodaerarri", "Lambo", "Mustang"];

console.log(cars[1]);
cars.push("Tesla");
// console.log(cars);
// cars.pop();
// var number = cars.length;
// console.log("Number of cars",number);
// cars = cars.sort();
// cars=cars.reverse();

var lastCar = cars[cars.length-1];
*/

// CONDITIONALS if, else, for, while syntax like c
//SWITCH
// && || !
/*
var grad = "F";
switch(grad){
    case "A": console.log("HOORAAY!");
    break;
    case "B": console.log("You good");
    break;
    default: console.log("Wrong grade");
}
*/

//traditional for same as c
//for in loop //every part wil be executed
/*let letters = ["H","E","L","L","O"];
for(let i in letters){
    console.log(letters[i]);
}

let car = {
    make: "Chevy",
    color: "Red",
    year: 2020,
    model: "Skoda"
}

for(let i in car){@
    console.log(car[i]);
}
*/

// var symbol=window.prompt("Enter a symbol to use");
// var rows=window.prompt("Enter # of rows");
// var columns=window.prompt("Enter number of columns");

// for(let i=0;i<rows;i++){
//     for(let j=0;j<columns;j++){
//         document.getElementById("myRectangle").innerHTML+=symbol;
//     }
//     document.getElementById("myRectangle").innerHTML+= "<br>";
// }

//MATH FUNCTIONS  Math.________

// var myNum;

// myNum=Math.round(3.5);
// myNum=Math.pow(3,4);
// myNum=Math.PI;

// console.log(myNum);
/*
var randNum;

// randNum=Math.random();  //0-1 range
// randNum=Math.floor(Math.random()*6);    //0-5

function getRandomNum(min,max){
    return Math.floor(Math.random()*(max-min+1)+min);
}
randNum=getRandomNum(6,20);
console.log(randNum);
*/

//DATE OBJECT
/*
date = new Date(0);
// date = new Date();
date = new Date("April 20, 2022 16:20:01:02");
console.log(date);

let year = date.getFullYear();
let dayofweek = date.getDay();
let dayofmonth = date.getDate();

date.setFullYear(2022);
date.setMonth(07);
*/

// STRINGS
/*
var word = "Hello there";
var word2 = "Yes hi";
console.log(word.charAt(2));
console.log(word.trim());
console.log(word.toUpperCase());

var firstWord = word.slice(0, word.indexOf(" "));
console.log(firstWord);

var final = word.concat(" ",word2);
console.log(final);

word=word.replace(" ","-");
console.log(word);
*/

//METHOD CHAINING
/*
let user = "bro";
user = user.charAt(0).toUpperCase() + user.slice(1);
console.log(user);
*/

//SCOPE

//ECMAScript 

//let= declare variables with a block scoped {}
// var=declare variables with a function scope {}
/*
for(var i=1;i<9;i++){       //if let was used in for () it is outside { scope and hence will be error}
    console.log(i);
}
*/
//we try to use let because using var can overwrite window object properties

// forEach() = performs a function for each element in an array
/*
let total=0;
let cart = [1,4,5,3,6,3];

function sum(element){
    total+=element;
}

cart.forEach(sum);
console.log("Sum is"+total);
*/

// map() = performs a function on each element in array and stores returned value in a new array
/*
let usd= [4,5,6,7,8];

function toEuros(value){
    value*=0.85;
    return value;
}

let inEuroes= usd.map(toEuros);

console.log(inEuroes);
*/

//filter() = Returns the element of an array that meets a specified condition in a func
/*
let students = [23,23,12,45,33];

function checkAge(age, index, array){
    if(age>23)
        return age;
}

let grads= students.filter(checkAge);
console.log(grads);
*/

// reduce() = returns single value by pasisng array
/*
let letters = ["w", "o", "r", "d"];

function combine(total, nextLetter, index, array){
    return total+nextLetter;
}

let word = letters.reduce(combine);
console.log(word);
*/

//**************************************

//callback passung func to func as arg
/*
let message;
function displayConsole(output){
    console.log(output);
}
function displayDOM(output){
    document.getElementById("myH1").innerHTML = output;
}
function setMessage(text, callback){
    message = text;
    callback(message);
}

//displayConsole(setMessage("Hi mom!"));
//displayDOM(setMessage("Hey there!"));

//add another arg in functions for callback

setMessage("Hi mom!",displayDOM);   //displays on doc
*/

//function expression = a fun can be defined using an expression
//                      can be stored in a variable
//                      variable can be ised as func and invoked using ()

//*****FUNCTION DECLARATION***********
/*
sayHey();
function sayHey(){
    console.log("Heyyy");
}
//*****FUNCTION EXPRESSION****************
// can be used as funcs that run as soon as they're defined
// can be passed as args to other funcs
//let greeting = function(){ console.log("Hello")};
let greeting = function(){document.getElementById("myH1").innerHTML="Hello world"};
output(greeting);
function output(func){
    func();
}
*/

// nested funcs

//***************anonymous funcs******************
//                   = funcs w/o a name. not accessible after creation
//IIFE = a JS func that runs as soon as its defined 
// grouping operator = (func enclosed in)
// can be passed as arg 
/*
(function(){
    document.getElementById("myH1").innerHTML="hellooo";
})();

let task = function(){document.getElementById("myH1").innerHTML="sup"};
setTimeout(task,10000);
*/

//closure

//*************arrow function****************** */
/*
let x="Yo", y="Bro";
hello = (x,y) => x+" "+y;
console.log(hello(x,y));
// map(), filter(), reduce() difference?

*/
 
//**********number sorting********* */
/*
let numbers = [3,14,1,5,2];

//numbers.sort();
numbers.sort((x,y)=>y-x);
console.log(numbers);
*/



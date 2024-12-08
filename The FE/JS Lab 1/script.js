// Q1

function printFullName() {
    var f_name = document.getElementById("first").value;
    var l_name = document.getElementById("second").value;
    
    var full_name = f_name + " " + l_name;

    console.log(full_name);
}


// Q2
function getMinMax() {
    var number = []
  for (var i = 0; i < 3; i++) {
    number[i] = +prompt('Enter number ' + (i+1));
  }

  var max = number[0];
    var min = number[0];
    for (var i = 0; i < number.length; i++) {
        if (number[i] > max) {
            max = number[i];
        }
        if (number[i] < min) {
            min = number[i];
        }
    }

    console.log("Max: " + max);
    console.log("Min: " + min);
}

// getMinMax();


// Q3

function isEvenOrOdd() {

    var number = +prompt('Enter a number');
    if (number % 2 === 0) {
        console.log("this is Even");
    } else {
        console.log("this is Odd");
    }
}

// isEvenOrOdd();


// Q4

function FizzBuzz() { 
    for (var i = 1; i <= 20; i++) {
        const isFizz = i % 3 === 0;
        const isBuzz = i % 5 === 0;
        if (i % 3 === 0 && i % 5 === 0) {
            console.log(`Number: ${i} FizzBuzz`);
        } else if (i % 3 === 0) {
            console.log(`Number: ${i} Fizz`);
        } else if (i % 5 === 0) {
            console.log(`Number: ${i} Buzz`);
        } else {
            console.log(`Number: ${i}`);
        }
    }
}

// FizzBuzz();

// Q5 

function Factorial() {
    do {
        var number = +prompt('Enter a number');
    } while (number < 0 || Number(number) !== number);
    
    var result = 1;
    for (var i = 1; i <= number; i++) {
        result *= i;
    }
    console.log(`Factorial of ${number} is ${result}`);
}

// Factorial();

// Q6



function AddCard() {
    var container = document.getElementsByClassName("container")[0]
    var card = document.createElement("div");
    
    card.innerHTML = ` <div class="card">
            <img src="https://via.placeholder.com/150" alt="Avatar" >
            <div>
                <h3>Card Title</h3>
                <p>Card Description</p>
            </div>
        </div>`

    container.appendChild(card);
}
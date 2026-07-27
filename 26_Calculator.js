// ==========================================
// STEP 1: ASK (Gather the inputs)
// ==========================================
let answer; // Create an empty box to hold our final result

// Ask the user what they want to do
let mathSymbol = prompt('Enter a symbol (+, -, *, /): ');

// Ask the user for numbers (and convert their text into real numbers)
let num1 = parseFloat(prompt('Enter first number: '));
let num2 = parseFloat(prompt('Enter second number: '));


// ==========================================
// STEP 2: DECIDE (Check the symbol)
// ==========================================
switch(mathSymbol) { 

    // ==========================================
    // STEP 3: ACT (Do the math and print it)
    // ==========================================
    case '+':
        answer = num1 + num2;
        console.log(`${num1} + ${num2} = ${answer}`);
        break; // "break" tells the computer: Stop here, we found the right answer!

    case '-':
        answer = num1 - num2;
        console.log(`${num1} - ${num2} = ${answer}`);
        break;

    case '*':
        answer = num1 * num2;
        console.log(`${num1} * ${num2} = ${answer}`);
        break;

    case '/':
        answer = num1 / num2;
        console.log(`${num1} / ${num2} = ${answer}`);
        break;

    default: // If they typed something weird like "pizza" instead of "+"
        console.log('Oops! That is an invalid symbol.');
        break;
}

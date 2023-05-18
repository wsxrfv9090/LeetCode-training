'use strict';

// Problem:
// (1)
// We have an array here: arr = { 1,1,1,3,4,5,4,3,5 }
// And you have to use algorithms to find the odd number here
// requirements: Complexity of Time: O(N)
// (2)
// Change the array to arr = { 2,2,2,3,3,3,6,4,5,5,4,6 }
// Use the algorithms to find the two odd numbers here
// same requirements as the first one

const arr = [1, 1, 1, 3, 4, 5, 4, 3, 5];
let eor = 0;
for (let i = 0; i < 9; i++)
    eor = eor ^ arr[i];
console.log(`The answer for the first problem is ${eor}`);

const arr0 = [2, 2, 2, 4, 4, 4, 6, 4, 5, 5, 4, 6];
let eor1 = 0;
let eor2 = 0;
let count = 0;

for (let i = 0; i < arr0.length; i++)
    eor1 = eor1 ^ arr0[i];//a ^ b
let rightOne = eor1 & (~eor1 + 1);

for (let i = 0; i < arr0.length; i++) {
    if ((arr0[i] & rightOne) === rightOne)
        eor2 = eor2 ^ arr0[i];
}
let answer3 = eor2 ^ eor1;
console.log(`The two numebers for the second problem are: ${eor2}, ${answer3}`);

//Time Complexity: O(N)
//Space Complexity: O(1)




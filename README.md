# PostFix Calculator

What is postfix?

> *Postfix (or reverse polish notation) is a mathematical notation in which operators follow their operands.* [Source: Wikipedia](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
>
> Example: calculation 3+5 is 3 5 + with postfix notation.


## How to compile

:bangbang: Make sure you have installed g++ CLI tools on your device.
You can check it with

```gcc --version``` or shorter ```gcc -v```

For Ubuntu, you can install g++ with this command:

```sudo apt install g++```

... or if you have MacOS/ Linux with [Homebrew](https://brew.sh), you can install g++ with

```brew install gcc```

When g++ CLI tools installed, you can type these commands below to compile this calculator:

```git clone https://github.com/jenjei/postfix-calculator-cpp```

:arrow_down:

```cd postfix-calculator-cpp```

:arrow_down:

```g++ main.cpp -o postfix```

:arrow_down:

```./postfix```

## Tasks

- [x] Create a simple PostFix Calculator (+ - / *) -> (e.g. **8 4 /** input would mean same as 8/4) <br/>
- [x] Exchange order of operations with x command (e.g. **3 5 x -** input would mean same as 5-3)<br/>
- [] Add the sum function (command s) to the calculator which calculates the total sum of the numbers in the stack at that moment, then remove the numbers used for the sum from the stack, and finally add the total to the top of the stack. (e.g. **5 2 4 s** input would calculate 5+2+4, and result 11 is the only value left in stack) <br/>
- [] Implement an average function in your calculator (command a) that calculates the average of all the numbers in the stack. The numbers participating in the average calculation are removed from the stack (all) and the result (average value) is printed on the stack. <br/>
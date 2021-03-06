# Functions

In greylang, functions server as functions, blocks, and operators from other
languages, so they're even more important than in other languages.

* Functions are defined with just `{` and `}`; `{}` is a valid empty function.
* Functions are just any other data type, and can thus be passed to other
  functions, returned from functions, and assigned to variables.
* Functions can declare arguments, like this:

	f = {(str)
		print(str);
	};
	f("Hi World");

* Declaring arguments is optional, and all arguments passed to the function is
  available as `$1`, `$2`, etc:

	f = { print($1) };
	f("Hi World");

* Functions can be called inline, like this:

	plus = {(a, b) a + b };
	print(10 plus 20);

# Standard Library

## Viariables

* `none`: Variable of type `none`.
* `true`: Boolean with value true.
* `fasle`: Boolean with value false.

## Flow Control

Flow control functions' arguments are reversed if they're called as infix
functions; e.g `if(true, {print("hi")})` becomes `{print("hi")} if true`.

* `if(condition, function)`:
	* Run function if condition returns true.
	* `if(1 == 1, { print("Hello World") });`
* `repeat(count, function)`:
	* Run function `count` times.
	* `repeat(10, { print("Hello World") });`
* `while(function, function)`:
	* Run the second function as long as the first function returns true.
	* `i = 0; while({ i < 10 }, { print("Hello World"); i = i + 1 })`

## General

* `new(object[, object])`
	* Look at `examples/classes.grey`.
* `return(n, value)`
	* Return `value` through `n` functions.
	* Because `if` and `while` and such execute functions, not blocks,
	  you have to be able to return through some number of functions for
	  `return`to be useful.
	* Because the last expression in a function is returned by default, using
	  `return` is generally unnecessary except as a mechanism to return early.

## Arithmatic

All arithmatic is done using functions which are generally called as infix
functions. All are just regular functions, as `+`, `-`, etc. are valid
identifiers.

* `10 + 20`
* `10 - 20`
* `10 * 20`
* `10 / 20`
* `10 ^ 20` (10 to the power of 20)

## Boolean Logic

Like arithmatic, all logic is done using regular functions.

* `10 == 10`
* `10 != 10`
* `20 > 10`
* `10 < 20`
* `20 >= 10`
* `10 <= 20`
* `true and true`, or `true && true`
* `false or true`, or `false || true`

## Misc

* `print(string[, string, ...])`:
	* Print to console.
* `read(prompt)`:
	* Read from console.
* `error(message)`:
	* Error.
* `tostring(variable)`:
	* Convert any variable to a string.
* `tonumber(string)`:
	* Convert a string to a number.
* `type(variable)`:
	* Return the type of a variable as a string.
* `concat(string, string[, string])`:
	* Concatenate strings.
* `..`: Alias of `concat`.

## Methods

### Array Methods

* `array.len()`:
	* Get the length of the array.
* `array.push(value)`:
	* Add a variable to the end of the array.
* `array.pop()`:
	* Remove and return the last element of the aray.
* `aray.map(function)`:
	* Run function for every variable in the array.

### String Methods

* `string.len()`:
	* Get the length of the string.
* `string.sub(start[, end])`:
	* Get a substring of the string.

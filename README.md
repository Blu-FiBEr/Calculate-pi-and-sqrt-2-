## Generate Digits of π to any given Precision

### Keshav Goyal

#### Instructor : Prof. G.Srinivasaraghavan

## Aim

Implement a programme that can calculate the value of π to any given
precision and verify this value for its correctness.

## Algorithms

1. Basic Integer Algorithms: shoup.net
    - Addition
    - Subtraction
    - Multiplication
    - DivMod
2. Division Algorithm: Repeated DivMod
3. Toom-Cook (Toom3) Multiplication
4.Base Conversion Algorithms (In order to get result in decimal form):
5. Special Shift Algorithm (To facilitate multiplication and exact division by
    powers of 2)
6. Newton-Raphson Iterative Algorithm
7. Borwein’s exp-2 Algorithm
8. Verification Tools:
## Instructions to run

- Commands:
    - make calculate
    - ./calculate
- Follow the instructions given and input the required numbers in decimal form.

## Procedure

- I have implemented these algorithms by utilising the OOP functionality of
    C++. I have created an _Integer_ class which represents any integer of base
    2 m. This class was then used as a data member in another class called
    _Float_. _Float_ class represents any rational number(upto finite precision)
    having base 2m. All the basic arithmetic and algorithms have then been
    defined for these classes using methods like operator overloading.

- When run, the programme prompts the user to choose if they want value
    of π or √2. Then it asks for the required precision and the base to be used
    for calculations. For calculation of π , user will also get the option of
    choosing Toom3 as multiplication method. Programme then calculates the
    value of π or √2 and prints it to stdout in decimal form. The programme
    then goes on to verify this calculated value using the pre-stored 1 million
    digit precision value of π as well as for √2. It then informs the user whether
    the value calculated was correct or not. The total time taken for the whole
    process is then shown in seconds( Time taken for Calculating in given
    base, Converting to decimal and finally verifying).

- I have implemented Toom3 algorithm but it hasn’t been extensively used in
    my implementation. This is because both Newton-Raphson method and
    Borwein’s Algorithm only need multiplications with 0.5 (Division by 2). For
    this simple multiplication was found to be faster than Toom3. Anyway, the
    option to use Toom3 for calculation has been included in the main menu.

- Anyhow, my Toom3 implementation did give decent results when
    separately tested for huge multiplications(In the order of 10^5 digits).
- Both, Borwein’s Algorithm and Newton-Raphson Algorithm stop iterating
    when the difference between two consecutive estimates becomes less
    than the required precision.
- The intermediate results such as square roots and divisions are calculated
    upto a precision of [ (Actual Precision) + 8 ]. This maintains the accuracy of
    the digits at higher precision places.

## Future Scope

- My laptop kills the running programme when the swap utilised by it
    exceeds 55 GB(This is unalterable in MacOS). To reduce the utilised swap, I
    can better implement the concept of destructors. This would allow me to
    get precisions of more than 35,000.
- This would also allow me to use much smaller bases for higher precisions.^
- My Toom3 implementation can still be optimised further, which would
    allow me to incorporate it in the implementation of Newton-Raphson
    method and Borwein’s Algorithm



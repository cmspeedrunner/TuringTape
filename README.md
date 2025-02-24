# TuringTape
TuringTape is a turing machine written in just 200 lines of C++<br>

## The Tape
On start, a 2040 bit, 255 byte 1 dimensional array is initalised, it contains 2040 values, randomised as a 1 or a 0<br>
You should see a screen like this:
```
tape>
```
From here, 11 possible commands can be entered.
## Commands
Your pointer begins at index 0, to move left or right, use `<` and `>` like this:
```
Tape>>

SHIFTED FROM: 0 TO: 1
Tape><

SHIFTED FROM: 1 TO: 0
```
You can display a cell of the tape (the surrounding 10 values and addresses) using `t` like this:
```
Tape>t

TAPE VALUES:
---------------------------
[1] 1 0 0 1 0 0 0 0 0
---------------------------

MEMORY ADDRESS:
---------------------------
[0] 1 2 3 4 5 6 7 8 9
```
You can layer any commands together in a single line, for example:
```
Tape>>>>>>t

SHIFTED FROM: 0 TO: 1
Tape>
SHIFTED FROM: 1 TO: 2
Tape>
SHIFTED FROM: 2 TO: 3
Tape>
SHIFTED FROM: 3 TO: 4
Tape>
SHIFTED FROM: 4 TO: 5
Tape>
TAPE VALUES:
---------------------------
1 1 0 0 1 [0] 0 0 0 0
---------------------------

MEMORY ADDRESS:
---------------------------
0 1 2 3 4 [5] 6 7 8 9
```
You can read and write to the value at your current address using `r` and `w` like this:
```
Tape>r
VALUE: 0 AT ADDRESS: 2

Tape>w1

WRITE AT ADRESS:
Write>Tape>r
VALUE: 1 AT ADDRESS: 2
```
As you can see, we read the value 0 at address 2, and then wrote 1 into that address, reading it again shows 1.<br>
You can also use `x` to wipe the value by default to zero like so:
```
Tape>x

WIPED VALUE: 1 FROM ADDRESS: 2
Tape>r
VALUE: 0 AT ADDRESS: 2
```
You can jump around the tape by using `j` followed by the address. Here is an example:
```
Tape>j100j0

JUMP TO ADRESS:
Jump>
JUMPED FROM: 2 TO: 100
Tape>
JUMP TO ADRESS:
Jump>
JUMPED FROM: 100 TO: 0
Tape>
```
This also shows how you can layer the commands, in this case, jumping from address 2->100->0.<br>
Another feature is copying the value from one address to another by entering `c` followed by where from you want to copy, and where to (seperated by a space):
```
Tape>c5 0

COPY FROM ADDRESS:
Copy From>
TO ADDRESS:
Into>
COPIED VALUE: 0 FROM ADDRESS: 5
OVERWRITING VALUE: 1 AT ADRESS: 0
```
You can cut the tape and partition it at the current address using `p`, here is a full example where we jump to address 500, partition the tape, and then jump back.
```
Tape>sj500pj0s
TAPE SIZE: 2040
Tape>
JUMP TO ADRESS:
Jump>
JUMPED FROM: 0 TO: 500
Tape>--PARTITION--
Tape split at position: 500
New tape size: 501

Tape>
JUMP TO ADRESS:
Jump>
JUMPED FROM: 500 TO: 0
Tape>TAPE SIZE: 501
```
Note the use of `s` here, which displays the size of the tape. We can see how it changes once we cut the tape.<br>
To display the whole tape, you can use `f`, in this example, I will split the tape at 50, just so this readme doesnt look cluttered.
```
Tape>j50pf

JUMP TO ADRESS:
Jump>
JUMPED FROM: 0 TO: 50
Tape>--PARTITION--
Tape split at position: 50
New tape size: 51

Tape>FULL TAPE:
1 1 0 0 1 0 0 0 0 0 1 1 1 1 1 1 1 0 1 0 1 0 0 1 0 0 1 0 0 1 1 0 1 0 1 0 1 1 1 0 1 1 0 1 1 0 1 1 1 0
1
```
You can also expand the tape, using `e` followed by how many bits you want to expand it by, it will initialise that amount and allocated random values into them just as it does on start.
```
Tape>e50f

EXPAND TAPE BY: --TAPE EXPANDED--
New tape size: 101

Tape>FULL TAPE:
1 1 0 0 1 0 0 0 0 0 1 1 1 1 1 1 1 0 1 0 1 0 0 1 0 0 1 0 0 1 1 0 1 0 1 0 1 1 1 0 1 1 0 1 1 0 1 1 1 0
1 1 1 0 1 0 0 0 1 0 1 1 0 0 1 1 1 1 0 1 0 1 0 1 1 1 1 0 1 0 1 1 0 0 0 1 1 0 0 1 0 0 1 1 1 0 0 0 1 1
1
```
As you can see, I expanded the tape used earlier by 50 and then displayed the tape.<br>
The last two commands are `l` and `o` which load the tape and save it as a file respectively. For example:
```
Tape>o tape.txt
SAVE TAPE AS: --TAPE SAVED--
File: tape.txt
```
If I saved a tape with the size of 5000, and loaded it into a new tape with the default size of 2040, it would reallocate the tape and copy the values in, for example.
```
Tape>s
TAPE SIZE: 2040
Tape>l bigtape.txt
LOAD TAPE: --TAPE LOADED--
New size: 5001
```
As you can see, it resized the tape to accomodate the values.
## Example
This is a complex example of a command that jumps to address 10, shortens the length of the tape to 10, jumps back to 0 and iterates through each value, clearing it. Finally, it jumps back to 0 and displays the tape.
```
Tape>j10pj0x>x>x>x>x>x>x>x>x>xj0t
```
I wont paste all the output in, just the tape values:
```
TAPE VALUES:
---------------------------
[0] 0 0 0 0 0 0 0 0 0
---------------------------

MEMORY ADDRESS:
---------------------------
[0] 1 2 3 4 5 6 7 8 9
```

## End
Thank you for reading! This is just a fun little project that I made to improve my c++ skills. It isn't meant to be anything serious.<br>
Thanks!

# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


test "PINA: 0x64 PINB: 0x0A PINC: 0x0A => PORTD: 0x7A"
setPINA 0x64
setPINB 0x0A
setPINC 0x0A
continue 5
expectPORTD 0x7A
checkResult

test "PINA: 0x78 PINB: 0x14 PINC: 0x0A => PORTD: 0x97"
setPINA 0x78
setPINB 0x14
setPINC 0x0A
continue 5
expectPORTD 0x97
checkResult

test "PINA: 0x28 PINB: 0x28 PINC: 0x28 => PORTD: 0x54"
setPINA 0x28
setPINB 0x28
setPINC 0x28
continue 5
expectPORTD 0x78
checkResult

test "PINA: 0x32PINB: 0x32 PINC: 0x32 => PORTD: 0x95"
setPINA 0x32
setPINB 0x32
setPINC 0x32
continue 5
expectPORTD 0x95
checkResult


#test "PINA: 0x0B => PORTC: 0x01"
#setPINA 0x0B
#continue 5
#expectPORTC 0x01
#checkResult

#test "PINA: 0x03 => PORTC: 0x02"
#setPINA 0x03
#continue 5
#expectPORTC 0x02
#checkResult

#test "PINA: 0x0F => PORTC: 0x80"
#setPINA 0x0F
#continue 5
#expectPORTC 0x80
#checkResult

# Add tests below
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n

SOL=$(sudo grep -rl Solved! . | grep "debug.txt" | head -1)
if [ ! -z $SOL ]
then
    echo "find solution in $SOL"
    sudo awk '/Solved/{ f = 1; next } /End of solution/{ f = 0 } f' $SOL > result.txt
else
    echo "No solution found"
fi

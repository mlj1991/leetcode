# Read from the file file.txt and output the tenth line to stdout.

# One
awk '{if (NR==10) {print $0;}}' file.txt

# Two
sed -n "10p" file.txt

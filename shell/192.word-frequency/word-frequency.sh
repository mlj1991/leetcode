# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | awk '{for (i=1;i<=NF;++i) {if (freq[$i]) {++freq[$i]} else {freq[$i]=1}}} END{for (word in freq) {print word, freq[word]}}' | sort -n -r -k 2

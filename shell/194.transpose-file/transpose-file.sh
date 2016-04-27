# Read from the file file.txt and print its transposed content to stdout.
awk '{
  for (i = 1; i <= NF; ++i)
    matrix[NR, i] = $i
}
END {
  for (i = 1; i <= NF; ++i)
    for (j = 1; j <= NR; ++j)
      printf(j==NR ? "%s\n" : "%s ", matrix[j, i])
}' file.txt

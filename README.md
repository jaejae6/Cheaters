# Project - *Cheaters*

**Cheaters** is a program that reads through multiple documents and tries to determine if cheating had occured. For each document in the folder, every 6 words are grouped together into 1 string where all the letters are capatialized and there are no spaces or punctuation. The string gets inserted into a hash table. If two documents had more than 200 matches, it displays the names of both files and how many matches they had in common.

Time spent: **3** days spent in total

How To Run Program
1. Unzip the folder containg the code
2. Make sure the folder containg the documents you want to search is unzipped and located in the same    folder as the code
3. Compile the code using "make -f makefile"
4. Run executable program using 
   Ex) ./a.out "name of the file where all your documents are stored"


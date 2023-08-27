# Technical Task for Entrust internship application

## Context
In this repository you can find a completed technical task for Entrust. The goal of this task is to develop a pagin application.

### Problem to solve
The paging problem consists in creating a file that is properly paged. Given a one-line text file, the program has to separate it in lines of 80 characters (if we reach this number of chars in the middle of a word, this one will be included in the actual line) and in pages every 25 lines. Pages will be differenciated with a separation mark. this separation mark will consist in a line of hastags "#" with the page number in the middle and one blank line before and after this separation line.

## Run and test the code
In this repository the code for this problem can be found. The chosen programming language is C++. In order to run this code, it has to be compiled using the following bash command:

```bash
g++ -o prova.x prova_entrust_paging.cc
```

Once the code is compiled, it can be runned using the following bash command:

```bash
./prova.x
```

You should have a new text file called `documentPaged.txt` in the directory where you ran the code.

In order to test this code, you can use other text files and check the new created file.

## Considerations
- It can be tested using one-line text files called `document.txt`.
- The file and the code file must be in the same directory or folder.
- DO NOT use files that don't accomplish these conditions.
- If it is asked, this code can be upgraded in order to use files with more than one line of text and with different names (giving the name as an input parameter).

## Question
![image](https://github.com/piru72/Operating-System-Lab/assets/63257806/a49a91ae-299f-427d-b033-c8c14ae49ec2)

1. You should create a folder on the desktop using the terminal. Folder Name should be
your full ID. This folder will have 3 sub folders.
2. Sub Folder 1 should be named as WorkingDirectory. After creating this folder, you
should open this folder using terminal (cd folder) and work from there. This folder will
contain a text file named your full id.txt . Write the following line in this text file
“Assignment 1 commands: ” while creating it.
3. Sub Folder 2 (named “Task1”) contains 2 folders. The empty folder should be named
“empty” and the other one should be named “Numbers”. The Numbers folder will have a
file “File1.txt” and this file should contain 15 random numbers (A single number in each
line).
4. Sub Folder 3 (named “Introduction”) should have 2 files. The file names are given in the
diagram. First file should contain your full ID and the 2nd file should contain your full
name.
5. Now you should copy the “Numbers” folder to Sub Folder 3 and you should rename the
file inside this folder as “Numbers.txt”. Show from (Last 3 digits of Your ID%10) no. line

to 12th line in terminal using file read commands. Now delete both empty and numbers
folder of Task 1. Now change directory to Sub Folder 3 (“Introduction”).
6. Change permission of “Numbers.txt” according to the following table.
Owner Owners’ Group Others
r _ x r w x r _ _
7. Finally, open “Your full ID.txt” file inside the WorkingDirectory folder and append all the
commands for the assignment.

## Answers : 

### STEP 1 : Create the necessary folders
```
mkdir Desktop/20200104129
cd Desktop/20200104129
mkdir WorkingDirectory Task1 Introduction
```
In this step, we create the main folder with your full ID on the desktop. Inside that folder, we create three subfolders: WorkingDirectory, Task1, and Introduction.
### STEP 2 : Create and view a text file in WorkingDirectory
```
cd WorkingDirectory
echo "Assignment 1 commands" > 20200104129.txt
more 20200104129.txt
```
In this step, we navigate to the WorkingDirectory folder
and create a text file named 20200104129.txt containing the line "Assignment 1 commands". The more command is used to view the contents of the file.
### STEP 3 : Create folders and a file in Task1   
```
mkdir ../Task1/empty ../Task1/Numbers
touch ../Task1/Numbers/File1.txt
cat > ../Task1/Numbers/File1.txt
```
Here, we navigate back to the main folder and create two subfolders inside Task1: empty and Numbers. 
We then use the touch command to create an empty file named File1.txt inside the Numbers folder. The cat command is used to input content into the file.
### STEP 4 : Create files in Introduction   
```
touch ../Introduction/20200104129.txt ../Introduction/ParvezAhammed.txt
```
In this step, we create two files inside the Introduction folder: 20200104129.txt and ParvezAhammed.txt.
### STEP 5 : Copy and manipulate files  
```
cp -r ../Task1/Numbers ../Introduction
mv ../Introduction/Numbers/File1.txt ../Introduction/Numbers/Numbers.txt
head -n 12 ../Introduction/Numbers/Numbers.txt | tail -n +9 
rm -r ../Task1/empty ../Task1/Numbers
cd ../Introduction
```
Here, we first copy the entire Numbers folder from Task1 to the Introduction folder. Then, we rename File1.txt inside the Numbers folder to Numbers.txt. The head and tail commands are
used together to display lines 9 to 12 of Numbers.txt. Next, we remove the empty and Numbers folders from Task1. Finally, we navigate to the Introduction folder.
### STEP 6 : Change file permissions
```
chmod 574 Numbers/Numbers.txt
ls -l Numbers
```
In this step, we change the permissions of Numbers.txt inside the Numbers folder using the chmod command. The permission pattern 574 is assigned, giving read (r), 
write (w), and execute (x) permissions to the owner, read (r) and execute (x) permissions to the owner's group, 
and read (r) permissions to others. The ls -l command is used to view the permissions of the Numbers folder.
### STEP 7 : View command history and append to a text file 
```
history
cat >> ../WorkingDirectory/20200104129.txt
```
Here, we view the command history using the history command. Then, we append the command history to the 20200104129.txt file in the WorkingDirectory folder using the 
cat command with the >> redirection operator.

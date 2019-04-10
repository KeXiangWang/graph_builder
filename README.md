# A General Graph Builder.

### Introduction
It is a graph builder written for the LianTong's project. With a file used to control, in which potential edges and the types of vertexes are defined, it can quickly build a graph contains edges and vertexes. 

### Update Part
- This branch is updated for Linux compatibility. The defect of linux_string version has been solved. Now with this version, only about 16G memory can be able to accommodate the larger LianTong's project's running. 
- **In this version, we start to use the word "attribute" to descibe label of edge, which keeps consistent with codes. And this change make it easier to distinguish edge attribute from vertex label.**


### Programming Language and Environment  
Written in object-oriented C++ 11.  
Written with Clion 2018.3.4 under Manjaro.  
System Version:  
- LSB Version:	n/a  
- Distributor ID:	ManjaroLinux  
- Description:	Manjaro Linux  
- Release:	18.0.4  
- Codename:	Illyria  

### Control File Grammar  
>Explanation for the Controller File.

The front rows are for defination of files.  
For each row:  
- The first string should be the name of the file. (the loaction could be raletive of absolutely both and can be changed in function: TableParser::parse)  
- The following strings are the title of the correspond volumns, which imply the real meaning of the data. They are seperated by a *tab*.  
- Each row have a potential title "table_x", which means it's **x**th table. And it is designed for the condition that there need a vertex without any meaningful infomation.  

After the rows for defination, the subsequent row should be a designated row with text, "edges:".  
Then the following rows are description of edges.  
For each row:  
- The first string and the second string are the titles defined in the front rows. They are seperated by a *tab*.  
- It means there may be a edge between the first string and the second string. If in a row of one file, the two strings appears at the same time, the program will make an edge from the first string to the second string and give the edge a label.  

### Example
> **Controller File: "control.txt"**
```html
sms_train_small.txt	uid	opp_num	opp_head	opp_len	start_time	in_out		
voice_train_small.txt	uid	opp_num	opp_head	opp_len	start_time	end_time	call_type	in_out
wa_train_small.txt	uid	wa_name	visit_cnt	visit_dura	up_flow	down_flow	wa_type	date

edges:
uid	opp_num
uid	table_0
opp_head	opp_num
opp_head	opp_len
table_0	start_time
table_0	in_out
```

&nbsp;
> **Output of Edges(partly): "graph.e"**
```html
1	3	2
1	6	5
1	7	6
2	1	1
2	8	1
2	34	7
2	39	7
2	55	13
2	63	13
3	4	3
```

Notes:

The third column contains the corresponding integers of the edge attributes combined sources' labels and targets' labels.  

&nbsp;
> **Output of Vertexes(partly): "graph.v"**
```html
1	1
2	2
3	3
4	4
5	5
6	6
7	7
8	1
9	6
10	7
```

Notes:

The prefixes are attached for distinguishing integers from different volumns.  
The ones with a profix "table_x_table_x_" are the vertexes without any meaningful information.  

&nbsp;
> **Output of Edge Attribute Dictionary(partly): "dictE.txt"**
```html
opp_num_to_opp_head	3
opp_num_to_opp_len	4
table_0_to_msg_in_out	6
table_0_to_msg_start_time	5
table_0_to_opp_num	2
table_1_to_call_end_time	10
table_1_to_call_in_out	12
table_1_to_call_start_time	9
table_1_to_call_type	11
table_1_to_opp_num	8
```

Notes:

The edge attributes has the format like A_to_B, in which A is source'label and B is target's label.  

&nbsp;
> **Output of Vertex Dictionary(partly): "dictV.txt"**
```html
call_end_time_02	47
call_end_time_03	36
call_end_time_04	40
call_in_out_0	45
call_in_out_1	38
opp_num_c1	19
opp_num_d1	22
table_0_table_0_0	1
table_0_table_0_1	8
table_0_table_0_10	30
```

Notes:

The prefixes "tabel_x_" are attached for distinguishing integers from different volumns.  
The ones with a profix "table_x_table_x_" are the vertexes without any meaningful information.  

&nbsp;
> **Output of Vertex Label Dictionary(partly): "dictL.txt"**
```html
call_end_time	10
call_in_out	12
call_start_time	9
call_type	11
date	20
down_flow	18
is_fake	22
msg_in_out	7
msg_start_time	6
opp_head	4
```
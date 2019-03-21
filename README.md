# Project written for a general graph builder.

#### Introduction
It is a graph builder for the LianTong's project. With a file used to control which edges are potential edges, It quickly build a graph contains edges and vertexes. 

#### Programming Language and Environment
Written in object-oriented C++ 11.
Written with Visual Studio 2017 under Windows 10.

#### Control File Grammar
>Explanation for the Controller File.

The front rows are for defination of files. 
For each row:
	The first string should be the name of the file. (the loaction could be raletive of absolutely both and can be changed in function: TableParser::parse)
	The following strings are the title of the correspond volumns, which imply the real meaning of the data. They are seperated by a *tab*.
	Each row have a potential title "table_x", which means it's **x**th table. And it is designed for the condition that there need a vertex without any meaningful infomation. 

After the rows for defination, the subsequent row should be a designated row with text, "edges:".
Then the following rows are description of edges.
For each row:
	The first string and the second string are the titles defined in the front rows. They are seperated by a *tab*.
	It means there may be a edge between the first string and the second string. If in a row of one file, the two strings appears at the same time, the program will make an edge from the first string to the second string and give the edge a label.

#### Example
>Controller File
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

>Output of Edges(partly)
```html
opp_num_a1	opp_head_123	opp_num_to_opp_head
opp_num_b1	opp_head_321	opp_num_to_opp_head
opp_num_c1	opp_head_145	opp_num_to_opp_head
opp_num_d1	opp_head_145	opp_num_to_opp_head
uid_u1	opp_num_a1	uid_to_opp_num
uid_u1	opp_num_c1	uid_to_opp_num
uid_u2	opp_num_a1	uid_to_opp_num
uid_u2	opp_num_b1	uid_to_opp_num
uid_u2	opp_num_c1	uid_to_opp_num
```

>Output of Vertexes(partly)
The third strings are the given labels.
```html
opp_num_a1
opp_num_b1
opp_num_c1
opp_num_d1
start_time_01
start_time_02
start_time_03
start_time_04
table_0_table_0_0
table_0_table_0_1
table_0_table_0_10
table_0_table_0_11
table_0_table_0_12
```
The prefixes are attached for distinguishing integers between different volumns. 
The ones with a profix "table_x_table_x_" are the vertexes without any meaningful information. 
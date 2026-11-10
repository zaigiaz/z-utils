# Overview
Implemented Data Structures and utilities in C
collection of parsers and other header libraries I created for personal use in projects

The dyn_arrays and hash_table were written months ago when I was a much worse programmer, so I will probably rewrite in the future.
I will add Memory Allocators and ring-buffers, queues, stacks, linked-list, etc later.

# current 

- Dynamic Arrays (not used)
- String-Buffers
- CSV Parser
- Arenas and Memory Pools

# Planned

next I want to do Linked-Lists and Tree-like structures
(Linked Lists, Binary Tree, Radix Tree, AVL Tree, RB Trees)

Then a basic .ini file format based off of strbuf
and basic .csv or .dat handling for any projects I have in the future.

I want to re-review the lexopt parser and maybe add an easier api interface on top like

```c
	parser.add_argument("p", "path-name", "s")

	//	where first is the letter we want, second is the name of the variable, and third is the return type?
```

I would like a generalized interface into cmd_line parsing for just simple (-name file.txt -break true)
for programs, and maybe support for more complex parsing later on.

# resources

- https://hackaday.com/2024/12/19/better-c-strings-simply/
  Good discussion here about string types in C and C++

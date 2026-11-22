# Overview
Implemented Data Structures and utilities in C
collection of parsers and other header libraries I created for personal use in projects

# current 

- str8   (length based u8 string)
- strbuf (buffer string type for bufio purposes)
- strmap (simple first-pass bucket associative array (non-hashing))
- CSV Parser 
- Ini Parser
- Pool and Arena Allocaters

# Planned

- prng random numbers
- file-formats (csv, ini, and custom)
- better lexopt or cmdline wrapper
- custom memory allocater (Pool + Arena Characteristics)
- range and vector/matrix types? (not-needed for now)
- stack or queue functions just built off either linked-lists or arrays
- Linux Daemon and Shell utilities (Launch Processes etc.)
- Path Iteration (Find Root, Split, Iteration)
- Helper Macros
- Formatted String like sprintf but very simple for str8, can insert into strmap or buf
- regex or peg for string processing?
- tiny apl-like dialect/dsl for processing array-types


## Simpler Commands

I want to re-review the lexopt parser and maybe add an easier api interface on top like

```c
    parser_init(&p);
	parser_add_argument("p", "path-name", "s");
	arglist *res = parser_get_arglist();

	//	where first is the letter we want, second is the name of the variable, and third is the return type?
	//  and we return array of parsed flags and values
```

I would like a generalized interface into cmd_line parsing for just simple (-name file.txt -break true)
for programs, and maybe support for more complex parsing later on.

# resources

- https://hackaday.com/2024/12/19/better-c-strings-simply/
  Good discussion here about string types in C and C++

- https://github.com/jamesroutley/write-a-hash-table/tree/master
  great repository for learning about hash-table implementation

- regex engine in 30 lines :: https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html

# libft
My implementation of some C standard library functions and additional functions.

## Version
There are two versions of my C standard libary function:
	
	1. original_version: this is the 42 project version
	
	2. updated_version: (libft) this is my customize library which includes
	
		a. libc function		(ft_libc)
		b. 42 additional function	(ft_add_on)
		c. linked list function		(lst)
		d. extra function		(ft_extra)
		e. get_next_line function	(gnl)
		f. rewrite printf function	(ft_printf)

## Getting Started
* Note: tested on Mac OS High Sierra
1. `git clone https://github.com/jding05/libft.git`
2. `cd libft`
3. run `make` to compile the library and produce a `libft.a` file
4. to make use of the Library run `gcc -L. -lft your_c_file.c` while in the `libft/` directory
	* you can move the `libft.a` file into your project repo **but** you must also copy over the `libft.h` header file
	* if you decide to move the library, run `gcc -L<path_to_library> -lft your_c_file.c`
5. Makefile commands:
	* `re`, `clean`, `fclean`, `all`

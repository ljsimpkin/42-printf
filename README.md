# ft_printf @ 42
This is a partial printf reimplementation for 42 Silicon Valley

## Description
ft_printf handles the following conversions: `cspdouxX%`

And the following flags: `#+-0` and `space`

With the following modifiers: `hh`, `h`, `l`, `ll`

ft_printf also correctly handles input for minimum field width and precision specified with `.`

Field width and precision can be specified in the format string as a number value or as `*` and passed as argument.

## Using this library
Run `make`
This will build the `libftprintf.a` library
Then include the `ft_printf.h` header in your project and compile with the library

For more information the brief can be downloaded here: [printf.pdf] (https://github.com/EDalSanto/42/raw/master/ft_printf/ft_printf.en.pdf) [printf.pdf](https://github.com/EDalSanto/42/raw/master/ft_printf/ft_printf.en.pdf)

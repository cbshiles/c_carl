tf=trans/$1'.c' # trans file
lang_src/parser src/$1'.carl' > "$tf"
gcc $tf -o exec/$1'.x'

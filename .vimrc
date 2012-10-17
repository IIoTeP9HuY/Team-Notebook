set nu
set tabstop=2
set shiftwidth=2
set expandtab
set autoindent
set showmatch
syntax on
colorscheme ron

func CompileRunGcc()
	w
	!g++ -D_DEBUG -std=c++0x -O2 % -o %<
	!./%<
endfunc

map <F5> :call CompileRunGcc() <CR>

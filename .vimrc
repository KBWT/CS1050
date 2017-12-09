set enc=utf-8
set fenc=utf-8
set termencoding=utf-8
set nocompatible
set mouse=a
set autoindent
set cindent
set tabstop=4
set shiftwidth=4
set expandtab
set textwidth=120
colo evening
set lbr
set tw=500
syntax on
set number
set showmatch
set comments=sl:/*,mb:\ *,elx:\ */
set nobackup
set noswapfile
set nowb
filetype indent on
set smartindent
autocmd BufRead,BufWritePre *.c normal gg=G

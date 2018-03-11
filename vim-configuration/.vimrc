set number 
syntax enable
filetype plugin indent on
set et 
set sw=4
set smarttab
set incsearch
set tabstop=4
set showmatch
set ruler 
set magic
set laststatus=2
set clipboard=unnamed

au BufNewFile,BufFilePre,BufRead *.md set filetype=markdown
autocmd BufRead,BufNewFile *.md setlocal spell spelllang=en_us
colorscheme monokai

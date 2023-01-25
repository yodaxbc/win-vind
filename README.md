<h1></h1>
<p align="center">
  <img src="res/banner.gif?raw=true" />
  <p align="center">
    <a href="https://scan.coverity.com/projects/pit-ray-win-vind"><img alt="Coverity Scan Build Status" src="https://img.shields.io/coverity/scan/pit-ray-win-vind?style=flat-square&color=4DB6AC" /></a>
    <a href="https://www.codacy.com/gh/pit-ray/win-vind/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=pit-ray/win-vind&amp;utm_campaign=Badge_Grade"><img src="https://img.shields.io/codacy/grade/8f2e6f2826904efd82019f5888574327?style=flat-square&color=4DB6AC" /></a>
    <a href="https://github.com/pit-ray/win-vind/actions/workflows/codeql-analysis.yml"><img src="https://img.shields.io/github/actions/workflow/status/pit-ray/win-vind/codeql-analysis.yml?branch=master&label=CodeQL&logo=github&style=flat-square&color=4DB6AC" /></a>
    <a href="https://github.com/pit-ray/win-vind/actions/workflows/test.yml"><img src="https://img.shields.io/github/actions/workflow/status/pit-ray/win-vind/test.yml?branch=master&label=test&logo=github&style=flat-square&color=4DB6AC" /></a>
    <br>  
    <a href="https://github.com/pit-ray/win-vind/actions/workflows/coverity.yml"><img src="https://img.shields.io/github/actions/workflow/status/pit-ray/win-vind/coverity.yml?branch=master&label=cov-build&logo=github&style=flat-square&color=4DB6AC" /></a>
    <a href="https://github.com/pit-ray/win-vind/actions/workflows/mingw.yml"><img src="https://img.shields.io/github/actions/workflow/status/pit-ray/win-vind/mingw.yml?branch=master&label=MinGW%20build&logo=github&style=flat-square&color=4DB6AC" /></a>
    <a href="https://github.com/pit-ray/win-vind/actions/workflows/msvc.yml"><img src="https://img.shields.io/github/actions/workflow/status/pit-ray/win-vind/msvc.yml?branch=master&label=MSVC%20build&logo=github&style=flat-square&color=4DB6AC" /></a>
    <br>
    <a href="https://community.chocolatey.org/packages/win-vind"><img src="https://img.shields.io/badge/chocolatey-supported-blue?style=flat-square&color=607D8B" /></a>
    <a href="https://github.com/microsoft/winget-pkgs/tree/master/manifests/p/pit-ray/win-vind"><img src="https://img.shields.io/badge/winget-supported-blue?style=flat-square&color=607D8B" /></a>
    <a href=""><img src="https://img.shields.io/badge/scoop-supported-blue?style=flat-square&color=607D8B" /></a>
    <img src="https://img.shields.io/badge/Windows%2011-supported-blue?style=flat-square&color=607D8B" />
  </p>
</p>  

## Description
**win-vind** provides a lightweight hybrid UI system of CUI and GUI for Windows.  

### 1. Vim-user friendly.
All configuration methods and mode concepts are derived from Vim, allowing for Vim-like UI operation.  
Vim users only need to understand win-vind's macro features and mode concepts with little learning cost.  

- Fast binding system
- Vim-like mode management
- .vimrc style configuration

### 2. There are many useful built-in commands.
You don't have to worry about complicated scripts and dependencies like with traditional key binding tools.  
You can freely create user-defined commands by combining low-level optimized built-in commands.

- GUI operation without mouse
- Vim emulation everywhere
- Process launcher like `:!vim ~/.vimrc` on resident command line
- Low-level key mapping (e.g. Capslock -> Ctrl)
- Keystroke macros
- Tiling window manager
- Hinting feature like Vimium or EasyMotion for GUI.

### 3. Very portable.
win-vind is a small single binary with no dependencies that runs with user permissions.   
It is also available from the command line as a command for UI operations.

- Running in user permission
- Oneshot use for Vim or AHK (e.g. `$ win-vind -f easy_click_left`)


#### Top Feature Demo

<img src="docs/imgs/4xxdemo.gif" title="Demo" >

#### Macro Feature Demo
https://user-images.githubusercontent.com/42631247/147887231-24424d36-410d-4379-8846-7dc6a5a7f355.mp4

<br>  

## Installation
We support a variety of installation methods.

#### [Chocolatey](https://chocolatey.org/)

```sh
$ choco install win-vind
```

#### [winget](https://github.com/microsoft/winget-cli)

```sh
$ winget install win-vind
```

#### [scoop](https://scoop.sh/)
Not yet open.
```sh
$ scoop install win-vind
```

#### Executable Installer
- [win-vind_5.0.0_32bit_installer.zip](https://github.com/pit-ray/win-vind/releases)
- [win-vind_5.0.0_64bit_installer.zip](https://github.com/pit-ray/win-vind/releases)

#### Portable Zip
- [win-vind_5.0.0_32bit_portable.zip](https://github.com/pit-ray/win-vind/releases)
- [win-vind_5.0.0_64bit_portable.zip](https://github.com/pit-ray/win-vind/releases)


## Usage
You can refer to the installation and quick tutorial in [Usage - win-vind](https://pit-ray.github.io/win-vind/usage/).  


### .vindrc samples  

You can configure it in .vimrc style. What you can do in .vindrc is switch options, set parameters, remap low-level keys, and define function bindings.

```vim
" Virtual command line options
set shell = cmd
set cmd_fontsize = 14
set cmd_roughpos = LowerLeft
set cmd_maxchar = 100

" Enable block style caret
set blockstylecaret
set blockstylecaret_mode = solid

" Low-level key mapping in resident mode
rmap <capslock> {<ctrl>}

" Define bindings in Normal mode
nnoremap <c-h> <select_left_window>
nnoremap <c-l> <select_right_window>
nnoremap <c-k> <select_upper_window>
nnoremap <c-j> <select_lower_window>

" Define bindings in insert mode
inoremap <capslock> <to_edi_normal>
inoremap <ralt> <easy_click_left>
inoremap <app> <window_resizer>
```

The [Functions](https://pit-ray.github.io/win-vind/cheat_sheet/functions/) page lists all supported functions, the [Options](https://pit-ray.github.io/win-vind/cheat_sheet/options/) document lists parameters and useful extensions, and the [Keyword List](https://pit-ray.github.io/win-vind/cheat_sheet/keywords/) contains keyword notations for writing .vindrc. If you want to know the default bindings, refer to <a href="https://pit-ray.github.io/win-vind/cheat_sheet/defaults">Default Mappings</a>. 

## Known Issues
- EasyClick does not seem to work properly for some applications on older Windows 10 before 1803. The cause is not known, but we have confirmed that it works after 1909. ([#11](https://github.com/pit-ray/win-vind/issues/11))
- Windows 10/11 Single Language does not seem to be able to map toggle keys such as `<Capslock>`. ([#40](https://github.com/pit-ray/win-vind/issues/40))

- If you want to use word motion (e.g. `w`, `B`, `e`) in MS Office Word, it is recommended to disable `Use smart paragraph selection`.  

  <img src="docs/imgs/opt_in_ms_word.png" title="Option in MS Word" width=600>

## How to build

#### Preparation
The dependencies required for the build are installed locally in the project directory. The system is not affected.
```bash
$ ./tools/setup_libs.bat -msvc 64
```

#### Debug

```bash
$ cmake -B debug -G "Visual Studio 16 2019" .
$ cmake --build debug
$ ./debug/Debug/win-vind.exe
```

#### Release

```bash
$ cmake -B release -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 16 2019" .
$ cmake --build release --config Release
$ ./debug/Release/win-vind.exe
```

If you want to build with MinGW or create an installer, see [here](https://github.com/pit-ray/win-vind/blob/master/CONTRIBUTING.md#to-development).


## Contribute
If you would like to contribute to win-vind, see [CONTRIBUTING.md](https://github.com/pit-ray/win-vind/blob/master/CONTRIBUTING.md).

The project is managed with <a href="https://github.com/users/pit-ray/projects/2">GitHub Projects</a>. 

## Similar Projects
- [rcmdnk/vim_ahk](https://github.com/rcmdnk/vim_ahk)
- [microsoft/PowerToys](https://github.com/microsoft/PowerToys)
- [zsims/hunt-and-peck](https://github.com/zsims/hunt-and-peck)

## License  

This software is provided by pit-ray under the **MIT License**.  

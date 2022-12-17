@echo off
color a
chcp 65001 > nul
:menu
    cls
    echo 1: Mở cùng với Windows
    echo 2: Gỡ cài đặt
    echo 3: thoát
    set /p option=Nhập lựa chọn: 
    if "%option%" == "1" goto startup
    if "%option%" == "2" goto uninstall
    if "%option%" == "3" exit
goto menu

:startup
cls
copy *.exe "%userprofile%/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup"
pause
goto menu
:uninstall
cls
echo đang gỡ cài đặt...
del *.exe
del "%userprofile%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\*.exe"
echo hoàn tất!
pause
goto menu
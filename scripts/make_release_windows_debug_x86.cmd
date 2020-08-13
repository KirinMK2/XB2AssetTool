@echo off

setlocal

if not exist "%CD%\bind32\" mkdir bind32
set PATH=C:\Qt\5.14.2\msvc2017\bin\;%PATH%

pushd bind32
	copy ..\out\build\x86-debug\src\ui\debug\xb2at.exe .
	windeployqt .\xb2at.exe
:: delete some files that aren't needed
:: (slims down the build tree quite a bit)
	del opengl32sw.dll
	del D3Dcompiler_47.dll
	del libEGLd.dll
	del libGLESv2d.dll
popd


endlocal
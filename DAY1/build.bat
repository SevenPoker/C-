cls

@echo [101mg++ %* -std=c++23 -o out.exe [0m
@g++ %* -std=c++23 -lstdc++exp -o out.exe

@IF %ERRORLEVEL% EQU 0 (
	echo [37;4m[ g++ compiling success !! run out.exe ][0m
  	out.exe
) ELSE (
	echo [37;4m[ Error !!, g++ fail to compile. ][0m
)
@echo:

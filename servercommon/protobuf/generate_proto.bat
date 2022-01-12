echo.
for %%i in (./proto/*.proto) do (call:gen_protobuf_code ./proto/%%i)
pause
exit

rem 以下是生成protobuf cpp代码的函数，若输出FAIL FAIL FAIL, 则是proto有问题，需要检查

:gen_protobuf_code
@echo off
echo generating %1
protoc --proto_path=. --cpp_out=. %1
IF %ERRORLEVEL% NEQ 0 (
    echo FAIL FAIL FAIL
	echo.
	timeout /T -1 /NOBREAK
) ELSE (
	echo SUCC SUCC SUCC
	echo.
)

goto:eof


@echo off
setlocal
set ROOT=%~dp0
if exist "%ROOT%build\client.exe" (
    "%ROOT%build\client.exe"
) else (
    "%ROOT%build\Debug\client.exe"
)

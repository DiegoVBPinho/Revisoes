@echo off
chcp 65001 > nul
echo --- 🔄 INICIANDO PROTOCOLO DE ATUALIZACAO ---

:: 1. Roda os trackers dentro de cada pasta (Level 1, Level 2...)
for /d %%D in (*) do (
    if exist "%%D\tracker.exe" (
        echo [TRACKER LOCAL] Processando: %%D
        cd "%%D"
        tracker.exe
        cd ..
    )
)

:: 2. Roda o tracker global na raiz
echo.
echo [TRACKER GLOBAL] Atualizando Dashboard...
if exist "global.exe" (
    global.exe
) else (
    echo ERRO: global.exe nao encontrado na raiz!
)

:: 3. GIT AUTO-COMMIT & PUSH
echo.
echo [GITHUB] 🐙 Salvando na nuvem...
git add .
git commit -m "Auto-update: Atualizacao diaria do Tracker"
git push origin main

:: 4. ABRIR O VS CODE
echo.
echo [VS CODE] 💻 Abrindo ambiente de trabalho...
:: O comando "code ." abre a pasta atual no VS Code
code .

echo.
echo ✅ TUDO PRONTO MESTRE!
timeout /t 5
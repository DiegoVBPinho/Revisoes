@echo off
chcp 65001 > nul
echo --- 🔄 INICIANDO ATUALIZACAO EM MASSA ---

:: Salva o caminho da raiz onde o tracker.exe principal está
set "RAIZ=%~dp0"

:: Loop Duplo: Para cada PASTA DE TEMA -> Para cada PASTA DE LEVEL
for /d %%A in (*) do (
    if exist "%%A" (
        pushd "%%A"
        
        :: Entra em cada subpasta (Level)
        for /d %%B in (*) do (
            echo [TRACKER LOCAL] Atualizando: %%A \ %%B
            cd "%%B"
            
            :: Executa o tracker da raiz passando o caminho (usando o exe que você colou o código novo)
            if exist "%RAIZ%tracker.exe" (
                "%RAIZ%tracker.exe" > nul
            ) else (
                echo [ERRO] tracker.exe nao encontrado na raiz!
            )
            
            cd ..
        )
        popd
    )
)

echo.
echo [TRACKER MESTRE] Consolidando dados globais...
if exist "master.exe" (
    master.exe
) else (
    echo ERRO: master.exe nao encontrado na raiz!
)

:: GIT AUTO-COMMIT & PUSH
echo.
echo [GITHUB] 🐙 Salvando na nuvem...
git add .
git commit -m "Auto-update: Atualizacao diaria do Tracker"
git push origin main

:: ABRIR O VS CODE NA RAIZ
echo.
echo [VS CODE] 💻 Abrindo Quartel General...
code .

echo.
echo ✅ TUDO PRONTO MESTRE!
timeout /t 5
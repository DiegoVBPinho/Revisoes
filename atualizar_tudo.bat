@echo off
chcp 65001 > nul
echo --- 🔄 INICIANDO ATUALIZACAO EM MASSA ---

:: Loop Duplo: Para cada PASTA DE TEMA -> Para cada PASTA DE LEVEL
:: %%A = Pasta do Tema (ex: 01 - Ponteiros)
:: %%B = Pasta do Level (ex: Level 1...)

for /d %%A in (*) do (
    :: Só entra se não for pasta oculta ou do sistema
    if exist "%%A" (
        pushd "%%A"
        
        :: Agora estamos dentro de "01 - Ponteiros". Procuramos os Levels
        for /d %%B in (*) do (
            if exist "%%B\tracker.exe" (
                echo [TRACKER LOCAL] Atualizando: %%A \ %%B
                cd "%%B"
                tracker.exe > nul
                cd ..
            )
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
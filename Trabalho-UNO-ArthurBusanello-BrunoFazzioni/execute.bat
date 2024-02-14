echo > Setup required Environment
echo -------------------------------------
SET RAYLIB_PATH=C:\raylib\raylib
SET COMPILER_PATH=C:\raylib\w64devkit\bin
ENV_SET PATH=$(COMPILER_PATH)
SET CC=gcc
SET CFLAGS=$(RAYLIB_PATH)\src\raylib.rc.data -s -static -Os -std=c99 -Wall -I$(RAYLIB_PATH)\src -Iexternal -DPLATFORM_DESKTOP
SET LDFLAGS=-lraylib -lopengl32 -lgdi32 -lwinmm
cd $(CURRENT_DIRECTORY)
echo
echo > Clean latest build
echo ------------------------
cmd /c IF EXIST $(NAME_PART).exe del /F $(NAME_PART).exe
echo
echo > Saving Current File
echo -------------------------
npp_save
echo
echo > Compile program
echo -----------------------
$(CC) -o $(NAME_PART).exe $(FILE_NAME) $(CFLAGS) $(LDFLAGS) TADS/menu.c TADS/deque_enc.c TADS/fila_enc.c TADS/lista_circ_enc_dupla.c TADS/lista_enc_dupla.c TADS/pilha.c 
echo
echo > Reset Environment
echo --------------------------
ENV_UNSET PATH
echo
echo > Execute program
echo -----------------------
cmd /c IF EXIST $(NAME_PART).exe $(NAME_PART).exe

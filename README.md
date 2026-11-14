# UnrealMapDrawTool

在 2D 视图里绘制 3D 地图 :)

工具可以把绘制好的格子导出为 Half-Life / Counter-Strike 使用的 `.map` 文件，也可以通过 JACK 编辑器插件直接导入。

## 简介（中文）

- **新建地图**：设置 X/Y 方向的格子数量、格子尺寸与高度、地图高度层数以及每层的图层数。
- **绘制**：左侧工具栏选择格子类型（画刷 / 人质 / 恐怖分子 / 反恐精英 / 灯光 / 购买区 / 炸弹区 / 水域），按住鼠标左键填充，右键清除。
- **保存工程**：保存为 `.umd`，可再次载入继续编辑，支持自动保存。
- **导出地图**：生成 `.map` 文件，交由 VHE / J.A.C.K. 等编辑器编译成 `.bsp`。

## 界面语言

界面默认简体中文，同时保留英文与俄文。语言在 `src/umd_i18n.h` 中切换：

```cpp
#ifndef UMD_LANGUAGE
#define UMD_LANGUAGE UMD_LANG_ZH   // UMD_LANG_ZH / UMD_LANG_EN / UMD_LANG_RU
#endif
```

所有界面文案统一写成 `TRS("中文", "English", "Русский")`，新增文字时按同样格式书写即可。

中文界面会自动从系统字体目录（优先 `msyh.ttc` 微软雅黑，其次黑体 / 宋体等）合并中文字库，无需额外附带字体文件。若系统缺少这些字体，中文可能显示为方框。

源文件为 UTF-8 编码，VS 工程已添加 `/utf-8` 编译选项，修改文案后请保持 UTF-8 编码保存。

## 构建

**MSVC（推荐）**：用 VS 2022 打开 `vc_project/UnrealMapDrawTool.sln`，选择 `Release | x64` 编译；或命令行：

```bat
msbuild vc_project\UnrealMapDrawTool.sln /p:Configuration=Release /p:Platform=x64
```

需要安装「使用 C++ 的桌面开发」工作负载（含 Windows SDK）。产物输出到 `Release\DrawMap_x64.exe`。

**MinGW-w64（无 VS 环境时可用）**：先下载 GLFW 3.4 的 Windows 预编译包（`glfw-3.4.bin.WIN64.zip`），然后：

```bash
g++ -std=c++17 -O2 -DNDEBUG -DGLEW_STATIC -DNOMINMAX -DWIN32 \
    -static -static-libgcc -static-libstdc++ \
    -I src -I src/GLFW \
    src/main.cpp src/ImFileDialog.cpp src/imgui.cpp src/imgui_draw.cpp \
    src/imgui_tables.cpp src/imgui_widgets.cpp src/imgui_impl_glfw.cpp \
    src/imgui_impl_opengl3.cpp src/misc/cpp/imgui_stdlib.cpp \
    <glfw解压目录>/lib-mingw-w64/libglfw3.a src/glew64s.lib \
    -lopengl32 -lgdi32 -lshell32 -lole32 -luuid -lcomdlg32 -luser32 \
    -o Release/DrawMap_x64.exe
```

## English

Draw 3d maps in 2d mode :)

newbspguy can be used to export any exiting .bsp map to .umd

JACK editor can import .umd via plugin

UI is available in Simplified Chinese (default), English and Russian — see `src/umd_i18n.h`.

https://www.youtube.com/watch?v=CRrs6TRE-II

https://www.youtube.com/watch?v=RySttkij1xU

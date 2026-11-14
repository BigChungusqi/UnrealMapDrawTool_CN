#pragma once

// ===========================================================================
//  UnrealMapDrawTool 界面语言配置 / UI localization
//
//  默认语言：简体中文
//  切换方式：修改下面的 UMD_LANGUAGE 宏
//      UMD_LANG_ZH  简体中文
//      UMD_LANG_EN  English
//      UMD_LANG_RU  Русский
//
//  代码中统一使用：TRS("中文", "English", "Русский")
// ===========================================================================

#define UMD_LANG_ZH 1
#define UMD_LANG_EN 2
#define UMD_LANG_RU 3

// 兼容旧写法：定义 RUSSIAN_LANGUAGE 时自动切换为俄语
#if defined(RUSSIAN_LANGUAGE) && !defined(UMD_LANGUAGE)
#define UMD_LANGUAGE UMD_LANG_RU
#endif

#ifndef UMD_LANGUAGE
#define UMD_LANGUAGE UMD_LANG_ZH
#endif

#if UMD_LANGUAGE == UMD_LANG_ZH
#define TRS(zh, en, ru) zh
#elif UMD_LANGUAGE == UMD_LANG_RU
#define TRS(zh, en, ru) ru
#else
#define TRS(zh, en, ru) en
#endif

// 当前是否为中文界面（字体图集需要额外加载中文字形）
#define UMD_ZH_UI (UMD_LANGUAGE == UMD_LANG_ZH)

// 常用 2500 字之外、界面里额外用到生僻字时，追加到这里
// （"频" 不在 ImGui 的常用字表内，但"视频"等目录名需要）
#define UMD_CJK_EXTRA_TEXT "频"

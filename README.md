# Quad Salamander

Open Salamander is a fast and reliable two-panel file manager for Windows.
Quad Salamander is a modification of it, which adds in total 4 file managers.

Quad Salamander is fully functional and many things were well thought out so that it works as a true quad file manager (drag/drop between all panels, using tab or shift+tab to change active panel, resizing panels, swapping panels, etc.). It can easily be used as a beaseline for further work in that direction.

<img src="https://github.com/beklemeto/salamander/blob/main/Quad%20Salamander.png" alt="Image 1" width="*" />

There are several smaller changes complementing the 4 panels such as:
- added "Age" column: showing the time interval since file modified datetime.
- added music, pictures, videos, downloads, and desktop user folders to the drive bar

The only projects that were modified were:
- salamand
- lang
  
Both projects are part of the solution salamander_lite.sln.
Projects require VisualStudio 2019 with Windows10 SDK. However this can be easily changed (OpenSalamander uses VS2022).


The Quad Salamander should still support all the plugins, but the plugin will be aware only about the top left and top right panels. No exapnsion of the plugins interface is made, to ensure the compatibility.

It's was nice after so many years since Servant Salamander was released to be able to work on its source code for a while. Thanks!




The rest of the information is comming from Open Salamander:

## Origin

The original version of Servant Salamander was developed by Petr Šolín while he was studying at the Czech Technical University. He released it as freeware in 1997. After graduating, Petr Šolín founded [Altap](https://www.altap.cz/) together with Jan Ryšavý. In 2001, they released the first shareware version of the program. In 2007, the project was renamed Altap Salamander with the release of version 2.5. Many other programmers and translators have [contributed](AUTHORS) to the project over the years. In 2019, Altap was acquired by [Fine](https://www.finesoftware.eu/). After the acquisition, Altap Salamander 4.0 was released as freeware. In 2023, the source code was released under the GPLv2 license as Open Salamander 5.0.

The name Servant Salamander came from a brainstorming session between Petr Šolín and his friend Pavel Schreib. At the time, the best-known file managers were the aging Norton Commander and the increasingly popular Windows Commander. They wondered why a file manager should be called a commander at all: a good file manager serves its users rather than commands them. That idea led to the name Servant Salamander.

Salamander was our first major C++ project, and the code reflects both that learning process and the era in which it was built. It does not follow the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines), use smart pointers, rely on [RAII](https://en.cppreference.com/w/cpp/language/raii), or use libraries such as the [STL](https://github.com/microsoft/STL) or [WIL](https://github.com/microsoft/wil). Most of these practices and libraries were still emerging when Salamander was created. Many comments are still written in Czech, but recent advances in AI-assisted translation make them much easier to improve incrementally. Salamander is a pure WinAPI application and does not use application frameworks such as MFC.

We would like to thank [Fine](https://www.finesoftware.eu/) for making the open-source release of Salamander possible.

## Development

### Prerequisites
- Windows 11 or newer
- [Visual Studio 2022](https://visualstudio.microsoft.com/downloads/)
- [Desktop development with C++](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170) workload installed in VS2022
- [Windows 11 (10.0.26100.4654) SDK](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/) optional component installed in VS2022

### Optional requirements
- [Git](https://git-scm.com/downloads)
- [PowerShell 7.4](https://learn.microsoft.com/en-us/powershell/scripting/install/installing-powershell-on-windows) or newer
- [HTMLHelp Workshop 1.3](https://learn.microsoft.com/en-us/answers/questions/265752/htmlhelp-workshop-download-for-chm-compiler-instal)
- Set the `OPENSAL_BUILD_DIR` environment variable to specify the build directory. The path must include a trailing backslash, for example `D:\Build\OpenSal\`.

### Building

You can build the `\src\vcxproj\salamand.sln` solution in Visual Studio or from the command line with `\src\vcxproj\rebuild.cmd`.

Use `\src\vcxproj\!populate_build_dir.cmd` to populate the build directory with the files required to run Open Salamander.

### Contributing

Contributions that help build, maintain, and improve Open Salamander are welcome.

## Repository Contents

```
\convert         Conversion tables for the Convert command
\doc             Documentation
\help            User manual source files
\src             Open Salamander core source code
\src\common      Shared libraries
\src\common\dep  Shared third-party libraries
\src\lang        English resources
\src\plugins     Plugin source code
\src\reglib      Access to Windows Registry files
\src\res         Image resources
\src\salmon      Crash detection and reporting
\src\salopen     Open files helper
\src\salspawn    Process spawning helper
\src\setup       Installer and uninstaller
\src\sfx7zip     Self-extractor based on 7-Zip
\src\shellext    Shell extension DLL
\src\translator  Tools for translating the Salamander UI into other languages
\src\tserver     Trace server for displaying information and error messages
\src\vcxproj     Visual Studio project files
\tools           Minor utilities
\translations    Translations into other languages
```

Some Altap Salamander 4.0 plugins are either not included or cannot currently be compiled. For example, the PictView engine, `pvw32cnv.dll`, is not open source, so the project should eventually move to [WIC](https://learn.microsoft.com/en-us/windows/win32/wic/-wic-about-windows-imaging-codec) or another image library. The Encrypt plugin is incompatible with modern SSDs and has been deprecated. The UnRAR plugin is missing [unrar.dll](https://www.rarlab.com/rar_add.htm), and the FTP plugin is missing the [OpenSSL](https://www.openssl.org/) libraries. Both issues are solvable because both projects are open source. Building the WinSCP plugin requires Embarcadero C++ Builder.

All source files use UTF-8 with BOM and are formatted with `clang-format`. See `\normalize.ps1` for details.

## Resources

- [Altap Salamander website](https://www.altap.cz/)
- Altap Salamander 4.0 [features](https://www.altap.cz/salamander/features/)
- Altap Salamander 4.0 [documentation](https://www.altap.cz/salamander/help/)
- Servant Salamander and Altap Salamander [changelogs](https://www.altap.cz/salamander/changelogs/)
- [User community forum](https://forum.altap.cz/)
- Altap Salamander on [Wikipedia](https://en.wikipedia.org/wiki/Altap_Salamander)

## Related Forks

Two interesting Open Salamander forks are [Sally](https://github.com/0xeb/sally) by 0xeb and [Samandarin](https://github.com/KRtkovo-eu-AI/salamander/) by KRtekTM.

## License

Open Salamander is open-source software licensed under [GPLv2](LICENSE) or later.
Some individual [files and libraries](doc/third_party.txt) use different but compatible licenses.

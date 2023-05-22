#pragma once

struct Fonts
{
    ~Fonts() = default;

    void BuildFonts(const SIZE& aOutSize);
    void RebuildFonts(ID3D12CommandQueue* apCommandQueue, SIZE aOutSize);
    void RebuildFontNextFrame();

    const bool UseEmojiFont();

    void EnumerateSystemFonts();
    const std::vector<std::string>& GetSystemFonts();
    std::filesystem::path GetSystemFontPath(const std::string& acFontName);
    std::filesystem::path GetFontPathFromOption(const std::string& acFontOption);

    ImFont* MainFont;
    ImFont* MonospaceFont;

private:
    friend struct CET;
    Fonts(Options& aOptions, Paths& aPaths);

    Options& m_options;
    Paths& m_paths;

    bool m_rebuildFonts{false};
    bool m_useEmojiFont{false};
    std::vector<std::string> m_systemFonts{"Default"};
    std::unordered_map<std::string, std::filesystem::path> m_systemFontPaths{};

    std::filesystem::path m_defaultPrimaryFont{L"NotoSans-Regular.ttf"};
    std::vector<std::filesystem::path> m_defaultFonts{
        L"NotoSansJP-Regular.otf",
        L"NotoSansKR-Regular.otf",
        L"NotoSansSC-Regular.otf",
        L"NotoSansTC-Regular.otf",
        L"NotoSansThai-Regular.ttf"
    };

    std::filesystem::path m_defaultMonospaceFontPath{L"NotoSansMono-Regular.ttf"};
    std::filesystem::path m_defaultIconFontPath{L"materialdesignicons.ttf"};
    std::filesystem::path m_defaultEmojiFontPath{L"C:\\Windows\\Fonts\\seguiemj.ttf"}; // tried to use noto color emoji but it wont render. only this one works
};

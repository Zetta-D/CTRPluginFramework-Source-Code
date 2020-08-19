#include "CTRPluginFramework/Menu/PluginMenu.hpp"

namespace CTRPluginFramework
{
    PluginMenu *g_runningInstance = nullptr;

    PluginMenu::PluginMenu(std::string name = "Cheats", std::string about = "")
    {
        _menu = std::make_uniue<PluginMenuImpl>(new PluginMenuImpl(name, about));
        PluginMenuImpl::PluginMenuImpl(name, about);
    }

    PluginMenu::PluginMenu(std::string name, void *about, DecipherPointer func)
    {
        _menu = std::make_uniue<PluginMenuImpl>(new PluginMenuImpl(name, about));
        PluginMenuImpl::PluginMenuImpl(name, about, func);
    }

    PluginMenu::PluginMenu(std::string name, u32 major, u32 minor, u32 revision, std::string about = "")
    {
        _menu = std::make_uniue<PluginMenuImpl>(new PluginMenuImpl(name, about));
        _menu->AddPluginVersion((u16)(minor << 8) | major | (revision << 16) & 0xFF0000)
    }

    PluginMenu::~PluginMenu(void)
    {
        _menu->~PluginMenuImpl();
    }

    void PluginMenu::Append(MenuEntry *item) const
    {
        if(item != nullptr)
            _menu->Append(item);
    }

    void PluginMenu::Append(MenuFolder *item) const
    {
        if(item != nullptr)
            _menu->Append(item);
    }

    void PluginMenu::operator += (const MenuEntry *entry) const
    {
        if(item != nullptr)
            _menu->Append(item);
    }

    void PluginMenu::operator -= (const MenuFolder *folder) const
    {
        if(item != nullptr)
            _menu->Append(item);
    }

    void PluginMenu::operator += (CallbackPointer callback) const
    {
        if(callback != nullptr)
            _menu->Callback(callback);
    }

    void PluginMenu::operator -= (CallbackPointer callback) const
    {
        if(callback != nullptr)
            _menu->RemoveCallback(callback);
    }

    int PluginMenu::Run(void) const
    {
        g_runningInstance = nullptr;
        return _menu->Run();
    }

    std::vector<MenuEntry *> PluginMenu::GetEntryList(void) const
    {
        _menu->GetRoot();
        return _menu->GetEntryList();
    }

    std::vector<MenuFolder *> PluginMenu::GetFolderList(void) const
    {
        _menu->GetRoot();
        return _menu->GetFolderList();
    }

    void PluginMenu::SetHexEditorState(bool isEnabled) const
    {
        _menu->SetHexEditorState(isEnabled);
    }

    void PluginMenu::ShowWelcomeMessage(bool showMsg) const
    {
        _menu->ShowWelcomeMessage(showMsg);
    }

    bool PluginMenu::IsOpen(void)
    {
        return _menu->IsOpen();
    }

    bool PluginMenu::WasOpened(void)
    {
        return _menu->WasOpened();
    }

    PluginMenu *PluginMenu::GetRunningInstance(void)
    {
        return g_runningInstance;
    }

    void PluginMenu::SynchronizeWithFrame(const bool useSync)
    {
        _menu->synchronizeWithFrame = useSync;
    }

    std::string &PluginMenu::Title()
    {
        return _menu->title;
    }
}

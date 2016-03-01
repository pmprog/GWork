/*
 *  Gwork
 *  Copyright (c) 2012 Facepunch Studios
 *  Copyright (c) 2013-2016 Billy Quith
 *  See license in Gwork.h
 */

#include <Gwork/Platform.h>
#include <time.h>

static Gwk::String gs_ClipboardEmulator;

void Gwk::Platform::Sleep(unsigned int ms)
{
    ::sleep(ms);
}

void Gwk::Platform::SetCursor(unsigned char iCursor)
{
    // No platform independent way to do this
}

Gwk::String Gwk::Platform::GetClipboardText()
{
    return gs_ClipboardEmulator;
}

bool Gwk::Platform::SetClipboardText(const Gwk::String& str)
{
    gs_ClipboardEmulator = str;
    return true;
}

float Gwk::Platform::GetTimeInSeconds()
{
    float fSeconds = (float)clock()/(float)CLOCKS_PER_SEC;
    return fSeconds;
}

bool Gwk::Platform::FileOpen(const String& Name, const String& StartPath, const String& Extension,
                             String& filePathOut)
{
    return false;
}

bool Gwk::Platform::FileSave(const String& Name, const String& StartPath, const String& Extension,
                             String& filePathOut)
{
    return false;
}

bool Gwk::Platform::FolderOpen(const String& Name, const String& StartPath, String& filePathOut)
{
    return false;
}

void* Gwk::Platform::CreatePlatformWindow(int x, int y, int w, int h,
                                          const Gwk::String& strWindowTitle)
{
    return NULL;
}

void Gwk::Platform::DestroyPlatformWindow(void* ptr)
{
}

bool Gwk::Platform::MessagePump(void* window)
{
    return false;
}

void Gwk::Platform::SetBoundsPlatformWindow(void* ptr, int x, int y, int w, int h)
{
}

void Gwk::Platform::SetWindowMaximized(void* ptr, bool bMax, Gwk::Point& newPos,
                                        Gwk::Point& newSize)
{
}

void Gwk::Platform::SetWindowMinimized(void* ptr, bool bMinimized)
{
}

bool Gwk::Platform::HasFocusPlatformWindow(void* ptr)
{
    return true;
}

void Gwk::Platform::GetDesktopSize(int& w, int& h)
{
    w = 1024;
    h = 768;
}

void Gwk::Platform::GetCursorPos(Gwk::Point& po)
{
}
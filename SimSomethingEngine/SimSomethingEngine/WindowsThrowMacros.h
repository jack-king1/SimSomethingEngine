#pragma once

#define KIWND_EXCEPT( hr ) Window::HrException( __LINE__,__FILE__,(hr) )
#define KIWND_LAST_EXCEPT() Window::HrException( __LINE__,__FILE__,GetLastError() )
#define KIWND_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ )
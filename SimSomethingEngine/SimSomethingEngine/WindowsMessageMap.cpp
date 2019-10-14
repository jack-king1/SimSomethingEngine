#include "WindowsMessageMap.h"
#include <string>
#include <sstream>
#include <iomanip>
//Tutorial #4 fore this to finish

//secret messages
#define WM_UAHDESTROYWINDOW 0x0090
#define WMUAHDRAWMENU 0x0091
#define WM_UAHDRAWMENUITEM 0x0092
#define WM_UAHINITMENU 0x0093
#define WM_UAHMEASUREMENUITEM 0x0094
#define WM_UAHNCPAINTMENUPOPUP 0x0095

#define REGISTER_MESSAGE(msg){msg,#msg}



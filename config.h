#pragma once

#define LAYER_STATE_8BIT // Limit the number of layers to 8 to save firmware size.

#ifndef __ASSEMBLER__
#include "quantum/keycodes.h"
// Define all of custom keycodes. Needs to be protected.
#define SELWORD QK_USER
#define UPDIR QK_USER + 1
#define LLOCK QK_USER + 2
#endif
